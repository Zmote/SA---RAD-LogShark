#ifndef CUSTOMFILTERPROXYMODEL_H
#define CUSTOMFILTERPROXYMODEL_H
#include <QSortFilterProxyModel>
#include "RT_LogFilter.h"

/*!
 * \class CustomFilterProxyModel
 * \brief A custom proxy model for client table filtering
 * \author Zafer Dogan, <a href="mailto:zdogan@hsr.ch">Zafer Dogan</a>
 * \version 1.1
 * \since 1.2
 */
class CustomFilterProxyModel : public QSortFilterProxyModel
{
	Q_OBJECT
public:
	CustomFilterProxyModel(QObject * parent = 0);
	/*!
	 * \brief Sets filter object for the custom proxy model
	 * \param pFilter \ref RT_LogFilter filter object to be used for filtering
	 */
	void setFilter(RT_LogFilter & pFilter);
	/**
	 * \brief Gets visible log data from the proxy model
	 * \return visible log data
	 */
	QList<QList<QString>> getProxyModelContent() const;
protected:
	bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;
	bool lessThan(const QModelIndex &left, const QModelIndex &right) const override;
private:
	/*!
	 * \brief \ref RT_LogFilter filter object
	 */
	RT_LogFilter filter;
};

#endif //!CUSTOMFILTERPROXYMODEL_H