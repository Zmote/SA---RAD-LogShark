#pragma once
#include <QObject>
#include <QTest>

class CommonStringUtils_Test : public QObject {
	Q_OBJECT

public:
	CommonStringUtils_Test(QObject * parent = Q_NULLPTR);
	~CommonStringUtils_Test();

private slots:
void testAdjustTimeString() const;
void testPadString() const;
void testPrepareTimeString() const;
};
