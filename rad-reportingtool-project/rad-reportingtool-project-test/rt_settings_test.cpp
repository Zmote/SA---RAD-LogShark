#include "rt_settings_test.hpp"
#include "RT_Settings.h"
#include <qtestcase.h>

int RT_Settings_Test::argc = 0;
char ** RT_Settings_Test::argv;

RT_Settings_Test::RT_Settings_Test(int& pArgc, char** pArgv, QObject* parent)
{
	argc = pArgc;
	argv = pArgv;
}

RT_Settings_Test::~RT_Settings_Test() {
	
}

void RT_Settings_Test::testSaveConfig() const
{
	RT_Settings::currentConfigurationFileName("testConfig");
	RT_Settings::save();
	bool fileFound = RT_Settings::load("testConfig");
	QCOMPARE(fileFound, true);
}

void RT_Settings_Test::testRestoreDefaultSettings() const
{
	RT_Settings::autoRegistrationAllowed(false);
	RT_Settings::reset();
	QCOMPARE(RT_Settings::autoRegistrationAllowed(), true);
}
