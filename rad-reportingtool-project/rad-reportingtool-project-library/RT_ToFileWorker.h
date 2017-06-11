#ifndef RT_TOFILEWORKER_H
#define RT_TOFILEWORKER_H
#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QRegExp>
#include "CommonLogUtils.h"

/**
 * \brief Worker class, for processing file log operations in a different thread
 * \author Zafer Dogan, <a href="mailto:zdogan@hsr.ch">Zafer Dogan</a>
 * \version 1.2
 * \since 1.3
 */
class RT_ToFileWorker : public QObject
{
	Q_OBJECT
public:
	RT_ToFileWorker();
private:
	/**
	* \brief
	* \param fileName Name of file
	* \return count of lines in file
	*/
	static int fileLineCount(const QString & fileName);
	QList<QString> readLogsFromFile(QTextStream& stream);
	void adjustFile(QFile & file, QTextStream & stream);

	QRegExp rx{ "_D:|_T:|_G:|_K:|_M:|_C:" };
public slots:
	/**
	 * \brief Writes logs to file
	 * \param clientName Name of Client
	 * \param logs Logs to be written to file
	 * \param toFile client state toFile
	 * \param toRingFile client state toRingFile
	 * \param toSharedFile client state toSharedFile
	 * \param sharedFileName client state sharedfileName
	 */
	void processLogToFile(const QString& clientName, const QList<QList<QString>>& logs, bool toFile, 
								 bool toRingFile, bool toSharedFile, const QString& sharedFileName);
	/**
	 * \brief Reads logs from file
	 * \param filename Name of file to read logs from
	 */
	void processLogFromFile(const QString & filename);
	signals:
	/**
	 * \brief 
	 * \param readLogs Logs read from file
	 * \param tableName Name of table \ clientName to add logs to
	 */
	void openFileFinished(const QList<QList<QString>> & readLogs, const QString & tableName);
};

#endif // !RT_TOFILEWORKER_H
