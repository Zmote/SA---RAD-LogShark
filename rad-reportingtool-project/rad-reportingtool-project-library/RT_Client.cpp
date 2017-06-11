#include "RT_Client.h"
#include "CustomTableModel.h"
#include <QDebug>
#include <QScrollBar>
#include "CommonViewUtils.h"
#include "CustomFilterProxyModel.h"
#include "RT_Settings.h"

RT_Client::RT_Client(const int pClientId, const QString pClientName, const QString pGroupName, QTableView* pTable)
	: table{pTable}, isBinary{false}, isActive{false}, isLive{false}, isToFile{false},
	  isToRingFile{false}, isToSharedFile(false), isToParent{false}, isToGlobal(false), isToMergeView(false), isNewestOnTop{false}, isScrollToBottom{true}, isWindowed{false}, clientId{pClientId},
	  tableColor(Qt::white), clientName{pClientName}, groupName{pGroupName}, mergeViewName{""},sharedFileName{""}
{
	if (table == nullptr)
	{
		table = CommonViewUtils::setupTable(pClientName);
	}
}

RT_Client::RT_Client(const RT_Client& copy)
{
	*this = copy;
}

RT_Client& RT_Client::operator=(const RT_Client& copy)
{
	this->clientId = copy.clientId;
	this->clientName = copy.clientName;
	this->groupName = copy.groupName;
	this->mergeViewName = copy.mergeViewName;
	this->sharedFileName = copy.sharedFileName;
	this->isBinary = copy.isBinary;
	this->isActive = copy.isActive;
	this->isLive = copy.isLive;
	this->isToFile = copy.isToFile;
	this->isToRingFile = copy.isToRingFile;
	this->isToSharedFile = copy.isToSharedFile;
	this->isToParent = copy.isToParent;
	this->isToGlobal = copy.isToGlobal;
	this->isToMergeView = copy.isToMergeView;
	this->isNewestOnTop = copy.isNewestOnTop;
	this->isScrollToBottom = copy.isScrollToBottom;
	this->isWindowed = copy.isWindowed;
	this->tableColor = copy.tableColor;
	table = copy.table;
	return *this;
}

bool RT_Client::operator==(const RT_Client& copy) const
{
	return this->clientName == copy.clientName && this->groupName == copy.groupName;
}

bool RT_Client::isParent() const
{
	if(clientId == RT_Constants::GLOBAL_ID || clientId == RT_Constants::GROUP_ID)
	{
		return true;
	}
	return false;
}

void RT_Client::clearModel() const
{

	CustomFilterProxyModel * proxyModel = static_cast<CustomFilterProxyModel*>(table->model());
	static_cast<CustomTableModel*>(proxyModel->sourceModel())->clearModel();
}

void RT_Client::scroll(int rowCount)
{
	QTableView * _table = getTable();
	if (_table->verticalScrollBar()->maximum() <= RT_Settings::logBufferLimit())
	{
		_table->verticalScrollBar()->setMaximum(rowCount);
	}
	_table->verticalScrollBar()->setValue(_table->verticalScrollBar()->maximum());
}

QTableView * RT_Client::getTable()
{
	if (table.isNull())
	{
		table = CommonViewUtils::setupTable(clientName);
	}
	return table.data();
}

QColor RT_Client::color() const
{
	return tableColor;
}

bool RT_Client::binary() const
{
	return isBinary;
}

bool RT_Client::active() const
{
	return isActive;
}

bool RT_Client::live() const
{
	return isLive;
}

bool RT_Client::toFile() const
{
	return isToFile;
}

bool RT_Client::toRingFile() const
{
	return isToRingFile;
}

bool RT_Client::toSharedFile() const
{
	return isToSharedFile;
}

bool RT_Client::toParent() const
{
	return isToParent;
}

bool RT_Client::newestOnTop() const
{
	return isNewestOnTop;
}

bool RT_Client::scrollToBottom() const
{
	return isScrollToBottom;
}

bool RT_Client::windowed() const
{
	return isWindowed;
}

bool RT_Client::toGlobal() const
{
	return isToGlobal;
}

bool RT_Client::toMergeView() const
{
	return isToMergeView;
}

int RT_Client::getClientId() const
{
	return clientId;
}

QString RT_Client::getClientName() const
{
	return clientName;
}

QString RT_Client::getGroupName() const
{
	return groupName;
}


QString RT_Client::getSharedFileName() const
{
	return sharedFileName;
}

QString RT_Client::getMergeViewName() const
{
	return mergeViewName;
}

void RT_Client::color(const QColor& color)
{
	tableColor = color;
}

void RT_Client::binary(bool val)
{
	isBinary = val;
}

void RT_Client::active(bool val)
{
	isActive = val;
}

void RT_Client::live(bool val)
{
	isLive = val;
}

void RT_Client::toFile(bool val)
{
	isToFile = val;
}

void RT_Client::toRingFile(bool val)
{
	isToRingFile = val;
}

void RT_Client::toSharedFile(bool val)
{
	isToSharedFile = val;
}

void RT_Client::toParent(bool val)
{
	isToParent = val;
}

void RT_Client::toGlobal(bool val)
{
	isToGlobal = val;
}

void RT_Client::toMergeView(bool val)
{
	isToMergeView = val;
}

void RT_Client::newestOnTop(bool val)
{
	isNewestOnTop = val;
}

void RT_Client::scrollToBottom(bool val)
{
	isScrollToBottom = val;
}

void RT_Client::windowed(bool val)
{
	isWindowed = val;
}

void RT_Client::addLog(const QList<QList<QString>>& rows)
{
	CustomFilterProxyModel* proxyModel = static_cast<CustomFilterProxyModel *>(getTable()->model());
	CustomTableModel * model = static_cast<CustomTableModel*>(proxyModel->sourceModel());
	if (isNewestOnTop)
	{
		model->insertOnTop(rows);
	}
	else
	{
		model->appendRow(rows);
	}
	if (isScrollToBottom)
	{
		scroll(proxyModel->rowCount());
	}
}

void RT_Client::setSharedFileName(QString fileName)
{
	sharedFileName = fileName;
}

void RT_Client::setMergeViewName(QString pMergeViewName)
{
	mergeViewName = pMergeViewName;
}
