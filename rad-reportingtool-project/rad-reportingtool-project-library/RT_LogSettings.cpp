#include "RT_LogSettings.h"
#include <QMutexLocker>

RT_LogSettings& RT_LogSettings::operator=(const RT_LogSettings& copy)
{
	messageStates = copy.messageStates;
	bufferTriggers = copy.bufferTriggers;
	return *this;
}

bool RT_LogSettings::enableInfo() const
{
	QMutexLocker locker(&mutex);
	return messageStates.enableInfo;
}

bool RT_LogSettings::enableWarning() const
{
	QMutexLocker locker(&mutex);
	return messageStates.enableWarning;
}

bool RT_LogSettings::enableError() const
{
	QMutexLocker locker(&mutex);
	return messageStates.enableError;
}

bool RT_LogSettings::enableException() const
{
	QMutexLocker locker(&mutex);
	return messageStates.enableException;
}

bool RT_LogSettings::enableFatal() const
{
	QMutexLocker locker(&mutex);
	return messageStates.enableFatal;
}

bool RT_LogSettings::enableBinary() const
{
	QMutexLocker locker(&mutex);
	return messageStates.enableBinary;
}

bool RT_LogSettings::infoMessage() const
{
	QMutexLocker locker(&mutex);
	return bufferTriggers.infoMessage;
}

bool RT_LogSettings::warningMessage() const
{
	QMutexLocker locker(&mutex);
	return bufferTriggers.warningMessage;
}

bool RT_LogSettings::errorMessage() const
{
	QMutexLocker locker(&mutex);
	return bufferTriggers.errorMessage;
}

bool RT_LogSettings::exceptionMessage() const
{
	QMutexLocker locker(&mutex);
	return bufferTriggers.exceptionMessage;
}

bool RT_LogSettings::fatalMessage() const
{
	QMutexLocker locker(&mutex);
	return bufferTriggers.fatalMessage;
}

void RT_LogSettings::enableInfo(bool val)
{
	QMutexLocker locker(&mutex);
	messageStates.enableInfo = val;
}

void RT_LogSettings::enableWarning(bool val)
{
	QMutexLocker locker(&mutex);
	messageStates.enableWarning = val;
}

void RT_LogSettings::enableError(bool val)
{
	QMutexLocker locker(&mutex);
	messageStates.enableError = val;
}

void RT_LogSettings::enableException(bool val)
{
	QMutexLocker locker(&mutex);
	messageStates.enableException = val;
}

void RT_LogSettings::enableFatal(bool val)
{
	QMutexLocker locker(&mutex);
	messageStates.enableFatal = val;
}

void RT_LogSettings::enableBinary(bool val)
{
	QMutexLocker locker(&mutex);
	messageStates.enableBinary = val;
}

void RT_LogSettings::infoMessage(bool val)
{
	QMutexLocker locker(&mutex);
	bufferTriggers.infoMessage = val;
}

void RT_LogSettings::warningMessage(bool val)
{
	QMutexLocker locker(&mutex);
	bufferTriggers.warningMessage = val;
}

void RT_LogSettings::errorMessage(bool val)
{
	QMutexLocker locker(&mutex);
	bufferTriggers.errorMessage = val;
}

void RT_LogSettings::exceptionMessage(bool val)
{
	QMutexLocker locker(&mutex);
	bufferTriggers.exceptionMessage = val;
}

void RT_LogSettings::fatalMessage(bool val)
{
	QMutexLocker locker(&mutex);
	bufferTriggers.fatalMessage = val;
}
