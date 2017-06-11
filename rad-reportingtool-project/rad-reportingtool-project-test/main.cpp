#include "commonstringutils_test.hpp"
#include "commonlogutils_test.hpp"
#include "commonviewutils_test.hpp"
#include "rt_client_test.hpp"
#include "rt_logfilter_test.hpp"
#include "commonsettingsutils_test.hpp"
#include "rt_main_test.hpp"
#include "rt_logwindow_test.hpp"
#include "rt_settingswindow_test.hpp"
#include "rt_main_modell_test.hpp"
#include "rt_settings_test.hpp"

int main(int argc, char *argv[])
{
	int status{};
	CommonStringUtils_Test csut{};
	status |= QTest::qExec(&csut, argc, argv);

	CommonLogUtils_Test clu{};
	status |= QTest::qExec(&clu, argc, argv);

	CommonViewUtils_Test cvu{argc, argv};
	status |= QTest::qExec(&cvu, argc, argv);

	CommonSettingsUtils_Test csu{ argc, argv };
	status |= QTest::qExec(&csu, argc, argv);

	RT_Client_Test rct{argc, argv};
	status |= QTest::qExec(&rct, argc, argv);

	RT_LogFilter_Test rlft{ argc, argv };
	status |= QTest::qExec(&rlft, argc, argv);

	RT_Settings_Test rst{ argc,argv };
	status |= QTest::qExec(&rst, argc, argv);

	RT_Main_Modell_Test rmmt{argc,argv};
	status |= QTest::qExec(&rmmt, argc, argv);

	RT_Main_Test rmt{ argc,argv };
	status |= QTest::qExec(&rmt, argc, argv);

	RT_LogWindow_Test rlwt{argc,argv}; 
	status |= QTest::qExec(&rlwt, argc, argv);

	RT_SettingsWindow_Test rswt{ argc,argv };
	status |= QTest::qExec(&rswt, argc, argv);

	return status;
}
