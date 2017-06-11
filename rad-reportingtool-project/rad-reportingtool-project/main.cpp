#include "rt_main.h"
#include <QSettings>
#include <QDebug>

#include "RT_Master.h"
#include "RT_Settings.h"

void processConsoleParams(int argc, char** argv)
{
	if (argc > 1)
	{
		if (argc % 2 == 1)
		{
			for (int i = 1; i < argc; i++)
			{
				if (i % 2 == 1)
				{
					QString command = argv[i];
					QString arg = argv[i + 1];
					if (command == "-config")
					{
						QString configFileName = arg;
						QSettings settings;
						settings.setValue("currentConfigurationFileName", configFileName);
					}
					if (command == "-host")
					{
						RT_Settings::masterHost = arg;
					}
					if (command == "-port")
					{
						bool ok = false;
						int port = arg.toInt(&ok);
						if (ok)
						{
							RT_Settings::masterPort = port;
						}
					}
				}
			}
		}else
		{
			qDebug() << "Malformed argument list";
		}
	}
}

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	QApplication::setOrganizationName("Rheinmetall Air Defence AG, Oerlikon");
	QApplication::setOrganizationDomain("rheinmetall-defence.com");
	QApplication::setApplicationName("RAD LogShark");
	processConsoleParams(argc, argv);
	RT_Main w;
	RT_Master master{w};
	QObject::connect(&w, &RT_Main::restartMaster, &master, &RT_Master::restart);
	QObject::connect(&master, &RT_Master::signalError, &w, &RT_Main::setApplicationOutput);
	QObject::connect(&master, &RT_Master::signalClearClientAndGroupList, &w, &RT_Main::clearClientsAndGroups);
	master.start();
	w.show();
	auto status{0};
	status |= a.exec();
	return status;
}
