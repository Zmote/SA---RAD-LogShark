#pragma once
#include <QObject>
#include <QTest>

class RT_LogFilter_Test : public QObject {
	Q_OBJECT

public:
	RT_LogFilter_Test(int & argc, char ** argv, QObject * parent = Q_NULLPTR);
	~RT_LogFilter_Test();

private slots:
void testDefaultLogFilter() const;
void testLogFilterWithFilterString1() const;
void testLogFilterWithFilterString2() const;
void testLogFilterWithFilterString3() const;
void testLogFilterWithFilterString4() const;
	static void testLogFilterIsValid();
	static void testLogFilterIsInvalid();
private:
	static int argc;
	static char ** argv;
};
