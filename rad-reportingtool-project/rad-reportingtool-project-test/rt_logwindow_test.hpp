#pragma once
#include <QObject>

class RT_LogWindow_Test : public QObject
{
	Q_OBJECT

public:
	RT_LogWindow_Test(int& pArgc, char** pArgv, QObject* parent = Q_NULLPTR);
	~RT_LogWindow_Test();
private slots:
	void testClientStateChange();
private:
	static int argc;
	static char** argv;
};
