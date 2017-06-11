#include "RT_Main_Modell.h"
#include "RT_Constants.h"

RT_Main_Modell::RT_Main_Modell(): globalClient()
{
	QSizePolicy policy{ QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding };
	tabWidget->setObjectName("tabWidget");
	tabWidget->setSizePolicy(policy);
	tabWidget->setTabsClosable(true);
	tabWidget->setAcceptDrops(true);
	tabWidget->setDocumentMode(true);
	tabWidget->setMovable(true);
	tabWidget->setMouseTracking(true);
}

QStandardItemModel* RT_Main_Modell::getClientsModel() const
{
	return clientsModel;
}

QStandardItemModel* RT_Main_Modell::getGroupsModel() const
{
	return groupsModel;
}

RT_Client& RT_Main_Modell::getClient(QString clientName)
{
	auto it = clientsMap.find(clientName);
	if (it != clientsMap.end())
	{
		return it.value();
	}
	return globalClient;
}

RT_Client& RT_Main_Modell::getGroupClient(QString groupName)
{
	auto it = groupsMap.find(groupName);
	if (it != groupsMap.end())
	{
		return it.value();
	}
	return globalClient;
}

const RT_Client& RT_Main_Modell::getConstClient(QString clientName) const
{
	const auto it = clientsMap.constFind(clientName);
	if (it != clientsMap.constEnd())
		return it.value();
	return globalClient;
}

const RT_Client& RT_Main_Modell::getConstGroupClient(QString groupName) const
{
	const auto it = groupsMap.constFind(groupName);
	if (it != groupsMap.constEnd())
		return it.value();
	return globalClient;
}

QList<RT_Client> RT_Main_Modell::getClients() const
{
	return clientsMap.values();
}

QList<RT_Client> RT_Main_Modell::getGroupClients() const
{
	return groupsMap.values();
}

QList<RT_Client> RT_Main_Modell::getMergeViewClients() const
{
	QList<RT_Client> mergeViewClients{};
	for(const RT_Client & groupClient : groupsMap.values())
	{
		if (groupClient.getClientName().contains(RT_Constants::MERGEVIEW_PREFIX))
		{
			mergeViewClients.append(groupClient);
		}
	}
	return mergeViewClients;
}

QList<QString> RT_Main_Modell::getClientsOfGroup(QString groupName) const
{
	if (groupName != RT_Constants::GLOBAL)
	{
		QList<QString> clients{};
		for (const RT_Client& client : clientsMap.values())
		{
			if (client.getGroupName() == groupName)
			{
				clients.append(client.getClientName());
			}
			if(client.getMergeViewName() == groupName)
			{
				clients.append(client.getClientName());
			}
		}
		return clients;
	}
	return clientsMap.keys();
}

int RT_Main_Modell::getLiveClientsCount() const
{
	int count{0};
	for (RT_Client& client : clientsMap.values())
	{
		if (client.live())
		{
			count++;
		}
	}
	return count;
}

int RT_Main_Modell::getWindowedClientsCount() const
{
	int count{0};
	for (RT_Client& client : clientsMap.values())
	{
		if (client.windowed())
		{
			count++;
		}
	}
	for (RT_Client& client : groupsMap.values())
	{
		if (client.windowed())
		{
			count++;
		}
	}
	if (globalClient.windowed()) count++;
	return count;
}

RT_LogFilter& RT_Main_Modell::getFilter()
{
	return filter;
}

QTabWidget* RT_Main_Modell::getTabWidget() const
{
	return tabWidget;
}

void RT_Main_Modell::addClient(int clientId, QString clientName, QString groupName)
{
	clientIdMap.insert(clientId, clientName);
	RT_Client client{clientId, clientName, groupName};
	clientsMap.insert(clientName, client);
}

void RT_Main_Modell::addClient(const RT_Client& pClient)
{
	clientsMap.insert(pClient.getClientName(), pClient);
}

void RT_Main_Modell::updateClient(const RT_Client& pClient)
{
	auto it = clientsMap.find(pClient.getClientName());
	if(it != clientsMap.end())
	{
		it.value() = pClient;
	}
}

void RT_Main_Modell::clearClients()
{
	clientsMap.clear();
}

void RT_Main_Modell::addGroupClient(QString groupName)
{
	RT_Client groupClient{RT_Constants::GROUP_ID,groupName,RT_Constants::GLOBAL};
	groupsMap.insert(groupName, groupClient);
}

void RT_Main_Modell::addGroupClient(const RT_Client& pGroupClient)
{
	groupsMap.insert(pGroupClient.getClientName(), pGroupClient);
}

void RT_Main_Modell::updateGroupClient(const RT_Client& pGroupClient)
{
	auto it = groupsMap.find(pGroupClient.getClientName());
	if (it != groupsMap.end())
	{
		it.value() = pGroupClient;
	}
}

void RT_Main_Modell::clearGroupClients()
{
	groupsMap.clear();
}

void RT_Main_Modell::removeGroupClient(QString groupName)
{
	groupsMap.remove(groupName);
}

bool RT_Main_Modell::clientExists(QString clientName) const
{
	return clientsMap.keys().contains(clientName);
}

void RT_Main_Modell::setFilter(const RT_LogFilter& pFilter)
{
	this->filter = pFilter;
}

void RT_Main_Modell::setTabWidget(QTabWidget* pTabWidget)
{
	this->tabWidget = static_cast<CustomQTabWidget*>(pTabWidget);
}
