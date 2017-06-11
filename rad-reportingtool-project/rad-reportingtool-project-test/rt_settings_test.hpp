#pragma once
#include <QObject>

class RT_Settings_Test : public QObject {
	Q_OBJECT

public:
	RT_Settings_Test(int & pArgc, char ** pArgv, QObject * parent = Q_NULLPTR);
	~RT_Settings_Test();
	private slots:
	void testSaveConfig() const;
	void testRestoreDefaultSettings() const;
private:
	static int argc;
	static char** argv;
	
};
