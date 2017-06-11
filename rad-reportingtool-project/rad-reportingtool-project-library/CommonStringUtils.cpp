#include "CommonStringUtils.h"

QString CommonStringUtils::padString(const QString & inputString, int padAt, const QString & delimiter) {
	QString paddedString{};
	for (int i = 0; i < inputString.length(); i++) {
		if (i != 0 && i % padAt == 0) {
			paddedString += delimiter;
			paddedString += inputString.at(i);
		}
		else {
			paddedString += inputString.at(i);
		}
	}
	return paddedString;
}

QString CommonStringUtils::adjustTimeString(int value)
{
	return value < 10 ? "0" + QString::number(value) : QString::number(value);
}


QString CommonStringUtils::prepareTimeString(int first, int second, int third, const QString & delimiter)
{
	QString sFirst = adjustTimeString(first);
	QString sSecond = adjustTimeString(second);
	QString sThird = adjustTimeString(third);
	return sFirst + delimiter + sSecond + delimiter + sThird;
}
