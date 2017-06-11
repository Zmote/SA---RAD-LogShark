#include "CommonSettingsUtils.h"

RT_Client CommonSettingsUtils::constructClientFromObject(const QJsonObject& clientObject)
{
	int clientId = clientObject.value("clientId").toInt();
	QString clientName = clientObject.value("clientName").toString();
	QString groupName = clientObject.value("groupName").toString();
	RT_Client client{ clientId, clientName, groupName };
	client.live(clientObject.value("live").toBool());
	client.active(clientObject.value("active").toBool());
	client.binary(clientObject.value("binary").toBool());
	client.toFile(clientObject.value("toFile").toBool());
	client.toRingFile(clientObject.value("toRingFile").toBool());
	client.toSharedFile(clientObject.value("toSharedFile").toBool());
	client.setSharedFileName(clientObject.value("sharedFileName").toString());
	client.toParent(clientObject.value("toParent").toBool());
	client.toGlobal(clientObject.value("toGlobal").toBool());
	client.toMergeView(clientObject.value("toMergeView").toBool());
	client.setMergeViewName(clientObject.value("mergeViewName").toString());
	client.newestOnTop(clientObject.value("newestOnTop").toBool());
	client.scrollToBottom(clientObject.value("scrollToBottom").toBool());
	client.windowed(clientObject.value("windowed").toBool());
	client.color(clientObject.value("color").toString());
	return client;
}

QJsonObject CommonSettingsUtils::constructClientObject(RT_Client& client)
{
	QJsonObject clientObject = {};
	clientObject.insert("clientId", client.getClientId());
	clientObject.insert("clientName", client.getClientName());
	clientObject.insert("groupName", client.getGroupName());
	clientObject.insert("binary", client.binary());
	clientObject.insert("active", client.active());
	clientObject.insert("live", client.live());
	clientObject.insert("toFile", client.toFile());
	clientObject.insert("toRingFile", client.toRingFile());
	clientObject.insert("toSharedFile", client.toSharedFile());
	clientObject.insert("sharedFileName", client.getSharedFileName());
	clientObject.insert("toParent", client.toParent());
	clientObject.insert("toGlobal", client.toGlobal());
	clientObject.insert("toMergeView", client.toMergeView());
	clientObject.insert("mergeViewName", client.getMergeViewName());
	clientObject.insert("newestOnTop", client.newestOnTop());
	clientObject.insert("scrollToBottom", client.scrollToBottom());
	clientObject.insert("windowed", client.windowed());
	clientObject.insert("color", client.color().name());
	return clientObject;
}

QJsonObject CommonSettingsUtils::constructSettingsObject()
{
	QJsonObject settingsObject = {};
	settingsObject.insert("baseFileSaveLocation", RT_Settings::baseFileSaveLocation());
	settingsObject.insert("toFileSaveLocation", RT_Settings::toFileSaveLocation());
	settingsObject.insert("toRingFileSaveLocation", RT_Settings::toRingFileSaveLocation());
	settingsObject.insert("toSharedFileSaveLocation", RT_Settings::toSharedFileSaveLocation());

	settingsObject.insert("logBufferLimit", RT_Settings::logBufferLimit());
	settingsObject.insert("ringBufferLimit", RT_Settings::ringBufferLimit());
	settingsObject.insert("messageBufferLimit", RT_Settings::messageBufferLimit());

	settingsObject.insert("autoRegistrationAllowed", RT_Settings::autoRegistrationAllowed());

	settingsObject.insert("masterHost", RT_Settings::masterHost);
	settingsObject.insert("masterPort", RT_Settings::masterPort);

	settingsObject.insert("currentConfigurationFileName", RT_Settings::currentConfigurationFileName());
	return settingsObject;
}

void CommonSettingsUtils::constructSettingsFromObject(const QJsonObject& settingsObject)
{
	RT_Settings::baseFileSaveLocation(settingsObject.value("baseFileSaveLocation").toString());
	RT_Settings::toFileSaveLocation(settingsObject.value("toFileSaveLocation").toString());
	RT_Settings::toRingFileSaveLocation(settingsObject.value("toRingFileSaveLocation").toString());
	RT_Settings::toSharedFileSaveLocation(settingsObject.value("toSharedFileSaveLocation").toString());

	RT_Settings::logBufferLimit(settingsObject.value("logBufferLimit").toInt(10000));
	RT_Settings::ringBufferLimit(settingsObject.value("ringBufferLimit").toInt(10000));
	RT_Settings::messageBufferLimit(settingsObject.value("messageBufferLimit").toInt(200));

	RT_Settings::autoRegistrationAllowed(settingsObject.value("autoRegistrationAllowed").toBool(true));

	RT_Settings::masterHost = settingsObject.value("masterHost").toString("0.0.0.0");
	RT_Settings::masterPort = settingsObject.value("masterPort").toInt(52525);

	RT_Settings::currentConfigurationFileName(settingsObject.value("currentConfigurationFileName").toString());
}

QJsonObject CommonSettingsUtils::constructViewSettingsObject()
{
	QJsonObject viewSettingsObject{};
	viewSettingsObject.insert("useDateStamp", RT_Settings::viewSettings.useDateStamp);
	viewSettingsObject.insert("useTimeStamp", RT_Settings::viewSettings.useTimeStamp);
	viewSettingsObject.insert("useGroupStamp", RT_Settings::viewSettings.useGroupStamp);
	viewSettingsObject.insert("useClientStamp", RT_Settings::viewSettings.useClientStamp);
	viewSettingsObject.insert("useMessageHeaderStamp", RT_Settings::viewSettings.useMessageHeaderStamp);
	viewSettingsObject.insert("useContentStamp", RT_Settings::viewSettings.useContentStamp);

	viewSettingsObject.insert("showFilterArea", RT_Settings::viewSettings.showFilterArea);
	viewSettingsObject.insert("showLogDetailArea", RT_Settings::viewSettings.showLogDetailArea);
	viewSettingsObject.insert("showClientSection", RT_Settings::viewSettings.showClientSection);
	viewSettingsObject.insert("showGroupSection", RT_Settings::viewSettings.showGroupSection);
	return viewSettingsObject;
}

void CommonSettingsUtils::constructViewSettingsFromObject(const QJsonObject& viewSettingsObject)
{
	RT_Settings::viewSettings.useDateStamp = viewSettingsObject.value("useDateStamp").toBool(true);
	RT_Settings::viewSettings.useTimeStamp = viewSettingsObject.value("useTimeStamp").toBool(true);
	RT_Settings::viewSettings.useGroupStamp = viewSettingsObject.value("useGroupStamp").toBool(true);
	RT_Settings::viewSettings.useClientStamp = viewSettingsObject.value("useClientStamp").toBool(true);
	RT_Settings::viewSettings.useMessageHeaderStamp = viewSettingsObject.value("useMessageHeaderStamp").toBool(true);
	RT_Settings::viewSettings.useContentStamp = viewSettingsObject.value("useContentStamp").toBool(true);

	RT_Settings::viewSettings.showFilterArea = viewSettingsObject.value("showFilterArea").toBool(true);
	RT_Settings::viewSettings.showLogDetailArea = viewSettingsObject.value("showLogDetailArea").toBool(true);

	RT_Settings::viewSettings.showClientSection = viewSettingsObject.value("showClientSection").toBool(true);
	RT_Settings::viewSettings.showGroupSection = viewSettingsObject.value("showGroupSection").toBool(true);
	RT_Settings::persistViewSettings = true;
}

QJsonObject CommonSettingsUtils::constructGlobalLogSettingsObject()
{
	QJsonObject globalSettingsObject{};
	globalSettingsObject.insert("enableInfo", RT_Settings::logSettings.enableInfo());
	globalSettingsObject.insert("enableWarning", RT_Settings::logSettings.enableWarning());
	globalSettingsObject.insert("enableError", RT_Settings::logSettings.enableError());
	globalSettingsObject.insert("enableException", RT_Settings::logSettings.enableException());
	globalSettingsObject.insert("enableFatal", RT_Settings::logSettings.enableFatal());
	globalSettingsObject.insert("enableBinary", RT_Settings::logSettings.enableBinary());

	globalSettingsObject.insert("infoMessage", RT_Settings::logSettings.infoMessage());
	globalSettingsObject.insert("warningMessage", RT_Settings::logSettings.warningMessage());
	globalSettingsObject.insert("errorMessage", RT_Settings::logSettings.errorMessage());
	globalSettingsObject.insert("exceptionMessage", RT_Settings::logSettings.exceptionMessage());
	globalSettingsObject.insert("fatalMessage", RT_Settings::logSettings.fatalMessage());
	return globalSettingsObject;
}

void CommonSettingsUtils::constructGlobalLogSettingsFromObject(const QJsonObject& globalLogSettings)
{
	RT_Settings::logSettings.enableInfo(globalLogSettings.value("enableInfo").toBool(true));
	RT_Settings::logSettings.enableWarning(globalLogSettings.value("enableWarning").toBool(true));
	RT_Settings::logSettings.enableError(globalLogSettings.value("enableError").toBool(true));
	RT_Settings::logSettings.enableException(globalLogSettings.value("enableException").toBool(true));
	RT_Settings::logSettings.enableFatal(globalLogSettings.value("enableFatal").toBool(true));
	RT_Settings::logSettings.enableBinary(globalLogSettings.value("enableBinary").toBool(true));

	RT_Settings::logSettings.infoMessage(globalLogSettings.value("infoMessage").toBool(false));
	RT_Settings::logSettings.warningMessage(globalLogSettings.value("warningMessage").toBool(false));
	RT_Settings::logSettings.errorMessage(globalLogSettings.value("errorMessage").toBool(true));
	RT_Settings::logSettings.exceptionMessage(globalLogSettings.value("exceptionMessage").toBool(true));
	RT_Settings::logSettings.fatalMessage(globalLogSettings.value("fatalMessage").toBool(true));
	RT_Settings::persistGlobalSettings = true;
}
