#include "commonstringutils_test.hpp"
#include "CommonStringUtils.h"

CommonStringUtils_Test::CommonStringUtils_Test(QObject * parent) : QObject(parent) {
	
}

CommonStringUtils_Test::~CommonStringUtils_Test() {
}

void CommonStringUtils_Test::testAdjustTimeString() const
{
	int timeValue = 1;
	QString timeValueString = CommonStringUtils::adjustTimeString(timeValue);
	QCOMPARE(timeValueString, QString("01"));
}

void CommonStringUtils_Test::testPadString() const
{
	QString stringToPad{ "padme" };
	QString paddedString = CommonStringUtils::padString(stringToPad, 1, "+");
	QCOMPARE(paddedString, QString("p+a+d+m+e"));
}

void CommonStringUtils_Test::testPrepareTimeString() const
{
	QString timeString = CommonStringUtils::prepareTimeString(10, 22, 22, ":");
	QCOMPARE(timeString, QString("10:22:22"));
}


