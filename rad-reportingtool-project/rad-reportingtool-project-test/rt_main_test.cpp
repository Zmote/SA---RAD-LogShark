#include "rt_main_test.hpp"
#include <qtestcase.h>
#include <ReportingTool/ProxyProtocol/Messages/RegisterClientMsg.hpp>
#include "rt_main.h"
#include <qtestkeyboard.h>
#include <QTest>

int RT_Main_Test::argc = 0;
char ** RT_Main_Test::argv;

RT_Main_Test::RT_Main_Test(int& pArgc, char** pArgv, QObject* parent)
{
	argc = pArgc;
	argv = pArgv;
}

RT_Main_Test::~RT_Main_Test() {
	
}

void RT_Main_Test::testIsGlobal() const
{
	QApplication a(argc, argv);
	RT_Main w;
	RT_Client globalClient{ RT_Constants::GLOBAL_ID, "Global", "Global" };
	QCOMPARE(w.isGlobal(globalClient),true);
}

void RT_Main_Test::testIsGroup() const
{

	QApplication a(argc, argv);
	RT_Main w;
	RT_Client globalClient{ RT_Constants::GROUP_ID, "Groupname", "Groupname" };
	QCOMPARE(w.isGroup(globalClient), true);
}

void RT_Main_Test::testLogWindowCreation() const
{
	QApplication a(argc, argv);
	RT_Main w;
	REP::PROTO::RegisterClientMsg msg{ 2, "Clientname", "Groupname", "comment", false };
	w.registerClient(msg);
	w.createLogWindow("Clientname", QPoint(100, 100));
	QCOMPARE(w.subWindowExists("Clientname"), true);
}

void RT_Main_Test::testClientSearchTermEntered() const
{
	QApplication a(argc, argv);
	RT_Main w;
	QLineEdit * clientInput = w.findChild<QLineEdit*>("clientInput");
	QTest::keyClicks(clientInput, "client10");
	QCOMPARE(clientInput->text(), QString("client10"));
}
