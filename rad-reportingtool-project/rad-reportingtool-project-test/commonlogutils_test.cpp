#include "commonlogutils_test.hpp"
#include "CommonLogUtils.h"
#include <ReportingTool/ProxyProtocol/Messages/LogBinaryMsg.hpp>
#include <ReportingTool/ProxyProtocol/Messages/LogMsg.hpp>
#include <ReportingTool/ProxyProtocol/Messages/Types.hpp>
#include <CL/Memory/ByteArray.hpp>
#include <CL/Time/Time.hpp>
#include <QTest>

CommonLogUtils_Test::CommonLogUtils_Test(QObject * parent) : QObject(parent) {
	
}

CommonLogUtils_Test::~CommonLogUtils_Test() {
	
}

void CommonLogUtils_Test::testParseLog()
{
	QString logToParse{"Entry\tEntry\tEntry\tEntry"};
	QList<QString> parsedLogEntry = CommonLogUtils::parseLog(logToParse);
	QCOMPARE(parsedLogEntry.size(), 6);
}

void CommonLogUtils_Test::testPrepareBinaryLogEntry()
{
	const CL::ByteArray message{};
	const CL::Time timestamp{};
	REP::PROTO::LogBinaryMsg msg{1,message, timestamp};
	QList<QString> entry = CommonLogUtils::prepareLogEntry("TestClient", "TestGroup", msg);
	QVERIFY(!entry.isEmpty());
}

void CommonLogUtils_Test::testPrepareLogEntryIsNotEmpty()
{
	const CL::Time timestamp{};;
	const std::string text{ "Lorem Ipsum" };
	REP::PROTO::LogMsg msg{ 1, REP::PROTO::MessageKind::MK__INFO, text, timestamp };
	QList<QString> entry = CommonLogUtils::prepareLogEntry("TestClient", "TestGroup", msg);
	QVERIFY(!entry.isEmpty());
}

void CommonLogUtils_Test::testPrepareLogEntryHasKindInfo()
{
	const CL::Time timestamp{};;
	const std::string text{ "Lorem Ipsum" };
	REP::PROTO::LogMsg msg{ 1, REP::PROTO::MessageKind::MK__INFO, text, timestamp };
	QList<QString> entry = CommonLogUtils::prepareLogEntry("TestClient", "TestGroup", msg);
	QVERIFY2(entry.at(4) == "Info", QString("Was" + entry.at(4) + "expected: Info").toStdString().c_str());
}

void CommonLogUtils_Test::testResolveMessageKind()
{
	QString resolvedKind = CommonLogUtils::resolveMessageKind(REP::PROTO::MessageKind::MK__ERROR);
	QVERIFY(resolvedKind == "Error");
}
