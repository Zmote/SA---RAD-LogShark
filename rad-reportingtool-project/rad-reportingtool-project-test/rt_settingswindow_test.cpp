#include "rt_settingswindow_test.hpp"

int RT_SettingsWindow_Test::argc = 0;
char ** RT_SettingsWindow_Test::argv;

RT_SettingsWindow_Test::RT_SettingsWindow_Test(int& pArgc, char** pArgv, QObject* parent)
{
	argc = pArgc;
	argv = pArgv;
}

RT_SettingsWindow_Test::~RT_SettingsWindow_Test() {
	
}

void RT_SettingsWindow_Test::testConfigNameEmptyWhenDefault()
{
}
