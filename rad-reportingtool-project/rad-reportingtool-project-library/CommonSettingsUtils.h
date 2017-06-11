#ifndef COMMONSETTINGSUTILS_H
#define COMMONSETTINGSUTILS_H

#include <QJsonObject>
#include "RT_Settings.h"

/*!
 * \brief Common Utility functions for \RT_Settings settings related operations
 * \author Zafer Dogan, <a href="mailto:zdogan@hsr.ch">Zafer Dogan</a>
 * \version 1.0
 * \since 1.4
 */
namespace CommonSettingsUtils
{
	/*!
	 * \brief Constructs a \ref RT_Client client from a JSON Object
	 * \param clientObject QJsonObject from which \RT_Client client is constructed
	 * \return \RT_Client client
	 */
	RT_Client constructClientFromObject(const QJsonObject& clientObject);
	/**
	 * \brief 
	 * \param client \ref RT_Client from which to construct a JSON Object 
	 * \return \ref QJsonObject constructed JSON Object
	 */
	QJsonObject constructClientObject(RT_Client& client);

	QJsonObject constructSettingsObject();
	void constructSettingsFromObject(const QJsonObject& settingsObject);

	QJsonObject constructViewSettingsObject();
	void constructViewSettingsFromObject(const QJsonObject& viewSettingsObject);

	QJsonObject constructGlobalLogSettingsObject();
	void constructGlobalLogSettingsFromObject(const QJsonObject& globalLogSettings);
}

#endif //! COMMONSETTINGSUTILS_H