#include "CommonViewUtils.h"
#include "CustomTableModel.h"
#include <QApplication>
#include <QHeaderView>
#include <QDebug>
#include <QItemDelegate>
#include "CustomFilterProxyModel.h"
#include <QLineEdit>

void resetTableColumnWidths(QTableView* logTable)
{
	logTable->setColumnWidth(0, 80);
	logTable->setColumnWidth(1, 60);
	logTable->setColumnWidth(2, 120);
	logTable->setColumnWidth(3, 100);
	logTable->setColumnWidth(4, 60);
}

QTableView * CommonViewUtils::setupTable(QString tablename) {
	QSizePolicy policy{ QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed };	
	auto logTable = new QTableView();
	logTable->setObjectName(tablename);
	CustomFilterProxyModel * proxyModel = new CustomFilterProxyModel(logTable);
	CustomTableModel * model = new CustomTableModel(proxyModel);
	model->setObjectName(tablename);
	proxyModel->setObjectName(tablename);
	proxyModel->setSourceModel(model);
	logTable->setModel(proxyModel);
	resetTableColumnWidths(logTable);
	logTable->setSizePolicy(policy);
	logTable->verticalHeader()->setDefaultSectionSize(18);
	logTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
	logTable->horizontalHeader()->setStretchLastSection(true);
	logTable->setSelectionMode(QAbstractItemView::SingleSelection);
	logTable->setTextElideMode(Qt::ElideRight);
	logTable->setSelectionBehavior(QAbstractItemView::SelectRows);
	logTable->setShowGrid(false);
	logTable->setStyleSheet(RT_Constants::QTABLEVIEW_ACTIVE_SELECTION_CSS);
	return logTable;
}

void CommonViewUtils::resetColumnWidths(RT_Client & client)
{
	QTableView * logTable = client.getTable();
	resetTableColumnWidths(logTable);
}

void CommonViewUtils::resetClient(RT_Client & client)
{
	client.active(false);
	client.live(false);
	client.toFile(false);
	client.toRingFile(false);
	client.toParent(false);
	client.toSharedFile(false);
	client.toGlobal(false);
	client.newestOnTop(false);
	client.scrollToBottom(false);
	client.setSharedFileName("");
	client.toMergeView(false);
	client.setMergeViewName("");
}

QTabWidget * CommonViewUtils::initTabWidget(QTabWidget * tabWidget)
{
	tabWidget->setAcceptDrops(true);
	tabWidget->setDocumentMode(true);
	tabWidget->setMovable(true);
	tabWidget->setMouseTracking(true);
	return tabWidget;
}

QString CommonViewUtils::prepareRouteState(const RT_Client& client)
{
	QString routeState{ "" };
	if (client.live()) routeState.append("L");
	if (client.toFile()) routeState.append("F");
	if (client.toRingFile()) routeState.append("RF");
	if (client.toSharedFile()) routeState.append("S");
	if (client.toParent()) routeState.append("P");
	if (client.toGlobal()) routeState.append("G");
	if (client.toMergeView()) routeState.append("MW");
	if (client.windowed()) routeState.prepend("*");;
	if (routeState.size() == 0) routeState.append("-");
	return routeState;
}

void CommonViewUtils::prepareIcon(const RT_Client& client, QStandardItem* activeItem, const QPixmap & tickImage, const QPixmap & crossImage)
{
	if(client.active())
	{
		activeItem->setIcon(tickImage);
	}else
	{
		activeItem->setIcon(crossImage);
	}
	QSize size{ 20,20 };
	activeItem->setSizeHint(size);
}

QList<QStandardItem*> CommonViewUtils::prepareListEntry(const RT_Client& client, const QPixmap & tickImage, const QPixmap & crossImage)
{
	QList<QStandardItem*> entry{};
	QStandardItem* activeItem = new QStandardItem("");
	prepareIcon(client, activeItem, tickImage,crossImage);
	entry.append(activeItem);
	QStandardItem * routeItem = new QStandardItem(prepareRouteState(client));
	entry.append(routeItem);
	QStandardItem* nameItem = new QStandardItem(client.getClientName());
	entry.append(nameItem);
	return entry;
}
