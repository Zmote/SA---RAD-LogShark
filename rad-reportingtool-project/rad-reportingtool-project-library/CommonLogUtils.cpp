#include "CommonLogUtils.h"
#include "CommonStringUtils.h"
#include <QFileDialog>
#include <QDebug>
#include <QRegExp>
#include <QByteArray>
#include <stdexcept>

QString CommonLogUtils::resolveMessageKind(const REP::PROTO::MessageKind& kind)
{
	switch (kind)
	{
	case REP::PROTO::MessageKind::MK__INFO:
		return QString(RT_Constants::MK_INFO);
	case REP::PROTO::MessageKind::MK__WARNING:
		return QString(RT_Constants::MK_WARNING);
	case REP::PROTO::MessageKind::MK__ERROR:
		return QString(RT_Constants::MK_ERROR);
	case REP::PROTO::MessageKind::MK__EXCEPTION:
		return QString(RT_Constants::MK_EXCEPTION);
	case REP::PROTO::MessageKind::MK__FATAL:
		return QString(RT_Constants::MK_FATAL);
	default:
		return QString(RT_Constants::MK_UNRECOGNIZED);
	}
}

QList<QString> CommonLogUtils::parseLog(const QString logEntry)
{
	QList<QString> row{"", "", "", "", "", "" };
	QRegExp rx("(\\\t)");
	QStringList query = logEntry.split(rx);
	for(QString entry : query)
	{
		try
		{
			if (entry.contains(QRegExp("_D:"))) row.replace(0, entry.split("_D:").at(1));
			if (entry.contains(QRegExp("_T:"))) row.replace(1, entry.split("_T:").at(1));
			if (entry.contains(QRegExp("_G:"))) row.replace(2, entry.split("_G:").at(1));
			if (entry.contains(QRegExp("_K:"))) row.replace(3, entry.split("_K:").at(1));
			if (entry.contains(QRegExp("_M:"))) row.replace(4, entry.split("_M:").at(1));
			if (entry.contains(QRegExp("_C:"))) row.replace(5, entry.split("_C:").at(1));
		}catch(std::out_of_range & ex)
		{
			qDebug() << ex.what();
		}
	}
	return row;
}

QList<QString> CommonLogUtils::prepareLogEntry(const QString & clientName, const QString & groupName, const REP::PROTO::LogBinaryMsg& msg)
{
	QList<QString> row{};
	auto dateWrapper = msg.timestamp().dateLocal();
	row.append(CommonStringUtils::prepareTimeString(1900 + dateWrapper.tm_year, dateWrapper.tm_mon, dateWrapper.tm_mday, "-"));
	row.append(CommonStringUtils::prepareTimeString(dateWrapper.tm_hour, dateWrapper.tm_min, dateWrapper.tm_sec, ":"));
	row.append(groupName);
	row.append(clientName);
	row.append("HEX");
	int messageSize = msg.message().size();
	QByteArray byteInfo{msg.message().data(), messageSize};
	QString message = QString(byteInfo.toHex()).toUpper();
	row.append(CommonStringUtils::padString(message, 2, " "));
	return row;
}

QList<QString> CommonLogUtils::prepareLogEntry(const QString & clientName, const QString & groupName, const REP::PROTO::LogMsg& msg)
{
	QList<QString> row{};
	auto dateWrapper = msg.timestamp().dateLocal();
	row.append(CommonStringUtils::prepareTimeString(1900 + dateWrapper.tm_year, dateWrapper.tm_mon, dateWrapper.tm_mday, "-"));
	row.append(CommonStringUtils::prepareTimeString(dateWrapper.tm_hour, dateWrapper.tm_min, dateWrapper.tm_sec, ":"));
	row.append(groupName);
	row.append(clientName);
	row.append(resolveMessageKind(msg.kind()));
	row.append(QString::fromStdString(msg.message()));
	return row;
}
