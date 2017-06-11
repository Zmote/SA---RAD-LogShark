#include "rt_logfilter_test.hpp"
#include "RT_LogFilter.h"

int RT_LogFilter_Test::argc = 0;
char ** RT_LogFilter_Test::argv;

RT_LogFilter_Test::RT_LogFilter_Test(int& pArgc, char** pArgv, QObject* parent)
{
	argc = pArgc;
	argv = pArgv;
}

RT_LogFilter_Test::~RT_LogFilter_Test() {}

void RT_LogFilter_Test::testDefaultLogFilter() const
{
	RT_LogFilter logFilter{};
	QCOMPARE(logFilter.plainSearchTerm, QString(""));
}

void RT_LogFilter_Test::testLogFilterWithFilterString1() const
{
	RT_LogFilter logFilter{ "Kind=Info" };
	QCOMPARE(logFilter.messageKindTerm.pattern(), QString("Info"));
}

void RT_LogFilter_Test::testLogFilterWithFilterString2() const
{
	RT_LogFilter logFilter{ "Kind=Info&&Content=Lorem Ipsum" };
	QCOMPARE(logFilter.messageKindTerm.pattern(), QString("Info"));
	QCOMPARE(logFilter.contentTerm.pattern(), QString("Lorem Ipsum"));
}

void RT_LogFilter_Test::testLogFilterWithFilterString3() const
{
	RT_LogFilter logFilter{"Date=2017-01-01&&Time=11:23:00&&Kind=Failure&&Content=Lorem Ipsum"};
	QCOMPARE(logFilter.messageKindTerm.pattern(), QString("Failure"));
	QCOMPARE(logFilter.contentTerm.pattern(), QString("Lorem Ipsum"));
	QCOMPARE(logFilter.dateTerm.pattern(), QString("2017-01-01"));
	QCOMPARE(logFilter.timeTerm.pattern(), QString("11:23:00"));
}

void RT_LogFilter_Test::testLogFilterWithFilterString4() const
{
	RT_LogFilter logFilter{ "Date=2017-01-01&&Time=11:23:00&&Kind=Failure&&Content=Lorem Ipsum&&Client=Testclient&&Group=TestGroup" };
	QCOMPARE(logFilter.messageKindTerm.pattern(), QString("Failure"));
	QCOMPARE(logFilter.contentTerm.pattern(), QString("Lorem Ipsum"));
	QCOMPARE(logFilter.dateTerm.pattern(), QString("2017-01-01"));
	QCOMPARE(logFilter.timeTerm.pattern(), QString("11:23:00"));
	QCOMPARE(logFilter.clientNameTerm.pattern(), QString("Testclient"));
	QCOMPARE(logFilter.groupNameTerm.pattern(), QString("TestGroup"));
}

void RT_LogFilter_Test::testLogFilterIsValid()
{
	RT_LogFilter logFilter{ "Date=2017-01-01&&Time=11:23:00&&Kind=Failure&&Content=Lorem Ipsum&&Client=Testclient&&Group=TestGroup" };
	QVERIFY(logFilter.isValid());
}

void RT_LogFilter_Test::testLogFilterIsInvalid()
{
	RT_LogFilter logFilter{ "Date==2017-02-03" };
	QVERIFY(!logFilter.isValid());
}
