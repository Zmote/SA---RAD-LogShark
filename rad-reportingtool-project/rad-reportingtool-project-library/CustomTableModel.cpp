#include "CustomTableModel.h"
#include <QString>
#include <QBrush>
#include <QRgb>
#include <QVector>
#include "RT_Settings.h"

CustomTableModel::CustomTableModel(QObject * parent)
	: QAbstractTableModel(parent), listOfEntries{}
{
}

int CustomTableModel::rowCount(const QModelIndex & parent) const
{
	Q_UNUSED(parent);
	return listOfEntries.size();
}

int CustomTableModel::columnCount(const QModelIndex & parent) const
{
	Q_UNUSED(parent);
	return 6;
}

QVariant CustomTableModel::data(const QModelIndex & index, int role) const
{
	if (!index.isValid())
		return QVariant();

	if (index.row() >= listOfEntries.size() || index.row() < 0)
		return QVariant();

	if(role == Qt::ForegroundRole)
	{
		const QModelIndex & kindIndex = this->index(index.row(), 4);
		const QString & indexData = kindIndex.data().toString();
		if (indexData == "Error" || indexData == "Fatal" || indexData == "Exception")
		{
			return QVariant::fromValue(QBrush{ Qt::red });
		}
	}
	if (role == Qt::DisplayRole || role == Qt::UserRole) {
		if (index.column() < 0 || index.column() > 6)
			return QVariant();
		const QList<QString> & row = listOfEntries.at(index.row());
		if (row.size() <= index.column() - 1)
		{
			return QVariant();
		}
		if(index.column() == 5)
		{
			const QString & content = row.at(index.column());
			return role == Qt::UserRole? row.at(index.column()) : content.simplified();
		}
		return row.at(index.column());
	}
	return QVariant();
}

QVariant CustomTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role != Qt::DisplayRole)
		return QVariant();

	if (orientation == Qt::Horizontal) {
		switch (section) {
		case 0:
			return tr("Date");
		case 1:
			return tr("Time");
		case 2:
			return tr("Group");
		case 3:
			return tr("Client");
		case 4:
			return tr("Kind");
		case 5:
			return tr("Content");
		default:
			return QVariant();
		}
	}
	return QVariant();
}

Qt::ItemFlags CustomTableModel::flags(const QModelIndex & index) const
{
	if (!index.isValid())
		return Qt::ItemIsEnabled;

	return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

bool CustomTableModel::appendRow(const QList<QList<QString>> & rows)
{
	int listSize = listOfEntries.size();
	if(listSize >= RT_Settings::logBufferLimit())
	{
		for (const auto& row : rows)
		{
			listOfEntries.removeFirst();
			listOfEntries.append(row);
		}
		emit dataChanged(index(0, 0), index(listSize-1, 5));
	}else
	{
		beginInsertRows(QModelIndex(), listSize, listSize + rows.size()-1);
		for (const auto& row : rows)
		{
			listOfEntries.append(row);
		}
		endInsertRows();
	}
	return true;
}

QList<QList<QString>> CustomTableModel::getModelContent() const
{
	return listOfEntries;
}

bool CustomTableModel::insertOnTop(const QList<QList<QString>> & rows)
{
	int listSize = listOfEntries.size();
	if(listSize >= RT_Settings::logBufferLimit())
	{
		for (const auto& row : rows)
		{
			listOfEntries.removeLast();
			listOfEntries.prepend(row);
		}
		emit dataChanged(index(0, 0), index(listSize - 1, 5));
	}else
	{
		beginInsertRows(QModelIndex(), 0, rows.size()-1);
		for (const auto& row : rows)
		{
			listOfEntries.prepend(row);
		}
		endInsertRows();
	}
	
	return true;
}

void CustomTableModel::clearModel()
{
	beginResetModel();
	listOfEntries.clear();
	endResetModel();
}

