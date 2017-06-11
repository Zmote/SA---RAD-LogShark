#include "rt_main.h"

#include <QStandardItemModel>
#include <QModelIndexList>
#include <QFileDialog>
#include <QInputDialog>
#include <QMap>
#include <QColorDialog>
#include <QListView>
#include <QHeaderView>
#include <QApplication>
#include <algorithm>
#include <QScreen>
#include <QRect>
#include <QMessageBox>
#include <QUuid>
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>
#include <QSettings>
#include <QMetaObject>

#include "RT_Main_Modell.h"
#include "CustomTableModel.h"
#include "RT_Client.h"
#include "RT_Constants.h"
#include "RT_LogFilter.h"
#include "CustomFilterProxyModel.h"
#include "CommonViewUtils.h"
#include "RT_SettingsWindow.h"
#include "RT_Settings.h"

void RT_Main::setApplicationOutput(QString text) const
{
	ui.applicationOutput->setPlainText(text);
}

void RT_Main::setupConfiguration()
{
	QString rememberedConfigurationFileName = QSettings{}.value("currentConfigurationFileName").toString();
	if (!rememberedConfigurationFileName.isEmpty())
	{
		if (RT_Settings::load(rememberedConfigurationFileName))
		{
			refreshApplicationState();
		}
		else
		{
			setApplicationOutput("Loading configuration file failed. Check if config file: " + rememberedConfigurationFileName + ".json exists under folder \n/config");
		}
	}
	else
	{
		setApplicationOutput("No configuration file found");
	}
}

RT_Main::RT_Main(QWidget* parent)
	: QMainWindow(parent), modell{}
{
	ui.setupUi(this);
	setWindowIcon(radlogoImage);
	initStartUpValues();
	setupMainConnections();
	setupConfiguration();
}

RT_Main::~RT_Main()
{
	if (fromFileWorker != nullptr) fromFileWorker->deleteLater();
}

void RT_Main::setupFileThread()
{
	for (int i = 0; i < 4; i++)
	{
		QThread* thread = new QThread(this);
		RT_ToFileWorker* worker = new RT_ToFileWorker();
		toFileWorkers.second.append(worker);
		worker->moveToThread(thread);
		thread->start();
	}
	toFileWorkers.first = 0;

	fromFileThread = new QThread(this);
	fromFileWorker = new RT_ToFileWorker();
	fromFileWorker->moveToThread(fromFileThread);
	fromFileThread->start();
}

void RT_Main::setupMainConnections()
{
	connect(modell.getTabWidget(), &CustomQTabWidget::tabCloseRequested, this, &RT_Main::closeTabClicked);
	connect(static_cast<CustomQTabWidget*>(modell.getTabWidget()), &CustomQTabWidget::floatWindowInitiated, this, &RT_Main::createLogWindow);
	connect(static_cast<CustomQTabWidget*>(modell.getTabWidget()), &CustomQTabWidget::tabWindowInitiated, this, &RT_Main::createTabWindow);
	connect(ui.groupList->selectionModel(), &QItemSelectionModel::selectionChanged, this, &RT_Main::handleGroupListSelectionChanged);
	connect(ui.clientList->selectionModel(), &QItemSelectionModel::selectionChanged, this, &RT_Main::handleClientListSelectionChanged);
	connect(this, &RT_Main::signalOpenFileTriggered, fromFileWorker, &RT_ToFileWorker::processLogFromFile, Qt::ConnectionType::QueuedConnection);
	connect(fromFileWorker, &RT_ToFileWorker::openFileFinished, this, &RT_Main::processReadLogs, Qt::ConnectionType::QueuedConnection);
	connect(modell.globalClient.getTable(), &QTableView::clicked, this, &RT_Main::handleTableClicked);
	connect(modell.globalClient.getTable()->selectionModel(), &QItemSelectionModel::selectionChanged, this, &RT_Main::handleTableSelectionChanged);
}

void RT_Main::setupGroupList() const
{
	ui.groupList->header()->setVisible(false);
	ui.groupList->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
	ui.groupList->setEditTriggers(QListView::EditTrigger::NoEditTriggers);
	QSortFilterProxyModel* groupProxyModel = new QSortFilterProxyModel(ui.groupList);
	modell.getGroupsModel()->setParent(groupProxyModel);
	groupProxyModel->setSourceModel(modell.getGroupsModel());
	ui.groupList->setModel(groupProxyModel);
	modell.getGroupsModel()->appendRow(CommonViewUtils::prepareListEntry(modell.globalClient, tickImage, crossImage));
	connect(ui.groupList, &QTableView::clicked, this, &RT_Main::handleGroupListSelectionChanged);
	ui.groupList->resizeColumnToContents(0);
	ui.groupList->setColumnWidth(1, 30);
	ui.groupList->setStyleSheet(RT_Constants::QTREEVIEW_ACTIVE_SELECTION_CSS);
	ui.groupList->setRootIsDecorated(false);
}

void RT_Main::setupClientList() const
{
	ui.clientList->header()->setVisible(false);
	QMargins margin{0,0,0,10};
	ui.clientList->setContentsMargins(margin);
	ui.clientList->header()->stretchLastSection();
	ui.clientList->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
	ui.clientList->setEditTriggers(QTableView::EditTrigger::NoEditTriggers);
	QSortFilterProxyModel* clientProxyModel = new QSortFilterProxyModel(ui.clientList);
	modell.getClientsModel()->setParent(clientProxyModel);
	clientProxyModel->setSourceModel(modell.getClientsModel());
	ui.clientList->setModel(clientProxyModel);
	connect(ui.clientList, &QTableView::clicked, this, &RT_Main::handleClientListSelectionChanged);
	ui.clientList->setStyleSheet(RT_Constants::QTREEVIEW_ACTIVE_SELECTION_CSS);
	ui.clientList->setRootIsDecorated(false);
}

void RT_Main::setupGlobalSettings() const
{
	ui.enableInfoCheckBox->setChecked(RT_Settings::logSettings.enableInfo());
	ui.enableWarningCheckBox->setChecked(RT_Settings::logSettings.enableWarning());
	ui.enableErrorCheckBox->setChecked(RT_Settings::logSettings.enableError());
	ui.enableExceptionCheckBox->setChecked(RT_Settings::logSettings.enableException());
	ui.enableFatalCheckBox->setChecked(RT_Settings::logSettings.enableFatal());
	ui.enableBinaryCheckBox->setChecked(RT_Settings::logSettings.enableBinary());

	ui.infoMessageCheckBox->setChecked(RT_Settings::logSettings.infoMessage());
	ui.warningMessageCheckBox->setChecked(RT_Settings::logSettings.warningMessage());
	ui.errorMessageCheckBox->setChecked(RT_Settings::logSettings.errorMessage());
	ui.exceptionMessageCheckBox->setChecked(RT_Settings::logSettings.exceptionMessage());
	ui.fatalMessageCheckBox->setChecked(RT_Settings::logSettings.fatalMessage());
}

void RT_Main::setupViewSettings() const
{
	ui.useDateStampCheckBox->setChecked(RT_Settings::viewSettings.useDateStamp);
	ui.useTimeStampCheckBox->setChecked(RT_Settings::viewSettings.useTimeStamp);
	ui.useGroupStampCheckBox->setChecked(RT_Settings::viewSettings.useGroupStamp);
	ui.useClientStampCheckBox->setChecked(RT_Settings::viewSettings.useClientStamp);
	ui.useMessageHeaderCheckBox->setChecked(RT_Settings::viewSettings.useMessageHeaderStamp);
	ui.useContentStampCheckBox->setChecked(RT_Settings::viewSettings.useContentStamp);

	ui.showGroupSectionCheckBox->setChecked(RT_Settings::viewSettings.showGroupSection);
	ui.showClientSectionCheckBox->setChecked(RT_Settings::viewSettings.showClientSection);
	ui.showFilterAreaCheckBox->setChecked(RT_Settings::viewSettings.showFilterArea);
	ui.showLogDetailCheckBox->setChecked(RT_Settings::viewSettings.showLogDetailArea);

	useDateStampCheckBoxClicked();
	useTimeStampCheckBoxClicked();
	useGroupStampCheckBoxClicked();
	useClientStampCheckBoxClicked();
	useMessageHeaderCheckBoxClicked();
	useContentStampCheckBoxClicked();
	showGroupSection();
	showClientSection();
	showFilterArea();
	showLogDetailCheckBoxClicked();
}

void RT_Main::setupStatusBar() const
{
	ui.statusBar->addPermanentWidget(new QLabel("Selected Client(s): "));
	ui.statusBar->addPermanentWidget(currentSelectedClients);
	ui.statusBar->addPermanentWidget(new QLabel("Client Group: "));
	ui.statusBar->addPermanentWidget(currentClientGroup);
	ui.statusBar->addPermanentWidget(new QLabel("MW: "));
	ui.statusBar->addPermanentWidget(currentClientMergeView);
	ui.statusBar->setContentsMargins(6, 0, 6, 0);
}

void RT_Main::setupMetaTypes() const
{
	qRegisterMetaType<REP::PROTO::LogMsg>("PROTO::LogMsg");
	qRegisterMetaType<REP::PROTO::LogBinaryMsg>("PROTO::LogBinaryMsg");
	qRegisterMetaType<REP::PROTO::RegisterClientMsg>("PROTO::RegisterClientMsg");
	qRegisterMetaType<QItemSelection>("QItemSelection");
	qRegisterMetaType<QList<QList<QStandardItem *>>>("QList<QList<QStandardItem *>>");
	qRegisterMetaType<QList<QStandardItem *>>("QList<QStandardItem *>");
	qRegisterMetaType<QVector<int>>("QVector<int>");
	qRegisterMetaType<QMap<QString, QList<QList<QString>>>>("QMap<QString,QList<QList<QString>>>");
}

void RT_Main::setupContentArea() const
{
	ui.mainContentLayout->addWidget(modell.getTabWidget());
	ui.contentSplitter->setStretchFactor(0, 1);
	ui.contentSplitter->setStretchFactor(1, 10);
	ui.contentSplitter->setStretchFactor(2, 2);
	ui.mainSplitter->setStretchFactor(0, 1);
	ui.mainSplitter->setStretchFactor(1, 20);
	ui.mainSplitter->setStretchFactor(2, 1);
}

void RT_Main::initGlobalClient()
{
	setupClientTabIcon(modell.globalClient);
	modell.getTabWidget()->tabBar()->tabButton(0, QTabBar::RightSide)->hide();
}

int RT_Main::setupClientTabIcon(RT_Client& client) const
{
	int tabPos = modell.getTabWidget()->addTab(client.getTable(), client.getClientName());
	QPixmap colorRect{15,15};
	colorRect.fill(client.color());
	modell.getTabWidget()->setTabIcon(tabPos, colorRect);
	return tabPos;
}

void RT_Main::initStartUpValues()
{
	setupMetaTypes();
	setupStatusBar();
	setupGlobalSettings();
	setupViewSettings();
	setupGroupList();
	setupClientList();
	setupContentArea();
	setupFileThread();
	initGlobalClient();
}

bool RT_Main::isGroup(const RT_Client& client)
{
	return client.getClientId() == RT_Constants::GROUP_ID;
}

bool RT_Main::isGlobal(const RT_Client& client)
{
	return client.getClientId() == RT_Constants::GLOBAL_ID;
}

void RT_Main::handleProcessedLogs(const QString& clientName, const QList<QList<QString>>& rows)
{
	handleClientLog(modell.getClient(clientName), rows);
}

void RT_Main::handleClientLog(RT_Client& client, const QList<QList<QString>>& logs)
{
	if (client.active())
	{
		if (client.live()) client.addLog(logs);
		if (client.toFile() || client.toRingFile() || client.toSharedFile()) signalToFileLog(logs, client);
		if (!(isGroup(client) || isGlobal(client)))
		{
			if (client.toParent()) handleClientLog(modell.getGroupClient(client.getGroupName()), logs);
			if (client.toMergeView()) handleClientLog(modell.getGroupClient(client.getMergeViewName()), logs);
		}
		if (!isGlobal(client) && client.toGlobal()) handleClientLog(modell.globalClient, logs);
	}
}

void RT_Main::prepareSignalToFileLog(const QString& fileName, const QList<QList<QString>>& logs, bool toFile, bool toRingFile, bool toSharedFile, const QString& sharedFileName)
{
	if (!toFileWorkers.second.isEmpty())
	{
		QMetaObject::invokeMethod(toFileWorkers.second.at(toFileWorkers.first), "processLogToFile", Qt::QueuedConnection,
		                          Q_ARG(const QString&, fileName),
		                          Q_ARG(const QList<QList<QString>>&, logs),
		                          Q_ARG(bool, toFile),
		                          Q_ARG(bool, toRingFile),
		                          Q_ARG(bool, toSharedFile),
		                          Q_ARG(const QString&, sharedFileName));
		toFileWorkers.first = ++toFileWorkers.first % toFileWorkers.second.size();
	}
}

void RT_Main::signalToFileLog(const QList<QList<QString>>& logs, const RT_Client& client)
{
	prepareSignalToFileLog(client.getClientName(), logs, client.toFile(), client.toRingFile(), client.toSharedFile(), client.getSharedFileName());
}

QString RT_Main::getClientState(const RT_Client& client)
{
	QString stateToFind = {RT_Constants::EMPTY_STATE};
	if (client.live()) stateToFind = RT_Constants::LIVE;
	if (client.toFile()) stateToFind = RT_Constants::TO_FILE;
	if (client.toRingFile()) stateToFind = RT_Constants::TO_RING_FILE;
	if (client.toSharedFile()) stateToFind = RT_Constants::TO_SHARED_FILE;
	if (!isGlobal(client) && client.toParent()) stateToFind = RT_Constants::TO_PARENT;
	if (client.toGlobal()) stateToFind = RT_Constants::TO_GLOBAL;
	if (client.toMergeView()) stateToFind = RT_Constants::TO_MERGE_VIEW;
	return stateToFind;
}

void RT_Main::initTabBarWithClient(const RT_Client& client) const
{
	ui.clientsStateComboBox->setCurrentIndex(ui.clientsStateComboBox->findText(getClientState(client)));
	ui.clientNewestOnTopCheckBox->setChecked(client.newestOnTop());
	ui.clientScrollToBottomCheckBox->setChecked(client.scrollToBottom());
	ui.clientActiveCheckBox->setChecked(client.active());
	ui.clientTabModeRadio->setChecked(!client.windowed());
	ui.clientWindowModeRadio->setChecked(client.windowed());
}

void RT_Main::initTabBarWithGroupClient(const RT_Client& client) const
{
	ui.groupStateComboBox->setCurrentIndex(ui.groupStateComboBox->findText(getClientState(client)));
	ui.newestOnTopCheckBox->setChecked(client.newestOnTop());
	ui.scrollToBottomCheckBox->setChecked(client.scrollToBottom());
	ui.activeCheckBox->setChecked(client.active());
	ui.tabModeRadio->setChecked(!client.windowed());
	ui.windowModeRadio->setChecked(client.windowed());
}

bool RT_Main::subWindowExists(QString windowName) const
{
	return subWindows.keys().contains(windowName);
}

bool RT_Main::tabExists(QString tabName) const
{
	for (auto i = 0; i < modell.getTabWidget()->count(); i++)
	{
		const QWidget* tab = modell.getTabWidget()->widget(i);
		if (tab->objectName() == tabName)
		{
			return true;
		}
	}
	return false;
}

int RT_Main::tabAt(QString tabName) const
{
	for (auto i = 0; i < modell.getTabWidget()->count(); i++)
	{
		const QWidget* tab = modell.getTabWidget()->widget(i);
		if (tab->objectName() == tabName)
		{
			return i;
		}
	}
	return -1;
}

void RT_Main::createIndependentLogWindow(QString tableName, QTableView* table)
{
	RT_Client* client = new RT_Client(-1, tableName, tableName, table);
	connect(client->getTable(), &QTableView::clicked, this, &RT_Main::handleTableClicked);
	connect(client->getTable()->selectionModel(), &QItemSelectionModel::selectionChanged, this, &RT_Main::handleTableSelectionChanged);
	RT_LogWindow* logWindow = new RT_LogWindow(*client, true);
	connect(logWindow, &RT_LogWindow::logWindowClosed, this, &RT_Main::independentLogWindowClosed);
	connect(logWindow, &RT_LogWindow::minimizeAll, this, &RT_Main::minimizeAll);
	connect(logWindow, &RT_LogWindow::arrangeWindows, this, &RT_Main::arrangeWindowsTriggered);
	connect(logWindow, &RT_LogWindow::prepareSignalToFileLog, this, &RT_Main::prepareSignalToFileLog);
	logWindow->setWindowIcon(QIcon(radlogoImage));
	logWindow->show();
	subWindows.insert(tableName, logWindow);
}

void RT_Main::createLogWindow(QString tableName, QPoint startPosition)
{
	if (!subWindowExists(tableName))
	{
		RT_LogWindow* logWindow;
		if (tableName == RT_Constants::GLOBAL)
		{
			modell.globalClient.windowed(true);
			logWindow = new RT_LogWindow(modell.globalClient, false);
		}
		else
		{
			RT_Client* client = &modell.getClient(tableName);
			if (client->getClientName() == RT_Constants::GLOBAL)
			{
				client = &modell.getGroupClient(tableName);
			}
			client->windowed(true);
			logWindow = new RT_LogWindow(*client, false);
		}
		logWindow->setWindowIcon(QIcon(radlogoImage));
		connect(static_cast<CustomQTabWidget*>(modell.getTabWidget()), &CustomQTabWidget::dragFinishedWithSuccess, logWindow, &RT_LogWindow::closeWindow);
		connect(logWindow, &RT_LogWindow::logWindowClosed, this, &RT_Main::logWindowClosed);
		connect(this, &RT_Main::windowCloseRequested, logWindow, &RT_LogWindow::closeWindow);
		connect(logWindow, &RT_LogWindow::minimizeAll, this, &RT_Main::minimizeAll);
		connect(logWindow, &RT_LogWindow::freezeAll, this, &RT_Main::freezeAll);
		connect(logWindow, &RT_LogWindow::unFreezeAll, this, &RT_Main::unFreezeAll);
		connect(logWindow, &RT_LogWindow::arrangeWindows, this, &RT_Main::arrangeWindowsTriggered);
		connect(logWindow, &RT_LogWindow::prepareSignalToFileLog, this, &RT_Main::prepareSignalToFileLog);
		connect(logWindow, &RT_LogWindow::signalClientActiveState, this, &RT_Main::initSignalClientActiveState);
		logWindow->move(startPosition);
		logWindow->show();

		subWindows.insert(tableName, logWindow);
		handleClientListSelectionChanged();
		adjustUpdateInterval();
	}
}

void RT_Main::createTabWindow(QString tableName)
{
	if (tableName != RT_Constants::GLOBAL)
	{
		if (!tabExists(tableName))
		{
			RT_Client* client = &modell.getClient(tableName);
			if (client->getClientName() == RT_Constants::GLOBAL)
			{
				client = &modell.getGroupClient(tableName);
			}
			auto it = subWindows.constFind(tableName);
			if (it != subWindows.constEnd())
			{
				modell.getTabWidget()->setCurrentIndex(setupClientTabIcon(*client));
				client->windowed(false);
			}
		}
	}
	else
	{
		modell.getTabWidget()->setCurrentIndex(setupClientTabIcon(modell.globalClient));
		modell.globalClient.windowed(false);
		for (int i = 0; i < modell.getTabWidget()->count(); i++)
		{
			QWidget* tab = modell.getTabWidget()->widget(i);
			if (tab->objectName() == RT_Constants::GLOBAL)
			{
				modell.getTabWidget()->tabBar()->tabButton(i, QTabBar::RightSide)->hide();
			}
		}
	}
	handleClientListSelectionChanged();
}

void RT_Main::handleClientsUpdate(std::function<void(RT_Client&)> function)
{
	const QStandardItemModel* clientModel = modell.getClientsModel();
	const QSortFilterProxyModel* proxyModel = static_cast<QSortFilterProxyModel*>(ui.clientList->model());
	const QModelIndexList selectedClientList = ui.clientList->selectionModel()->selectedRows();
	for (const QModelIndex& index : selectedClientList)
	{
		const QModelIndex& sourceIndex = proxyModel->mapToSource(index);
		const QStandardItem* clientNameItem = clientModel->item(sourceIndex.row(), 2);
		RT_Client& client = modell.getClient(clientNameItem->text());
		function(client);
		QStandardItem* activeItem = clientModel->item(sourceIndex.row(), 0);
		CommonViewUtils::prepareIcon(client, activeItem, tickImage, crossImage);
		QStandardItem* routeItem = clientModel->item(sourceIndex.row(), 1);
		routeItem->setText(CommonViewUtils::prepareRouteState(client));
	}
}

void RT_Main::handleGroupClientsUpdate(std::function<void(RT_Client&)> function)
{
	const QSortFilterProxyModel* proxyModel = static_cast<QSortFilterProxyModel*>(ui.groupList->model());
	const QStandardItemModel* groupModel = modell.getGroupsModel();
	const QModelIndexList selectedGroupClientList = ui.groupList->selectionModel()->selectedRows();
	for (QModelIndex index : selectedGroupClientList)
	{
		const QModelIndex& sourceIndex = proxyModel->mapToSource(index);
		const QStandardItem* item = groupModel->item(sourceIndex.row(), 2);
		RT_Client& client = modell.getGroupClient(item->text());
		function(client);
		QStandardItem* activeItem = groupModel->item(sourceIndex.row(), 0);
		CommonViewUtils::prepareIcon(client, activeItem, tickImage, crossImage);
		QStandardItem* routeItem = groupModel->item(sourceIndex.row(), 1);
		routeItem->setText(CommonViewUtils::prepareRouteState(client));
	}
}

void RT_Main::updateGroupClients(std::function<void(RT_Client&)> function)
{
	handleGroupClientsUpdate(function);
	handleGroupListSelectionChanged();
}

void RT_Main::updateClients(std::function<void(RT_Client&)> function)
{
	handleClientsUpdate(function);
	handleClientListSelectionChanged();
}

void RT_Main::refreshClientView(RT_Client& client)
{
	if (client.active())
	{
		if (client.live())
		{
			if (!tabExists(client.getClientName()))
			{
				modell.getTabWidget()->setCurrentIndex(setupClientTabIcon(client));
			}
		}
		if (client.windowed())
		{
			if (!subWindows.contains(client.getClientName()))
			{
				QPoint point = subWindows.isEmpty() ? QPoint(70, 70) : subWindows.last()->pos();
				point += QPoint(30, 30);
				createLogWindow(client.getClientName(), point);
			}
		}
	}
}

void RT_Main::refreshClientList() const
{
	QSortFilterProxyModel* proxyModel = static_cast<QSortFilterProxyModel*>(ui.clientList->model());
	QStandardItemModel* model = modell.getClientsModel();
	for (int i = 0; i < proxyModel->rowCount(); i++)
	{
		const QModelIndex& sourceIndex = proxyModel->mapToSource(proxyModel->index(i, 2));
		QStandardItem* activeItem = model->item(sourceIndex.row(), 0);
		QStandardItem* routeStateItem = model->item(sourceIndex.row(), 1);
		QStandardItem* nameItem = model->item(sourceIndex.row(), 2);
		const RT_Client& client = modell.getConstClient(nameItem->text());
		CommonViewUtils::prepareIcon(client, activeItem, tickImage, crossImage);
		routeStateItem->setText(CommonViewUtils::prepareRouteState(client));
	}
}

void RT_Main::refreshGroupList() const
{
	QSortFilterProxyModel* proxyModel = static_cast<QSortFilterProxyModel*>(ui.groupList->model());
	QStandardItemModel* model = modell.getGroupsModel();
	for (int i = 0; i < proxyModel->rowCount(); i++)
	{
		const QModelIndex& sourceIndex = proxyModel->mapToSource(proxyModel->index(i, 2));
		QStandardItem* activeItem = model->item(sourceIndex.row(), 0);
		QStandardItem* routeStateItem = model->item(sourceIndex.row(), 1);
		QStandardItem* nameItem = model->item(sourceIndex.row(), 2);
		const RT_Client& client = modell.getConstGroupClient(nameItem->text());
		CommonViewUtils::prepareIcon(client, activeItem, tickImage, crossImage);
		routeStateItem->setText(CommonViewUtils::prepareRouteState(client));
	}
}

void RT_Main::setCurrentClientName(int selectionAmount, const RT_Client& client) const
{
	if (selectionAmount > 1)
	{
		currentSelectedClients->setText("Base: " + client.getClientName() + ", Multiple");
		currentClientGroup->setText(client.getGroupName() + ", Multiple");
		currentClientMergeView->setText(client.getMergeViewName() + ", Multiple");
	}
	else
	{
		currentSelectedClients->setText(client.getClientName());
		currentClientGroup->setText(client.getGroupName());
		currentClientMergeView->setText(client.getMergeViewName());
	}
}

void RT_Main::handleGroupListPressed(QModelIndex index)
{
	const QModelIndexList selectedGroups = ui.groupList->selectionModel()->selectedRows();
	QSortFilterProxyModel* clientProxyModel = static_cast<QSortFilterProxyModel*>(ui.clientList->model());
	const QSortFilterProxyModel* groupProxyModel = static_cast<QSortFilterProxyModel*>(ui.groupList->model());
	QString regexString{""};
	if (selectedGroups.size() > 0)
	{
		const QStandardItem* topItem = modell.getGroupsModel()->item(groupProxyModel->mapToSource(selectedGroups[0]).row(), 2);
		RT_Client& group = modell.getGroupClient(topItem->text());
		initTabBarWithGroupClient(group);

		for (QModelIndex modelIndex : selectedGroups)
		{
			const QStandardItem* item = modell.getGroupsModel()->item(groupProxyModel->mapToSource(modelIndex).row(), 2);
			const QList<QString> groupClients = modell.getClientsOfGroup(item->text());
			for (const QString& clientName : groupClients)
			{
				regexString.append("^" + clientName + "$");
				regexString.append("|");
			}
		}
		setCurrentClientName(selectedGroups.size(), group);
	}
	else
	{
		currentSelectedClients->setText("None");
		currentClientGroup->setText("None");
		currentClientMergeView->setText("None");
	}
	regexString.remove(regexString.length() - 1, 1);
	QRegExp regexp{regexString,Qt::CaseSensitive};

	clientProxyModel->setFilterRegExp(regexp);
	clientProxyModel->setFilterKeyColumn(2);
}

void RT_Main::handleGroupListSelectionChanged()
{
	handleGroupListPressed(QModelIndex());
}

void RT_Main::handleClientListPressed(QModelIndex index)
{
	const QSortFilterProxyModel* proxyModel = static_cast<QSortFilterProxyModel*>(ui.clientList->model());
	const QModelIndexList& selectedClientList = ui.clientList->selectionModel()->selectedRows();
	if (selectedClientList.size() > 0)
	{
		const QModelIndex& sourceIndex = proxyModel->mapToSource(selectedClientList.at(0));
		const QStandardItem* item = modell.getClientsModel()->item(sourceIndex.row(), 2);
		const RT_Client& client = modell.getClient(item->text());
		initTabBarWithClient(client);
		setCurrentClientName(selectedClientList.size(), client);
	}
	else
	{
		currentSelectedClients->setText("None");
		currentClientGroup->setText("None");
		currentClientMergeView->setText("None");
	}
}

void RT_Main::handleClientListSelectionChanged()
{
	handleClientListPressed(QModelIndex());
}


void RT_Main::registerGroupClient(QString groupName)
{
	if (modell.getGroupsModel()->findItems(groupName, Qt::MatchExactly, 2).size() == 0)
	{
		modell.addGroupClient(groupName);
		RT_Client& groupClient = modell.getGroupClient(groupName);
		connect(groupClient.getTable(), &QTableView::clicked, this, &RT_Main::handleTableClicked);
		connect(groupClient.getTable()->selectionModel(), &QItemSelectionModel::selectionChanged, this, &RT_Main::handleTableSelectionChanged);
		modell.getGroupsModel()->appendRow(CommonViewUtils::prepareListEntry(groupClient, tickImage, crossImage));
		ui.groupList->sortByColumn(2, Qt::SortOrder::AscendingOrder);
		ui.groupList->resizeColumnToContents(0);
		ui.groupList->setColumnWidth(1, 30);
	}
}

void RT_Main::registerClient(const REP::PROTO::RegisterClientMsg& msg)
{
	if (modell.getClientsModel()->findItems(QString::fromStdString(msg.client()), Qt::MatchExactly, 2).size() == 0)
	{
		//Add client
		modell.addClient(msg.id(), QString::fromStdString(msg.client()), QString::fromStdString(msg.group()));
		RT_Client& client = modell.getClient(QString::fromStdString(msg.client()));
		if (msg.isBinary())
		{
			client.binary(true);
		}
		connect(client.getTable(), &QTableView::clicked, this, &RT_Main::handleTableClicked);
		connect(client.getTable()->selectionModel(), &QItemSelectionModel::selectionChanged, this, &RT_Main::handleTableSelectionChanged);
		modell.getClientsModel()->appendRow(CommonViewUtils::prepareListEntry(client, tickImage, crossImage));
		ui.clientList->sortByColumn(2, Qt::SortOrder::AscendingOrder);
		ui.clientList->resizeColumnToContents(0);
		ui.clientList->setColumnWidth(1, 30);
	}
}

void RT_Main::registerClientLog(const REP::PROTO::RegisterClientMsg& msg)
{
	if (RT_Settings::autoRegistrationAllowed())
	{
		registerGroupClient(QString::fromStdString(msg.group()));
		registerClient(msg);
	}
}

void RT_Main::minimizeAll() const
{
	std::for_each(subWindows.cbegin(), subWindows.cend(), [](RT_LogWindow* window)
	              {
		              window->showMinimized();
	              });
}

void RT_Main::freezeAll() const
{
	std::for_each(subWindows.cbegin(), subWindows.cend(), [](const RT_LogWindow* window)
	              {
		              window->changeFreezeState(true);
	              });
}

void RT_Main::unFreezeAll() const
{
	std::for_each(subWindows.cbegin(), subWindows.cend(), [](const RT_LogWindow* window)
	              {
		              window->changeFreezeState(false);
	              });
}

void RT_Main::handleTableClicked(const QModelIndex& index)
{
	QString tableName = index.model()->objectName();

	const CustomFilterProxyModel* proxyModel = static_cast<const CustomFilterProxyModel*>(index.model());
	CustomTableModel* model = static_cast<CustomTableModel*>(proxyModel->sourceModel());
	QString entry{""};
	for (int i = 0; i < 6; i++)
	{
		if (i == 5)
		{
			entry.append("\n");
			entry.append("\n----------- CONTENT ---------------\n\n");
			entry.append(model->data(model->index(proxyModel->mapToSource(index).row(), i), Qt::UserRole).toString());
		}
		else
		{
			entry.append(model->data(model->index(proxyModel->mapToSource(index).row(), i)).toString());
		}
		entry.append("\t");
	}
	if (!subWindowExists(tableName))
	{
		ui.logDetailInput->setPlainText(entry);
	}
	else
	{
		subWindows[tableName]->handleTableClicked(entry);
	}
}

void RT_Main::handleTableSelectionChanged(const QItemSelection& selected, const QItemSelection& deselected)
{
	Q_UNUSED(deselected);
	handleTableClicked(selected.indexes().first());
}

void RT_Main::closeTabClicked(int index)
{
	const QString tableName = modell.getTabWidget()->widget(index)->objectName();
	RT_Client* client = &modell.getClient(tableName);
	if (client->getClientName() == RT_Constants::GLOBAL)
	{
		client = &modell.getGroupClient(tableName);
	}
	client->live(false);
	client->clearModel();
	refreshClientList();
	refreshGroupList();
	handleClientListSelectionChanged();
	handleGroupListSelectionChanged();
	modell.getTabWidget()->removeTab(index);
}

void RT_Main::processReadLogs(const QList<QList<QString>>& readLogs, const QString& tableName)
{
	QTableView* table = CommonViewUtils::setupTable(tableName);
	CustomFilterProxyModel* proxyModel = static_cast<CustomFilterProxyModel *>(table->model());
	static_cast<CustomTableModel*>(proxyModel->sourceModel())->appendRow(readLogs);
	createIndependentLogWindow(tableName, table);
}

void RT_Main::selectAllGroups() const
{
	ui.groupList->selectAll();
}

void RT_Main::selectAllClients() const
{
	ui.clientList->selectAll();
}

void RT_Main::selectAllActive() const
{
	QList<QString> activeClients{};
	const auto& clientList = modell.getClients();
	std::for_each(clientList.constBegin(), clientList.constEnd(), [&activeClients](auto client)
	              {
		              if (client.active()) activeClients.append(client.getClientName());
	              });
	ui.clientList->selectionModel()->clearSelection();
	const QSortFilterProxyModel* proxyModel = static_cast<QSortFilterProxyModel *>(ui.clientList->model());
	std::for_each(activeClients.constBegin(), activeClients.constEnd(), [this, &proxyModel](const auto& clientName)
	              {
		              for (int i = 0; i < proxyModel->rowCount(); i++)
		              {
			              const QModelIndex& nameIndex = proxyModel->index(i, 2);
			              if (nameIndex.data().toString() == clientName)
			              {
				              const QItemSelection& itemSelection{(proxyModel->index(nameIndex.row(), 0)), (proxyModel->index(nameIndex.row(), 2))};
				              ui.clientList->selectionModel()->select(itemSelection, QItemSelectionModel::SelectionFlag::Select);
			              }
		              }
	              });
}

void RT_Main::freezeAllTriggered() const
{
	freezeAll();
}

void RT_Main::unfreezeAllTriggered() const
{
	unFreezeAll();
}

void RT_Main::clearCurrentTableTriggered() const
{
	const QTableView* currentView = static_cast<QTableView *>(modell.getTabWidget()->currentWidget());
	CustomFilterProxyModel* proxyModel = static_cast<CustomFilterProxyModel*>(currentView->model());
	static_cast<CustomTableModel*>(proxyModel->sourceModel())->clearModel();
}

void RT_Main::clearAllTablesTriggered() const
{
	for (auto i = 0; i < modell.getTabWidget()->count(); i++)
	{
		const QTableView* view = static_cast<QTableView *>(modell.getTabWidget()->widget(i));
		CustomFilterProxyModel* proxyModel = static_cast<CustomFilterProxyModel*>(view->model());
		static_cast<CustomTableModel*>(proxyModel->sourceModel())->clearModel();
	}
}

void RT_Main::clearAllMergeViews()
{
	const QList<RT_Client>& mergeViewClients = modell.getMergeViewClients();
	if (mergeViewClients.size() > 0)
	{
		for (const RT_Client& mergeViewClient : mergeViewClients)
		{
			QList<QString> clientsOfMergeView = modell.getClientsOfGroup(mergeViewClient.getClientName());
			for (QString& clientName : clientsOfMergeView)
			{
				RT_Client& client = modell.getClient(clientName);
				client.toMergeView(false);
				client.setMergeViewName("");
			}
			modell.removeGroupClient(mergeViewClient.getClientName());
		}
		modell.getGroupsModel()->clear();
		modell.getGroupsModel()->appendRow(CommonViewUtils::prepareListEntry(modell.globalClient, tickImage, crossImage));
		const QList<RT_Client>& groupClients = modell.getGroupClients();
		for (const RT_Client& client : groupClients)
		{
			modell.getGroupsModel()->appendRow(CommonViewUtils::prepareListEntry(client, tickImage, crossImage));
		}
		ui.groupList->resizeColumnToContents(0);
		ui.groupList->setColumnWidth(1, 30);
		refreshClientList();
		handleClientListSelectionChanged();
		handleGroupListSelectionChanged();
	}
}

void RT_Main::showInactiveClientsTriggered()
{
	std::for_each(subWindows.constBegin(), subWindows.constEnd(), [&](RT_LogWindow* window)
	              {
		              RT_Client* client = &modell.getClient(window->windowTitle());
		              if (client->getClientId() == RT_Constants::GROUP_ID)
		              {
			              client = &modell.getGroupClient(window->windowTitle());
		              }
		              if (!client->active())
		              {
			              window->showNormal();
			              window->raise();
		              }
		              else
		              {
			              window->showMinimized();
		              }
	              });
}

void RT_Main::showBinaryClientsTriggered()
{
	std::for_each(subWindows.constBegin(), subWindows.constEnd(), [&](RT_LogWindow* window)
	              {
		              RT_Client* client = &modell.getClient(window->windowTitle());
		              if (client->getClientId() == RT_Constants::GROUP_ID)
		              {
			              client = &modell.getGroupClient(window->windowTitle());
		              }
		              if (client->binary())
		              {
			              window->showNormal();
			              window->raise();
		              }
		              else
		              {
			              window->showMinimized();
		              }
	              });
}

void RT_Main::showTextClientsTriggered()
{
	std::for_each(subWindows.constBegin(), subWindows.constEnd(), [&](RT_LogWindow* window)
	              {
		              auto client = &modell.getClient(window->windowTitle());
		              if (client->getClientId() == RT_Constants::GROUP_ID)
		              {
			              client = &modell.getGroupClient(window->windowTitle());
		              }
		              if (!client->binary())
		              {
			              window->showNormal();
			              window->raise();
		              }
		              else
		              {
			              window->showMinimized();
		              }
	              });
}

void RT_Main::arrangeWindowsTriggered()
{
	if (subWindows.size() > 0)
	{
		QRect screenGeometry = QGuiApplication::primaryScreen()->geometry();
		int desktopHeight{screenGeometry.height()};
		int desktopWidth{screenGeometry.width()};
		QPoint initPoint{0,0};
		int windowWidth = desktopWidth / 2;
		int windowHeight = desktopHeight / 2;
		int windowNumber{0};
		QList<RT_LogWindow*> windows = subWindows.values();
		std::for_each(windows.begin(), windows.end(), [&initPoint,&windowWidth, &windowHeight, &windowNumber](RT_LogWindow* window)
		              {
			              if (windowNumber >= 4 && windowNumber % 4 == 0)
			              {
				              initPoint.setX(0);
				              initPoint.setY(0);
			              }
			              if (windowNumber >= 2 && windowNumber % 2 == 0)
			              {
				              initPoint.setX(0);
				              initPoint.setY(initPoint.y() + windowHeight);
			              }
			              else
			              {
				              if (windowNumber != 0)
				              {
					              initPoint.setX(initPoint.x() + windowWidth);
				              }
			              }
			              window->resize(windowWidth, windowHeight);
			              window->move(initPoint);
			              window->showNormal();
			              window->raise();
			              ++windowNumber;
		              });
	}
}

void RT_Main::resetSelectedClientsTriggered()
{
	std::function<void(RT_Client&)> function = [](RT_Client& client)
		{
			CommonViewUtils::resetClient(client);
		};
	updateClients(function);
	refreshClientList();
	refreshGroupList();
}

void RT_Main::resetAllClientsTriggered()
{
	QList<RT_Client> clients = modell.getClients();
	std::for_each(clients.begin(), clients.end(), [&](auto& client)
	              {
		              CommonViewUtils::resetClient(modell.getClient(client.getClientName()));
	              });
	QList<RT_Client> groupClients = modell.getGroupClients();
	std::for_each(groupClients.begin(), groupClients.end(), [&](auto& client)
	              {
		              CommonViewUtils::resetClient(modell.getGroupClient(client.getClientName()));
	              });
	CommonViewUtils::resetClient(modell.globalClient);
	refreshClientList();
	refreshGroupList();
}

RT_Main_Modell& RT_Main::getModel()
{
	return modell;
}

void RT_Main::closeEvent(QCloseEvent* event)
{
	Q_UNUSED(event);
	for (QPointer<RT_ToFileWorker> fileWorker : toFileWorkers.second)
	{
		if (!fileWorker.isNull())
		{
			fileWorker->thread()->terminate();
			fileWorker->thread()->deleteLater();
			fileWorker->deleteLater();
		}
	}
	QApplication::quit();
}

void RT_Main::updateState(QString state, bool isGroup)
{
	bool live = state == RT_Constants::LIVE ? true : false;
	bool toFile = state == RT_Constants::TO_FILE ? true : false;
	bool toRingFile = state == RT_Constants::TO_RING_FILE ? true : false;
	bool toSharedFile = state == RT_Constants::TO_SHARED_FILE ? true : false;
	QString toSharedFileName{""};
	QString toMergeViewName{""};
	bool toParent = state == RT_Constants::TO_PARENT ? true : false;
	bool toGlobal = state == RT_Constants::TO_GLOBAL ? true : false;
	bool toMergeView = state == RT_Constants::TO_MERGE_VIEW ? true : false;

	std::function<void(RT_Client&)> function = [&](RT_Client& client)
		{
			client.live(live);
			client.toFile(toFile);
			client.toRingFile(toRingFile);
			client.toSharedFile(toSharedFile);
			client.setSharedFileName(toSharedFileName);
			client.toParent(toParent);
			client.toGlobal(toGlobal);
			client.toMergeView(toMergeView);
			client.setMergeViewName(toMergeViewName);
			if (client.live())
			{
				refreshClientView(client);
			}
		};
	if (toSharedFile)
	{
		bool ok;
		toSharedFileName = QInputDialog::getText(this, tr("Input Shared File Dialog"), tr("Shared File Name"), QLineEdit::Normal, "", &ok);
		if (toSharedFileName.isEmpty()) toSharedFileName = QUuid::createUuid().toString();
		toSharedFileName.prepend(RT_Constants::SHAREDFILE_PREFIX);
		if (ok)
		{
			isGroup ? updateGroupClients(function) : updateClients(function);
		}
	}
	else if (toMergeView)
	{
		bool ok;
		toMergeViewName = QInputDialog::getText(this, tr("Input Merge View Name Dialog"), tr("Merge View Name"), QLineEdit::Normal, "", &ok);
		toMergeViewName = RT_Constants::MERGEVIEW_PREFIX + (toMergeViewName.isEmpty() ? QUuid::createUuid().toString() : toMergeViewName);
		if (ok)
		{
			registerGroupClient(toMergeViewName);
		}
		updateClients(function);
	}
	else
	{
		isGroup ? updateGroupClients(function) : updateClients(function);
	}
}

//Client Settings
void RT_Main::clientActiveCheckBoxClicked()
{
	std::function<void(RT_Client&)> function = [&](RT_Client& client)
		{
			client.active(ui.clientActiveCheckBox->isChecked());
			emit signalUpdateClientActivestate(client.getClientId(), client.active());
			if (client.active())
			{
				if (client.windowed())
				{
					clientWindowModeRadioClicked();
				}
				else
				{
					refreshClientView(client);
				}
			}
		};
	updateClients(function);
}

void RT_Main::clientsStateComboBoxChanged(int currentIndex)
{
	Q_UNUSED(currentIndex);
	updateState(ui.clientsStateComboBox->currentText(), false);
}

void RT_Main::clientNewestOnTopCheckBoxClicked()
{
	std::function<void(RT_Client&)> function = [&](RT_Client& client)
		{
			client.clearModel();
			client.newestOnTop(ui.clientNewestOnTopCheckBox->isChecked());
		};
	updateClients(function);
}

void RT_Main::clientScrollToBottomCheckBoxClicked()
{
	std::function<void(RT_Client&)> function = [&](RT_Client& client)
		{
			client.scrollToBottom(ui.clientScrollToBottomCheckBox->isChecked());
		};
	updateClients(function);
}

void RT_Main::clientTabModeRadioClicked()
{
	std::function<void(RT_Client&)> function = [&](RT_Client& client)
		{
			client.windowed(!ui.clientTabModeRadio->isChecked());
			emit windowCloseRequested(client.getClientName());
			createTabWindow(client.getClientName());
		};
	updateClients(function);
}

void RT_Main::clientWindowModeRadioClicked()
{
	QPoint startPoint = QPoint(100, 100);
	std::function<void(RT_Client&)> function = [&](RT_Client& client)
		{
			client.windowed(ui.clientWindowModeRadio->isChecked());
			if (client.active())
			{
				createLogWindow(client.getClientName(), startPoint);
				startPoint = startPoint + QPoint(30, 30);
			}
		};
	updateClients(function);
}

void RT_Main::clientListSearchTextChanged(QString searchTerm) const
{
	QSortFilterProxyModel* proxyModel = static_cast<QSortFilterProxyModel*>(ui.clientList->model());
	proxyModel->setFilterRegExp(searchTerm);
	proxyModel->setFilterKeyColumn(2);
}

//GROUP Settings
void RT_Main::activeCheckBoxClicked()
{
	std::function<void(RT_Client&)> function = [&](RT_Client& client)
		{
			client.active(ui.activeCheckBox->isChecked());
			if (client.active())
			{
				if (client.windowed())
				{
					windowModeRadioClicked();
				}
				else
				{
					refreshClientView(client);
				}
			}
		};
	updateGroupClients(function);
}

void RT_Main::groupStateComboBoxChanged(int currentIndex)
{
	Q_UNUSED(currentIndex);
	updateState(ui.groupStateComboBox->currentText(), true);
}

void RT_Main::newestOnTopCheckBoxClicked()
{
	std::function<void(RT_Client&)> function = [&](RT_Client& client)
		{
			client.clearModel();
			client.newestOnTop(ui.newestOnTopCheckBox->isChecked());
		};
	updateGroupClients(function);
}

void RT_Main::scrollToBottomCheckBoxClicked()
{
	std::function<void(RT_Client&)> function = [&](RT_Client& client)
		{
			client.scrollToBottom(ui.scrollToBottomCheckBox->isChecked());
		};
	updateGroupClients(function);
}

void RT_Main::tabModeRadioClicked()
{
	std::function<void(RT_Client&)> function = [&](RT_Client& client)
		{
			client.windowed(!ui.tabModeRadio->isChecked());
			emit windowCloseRequested(client.getClientName());
			createTabWindow(client.getClientName());
		};
	updateGroupClients(function);
}

void RT_Main::windowModeRadioClicked()
{
	QPoint startPoint = QPoint(100, 100);
	std::function<void(RT_Client&)> function = [&](RT_Client& client)
		{
			client.windowed(ui.windowModeRadio->isChecked());
			if (client.active())
			{
				createLogWindow(client.getClientName(), startPoint);
				startPoint = startPoint + QPoint(30, 30);
			}
		};
	updateGroupClients(function);
}

void RT_Main::groupListSearchTextChanged(QString searchTerm) const
{
	QSortFilterProxyModel* proxyModel = static_cast<QSortFilterProxyModel*>(ui.groupList->model());
	proxyModel->setFilterRegExp(searchTerm);
	proxyModel->setFilterKeyColumn(2);
}

void RT_Main::globalSearchTermChanged(QString searchTerm)
{
	if (!searchTerm.isEmpty())
	{
		RT_LogFilter filter{searchTerm, ui.caseSensitiveCheckBox->isChecked()};
		if (filter.isValid())
		{
			ui.inputField->setStyleSheet("#inputField{background-color:#ccffcc} #inputField:hover{border: 1px solid gray;background-color:#ccffcc}");
		}
		else
		{
			ui.inputField->setStyleSheet("#inputField{background-color:#ff9999} #inputField:hover{border: 1px solid gray;background-color:#ff9999}");
		}
		modell.setFilter(filter);
	}
	else
	{
		modell.setFilter(RT_LogFilter(""));
		ui.inputField->setStyleSheet("");
	}
}

void RT_Main::executeFilterClicked()
{
	if (modell.getFilter().isValid())
	{
		if (!ui.globalSearchCheckBox->isChecked())
		{
			QTableView* currentView = static_cast<QTableView*>(modell.getTabWidget()->currentWidget());
			CustomFilterProxyModel* proxyModel = static_cast<CustomFilterProxyModel*>(currentView->model());
			proxyModel->clear();
			proxyModel->setFilter(modell.getFilter());
			proxyModel->invalidate();
		}
		else
		{
			for (int i = 0; i < modell.getTabWidget()->count(); i++)
			{
				QTableView* view = static_cast<QTableView*>(modell.getTabWidget()->widget(i));
				CustomFilterProxyModel* proxyModel = static_cast<CustomFilterProxyModel*>(view->model());
				proxyModel->clear();
				proxyModel->setFilter(modell.getFilter());
				proxyModel->invalidate();
			}
		}
		ui.inputField->setStyleSheet("#inputField{background-color:#b8dff2} #inputField:hover{border: 1px solid gray;background-color:#b8dff2}");
	}
	else
	{
		QMessageBox* messageBox = new QMessageBox(this);
		messageBox->setWindowTitle("Invalid Filter");
		messageBox->setText("Current Filter is invalid. Please adjust your filter until the background lits up green");
		messageBox->show();
	}
}

void RT_Main::closeAppTriggered()
{
	QApplication::quit();
}


void RT_Main::importFileTriggered()
{
	const QString filename = QFileDialog::getOpenFileName(this, tr("Import File"), RT_Settings::baseFileSaveLocation(), "Log files (*.txt);;");
	if (!filename.isEmpty())
	{
		emit signalOpenFileTriggered(filename);
	}
}

void RT_Main::exportFileTriggered()
{
	QDir dir{};
	if (!dir.exists(RT_Settings::baseFileSaveLocation())) dir.mkpath(RT_Settings::baseFileSaveLocation());
	const QString filename = QFileDialog::getSaveFileName(this, tr("Save File"), RT_Settings::baseFileSaveLocation(), "Log files (*.txt);;");
	if (!filename.isEmpty())
	{
		QString tableName = modell.getTabWidget()->currentWidget()->objectName();
		RT_Client* client = &modell.getClient(tableName);
		if (client->getClientName() == RT_Constants::GLOBAL)
		{
			client = &modell.getGroupClient(tableName);
		}
		CustomFilterProxyModel* proxyModel = static_cast<CustomFilterProxyModel*>(client->getTable()->model());
		prepareSignalToFileLog(filename, proxyModel->getProxyModelContent());
	}
}

void RT_Main::clearClientsAndGroups()
{
	closeAllWindows();
	closeAllTabsTriggered();
	modell.getClientsModel()->clear();
	modell.getGroupsModel()->clear();
	modell.clearClients();
	modell.clearGroupClients();
	modell.getGroupsModel()->appendRow(CommonViewUtils::prepareListEntry(modell.globalClient, tickImage, crossImage));
	ui.groupList->resizeColumnToContents(0);
	ui.groupList->setColumnWidth(1, 30);
}

void RT_Main::refreshApplicationState()
{
	closeAllWindows();
	closeAllTabsTriggered();
	initMasterRestart();
	setupGlobalSettings();
	setupViewSettings();

	QList<RT_Client> groupClients = modell.getGroupClients();
	std::for_each(RT_Settings::groups.begin(), RT_Settings::groups.end(), [&](RT_Client& pGroupClient)
	              {
		              if (!groupClients.contains(pGroupClient))
		              {
			              modell.addGroupClient(pGroupClient);
			              connect(pGroupClient.getTable(), &QTableView::clicked, this, &RT_Main::handleTableClicked);
			              connect(pGroupClient.getTable()->selectionModel(), &QItemSelectionModel::selectionChanged, this, &RT_Main::handleTableSelectionChanged);
			              modell.getGroupsModel()->appendRow(CommonViewUtils::prepareListEntry(pGroupClient, tickImage, crossImage));
		              }
		              else
		              {
			              modell.updateGroupClient(pGroupClient);
		              }
		              refreshClientView(pGroupClient);
	              });
	refreshGroupList();
	handleGroupListSelectionChanged();

	QList<RT_Client> clients = modell.getClients();
	std::for_each(RT_Settings::clients.begin(), RT_Settings::clients.end(), [&](RT_Client& pClient)
	              {
		              if (!clients.contains(pClient))
		              {
			              modell.addClient(pClient);
			              connect(pClient.getTable(), &QTableView::clicked, this, &RT_Main::handleTableClicked);
			              connect(pClient.getTable()->selectionModel(), &QItemSelectionModel::selectionChanged, this, &RT_Main::handleTableSelectionChanged);
			              modell.getClientsModel()->appendRow(CommonViewUtils::prepareListEntry(pClient, tickImage, crossImage));
		              }
		              else
		              {
			              modell.updateClient(pClient);
		              }
		              refreshClientView(pClient);
	              });
	refreshClientList();
	handleClientListSelectionChanged();

	ui.groupList->sortByColumn(2, Qt::SortOrder::AscendingOrder);
	ui.groupList->resizeColumnToContents(0);
	ui.groupList->setColumnWidth(1, 30);

	ui.clientList->sortByColumn(2, Qt::SortOrder::AscendingOrder);
	ui.clientList->resizeColumnToContents(0);
	ui.clientList->setColumnWidth(1, 30);
	rapplicationInitialized();
}

void RT_Main::initMasterRestart()
{
	emit restartMaster();
	setApplicationOutput("Listening on:\n\nHost: " + RT_Settings::masterHost + "\nPort: " + QString::number(RT_Settings::masterPort));
}

void RT_Main::rapplicationInitialized()
{
	QList<RT_Client> clients = modell.getClients();
	std::for_each(clients.cbegin(),clients.cend(),[&](const RT_Client& pClient)
	{
		emit signalUpdateClientActivestate(pClient.getClientId(), pClient.active());
	});
}

void RT_Main::restartMasterTriggered()
{
	initMasterRestart();
}

void RT_Main::loadConfigTriggered()
{
	QString openFileName = QFileDialog::getOpenFileName(this, tr("Load Config File"), RT_Settings::configurationFilesLocation(), "Config files (*.json);;");
	if (!openFileName.isNull())
	{
		QString fileName = QFileInfo(openFileName).fileName();
		fileName = fileName.split(".").isEmpty() ? fileName : fileName.split(".").first();
		if (!RT_Settings::load(fileName))
		{
			setApplicationOutput("Loading configuration failed. Check if config file exists under folder\n/config and has .json ending");
		}
		else
		{
			refreshApplicationState();
			QSettings{}.setValue("currentConfigurationFileName", RT_Settings::currentConfigurationFileName());
		}
	}
}

void RT_Main::adjustUpdateInterval() const
{
	int windowCount = modell.getWindowedClientsCount();
	RT_Settings::updateInterval(windowCount > 1 ?
		                      RT_Constants::baseUpdateInterval + windowCount * (RT_Constants::baseUpdateInterval / 4)
		                      : RT_Constants::baseUpdateInterval);
}

void RT_Main::initSignalClientActiveState(int pClientId, bool pIsActive)
{
	emit signalUpdateClientActivestate(pClientId, pIsActive);
}

void RT_Main::logWindowClosed(QString tableName)
{
	if (tableName != RT_Constants::GLOBAL)
	{
		RT_Client* client = &modell.getClient(tableName);
		if (client->getClientId() == RT_Constants::GLOBAL_ID)
		{
			client = &modell.getGroupClient(tableName);
		}
		if (!client->windowed())
		{
			modell.getTabWidget()->setCurrentIndex(setupClientTabIcon(*client));
		}
		client->windowed(false);
		client->live(false);
	}
	else
	{
		modell.globalClient.windowed(false);
		setupClientTabIcon(modell.globalClient);
		for (int i = 0; i < modell.getTabWidget()->count(); i++)
		{
			QWidget* tab = modell.getTabWidget()->widget(i);
			if (tab->objectName() == RT_Constants::GLOBAL)
			{
				modell.getTabWidget()->tabBar()->tabButton(i, QTabBar::RightSide)->hide();
			}
		}
	}
	auto it = subWindows.constFind(tableName);
	if (it != subWindows.constEnd())
	{
		it.value()->close();
		if (it.value() != nullptr)
		{
			it.value()->deleteLater();
		}
		subWindows.remove(tableName);
	}
	refreshGroupList();
	handleGroupListSelectionChanged();
	refreshClientList();
	handleClientListSelectionChanged();

	adjustUpdateInterval();
}

void RT_Main::independentLogWindowClosed(QString tableName)
{
	if (subWindows.keys().contains(tableName))
	{
		RT_LogWindow* logWindow = subWindows[tableName];
		if (logWindow != nullptr)
		{
			logWindow->deleteLater();
		}
	}
	subWindows.remove(tableName);
}

void RT_Main::assignColor()
{
	QColor color = QColorDialog::getColor();
	std::function<void(RT_Client&)> function = [&](RT_Client& client)
		{
			client.color(color);
			client.getTable()->setStyleSheet("background-color:" + client.color().name());
			QPixmap colorRect{15,15};
			colorRect.fill(client.color());
			modell.getTabWidget()->setTabIcon(tabAt(client.getClientName()), colorRect);
		};
	updateClients(function);
	updateGroupClients(function);
}

void RT_Main::minimizeAllTriggered() const
{
	minimizeAll();
}

void RT_Main::maximizeAllTriggered()
{
	std::for_each(subWindows.constBegin(), subWindows.constEnd(), [](RT_LogWindow* window)
	              {
		              window->showNormal();
	              });
}

void RT_Main::closeAllTabsTriggered()
{
	modell.getTabWidget()->clear();
	setupClientTabIcon(modell.globalClient);
	modell.getTabWidget()->tabBar()->tabButton(0, QTabBar::RightSide)->hide();
	for (RT_Client& clientCopy : modell.getClients())
	{
		RT_Client& client = modell.getClient(clientCopy.getClientName());
		client.live(false);
	}
	for (RT_Client& groupClientCopy : modell.getGroupClients())
	{
		RT_Client& groupClient = modell.getGroupClient(groupClientCopy.getClientName());
		groupClient.live(false);
	}
	modell.globalClient.live(false);
	refreshClientList();
	refreshGroupList();
	handleClientListSelectionChanged();
	handleGroupListSelectionChanged();
}

void RT_Main::closeAllWindows()
{
	for (RT_LogWindow* logWindow : subWindows.values())
	{
		if (logWindow != nullptr)
		{
			logWindow->close();
			logWindow->deleteLater();
		}
	}
	subWindows.clear();
}

void RT_Main::settingsTriggered()
{
	RT_SettingsWindow* settingsWindow = new RT_SettingsWindow(modell, ui.groupList, ui.clientList, this);
	connect(settingsWindow, &RT_SettingsWindow::signalMasterRestart, this, &RT_Main::initMasterRestart);
	settingsWindow->show();
}

void RT_Main::restoreDefaultSettings()
{
	RT_Settings::reset();
	refreshApplicationState();
}

void RT_Main::aboutTriggered()
{
	QMessageBox* messageBox = new QMessageBox(this);
	messageBox->setWindowTitle("About");
	messageBox->setText("This logging tool - RAD LogShark - was developed by\nZafer Dogan as his term project at the HSR Rapperswil in 2017.\nYou can reach him via E-Mail: zdogan@hsr.ch");
	messageBox->show();
}

void RT_Main::helpTriggered()
{
	QDesktopServices::openUrl(QUrl(QApplication::applicationDirPath() + "/doc/html/index.html"));
}

void RT_Main::setColumnVisibility(int column, bool val) const
{
	for (auto& client : modell.getClients())
	{
		client.getTable()->setColumnHidden(column, val);
		if (!val) CommonViewUtils::resetColumnWidths(client);
	}
	for (auto& groupClient : modell.getGroupClients())
	{
		groupClient.getTable()->setColumnHidden(column, val);
		if (!val) CommonViewUtils::resetColumnWidths(groupClient);
	}
	auto globalClient = modell.globalClient;
	globalClient.getTable()->setColumnHidden(column, val);
	if (!val) CommonViewUtils::resetColumnWidths(globalClient);
}

//Global Filters
void RT_Main::enableInfoCheckBoxClicked() const
{
	RT_Settings::logSettings.enableInfo(ui.enableInfoCheckBox->isChecked());
}

void RT_Main::enableWarningCheckBoxClicked() const
{
	RT_Settings::logSettings.enableWarning(ui.enableWarningCheckBox->isChecked());
}

void RT_Main::enableErrorCheckBoxClicked() const
{
	RT_Settings::logSettings.enableError(ui.enableErrorCheckBox->isChecked());
}

void RT_Main::enableExceptionCheckBoxClicked() const
{
	RT_Settings::logSettings.enableException(ui.enableExceptionCheckBox->isChecked());
}

void RT_Main::enableFatalCheckBoxClicked() const
{
	RT_Settings::logSettings.enableFatal(ui.enableFatalCheckBox->isChecked());
}

void RT_Main::enableBinaryCheckBoxClicked() const
{
	RT_Settings::logSettings.enableBinary(ui.enableBinaryCheckBox->isChecked());
}

void RT_Main::useDateStampCheckBoxClicked() const
{
	RT_Settings::viewSettings.useDateStamp = ui.useDateStampCheckBox->isChecked();
	setColumnVisibility(0, !ui.useDateStampCheckBox->isChecked());
}

void RT_Main::useTimeStampCheckBoxClicked() const
{
	RT_Settings::viewSettings.useTimeStamp = ui.useTimeStampCheckBox->isChecked();
	setColumnVisibility(1, !ui.useTimeStampCheckBox->isChecked());
}

void RT_Main::useGroupStampCheckBoxClicked() const
{
	RT_Settings::viewSettings.useGroupStamp = ui.useGroupStampCheckBox->isChecked();
	setColumnVisibility(2, !ui.useGroupStampCheckBox->isChecked());
}

void RT_Main::useClientStampCheckBoxClicked() const
{
	RT_Settings::viewSettings.useClientStamp = ui.useClientStampCheckBox->isChecked();
	setColumnVisibility(3, !ui.useClientStampCheckBox->isChecked());
}

void RT_Main::useMessageHeaderCheckBoxClicked() const
{
	RT_Settings::viewSettings.useMessageHeaderStamp = ui.useMessageHeaderCheckBox->isChecked();
	setColumnVisibility(4, !ui.useMessageHeaderCheckBox->isChecked());
}

void RT_Main::useContentStampCheckBoxClicked() const
{
	RT_Settings::viewSettings.useContentStamp = ui.useContentStampCheckBox->isChecked();
	setColumnVisibility(5, !ui.useContentStampCheckBox->isChecked());
}

void RT_Main::infoMessageCheckBoxClicked() const
{
	RT_Settings::logSettings.infoMessage(ui.infoMessageCheckBox->isChecked());
}

void RT_Main::warningMessageCheckBoxClicked() const
{
	RT_Settings::logSettings.warningMessage(ui.warningMessageCheckBox->isChecked());
}

void RT_Main::errorMessageCheckBoxClicked() const
{
	RT_Settings::logSettings.errorMessage(ui.errorMessageCheckBox->isChecked());
}

void RT_Main::exceptionMessageCheckBoxClicked() const
{
	RT_Settings::logSettings.exceptionMessage(ui.exceptionMessageCheckBox->isChecked());
}

void RT_Main::fatalMessageCheckBoxClicked() const
{
	RT_Settings::logSettings.fatalMessage(ui.fatalMessageCheckBox->isChecked());
}


//View Settings

void RT_Main::adjustMainSplitter() const
{
	if (!ui.showClientSectionCheckBox->isChecked() && !ui.showGroupSectionCheckBox->isChecked())
	{
		ui.splitter->setVisible(false);
	}
	else
	{
		ui.splitter->setVisible(true);
	}
}

void RT_Main::showClientSection() const
{
	RT_Settings::viewSettings.showClientSection = ui.showClientSectionCheckBox->isChecked();
	if (ui.showClientSectionCheckBox->isChecked())
	{
		ui.clientSearchWidget->setVisible(true);
		ui.clientSettingsWidget->setVisible(true);
		ui.clientList->setVisible(true);
		ui.groupListLayout->setContentsMargins(0, 0, 0, 6);
	}
	else
	{
		ui.clientSearchWidget->setVisible(false);
		ui.clientSettingsWidget->setVisible(false);
		ui.clientList->setVisible(false);
		ui.groupListLayout->setContentsMargins(0, 0, 0, 0);
	}
	adjustMainSplitter();
}

void RT_Main::showGroupSection() const
{
	RT_Settings::viewSettings.showGroupSection = ui.showGroupSectionCheckBox->isChecked();
	if (ui.showGroupSectionCheckBox->isChecked())
	{
		ui.groupSearchWidget->setVisible(true);
		ui.groupSettingsWidget->setVisible(true);
		ui.groupList->setVisible(true);
		ui.groupListLayout->setContentsMargins(0, 0, 0, 6);
	}
	else
	{
		ui.groupSearchWidget->setVisible(false);
		ui.groupSettingsWidget->setVisible(false);
		ui.groupList->setVisible(false);
		ui.groupListLayout->setContentsMargins(0, 0, 0, 0);
	}
	adjustMainSplitter();
}

void RT_Main::showFilterArea() const
{
	RT_Settings::viewSettings.showFilterArea = ui.showFilterAreaCheckBox->isChecked();
	if (ui.showFilterAreaCheckBox->isChecked())
	{
		ui.filterWidget->setVisible(true);
	}
	else
	{
		ui.filterWidget->setVisible(false);
	}
}

void RT_Main::showLogDetailCheckBoxClicked() const
{
	RT_Settings::viewSettings.showLogDetailArea = ui.showLogDetailCheckBox->isChecked();
	if (ui.showLogDetailCheckBox->isChecked())
	{
		ui.logDetailInput->setVisible(true);
	}
	else
	{
		ui.logDetailInput->setVisible(false);
	}
}
