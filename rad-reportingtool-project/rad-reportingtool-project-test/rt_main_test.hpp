#pragma once
#include <QObject>

class RT_Main_Test : public QObject
{
	Q_OBJECT
public:
	RT_Main_Test(int& pArgc, char** pArgv, QObject* parent = Q_NULLPTR);
	~RT_Main_Test();
private slots:
	void testIsGlobal() const;
	void testIsGroup() const;
	void testLogWindowCreation() const;
	void testClientSearchTermEntered() const;
private:
	static int argc;
	static char** argv;
};
