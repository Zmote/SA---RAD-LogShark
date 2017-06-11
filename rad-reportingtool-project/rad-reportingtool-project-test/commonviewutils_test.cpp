#include "commonviewutils_test.hpp"
#include "CommonViewUtils.h"

int CommonViewUtils_Test::argc = 0;
char ** CommonViewUtils_Test::argv;

CommonViewUtils_Test::CommonViewUtils_Test(int& pArgc, char** pArgv, QObject* parent): QObject(parent) 
{
	argc = pArgc;
	argv = pArgv;
}

CommonViewUtils_Test::~CommonViewUtils_Test() {
	
}

void CommonViewUtils_Test::testSetupTable()
{
	QApplication a{argc, argv};
	QTableView * view = CommonViewUtils::setupTable("TestClient");
	QVERIFY(view->objectName() == "TestClient");
}

void CommonViewUtils_Test::testResetColumnWidths()
{
	QApplication a{ argc, argv };
	QTableView * view = CommonViewUtils::setupTable("TestClient");
	RT_Client client{ 1, "TestClient", "TestGroup", view };
	client.getTable()->setColumnWidth(0, 1000);
	CommonViewUtils::resetColumnWidths(client);
	QVERIFY(client.getTable()->columnWidth(0) == 80);
}

void CommonViewUtils_Test::testResetClient()
{
	QApplication a{ argc, argv };
	QTableView * view = CommonViewUtils::setupTable("TestClient");
	RT_Client client{ 1, "TestClient", "TestGroup", view };
	client.active(true);
	client.live(true);
	CommonViewUtils::resetClient(client);
	QVERIFY(client.active() == false);
	QVERIFY(client.live() == false);
}

void CommonViewUtils_Test::testInitTabWidget()
{
	QApplication a{ argc, argv };
	QTabWidget * tabWidget = new QTabWidget();
	CommonViewUtils::initTabWidget(tabWidget);
	QVERIFY(tabWidget->acceptDrops() == true);
	QVERIFY(tabWidget->documentMode() == true);
	QVERIFY(tabWidget->isMovable() == true);
	QVERIFY(tabWidget->hasMouseTracking() == true);
}

void CommonViewUtils_Test::testPrepareRouteState()
{
	QApplication a{ argc, argv };
	QTableView * view = CommonViewUtils::setupTable("TestClient");
	RT_Client client{ 1, "TestClient", "TestGroup", view };
	client.live(true);
	QVERIFY(CommonViewUtils::prepareRouteState(client) == "L");
}
