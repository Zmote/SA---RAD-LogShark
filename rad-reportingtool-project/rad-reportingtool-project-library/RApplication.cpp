//  ***************************************************************************
//  COPYRIGHT 2015 TO THE PRESENT   RHEINMETALL AIR DEFENCE AG   CH-8050 ZURICH
//
//  SOFTWARE DEVELOPMENT DEPARTMENT
//  ***************************************************************************

#include "RApplication.hpp"
#include <ReportingTool/ProxyProtocol/Protocol/ServerProtocol.hpp>
#include <ReportingTool/ProxyProtocol/Messages/BinaryStatusChangeMsg.hpp>
#include <ReportingTool/ProxyProtocol/Messages/ClientStatusChangeMsg.hpp>
#include <ReportingTool/ProxyProtocol/Messages/KeepAliveMsg.hpp>
#include <ReportingTool/ProxyProtocol/Messages/LogBinaryMsg.hpp>
#include <ReportingTool/ProxyProtocol/Messages/LogClientCommentsMsg.hpp>
#include <ReportingTool/ProxyProtocol/Messages/LogMsg.hpp>
#include <ReportingTool/ProxyProtocol/Messages/LogReportingMsg.hpp>
#include <ReportingTool/ProxyProtocol/Messages/LogUnregisteredMsg.hpp>
#include <ReportingTool/ProxyProtocol/Messages/RegisterClientMsg.hpp>
#include <ReportingTool/ProxyProtocol/Messages/SynMsg.hpp>
#include <ReportingTool/ReportingLib/Reporting.hpp>
#include <ReportingTool/ReportingLib/Singleton.hpp>
#include <ReportingTool/ReportingLib/ReportingImpl.hpp>
#include <CL/Time/Clocks.hpp>
#include <CL/Networking/TCPSocket.hpp>
#include "RT_CaptureWorker.h"
#include "RT_Settings.h"

namespace REP
{
	namespace
	{

		bool getState(int id)
		{
			switch (id)
			{
			case 0: return RT_Settings::logSettings.enableInfo();
			case 1: return RT_Settings::logSettings.enableWarning();
			case 2: return RT_Settings::logSettings.enableError();
			case 3: return RT_Settings::logSettings.enableException();
			case 4: return RT_Settings::logSettings.enableFatal();
			default: return false;
			}
		}

		PROTO::MsgKindStatusChangeMsg::MsgKindActivationState currentState()
		{
			PROTO::MsgKindStatusChangeMsg::MsgKindActivationState state;
			for (int i = 0; i <= PROTO::MK__LAST; ++i)
			{
				state.set(i, getState(i));
			}

			return state;
		}
	}

	RApplication::Client::Client()
		: localId(Reporting::UNREGISTERED_CLIENT_ID)
		  , isActive(false)
	{
		;
	}

	RApplication::Client::Client(int localId_, const std::string& name_, const std::string& group_)
		: name(name_)
		  , group(group_)
		  , localId(localId_)
		  , isActive(false)
	{
	}

	void RApplication::updateClientActiveState(int clientId, bool pIsActive)
	{
		sendMsg(PROTO::ClientStatusChangeMsg(clientId, pIsActive));
	}

	RApplication::RApplication(CL::TCPSocket* client)
		:  m_protocol(client)
		  , m_binaryActive(false)
	{
		captureThread = new QThread(this);
		captureWorker = new RT_CaptureWorker();
		captureWorker->moveToThread(captureThread);
		connect(this, &RApplication::logReceived, captureWorker, &RT_CaptureWorker::handleLog, Qt::ConnectionType::QueuedConnection);
		connect(this, &RApplication::binaryLogReceived, captureWorker, &RT_CaptureWorker::handleBinaryLog, Qt::ConnectionType::QueuedConnection);
		captureThread->start();
		updaterThread = new QThread(this);
		updateWorker = new RT_UpdateWorker();
		updateWorker->moveToThread(updaterThread);
		connect(this, &RApplication::startUpdater, updateWorker, &RT_UpdateWorker::startUpdater, Qt::ConnectionType::QueuedConnection);
		connect(updateWorker, &RT_UpdateWorker::signalUpdate, captureWorker, &RT_CaptureWorker::signalLogsReady, Qt::ConnectionType::QueuedConnection);
		updaterThread->start();
		emit startUpdater();
		m_timestamp = CL::monoClk().now();
	}

	RApplication::~RApplication()
	{
		if (!updateWorker.isNull())
			updateWorker->thread()->terminate();
			updateWorker->deleteLater();
		if (!captureWorker.isNull())
			captureWorker->thread()->terminate();
			captureWorker->deleteLater();
	}

	void RApplication::exec()
	{
		int id;
		while ((id = m_protocol.getNextMessageId()) != 0)
		{
			switch (id)
			{
			case PROTO::LogBinaryMsg::MSG_ID:
				{
					PROTO::LogBinaryMsg msg;
					if (m_protocol.parseMessage(msg))
					{
						handle(msg);
					}
					break;
				}

			case PROTO::LogClientCommentsMsg::MSG_ID:
				{
					PROTO::LogClientCommentsMsg msg;
					if (m_protocol.parseMessage(msg))
					{
						handle(msg);
					}
					break;
				}

			case PROTO::LogMsg::MSG_ID:
				{
					PROTO::LogMsg msg;
					if (m_protocol.parseMessage(msg))
					{
						if(needsBuffering(msg))
						{
							addToBuffer(msg);
						}else
						{
							handle(msg);
						}
					}
					break;
				}

			case PROTO::RegisterClientMsg::MSG_ID:
				{
					PROTO::RegisterClientMsg msg;
					if (m_protocol.parseMessage(msg))
					{
						handle(msg);
					}
					break;
				}

			case PROTO::KeepAliveMsg::MSG_ID:
				{
					PROTO::KeepAliveMsg msg;
					if (m_protocol.parseMessage(msg))
					{
						handle(msg);
					}
					break;
				}

			case PROTO::SynMsg::MSG_ID:
				{
					PROTO::SynMsg msg;
					if (m_protocol.parseMessage(msg))
					{
						handle(msg);
					}
					break;
				}

			default:
				m_protocol.skipMessage();
			}
		}
	}

	void RApplication::stop()
	{
		m_protocol.cancelReceive();
	}

	void RApplication::handle(const PROTO::KeepAliveMsg& msg)
	{
		m_timestamp = CL::monoClk().now();

		const PROTO::MsgKindStatusChangeMsg::MsgKindActivationState state = currentState();
		if (state != m_state) {
			sendMsg(PROTO::MsgKindStatusChangeMsg(state));
			m_state = state;
		}

		const bool binaryActive = RT_Settings::logSettings.enableBinary();
		if (binaryActive != m_binaryActive) {
			sendMsg(PROTO::BinaryStatusChangeMsg(binaryActive));
			m_binaryActive = binaryActive;
		}

		if (!m_protocol.hadError()) {
			m_protocol.flushBuffer();
		}
	}

	void RApplication::handle(const PROTO::LogClientCommentsMsg& msg)
	{
		Reporting::logClientComments(msg.fileName().str());
	}

	void RApplication::handle(const PROTO::LogBinaryMsg& msg)
	{
		auto const it = m_clients.find(msg.clientId());
		if (it != m_clients.cend())
		{
			emit binaryLogReceived(QString::fromStdString(it->second.name), QString::fromStdString(it->second.group), msg);
		}
	}

	void RApplication::handle(const PROTO::LogMsg& msg)
	{
		auto const it = m_clients.find(msg.clientId());
		if (it != m_clients.cend())
		{
			emit logReceived(QString::fromStdString(it->second.name), QString::fromStdString(it->second.group), msg);
		}
	}

	void RApplication::handle(const PROTO::RegisterClientMsg& msg)
	{
		emit registerClientLogReceived(msg);
		Client& c = m_clients[msg.id()];

		if (msg.isBinary())
		{
			c.localId = Reporting::registerBinClient(msg.client(), msg.group(), msg.comment());
		}
		else
		{
			c.localId = Reporting::registerClient(msg.client(), msg.group(), msg.comment());
		}

		c.group = msg.group();
		c.name = msg.client();
		c.isActive = false;
		sendMsg(PROTO::ClientStatusChangeMsg(msg.id(), c.isActive));
		emit signalRApplicationInitialized();
	}

	void RApplication::handle(const PROTO::LogUnregisteredMsg& msg)
	{
		Singleton::instance().impl().logUnregistered(static_cast<ReportingStrategy::MessageKind>(msg.kind()), msg.message(), msg.timestamp());
	}

	void RApplication::handle(const PROTO::LogReportingMsg& msg)
	{
		Singleton::instance().impl().logReporting(static_cast<ReportingStrategy::MessageKind>(msg.kind()), msg.message(), msg.timestamp());
	}

	const RT_CaptureWorker* RApplication::getWorker() const
	{
		return captureWorker;
	}

	void RApplication::handle(const PROTO::SynMsg& msg)
	{
		m_state = currentState();
		sendMsg(PROTO::MsgKindStatusChangeMsg(m_state));
		m_binaryActive = RT_Settings::logSettings.enableBinary();
		sendMsg(PROTO::BinaryStatusChangeMsg(m_binaryActive));
	}

	void RApplication::sendMsg(const PROTO::Message& msg)
	{
		m_protocol.sendMessage(msg);
	}

	bool RApplication::needsBuffering(const PROTO::LogMsg& msg)
	{
		switch (msg.kind())
		{
			case PROTO::MK__INFO: return RT_Settings::logSettings.infoMessage();
			case PROTO::MK__WARNING: return RT_Settings::logSettings.warningMessage();
			case PROTO::MK__ERROR: return RT_Settings::logSettings.errorMessage();
			case PROTO::MK__EXCEPTION: return RT_Settings::logSettings.exceptionMessage();
			case PROTO::MK__FATAL: return RT_Settings::logSettings.fatalMessage();
			default: return false;
		}
	}

	void RApplication::addToBuffer(const PROTO::LogMsg& msg)
	{
		switch (msg.kind())
		{
		case PROTO::MK__INFO:
			infoLogBuffer.append(msg);
			handleBufferedLogs(infoLogBuffer);
			break;
		case PROTO::MK__WARNING:
			warningLogBuffer.append(msg);
			handleBufferedLogs(warningLogBuffer);
			break;
		case PROTO::MK__ERROR:
			errorLogBuffer.append(msg);
			handleBufferedLogs(errorLogBuffer);
			break;
		case PROTO::MK__EXCEPTION: 
			exceptionLogBuffer.append(msg);
			handleBufferedLogs(exceptionLogBuffer);
			break;
		case PROTO::MK__FATAL:
			fatalLogBuffer.append(msg);
			handleBufferedLogs(fatalLogBuffer);
			break;
		default: break;
		}
	}

	void RApplication::handleBufferedLogs(QList<PROTO::LogMsg>& buffer)
	{
		if(buffer.size() >= RT_Settings::messageBufferLimit())
		{
			std::for_each(buffer.constBegin(),buffer.constEnd(),[&](const PROTO::LogMsg & msg)
			{
				handle(msg);
			});
			buffer.clear();
		}
	}

	RApplication::RApplication(const RApplication& other)
		: m_protocol(nullptr),
		  m_binaryActive(false)
	{
		updaterThread = new QThread(this);
		updateWorker = new RT_UpdateWorker();
		captureThread = new QThread(this);
		captureWorker = new RT_CaptureWorker();
		connect(this, &RApplication::logReceived, captureWorker, &RT_CaptureWorker::handleLog, Qt::ConnectionType::QueuedConnection);
		connect(this, &RApplication::binaryLogReceived, captureWorker, &RT_CaptureWorker::handleBinaryLog, Qt::ConnectionType::QueuedConnection);
		connect(this, &RApplication::startUpdater, updateWorker, &RT_UpdateWorker::startUpdater, Qt::ConnectionType::QueuedConnection);
		connect(updateWorker, &RT_UpdateWorker::signalUpdate, captureWorker, &RT_CaptureWorker::signalLogsReady, Qt::ConnectionType::QueuedConnection);
	}

	RApplication& RApplication::operator=(const RApplication& other)
	{
		return *this;
	}
}
