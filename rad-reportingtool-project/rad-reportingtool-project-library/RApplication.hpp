//  ***************************************************************************
//  COPYRIGHT 2015 TO THE PRESENT   RHEINMETALL AIR DEFENCE AG   CH-8050 ZURICH
//
//  SOFTWARE DEVELOPMENT DEPARTMENT
//  ***************************************************************************

#ifndef REP_RAPPLICATION_HPP_INCLUDED
#define REP_RAPPLICATION_HPP_INCLUDED

#include <ReportingTool/ProxyProtocol/Messages/MsgKindStatusChangeMsg.hpp>
#include <ReportingTool/ProxyProtocol/Protocol/ServerProtocol.hpp>
#include <CL/Networking/TCPSocket.hpp>
#include <CL/Time/Time.hpp>
#include <map>
#include <QThread>
#include "RT_Main_Modell.h"
#include "RT_CaptureWorker.h"
#include "RT_UpdateWorker.h"

namespace REP {

	namespace PROTO {
		class SynMsg;
		class Message;
		class LogBinaryMsg;
		class LogClientCommentsMsg;
		class LogMsg;
		class LogReportingMsg;
		class LogUnregisteredMsg;
		class RegisterClientMsg;
		class KeepAliveMsg;
	}

	class RApplication : public QObject {
		Q_OBJECT
			struct Client;
		public slots:
		void updateClientActiveState(int clientId, bool pIsActive);
		signals:
		void startUpdater();
		void logReceived(const QString & clientName, const QString & groupName, const PROTO::LogMsg & msg);
		void binaryLogReceived(const QString & clientName, const QString & groupName, const PROTO::LogBinaryMsg & msg);
		void registerClientLogReceived(const PROTO::RegisterClientMsg & msg);
		void signalRApplicationInitialized();
	public:
		explicit RApplication(CL::TCPSocket* client);
		~RApplication();

		void exec();

		void stop();

		struct Client {
			std::string name;
			std::string group;
			int localId;
			bool isActive;

			Client();
			Client(int localId_, const std::string& name_, const std::string& group);
		};
	
		const RT_CaptureWorker * getWorker() const;

	private:
		RApplication(const RApplication& other);
		RApplication& operator=(const RApplication& other);

		void handle(const PROTO::SynMsg& msg);
		void handle(const PROTO::KeepAliveMsg& msg);
		void handle(const PROTO::LogBinaryMsg& msg);
		static void handle(const PROTO::LogClientCommentsMsg& msg);
		void handle(const PROTO::LogMsg& msg);
		void handle(const PROTO::RegisterClientMsg& msg);
		static void handle(const PROTO::LogUnregisteredMsg& msg);
		static void handle(const PROTO::LogReportingMsg& msg);
		void sendMsg(const PROTO::Message& msg);
		static bool needsBuffering(const PROTO::LogMsg & msg);
		void addToBuffer(const PROTO::LogMsg& msg);
		void handleBufferedLogs(QList<PROTO::LogMsg> & buffer);
		typedef std::map<int, Client> Clients;

		PROTO::ServerProtocol m_protocol;
		Clients m_clients;
		PROTO::MsgKindStatusChangeMsg::MsgKindActivationState m_state;
		CL::Time m_timestamp;
		bool m_binaryActive;
		QThread * captureThread;
		QThread * updaterThread;
		QPointer<RT_UpdateWorker> updateWorker;
		QPointer<RT_CaptureWorker> captureWorker;
		QList<PROTO::LogMsg> infoLogBuffer{};
		QList<PROTO::LogMsg> warningLogBuffer{};
		QList<PROTO::LogMsg> errorLogBuffer{};
		QList<PROTO::LogMsg> exceptionLogBuffer{};
		QList<PROTO::LogMsg> fatalLogBuffer{};
	};

}

#endif
