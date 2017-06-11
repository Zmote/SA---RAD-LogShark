#pragma once
#include <QObject>

class CommonSettingsUtils_Test : public QObject {
	Q_OBJECT

public:
	CommonSettingsUtils_Test(int & pArgc, char ** pArgv, QObject * parent = Q_NULLPTR);
	~CommonSettingsUtils_Test();

private slots:
void testClientObjectCreated() const;
void testGroupObjectCreated() const;
void testSettingsObjectCreated() const;
void testGlobalSettingsObjectCreated() const;
void testViewSettingsObjectCreated() const;

void testClientObjectParsed() const;
void testGroupObjectParsed() const;
void testSettingsObjectParsed() const;
void testGlobalSettingsObjectParsed() const;
void testViewSettingsObjectParsed() const;
private:
	static int argc;
	static char ** argv;
	
};
