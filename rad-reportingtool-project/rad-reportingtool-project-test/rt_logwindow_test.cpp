#include "rt_logwindow_test.hpp"

int RT_LogWindow_Test::argc = 0;
char ** RT_LogWindow_Test::argv;

RT_LogWindow_Test::RT_LogWindow_Test(int& pArgc, char** pArgv, QObject* parent)
{
	argc = pArgc;
	argv = pArgv;
}

RT_LogWindow_Test::~RT_LogWindow_Test() {
	
}

void RT_LogWindow_Test::testClientStateChange()
{
}
