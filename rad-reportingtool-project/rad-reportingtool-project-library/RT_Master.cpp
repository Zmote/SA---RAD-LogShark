#include "RT_Master.h"
#include "RT_Settings.h"
#include <QDebug>
#include <QMessageBox>

RT_Master::RT_Master(RT_Main& pMainWindow)
	: mainWindow(pMainWindow)
{
	m_cfg.address = CL::SockAddress(RT_Settings::masterHost.toStdString(), RT_Settings::masterPort);
	try
	{
		master = new REP::Master(m_cfg, pMainWindow);
	}catch(CL::Socket::Error error)
	{
		qDebug() << "Error while settng up Socket: " << error.what();
		showPortInUseMessage();
		master = nullptr;
	}
}

RT_Master::~RT_Master()
{
	if(master != nullptr)
	{
		master->terminate();
		delete master;
	}
}

void RT_Master::showError() const
{
	emit signalError("Master was unable to start. Try restarting application with a different Host and Port. Either adjust configuration or start application with commands -host YOURHOST -port YOURPORT. Adjusting Host or Port in System settings will also reinitiate Master.");
}

void RT_Master::start() const
{
	if(master != nullptr)
	{
		master->start();
	}else
	{
		showError();
	}
}

void RT_Master::showPortInUseMessage() const
{
	QMessageBox * messageBox = new QMessageBox();
	messageBox->setWindowTitle("Error");
	messageBox->setText("Couldn't establish Master connection on address: " + RT_Settings::masterHost + ":" + QString::number(RT_Settings::masterPort)
		+ "\nCheck if Address isn't in use already or if another Master might be running on this address.");
	messageBox->show();
}

bool RT_Master::isSameMaster(CL::SockAddress previousAddress)
{
	return previousAddress.name() == RT_Settings::masterHost.toStdString() && previousAddress.port() == RT_Settings::masterPort;
}

void RT_Master::destroyOldMaster(REP::Master* oldMaster)
{
	oldMaster->terminate();
	delete oldMaster;
	emit signalClearClientAndGroupList();
}

void RT_Master::restart()
{
	//TODO: Application freezes when to many restarts request in short time arrive, gets stuck in RT_UpdateWorker loop
	bool newMasterCreated = true;
	REP::Master * oldMaster = master;
	CL::SockAddress previousAddress = m_cfg.address;
	try
	{
		if (master != nullptr && isSameMaster(previousAddress))
		{
			//if it's the same master, we need to destroy it beforehand, so the port is free for the new master for a refresh
			destroyOldMaster(oldMaster);
			//we set newMasterCreated to false here, in case of success, so that
			//the post-deletion operation for non-identical masters isn't triggered
			//as for this special case, we need to destroy it beforehand.
			//the post-deletion is necessary for restoring running master in case
			//switching to new master fails
			newMasterCreated = false;
			master = nullptr;
		}
		m_cfg.address = CL::SockAddress(RT_Settings::masterHost.toStdString(), RT_Settings::masterPort);
		master = new REP::Master(m_cfg, mainWindow);
		start();
	}
	catch (CL::Socket::Error error)
	{
		qDebug() << "Error while settng up Socket: " << error.what();
		showPortInUseMessage();
		m_cfg.address = previousAddress;
		RT_Settings::masterHost = QString::fromStdString(m_cfg.address.name());
		RT_Settings::masterPort = m_cfg.address.port();
		//if recreating the same master fails, set master to nullptr, ie. no valid master available
		if (master != nullptr)
		{
			//if new Master was different than the new, restore the pointer to old Master
			master = oldMaster;
		}
		else
		{
			//if master was nullptr and couldn't be initalized, show error message
			showError();
		}
		newMasterCreated = false;
	}
	//to avoid double delete
	if (newMasterCreated && oldMaster != nullptr) {
		destroyOldMaster(oldMaster);
	}
}
