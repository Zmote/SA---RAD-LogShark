#include "RT_Settings.h"
#include <qdir.h>
#include <QJsonDocument>
#include <QDebug>
#include "CommonSettingsUtils.h"
#include <QSettings>
#include <QCoreApplication>
#include <QMessageBox>

namespace
{
	QDir dir = QDir{};
}

QString RT_Settings::_baseFileSaveLocation{dir.absolutePath() + "/logs"};
QString RT_Settings::_toFileSaveLocation{ dir.absolutePath() + "/logs" };
QString RT_Settings::_toSharedFileSaveLocation{ dir.absolutePath() + "/logs" };
QString RT_Settings::_toRingFileSaveLocation{ dir.absolutePath() + "/logs" };

int RT_Settings::_logBufferLimit{10000};
int RT_Settings::_ringBufferLimit{ 10000 };
int RT_Settings::_messageBufferLimit{ 200 };

bool RT_Settings::_autoRegistrationAllowed{ true };

QString RT_Settings::masterHost{ "0.0.0.0" };
int RT_Settings::masterPort{ 52525 };

QString RT_Settings::_configurationFilesLocation{ dir.absolutePath() + "/config/" };
QString RT_Settings::_currentConfigurationFileName{""};

int RT_Settings::_updateInterval{ RT_Constants::baseUpdateInterval };
QMutex RT_Settings::mutex;

bool RT_Settings::persistGlobalSettings{ false };
bool RT_Settings::persistViewSettings{ false };

RT_LogSettings RT_Settings::logSettings{};
RT_ViewSettings RT_Settings::viewSettings{};
QList<RT_Client> RT_Settings::clients{};
QList<RT_Client> RT_Settings::groups{};

QString RT_Settings::baseFileSaveLocation()
{
	return _baseFileSaveLocation;
}

void RT_Settings::baseFileSaveLocation(QString val)
{
	_baseFileSaveLocation = val;
}

QString RT_Settings::toFileSaveLocation()
{
	return _toFileSaveLocation;
}

void RT_Settings::toFileSaveLocation(QString val)
{
	_toFileSaveLocation = val;
}

QString RT_Settings::toSharedFileSaveLocation()
{
	return _toSharedFileSaveLocation;
}

void RT_Settings::toSharedFileSaveLocation(QString val)
{
	_toSharedFileSaveLocation = val;
}

QString RT_Settings::toRingFileSaveLocation()
{
	return _toRingFileSaveLocation;
}

void RT_Settings::toRingFileSaveLocation(QString val)
{
	_toRingFileSaveLocation = val;
}

int RT_Settings::logBufferLimit()
{
	return _logBufferLimit;
}

int RT_Settings::messageBufferLimit()
{
	return _messageBufferLimit;
}

int RT_Settings::ringBufferLimit()
{
	return _ringBufferLimit;
}

void RT_Settings::messageBufferLimit(int val)
{
	QMutexLocker locker(&mutex);
	_messageBufferLimit = val;
}

void RT_Settings::logBufferLimit(int val)
{
	_logBufferLimit = val;
}

void RT_Settings::ringBufferLimit(int val)
{
	_ringBufferLimit = val;
}

void RT_Settings::autoRegistrationAllowed(bool val)
{
	_autoRegistrationAllowed = val;
}

bool RT_Settings::autoRegistrationAllowed()
{
	return _autoRegistrationAllowed;
}

void RT_Settings::currentConfigurationFileName(QString fileName)
{
	_currentConfigurationFileName = fileName;
}

QString RT_Settings::currentConfigurationFileName()
{
	return _currentConfigurationFileName;
}

bool RT_Settings::load(QString fileName)
{
	QFile loadFile{ _configurationFilesLocation + fileName + ".json"};
	if(loadFile.open(QIODevice::ReadOnly))
	{
		QString settingsString = loadFile.readAll();
		QJsonDocument settingsJsonDocument = QJsonDocument::fromJson(settingsString.toUtf8());
		if (settingsJsonDocument.isObject())
		{
			QJsonObject topLevelObject = settingsJsonDocument.object();
			QJsonValue settingsJsonValue = topLevelObject.value("Settings");

			if (settingsJsonValue.isObject())
			{
				CommonSettingsUtils::constructSettingsFromObject(settingsJsonValue.toObject());
			}

			QJsonValue groupsJsonValue = topLevelObject.value("Groups");
			if (groupsJsonValue.isObject())
			{
				groups.clear();
				QJsonObject groupsObject = groupsJsonValue.toObject();
				for (QString key : groupsObject.keys())
				{
					groups.append(CommonSettingsUtils::constructClientFromObject(groupsObject.value(key).toObject()));
				}
			}

			QJsonValue clientsJsonValue = topLevelObject.value("Clients");
			if (clientsJsonValue.isObject())
			{
				clients.clear();
				QJsonObject clientsObject = clientsJsonValue.toObject();

				for (QString key : clientsObject.keys())
				{
					clients.append(CommonSettingsUtils::constructClientFromObject(clientsObject.value(key).toObject()));
				}
			}

			QJsonValue globalSettingsValue = topLevelObject.value("GlobalLogSettings");
			if(globalSettingsValue.isObject())
			{
				CommonSettingsUtils::constructGlobalLogSettingsFromObject(globalSettingsValue.toObject());
			}

			QJsonValue viewSettingsValue = topLevelObject.value("ViewSettings");
			if(viewSettingsValue.isObject())
			{
				CommonSettingsUtils::constructViewSettingsFromObject(viewSettingsValue.toObject());
			}
		}
		return true;
	}
	return false;
}

void RT_Settings::save()
{
	QFile saveFile(_configurationFilesLocation + _currentConfigurationFileName + ".json");

	QJsonObject topLevelObject{};

	QJsonObject settingsObject = CommonSettingsUtils::constructSettingsObject();

	topLevelObject.insert("Settings", settingsObject);

	QJsonObject topLevelClientsObject{};
	for (RT_Client & client : clients)
	{
		topLevelClientsObject.insert(client.getClientName(), CommonSettingsUtils::constructClientObject(client));
	}

	QJsonObject topLevelGroupsObject{};
	for(RT_Client & client : groups)
	{
		topLevelGroupsObject.insert(client.getClientName(), CommonSettingsUtils::constructClientObject(client));
	}

	topLevelObject.insert("Clients", topLevelClientsObject);
	topLevelObject.insert("Groups", topLevelGroupsObject);

	if(persistGlobalSettings)
	{
		QJsonObject globalSettingsObject = CommonSettingsUtils::constructGlobalLogSettingsObject();
		topLevelObject.insert("GlobalLogSettings", globalSettingsObject);
	}

	if(persistViewSettings)
	{
		QJsonObject viewSettingsObject = CommonSettingsUtils::constructViewSettingsObject();
		topLevelObject.insert("ViewSettings", viewSettingsObject);
	}

	QJsonDocument jsonDoc{ topLevelObject };
	QDir dir{ };
	if (!dir.exists(_configurationFilesLocation)) dir.mkpath(_configurationFilesLocation);
	if(!saveFile.open(QIODevice::WriteOnly) || saveFile.write(jsonDoc.toJson()) == -1)
	{
		QMessageBox * msg = new QMessageBox();
		msg->setWindowTitle("Error");
		msg->setText("Something went wrong while saving the configuration. Please retry.");
		msg->show();
	}else
	{
		//Remember last configuration file via system
		QSettings{}.setValue("currentConfigurationFileName", _currentConfigurationFileName);
	}
	groups.clear();
	clients.clear();
}

void RT_Settings::reset()
{
	QSettings{}.remove("currentConfigurationFileName");
	_baseFileSaveLocation = dir.absolutePath() + "/logs";
	_toFileSaveLocation = dir.absolutePath() + "/logs";
	_toRingFileSaveLocation = dir.absolutePath() + "/logs";
	_toSharedFileSaveLocation = dir.absolutePath() + "/logs";

	_logBufferLimit = 10000;
	_ringBufferLimit = 10000;
	_messageBufferLimit = 200;

	_autoRegistrationAllowed = true;

	masterHost = "0.0.0.0";
	masterPort = 52525;

	_currentConfigurationFileName = "";

	persistGlobalSettings = false;
	persistViewSettings = false;
	logSettings = RT_LogSettings();
	viewSettings = RT_ViewSettings();
	groups.clear();
	clients.clear();
}

QString RT_Settings::configurationFilesLocation()
{
	return _configurationFilesLocation;
}

int RT_Settings::updateInterval()
{
	return _updateInterval;
}

void RT_Settings::updateInterval(int pUpdateInterval)
{
	QMutexLocker locker(&mutex);
	_updateInterval = pUpdateInterval;
}
