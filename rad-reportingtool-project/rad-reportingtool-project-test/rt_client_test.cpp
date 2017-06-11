#include "rt_client_test.hpp"
#include "RT_Client.h"
#include "CommonViewUtils.h"
#include "CommonLogUtils.h"

int RT_Client_Test::argc = 0;
char ** RT_Client_Test::argv;

RT_Client_Test::RT_Client_Test(int & pArgc, char ** pArgv, QObject * parent) 
: QObject(parent)
{
	argc = pArgc;
	argv = pArgv;
}

RT_Client_Test::~RT_Client_Test() {
	
}

void RT_Client_Test::testDefaultClientHasGlobalId()
{
	QApplication a{ argc,argv };
	RT_Client client{};
	QVERIFY(client.getClientId() == RT_Constants::GLOBAL_ID);
}

void RT_Client_Test::testGlobalClient()
{
	QApplication a{ argc,argv };
	RT_Client globalClient{RT_Constants::GLOBAL_ID, RT_Constants::GLOBAL, RT_Constants::GLOBAL, CommonViewUtils::setupTable(RT_Constants::GLOBAL)};
	QVERIFY(globalClient.getClientName() == RT_Constants::GLOBAL);
	QVERIFY(globalClient.getClientId() == RT_Constants::GLOBAL_ID);
}

void RT_Client_Test::testGroupClient()
{
	QApplication a{ argc,argv };
	RT_Client groupClient{ RT_Constants::GROUP_ID, "Groupname", RT_Constants::GLOBAL, CommonViewUtils::setupTable("Groupname") };
	QVERIFY(groupClient.getClientName() == "Groupname");
	QVERIFY(groupClient.getClientId() == RT_Constants::GROUP_ID);
}

void RT_Client_Test::testRegularClient()
{
	QApplication a{ argc,argv };
	RT_Client client{ 10,"Clientname","Groupname", CommonViewUtils::setupTable("Clientname") };
	QVERIFY(client.getClientName() == "Clientname");
	QVERIFY(client.getClientId() == 10);
	QVERIFY(client.getGroupName() == "Groupname");
	QVERIFY(client.getTable()->objectName() == "Clientname");
}

void RT_Client_Test::testClientDefaultTableGenerationWhenTableNotSet()
{
	QApplication a{ argc, argv };
	RT_Client client{};
	QVERIFY(client.getTable() != nullptr);
	QCOMPARE(client.getTable()->objectName(), client.getClientName());
}

void RT_Client_Test::testClientAutoTableGenerationWhenTableNullptrSet()
{
	QApplication a{ argc, argv };
	RT_Client client{ 10, "Clientname", "Groupname", nullptr };
	QVERIFY(client.getTable() != nullptr);
	QCOMPARE(client.getTable()->objectName(), client.getClientName());
}

void RT_Client_Test::testAddLogToClientTable() const
{
	QApplication a{ argc, argv };
	RT_Client client{ 1, "Clientname", "Groupname" };
	const CL::ByteArray message{};
	const CL::Time timestamp{};
	REP::PROTO::LogBinaryMsg msg{ 1,message, timestamp };
	QList<QString> entry = CommonLogUtils::prepareLogEntry(client.getClientName(), client.getGroupName(), msg);
	QList<QList<QString>> logEntry{entry};
	client.addLog(logEntry);
	QCOMPARE(client.getTable()->model()->rowCount(), 1);
}

void RT_Client_Test::testAddLogToClientTableDefaultOnBottom() const
{
	QApplication a{ argc, argv };
	RT_Client client{ 1, "Clientname", "Groupname" };
	client.newestOnTop(false);
	const CL::Time timestamp{};;
	const std::string text1{ "Lorem Ipsum" };
	const std::string text2{ "I'm on top" };
	REP::PROTO::LogMsg msg1{ 1, REP::PROTO::MessageKind::MK__INFO, text1, timestamp };
	REP::PROTO::LogMsg msg2{ 1, REP::PROTO::MessageKind::MK__INFO, text2, timestamp };
	QList<QString> entry1 = CommonLogUtils::prepareLogEntry(client.getClientName(), client.getGroupName(), msg1);
	QList<QString> entry2 = CommonLogUtils::prepareLogEntry(client.getClientName(), client.getGroupName(), msg2);
	QList<QList<QString>> logEntry1{ entry1 };
	QList<QList<QString>> logEntry2{ entry2 };
	client.addLog(logEntry1);
	client.addLog(logEntry2);
	QCOMPARE(client.getTable()->model()->data(client.getTable()->model()->index(1, 5)).toString(), QString::fromStdString(text2));
}

void RT_Client_Test::testAddLogOnTopToClientTable() const
{
	QApplication a{ argc, argv };
	RT_Client client{ 1, "Clientname", "Groupname" };
	client.newestOnTop(true);
	const CL::Time timestamp{};;
	const std::string text1{ "Lorem Ipsum" };
	const std::string text2{ "I'm on top" };
	REP::PROTO::LogMsg msg1{ 1, REP::PROTO::MessageKind::MK__INFO, text1, timestamp };
	REP::PROTO::LogMsg msg2{ 1, REP::PROTO::MessageKind::MK__INFO, text2, timestamp };
	QList<QString> entry1 = CommonLogUtils::prepareLogEntry(client.getClientName(), client.getGroupName(), msg1);
	QList<QString> entry2 = CommonLogUtils::prepareLogEntry(client.getClientName(), client.getGroupName(), msg2);
	QList<QList<QString>> logEntry1{entry1};
	QList<QList<QString>> logEntry2{entry2};
	client.addLog(logEntry1);
	client.addLog(logEntry2);
	QCOMPARE(client.getTable()->model()->data(client.getTable()->model()->index(0,5)).toString(), QString::fromStdString(text2));
}

void RT_Client_Test::testClearModelOfClientTable() const
{
	QApplication a{ argc, argv };
	RT_Client client{ 1, "Clientname", "Groupname" };
	client.newestOnTop(true);
	const CL::Time timestamp{};;
	const std::string text1{ "Lorem Ipsum" };
	const std::string text2{ "I'm on top" };
	REP::PROTO::LogMsg msg1{ 1, REP::PROTO::MessageKind::MK__INFO, text1, timestamp };
	REP::PROTO::LogMsg msg2{ 1, REP::PROTO::MessageKind::MK__INFO, text2, timestamp };
	QList<QString> entry1 = CommonLogUtils::prepareLogEntry(client.getClientName(), client.getGroupName(), msg1);
	QList<QString> entry2 = CommonLogUtils::prepareLogEntry(client.getClientName(), client.getGroupName(), msg2);
	QList<QList<QString>> logEntry1{ entry1 };
	QList<QList<QString>> logEntry2{ entry2 };
	client.addLog(logEntry1);
	client.addLog(logEntry2);
	client.clearModel();
	QCOMPARE(client.getTable()->model()->rowCount(), 0);
}
