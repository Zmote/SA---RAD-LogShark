#pragma once
#include <QObject>
#include <QTest>

class RT_Client_Test : public QObject
{
	Q_OBJECT

public:
	RT_Client_Test(int& argc, char** argv, QObject* parent = Q_NULLPTR);
	~RT_Client_Test();

private slots:
	static void testDefaultClientHasGlobalId();
	static void testGlobalClient();
	static void testGroupClient();
	static void testRegularClient();
	static void testClientDefaultTableGenerationWhenTableNotSet();
	static void testClientAutoTableGenerationWhenTableNullptrSet();
	void testAddLogToClientTable() const;
	void testAddLogToClientTableDefaultOnBottom() const;
	void testAddLogOnTopToClientTable() const;
	void testClearModelOfClientTable() const;
private:
	static int argc;
	static char** argv;
};
