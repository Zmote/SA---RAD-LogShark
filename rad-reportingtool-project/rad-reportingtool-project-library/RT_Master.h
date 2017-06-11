#ifndef RT_MASTER_H
#define RT_MASTER_H
#include <QObject>
#include "Master.hpp"

/*!
*\class RT_Master
* The Wrapper class for REP::Master, RT_Master. The RT_Master Wrapper allows 
* for the Master - Server to be restarted or refreshed at any time.
*
* \brief RT_Master Wrapper class
* \author Zafer Dogan, <a href="mailto:zdogan@hsr.ch">Zafer Dogan</a>
* \version 1.1
* \since 1.5
*/
class RT_Master:public QObject
{
	Q_OBJECT

public:
	RT_Master(RT_Main & pMainWindow);
	~RT_Master();
	void showError() const;
	void start() const;
	void showPortInUseMessage() const;
	static bool isSameMaster(CL::SockAddress previousAddress);
	void destroyOldMaster(REP::Master* oldMaster);
public slots:
	void restart();
	signals:
	void signalError(QString text) const;
	void signalClearClientAndGroupList();
private:
	REP::Master * master;
	RT_Main& mainWindow;
	REP::Master::Config m_cfg{};
};

#endif //!RT_MASTER_H
