#pragma once
#include <QObject>

class RT_SettingsWindow_Test : public QObject {
	Q_OBJECT

public:
	RT_SettingsWindow_Test(int& pArgc, char** pArgv, QObject * parent = Q_NULLPTR);
	~RT_SettingsWindow_Test();
private slots:
void testConfigNameEmptyWhenDefault();
private:
	static int argc;
	static char** argv;
	
};
