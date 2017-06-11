#ifndef RT_MAIN_MODELL_H
#define RT_MAIN_MODELL_H

#include <QStandardItemModel>
#include "RT_Client.h"
#include "CustomQTabWidget.h"
#include "RT_LogFilter.h"

/*!
* The Main Window Modell, which contains containers and fields relevant for UI
* interaction and stores data information like clients and the client filter
*
* \brief Main Window Modell
* \author Zafer Dogan, <a href="mailto:zdogan@hsr.ch">Zafer Dogan</a>
* \version 1.1
* \since 1.0
*/
class RT_Main_Modell : public QObject{
public:
	explicit RT_Main_Modell();
	/******** ACCESSORS ********/
	bool clientExists(QString clientName) const;
	QStandardItemModel * getClientsModel() const;
	QStandardItemModel * getGroupsModel() const;
	RT_Client & getClient(QString clientName);
	RT_Client & getGroupClient(QString groupName);
	const RT_Client & getConstClient(QString clientName) const;
	const RT_Client & getConstGroupClient(QString groupName) const;
	QList<RT_Client> getClients() const;
	QList<RT_Client> getGroupClients() const;
	QList<RT_Client> getMergeViewClients() const;
	QList<QString> getClientsOfGroup(QString groupName) const;
	int getLiveClientsCount() const;
	int getWindowedClientsCount() const;
	RT_LogFilter & getFilter();
	QTabWidget * getTabWidget() const;
	/******** SETTERS ********/
	void addClient(int clientId, QString clientName, QString groupName);
	void addClient(const RT_Client & pClient);
	void updateClient(const RT_Client & pClient);
	void clearClients();
	void addGroupClient(QString groupName);
	void addGroupClient(const RT_Client & pGroupClient);
	void updateGroupClient(const RT_Client & pGroupClient);
	void clearGroupClients();
	void removeGroupClient(QString groupName);
	void setFilter(const RT_LogFilter & pFilter);
	void setTabWidget(QTabWidget * pTabWidget);

	/******** FIELDS ********/
	RT_Client globalClient;
private:
	/******** FIELDS ********/
	/*!
	* Stores the search criterion / filter term entered in the search field,
	* this field is later parsed for log filtering
	*/
	RT_LogFilter filter{""};

	/******** UI REFERENCES ********/
	CustomQTabWidget * tabWidget = new CustomQTabWidget();

	/******** CONTAINERS ********/
	/*!
	* Map of registered clients, with their id as key
	* This map is used to resolve Log Client ID to Clientname and Groupname
	* QMap<ClientID, QPair<GroupName, ClientName>>
	*/
	QMap<QString, RT_Client> clientsMap{};
	QMap<QString, RT_Client> groupsMap{};
	QMap<int, QString> clientIdMap{};
	/*!
	* A simple StringList Model for the registered clients
	*/
	QStandardItemModel * clientsModel = new QStandardItemModel();
	/*!
	* A simple StringList Model for available groups
	*/
	QStandardItemModel * groupsModel = new QStandardItemModel();
};


#endif //RT_MAIN_MODELL_h