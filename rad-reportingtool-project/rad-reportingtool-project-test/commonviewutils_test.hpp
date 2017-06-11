#pragma once
#include <QObject>
#include <QTest>
class CommonViewUtils_Test : public QObject {
	Q_OBJECT

public:
	CommonViewUtils_Test(int & pArgc, char ** pArgv, QObject * parent = Q_NULLPTR);
	~CommonViewUtils_Test();
private slots:
static void testSetupTable();
static void testResetColumnWidths();
static void testResetClient();
static void testInitTabWidget();
static void testPrepareRouteState();
private:
	static int argc;
	static char ** argv;
};
