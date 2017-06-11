//  ***************************************************************************
//  COPYRIGHT 2015 TO THE PRESENT   RHEINMETALL AIR DEFENCE AG   CH-8050 ZURICH
//
//  SOFTWARE DEVELOPMENT DEPARTMENT
//  ***************************************************************************

#include "Session.hpp"
#include "RApplication.hpp"

namespace REP {

Session::Session(CL::TCPSocket* client)
	: m_app(client)
	, m_peer(client->peer())
{
	;
}

Session::~Session()
{
	BasicThread::terminate();
	m_app.stop();
	BasicThread::wait();
}

void Session::stopSession()
{
	m_app.stop();
}

void Session::threadCode()
{
	m_app.exec();
}

RApplication & Session::getRApplication()
{
	return this->m_app;
}

CL::SockAddress Session::peerAddress() const
{
	return m_peer;
}

}