#pragma once
#include <QObject>
#include <QTest>
class CommonLogUtils_Test : public QObject {
	Q_OBJECT
public:
	CommonLogUtils_Test(QObject * parent = Q_NULLPTR);
	~CommonLogUtils_Test();

private slots:
	static void testParseLog();
	static void testPrepareBinaryLogEntry();
	static void testPrepareLogEntryIsNotEmpty();
	static void testPrepareLogEntryHasKindInfo();
	static void testResolveMessageKind();

};
