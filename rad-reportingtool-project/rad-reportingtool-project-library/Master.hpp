//  ***************************************************************************
//  COPYRIGHT 2015 TO THE PRESENT   RHEINMETALL AIR DEFENCE AG   CH-8050 ZURICH
//
//  SOFTWARE DEVELOPMENT DEPARTMENT
//  ***************************************************************************

#ifndef REP_MASTER_HPP_INCLUDED
#define REP_MASTER_HPP_INCLUDED

#include <CL/Time/Time.hpp>
#include <CL/Threading/BasicThread.hpp>
#include <CL/Networking/SockAddress.hpp>
#include <CL/Networking/TCPSocket.hpp>
#include <list>
#include "rt_main.h"

namespace REP {

	class Session;

	class Master : public CL::BasicThread {
	public:
		struct Config {
			CL::SockAddress address;
			CL::Time timeout;
			int verbosity;

			Config();
		};

		Master(const Config& cfg, RT_Main & pMainWindow);

		virtual ~Master();

		void threadCode() override;

		void setConfig(Config cfg);
	private:
		Master(const Master& other) = delete;
		Master& operator=(const Master& other) = delete;

		Config m_cfg;
		CL::TCPSocket m_server;
		RT_Main & mainWindow;

		typedef std::list<Session*> Sessions;

		Sessions m_sessions;
	};


}


#endif
