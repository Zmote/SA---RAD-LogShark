#include "commonsettingsutils_test.hpp"
#include "CommonSettingsUtils.h"
#include "CommonViewUtils.h"
#include <QApplication>
#include <qtestcase.h>
#include <QJsonDocument>

int CommonSettingsUtils_Test::argc = 0;
char ** CommonSettingsUtils_Test::argv;

CommonSettingsUtils_Test::CommonSettingsUtils_Test(int& pArgc, char** pArgv, QObject* parent)
{
	argc = pArgc;
	argv = pArgv;
}

CommonSettingsUtils_Test::~CommonSettingsUtils_Test() {
	
}

void CommonSettingsUtils_Test::testClientObjectCreated() const
{
	QApplication a(argc, argv);
	RT_Client client{3,"Clientname", "Groupname", CommonViewUtils::setupTable("Clientname")};
	QJsonObject clientObject = CommonSettingsUtils::constructClientObject(client);
	QCOMPARE(clientObject.value("clientName").toString(), QString("Clientname"));
}

void CommonSettingsUtils_Test::testGroupObjectCreated() const
{
	QApplication a(argc, argv);
	RT_Client client{ RT_Constants::GROUP_ID,"Groupname", "Groupname", CommonViewUtils::setupTable("Groupname") };
	QJsonObject clientObject = CommonSettingsUtils::constructClientObject(client);
	QCOMPARE(clientObject.value("clientName").toString(), QString("Groupname"));
}

void CommonSettingsUtils_Test::testSettingsObjectCreated() const
{
	QApplication a(argc, argv);
	QJsonObject settingsObject = CommonSettingsUtils::constructSettingsObject();
	QCOMPARE(settingsObject.value("baseFileSaveLocation").toString(), RT_Settings::baseFileSaveLocation());
}

void CommonSettingsUtils_Test::testGlobalSettingsObjectCreated() const
{
	QApplication a(argc, argv);
	QJsonObject globalSettingsObject = CommonSettingsUtils::constructGlobalLogSettingsObject();
	QCOMPARE(globalSettingsObject.value("enableInfo").toBool(), RT_Settings::logSettings.enableInfo());
}

void CommonSettingsUtils_Test::testViewSettingsObjectCreated() const
{
	QApplication a(argc, argv);
	QJsonObject viewSettingsObject = CommonSettingsUtils::constructViewSettingsObject();
	QCOMPARE(viewSettingsObject.value("showClientSection").toBool(), RT_Settings::viewSettings.showClientSection);
}

void CommonSettingsUtils_Test::testClientObjectParsed() const
{
	QApplication a(argc, argv);
	RT_Client client{ 3,"Clientname", "Groupname", CommonViewUtils::setupTable("Clientname") };
	QJsonObject clientObject = CommonSettingsUtils::constructClientObject(client);
	RT_Client parsedClient = CommonSettingsUtils::constructClientFromObject(clientObject);
	QCOMPARE(parsedClient.getClientName(), QString("Clientname"));
}

void CommonSettingsUtils_Test::testGroupObjectParsed() const
{
	QApplication a(argc, argv);
	RT_Client client{ RT_Constants::GROUP_ID,"Groupname", "Groupname", CommonViewUtils::setupTable("Clientname") };
	QJsonObject clientObject = CommonSettingsUtils::constructClientObject(client);
	RT_Client parsedClient = CommonSettingsUtils::constructClientFromObject(clientObject);
	QCOMPARE(parsedClient.getClientName(), QString("Groupname"));
}

void CommonSettingsUtils_Test::testSettingsObjectParsed() const
{
	QJsonObject settingsObject = CommonSettingsUtils::constructSettingsObject();
	settingsObject.insert("baseFileSaveLocation", "Testlocation");
	CommonSettingsUtils::constructSettingsFromObject(settingsObject);
	QCOMPARE(RT_Settings::baseFileSaveLocation(), QString("Testlocation"));
}

void CommonSettingsUtils_Test::testGlobalSettingsObjectParsed() const
{
	QJsonObject globalSettingsObject = CommonSettingsUtils::constructGlobalLogSettingsObject();
	globalSettingsObject.insert("enableInfo", false);
	CommonSettingsUtils::constructGlobalLogSettingsFromObject(globalSettingsObject);
	QCOMPARE(RT_Settings::logSettings.enableInfo(), false);
}

void CommonSettingsUtils_Test::testViewSettingsObjectParsed() const
{
	QJsonObject viewSettingsObject = CommonSettingsUtils::constructViewSettingsObject();
	viewSettingsObject.insert("showClientSection", false);
	CommonSettingsUtils::constructViewSettingsFromObject(viewSettingsObject);
	QCOMPARE(RT_Settings::viewSettings.showClientSection, false);
}
