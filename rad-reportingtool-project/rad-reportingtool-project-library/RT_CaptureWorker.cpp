#include "RT_CaptureWorker.h"
#include <QDebug>
#include <QThread>
#include "CommonLogUtils.h"
#include "RT_Settings.h"

RT_CaptureWorker::RT_CaptureWorker(){}

void RT_CaptureWorker::handleBinaryLog(const QString & clientName, const QString & groupName, const REP::PROTO::LogBinaryMsg & msg)
{
	if(entries.contains(clientName))
	{
		entries[clientName].append(CommonLogUtils::prepareLogEntry(clientName, groupName, msg));
	}else
	{
		entries.insert(clientName, QList<QList<QString>>{CommonLogUtils::prepareLogEntry(clientName, groupName, msg)});
	}
}

void RT_CaptureWorker::signalLogsReady()
{
	if(!entries.isEmpty())
	{
		int sleepTime = RT_Settings::updateInterval() / entries.keys().count();
		for (const auto & key : entries.keys()) {
			emit logsProcessed(key, *entries.constFind(key));
			QThread::msleep(sleepTime);
		}
		entries.clear();
	}
}

void RT_CaptureWorker::handleLog(const QString & clientName, const QString & groupName, const REP::PROTO::LogMsg & msg)
{
	if (entries.contains(clientName))
	{
		entries[clientName].append(CommonLogUtils::prepareLogEntry(clientName, groupName, msg));
	}
	else
	{
		entries.insert(clientName, QList<QList<QString>>{CommonLogUtils::prepareLogEntry(clientName, groupName, msg)});
	}
}
