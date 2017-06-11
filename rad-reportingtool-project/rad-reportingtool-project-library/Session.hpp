//  ***************************************************************************
//  COPYRIGHT 2015 TO THE PRESENT   RHEINMETALL AIR DEFENCE AG   CH-8050 ZURICH
//
//  SOFTWARE DEVELOPMENT DEPARTMENT
//  ***************************************************************************

#ifndef REP_SESSION_HPP_INCLUDED
#define REP_SESSION_HPP_INCLUDED

#include "RApplication.hpp"
#include <CL/Threading/BasicThread.hpp>
#include <CL/Networking/SockAddress.hpp>

namespace REP {

	class Session : public CL::BasicThread {
	public:
		// takes ownership of `client`
		explicit Session(CL::TCPSocket* client);

		virtual ~Session();

		void stopSession();

		CL::SockAddress peerAddress() const;

		void threadCode() override;

		RApplication & getRApplication();

	private:
		RApplication m_app;
		CL::SockAddress m_peer;
	};

}

#endif
