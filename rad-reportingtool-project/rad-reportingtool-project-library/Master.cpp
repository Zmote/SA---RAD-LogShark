//  ***************************************************************************
//  COPYRIGHT 2015 TO THE PRESENT   RHEINMETALL AIR DEFENCE AG   CH-8050 ZURICH
//
//  SOFTWARE DEVELOPMENT DEPARTMENT
//  ***************************************************************************

#include "Master.hpp"
#include "RApplication.hpp"
#include "Session.hpp"
#include <CL/Networking/SockAddress.hpp>
#include "rt_main.h"
#include <QDebug>
#include <QObject>
#include "RT_CaptureWorker.h"

namespace REP {

	namespace {

		CL::TCPSocket* acceptSocket(CL::TCPSocket& s)
		{
			try {
				return s.accept();
			}
			catch (...) {
				return nullptr;
			}
		}

	}

	Master::Config::Config()
		: verbosity(0)
	{
		;
	}


	Master::Master(const Config& cfg, RT_Main & pMainWindow)
	: m_cfg(cfg), m_server(cfg.address), mainWindow(pMainWindow) {}

	Master::~Master()
	{
		BasicThread::terminate();

		m_server.cancelReceive();
		m_server.disconnect();

		for (Sessions::iterator it = m_sessions.begin();
			it != m_sessions.end();
			++it)
		{
			(*it)->stopSession();
			delete *it;
			*it = nullptr;
		}

		BasicThread::wait();
	}

	void Master::threadCode()
	{
		CL::TCPSocket* client;

		m_server.listen();

		qDebug() << "waiting for connection on " << m_server.address().str().c_str();

		while (!doTerminate() && ((client = acceptSocket(m_server)) != nullptr)) {
			qDebug() << "connection from " << client->peer().str().c_str();
			Session *session = new Session(client);
			QObject::connect(&session->getRApplication(), &RApplication::registerClientLogReceived, &mainWindow, &RT_Main::registerClientLog, Qt::ConnectionType::BlockingQueuedConnection);
			QObject::connect(session->getRApplication().getWorker(), &RT_CaptureWorker::logsProcessed, &mainWindow, &RT_Main::handleProcessedLogs, Qt::ConnectionType::QueuedConnection);
			QObject::connect(&mainWindow, &RT_Main::signalUpdateClientActivestate, &session->getRApplication(), &RApplication::updateClientActiveState, Qt::ConnectionType::DirectConnection);
			QObject::connect(&session->getRApplication(), &RApplication::signalRApplicationInitialized, &mainWindow, &RT_Main::rapplicationInitialized, Qt::ConnectionType::DirectConnection);
			session->start();
			qDebug() << "removing closed sessions...";
			// remove finished sessions from list
			Sessions::iterator it = m_sessions.begin();
			while (it != m_sessions.end()) {
				if (!(*it)->running()) {
					qDebug() << " " << (*it)->peerAddress().str().c_str();
					delete *it;
					it = m_sessions.erase(it);
				}
				else {
					++it;
				}
			}
			qDebug() << " done.";

			// put new session in list
			m_sessions.push_back(session);

			qDebug() << "waiting for connection on " << m_server.address().str().c_str();
		}
	}

	void Master::setConfig(Config cfg)
	{
		this->m_cfg = cfg;
	}
}
