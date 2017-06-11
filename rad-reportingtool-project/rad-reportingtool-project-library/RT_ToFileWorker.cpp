#include "RT_ToFileWorker.h"
#include "RT_Settings.h"
#include <QFileDialog>

RT_ToFileWorker::RT_ToFileWorker()
{
}

int RT_ToFileWorker::fileLineCount(const QString& fileName)
{
	QFile file{fileName};
	if (file.open(QIODevice::ReadOnly))
	{
		QTextStream stream{&file};
		int count{0};
		while (!stream.atEnd())
		{
			stream.readLine();
			count++;
		}
		return count;
	}
	return 0;
}

QList<QString> RT_ToFileWorker::readLogsFromFile(QTextStream& stream)
{
	stream.seek(0);
	QList<QString> entries{};
	while (!stream.atEnd())
	{
		QString line = stream.readLine();
		if(line.contains(rx))
		{
			entries.append(line);
		}else
		{
			if(!entries.isEmpty())
			{
				entries.last().append("\n" + line);
			}
		}
	}
	return entries;
}

void RT_ToFileWorker::adjustFile(QFile & file, QTextStream & stream)
{
	QList<QString> entries{ readLogsFromFile(stream) };
	if(entries.size() >= RT_Settings::ringBufferLimit())
	{
		while (entries.size() >= RT_Settings::ringBufferLimit())
		{
			entries.pop_front();
		}
		file.resize(0);
		for(const QString & entry : entries)
		{
			stream << entry << endl;
		}
	}
}

void RT_ToFileWorker::processLogToFile(const QString& clientName, const QList<QList<QString>>& logs, bool toFile,
                                       bool toRingFile, bool toSharedFile, const QString& sharedFileName)
{
	QString filename;
	if (toSharedFile)
	{
		filename = RT_Settings::toSharedFileSaveLocation() + "/" + sharedFileName;
	}
	else if (toRingFile)
	{
		filename = RT_Settings::toRingFileSaveLocation() + "/" + RT_Constants::RINGFILE_PREFIX + clientName;
	}
	else if (toFile)
	{
		filename = RT_Settings::baseFileSaveLocation() + "/" + clientName;
	}
	else
	{
		filename = clientName;
	}

	if (!filename.contains(QRegExp(".txt")))
	{
		filename += ".txt";
	}

	QDir dir{};
	QFileInfo fileInfo{ filename };
	if (!dir.exists(fileInfo.absolutePath())) dir.mkpath(fileInfo.absolutePath());
	QFile file{filename};
	if (file.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text))
	{
		QTextStream stream(&file);
		for (const QList<QString>& log : logs)
		{
			for (auto i = 0; i < log.size(); i++)
			{
				switch (i)
				{
				case 0:
					if (RT_Settings::viewSettings.useDateStamp) stream << "_D: " << log.at(0) << "\t";
					break;
				case 1:
					if (RT_Settings::viewSettings.useTimeStamp) stream << "_T: " << log.at(1) << "\t";
					break;
				case 2:
					if (RT_Settings::viewSettings.useClientStamp) stream << "_G: " << log.at(2) << "\t";
					break;
				case 3:
					if (RT_Settings::viewSettings.useGroupStamp) stream << "_K: " << log.at(3) << "\t";
					break;
				case 4:
					if (RT_Settings::viewSettings.useMessageHeaderStamp) stream << "_M: " << log.at(4) << "\t";
					break;
				case 5:
					if (RT_Settings::viewSettings.useContentStamp) stream << "_C: " << log.at(5) << "\t";
					break;
				default: break;
				}
			}
			stream << endl;
		}
		if (toRingFile)
		{
			adjustFile(file, stream);
		}
	}
}

void RT_ToFileWorker::processLogFromFile(const QString& filename)
{
	QFile file{filename};
	QList<QList<QString>> readLogs{};
	if (file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QTextStream stream(&file);
		QString line;
		QString buffer{};
		while (!(line = stream.readLine()).isEmpty())
		{
			if(line.split(rx).size() > 1)
			{
				if(buffer.size() > 0 && !readLogs.isEmpty())
				{
					QList<QString> log = readLogs.last();
					log.last().append(buffer);
					readLogs.removeLast();
					readLogs.append(log);
					buffer.clear();
				}else
				{
					buffer.clear();
				}
				readLogs.append(CommonLogUtils::parseLog(line));
			}else
			{
				buffer.append("\n" + line);
			}
		}
	}
	emit openFileFinished(readLogs, filename);
}
