#include "CustomFilterProxyModel.h"
#include "CustomTableModel.h"

CustomFilterProxyModel::CustomFilterProxyModel(QObject* parent):QSortFilterProxyModel(parent), filter("")
{
}

void CustomFilterProxyModel::setFilter(RT_LogFilter& pFilter)
{
	filter = pFilter;
}

bool CustomFilterProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex& sourceParent) const
{
	QModelIndex dateIndex = sourceModel()->index(sourceRow, 0, sourceParent);
	QModelIndex timeIndex = sourceModel()->index(sourceRow, 1, sourceParent);
	QModelIndex groupIndex = sourceModel()->index(sourceRow, 2, sourceParent);
	QModelIndex clientIndex = sourceModel()->index(sourceRow, 3, sourceParent);
	QModelIndex kindIndex = sourceModel()->index(sourceRow, 4, sourceParent);
	QModelIndex contentIndex = sourceModel()->index(sourceRow, 5, sourceParent);
	bool dateMatch = true;
	bool timeMatch = true;
	bool groupMatch = true;
	bool clientMatch = true;
	bool kindMatch = true;
	bool contentMatch = true;
	if (!filter.dateTerm.isEmpty()) dateMatch = sourceModel()->data(dateIndex).toString().contains(filter.dateTerm);
	if (!filter.timeTerm.isEmpty()) timeMatch = sourceModel()->data(timeIndex).toString().contains(filter.timeTerm);
	if (!filter.groupNameTerm.isEmpty()) groupMatch = sourceModel()->data(groupIndex).toString().contains(filter.groupNameTerm);
	if (!filter.clientNameTerm.isEmpty()) clientMatch = sourceModel()->data(clientIndex).toString().contains(filter.clientNameTerm);
	if (!filter.messageKindTerm.isEmpty()) kindMatch = sourceModel()->data(kindIndex).toString().contains(filter.messageKindTerm);
	if (!filter.contentTerm.isEmpty()) contentMatch = sourceModel()->data(contentIndex).toString().contains(filter.contentTerm);
	return dateMatch && timeMatch && groupMatch && clientMatch && kindMatch && contentMatch;
}

bool CustomFilterProxyModel::lessThan(const QModelIndex& left, const QModelIndex& right) const
{
	//TODO implemented sorting
	QVariant leftData = sourceModel()->data(left);
	QVariant rightData = sourceModel()->data(right);
	return true;
}

QList<QList<QString>> CustomFilterProxyModel::getProxyModelContent() const
{
	QList<QList<QString>> proxyEntryOfLists{};
	QList<QList<QString>> sourceEntryList = static_cast<CustomTableModel*>(sourceModel())->getModelContent();

	for(int i = 0; i < rowCount();i++)
	{
		QList<QString> row{};
		for(int j = 0; j <= 5;j++)
		{
			int sourceRow = mapToSource(index(i, 0)).row();
			row.append(sourceEntryList.at(sourceRow).at(j));
		}
		proxyEntryOfLists.append(row);
	}
	return proxyEntryOfLists;
}
