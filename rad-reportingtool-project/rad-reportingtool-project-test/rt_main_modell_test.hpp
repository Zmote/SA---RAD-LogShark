#pragma once
#include <QObject>

class RT_Main_Modell_Test : public QObject {
	Q_OBJECT
public:
	RT_Main_Modell_Test(int & pArgc, char ** pArgv, QObject * parent = Q_NULLPTR);
	~RT_Main_Modell_Test();
	private slots:
	void testGetClients() const;
private:
	static int argc;
	static char** argv;
};
