#ifndef RT_CAPTUREWORKER_H
#define RT_CAPTUREWORKER_H

#include <ReportingTool/ProxyProtocol/Messages/LogMsg.hpp>
#include <ReportingTool/ProxyProtocol/Messages/LogBinaryMsg.hpp>
#include "RT_Main_Modell.h"

/*!
* \class RT_CaptureWorker 
*
* \brief Worker class for capturing logs in a different thread than the UI
* The capture worker gathers logs and when it receives an update signal
* from \ref RT_UpdateWorker, which then sends the gathered logs to the main window
* to assign to the appropriate client tables
* \author Zafer Dogan, <a href="mailto:zdogan@hsr.ch">Zafer Dogan</a>
* \version 2.0
* \since 1.1
*/
class RT_CaptureWorker : public QObject {
	Q_OBJECT
public:
	RT_CaptureWorker();
public slots:
	/**
	 * \brief Handles log arriving via network
	 * \param clientName Name of client
	 * \param groupName Name of client group
	 * \param msg LogMsg to be handled
	 */
	void handleLog(const QString & clientName, const QString & groupName, const REP::PROTO::LogMsg & msg);
	/**
	 * \brief 
	 * \param clientName Name of client
	 * \param groupName Name of client group
	 * \param msg LogBinaryMsg to be handled
	 */
	void handleBinaryLog(const QString & clientName, const QString & groupName, const REP::PROTO::LogBinaryMsg & msg);
	/**
	 * \brief Initiates signal to update main window
	 */
	void signalLogsReady();
signals:
	/**
	 * \brief Signal definition, when main window is to be signaled
	 * \param clientName Name of Client
	 * \param rows log rows
	 */
	void logsProcessed(const QString & clientName, const QList<QList<QString>> & rows);
private:
	QMap<QString, QList<QList<QString>>> entries;
};

#endif //RT_CAPTUREWORKER_H