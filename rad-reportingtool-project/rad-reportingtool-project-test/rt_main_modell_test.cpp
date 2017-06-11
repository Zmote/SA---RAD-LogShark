#include "rt_main_modell_test.hpp"
#include <QApplication>
#include "rt_main.h"
#include <qtestcase.h>
#include <QTreeView>
#include <qtestkeyboard.h>
#include <qtestmouse.h>
#include <QSortFilterProxyModel>

int RT_Main_Modell_Test::argc = 0;
char ** RT_Main_Modell_Test::argv;

RT_Main_Modell_Test::RT_Main_Modell_Test(int& pArgc, char** pArgv, QObject* parent)
{
	argc = pArgc;
	argv = pArgv;
}

RT_Main_Modell_Test::~RT_Main_Modell_Test() {
	
}

void RT_Main_Modell_Test::testGetClients() const
{
	QApplication a(argc, argv);
	RT_Main w;
	REP::PROTO::RegisterClientMsg msg{ 2, "Clientname", "Groupname", "comment", false };
	w.registerClient(msg);
	QCOMPARE(w.getModel().getClients().size(), 1);
}
