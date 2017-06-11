#ifndef CUSTOMTABLEMODEL_H
#define CUSTOMTABLEMODEL_H

#include <QModelIndex>
#include <QObject>

/*!
 * \class CustomTableModel
 * \brief Custom Table Model for more efficient log append management
 * \author Zafer Dogan, <a href="mailto:zdogan@hsr.ch">Zafer Dogan</a>
 * \version 1.2
 * \since 1.1
 */
class CustomTableModel : public QAbstractTableModel {
	Q_OBJECT
public:
	CustomTableModel(QObject *parent = nullptr);
	int rowCount(const QModelIndex &parent) const override;
	int columnCount(const QModelIndex &parent) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
	Qt::ItemFlags flags(const QModelIndex &index) const override;
	bool appendRow(const QList<QList<QString>> & rows);
	QList<QList<QString>> getModelContent() const;
	bool insertOnTop(const QList<QList<QString>> & rows);
	void clearModel();
private:
	QList<QList<QString>> listOfEntries;
};

#endif // !CUSTOMTABLEMODEL_H
