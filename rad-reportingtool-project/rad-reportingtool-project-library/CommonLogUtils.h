#ifndef COMMONLOGUTILS_H
#define COMMONLOGUTILS_H

#include "RT_Client.h"
#include <ReportingTool/ProxyProtocol/Messages/LogBinaryMsg.hpp>
#include <ReportingTool/ProxyProtocol/Messages/LogMsg.hpp>
#include <ReportingTool/ProxyProtocol/Messages/Types.hpp>

/*!
 * \brief CommonLogUtils namespace provides common
 * functionalitites (free functions) used accross log handling
 * \author Zafer Dogan, <a href="mailto:zdogan@hsr.ch">Zafer Dogan</a>
 * \version 1.4
 * \since 1.0
 */
namespace CommonLogUtils {
	const QString HEX = "HEX";
	/*!
	* \brief Resolves MessageKind id to MessageKind name
	* \param kind reference to \ref REP::PROTO::MessageKind, from which MessageKind ID is attained
	* \returns resolved name of id to QString
	*/
	QString resolveMessageKind(const REP::PROTO::MessageKind & kind);
	/*!
	 * \brief Parses Log entries from a file to a format 
	 * with which the Application ca work with
	 * \param entry a QString, representing a line in the file
	 * \return parsed log entry as a list, with entries positioned at the right indexes
	 */
	QList<QString> parseLog(const QString entry);


	/*!
	 * \brief Prepares log entry from \ref REP::PROTO::LogMsg with which the Application can work with
	 * \param clientName Name of client
	 * \param groupName Name of client group
	 * \param msg Message received via Network
	 * \return prepared entry for the Application
	 */
	QList<QString> prepareLogEntry(const QString & clientName, const QString & groupName, const REP::PROTO::LogMsg& msg);

	/*!
	 * \brief Prepares log entry from \ref REP::PROTO::LogBinaryMsg with which the Application can work with
	 * \param clientName Name of client
	 * \param groupName Name of client group
	 * \param msg Binary message received via Network
	 * \return prepared entry for the Application
	 */
	QList<QString> prepareLogEntry(const QString & clientName, const QString & groupName, const REP::PROTO::LogBinaryMsg& msg);
};

#endif //! COMMONLOGUTILS_H