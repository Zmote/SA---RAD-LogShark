#include "RT_UpdateWorker.h"
#include "RT_Settings.h"

RT_UpdateWorker::RT_UpdateWorker(QObject* parent) : QObject(parent)
{
}

void RT_UpdateWorker::startUpdater()
{
	while (true)
	{
		emit signalUpdate();
		QThread::msleep(RT_Settings::updateInterval());
	}
}