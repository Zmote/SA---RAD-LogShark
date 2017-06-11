#ifndef COMMONSTRINGUTILS_H
#define COMMONSTRINGUTILS_H

#include <QString>

/*!
 * \brief Namespace with free functions for common operations on strings
 * \author Zafer Dogan, <a href="mailto:zdogan@hsr.ch">Zafer Dogan</a>
 * \version 1.3
 * \since 1.0
 */
namespace CommonStringUtils {
	/*!
	 * \brief Pads the input string at the defined location with a specified delimiter
	 * \param inputString string to pad
	 * \param padAt index at which to add padding delimiter
	 * \param delimiter character with which to pad the string
	 * \return padded string
	 */
	QString padString(const QString & inputString, int padAt, const QString & delimiter);
	/*!
	 * \brief Adjusts a time string, ie 1 becomes 01
	 * \param value time value to be adjusted
	 * \return adjusted time value
	 */
	QString adjustTimeString(int value);
	/*!
	 * \brief prepares a time string from the time integer values
	 * \param first 1. position of the time string, for ex. in yyyy-mm-dd, yyyy
	 * \param second 2. position of the time string, for ex. in yyyy-mm-dd, mm
	 * \param third 3. position of the time string, for ex. in yyyy-mm-dd, dd
	 * \param delimiter delimiter character with which to separate the time integers
	 * \return prepared time string
	 */
	QString prepareTimeString(int first, int second, int third, const QString & delimiter);
}

#endif // !COMMONSTRINGUTILS_H
