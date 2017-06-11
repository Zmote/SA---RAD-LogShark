#ifndef COMMONVIEWUTILS_H
#define COMMONVIEWUTILS_H

#include <QStandardItem>
#include "RT_Client.h"
#include <QTableView>

/*!
 * \brief Common functionalities (free functions) related to views
 * \author Zafer Dogan, <a href="mailto:zdogan@hsr.ch">Zafer Dogan</a>
 * \version 1.4
 * \since 1.0
 */
namespace CommonViewUtils {
	/*!
	 * \brief Sets up a \ref QTableview
	 * \param tablename Name of table to be set
	 * \return newly constructed \ref QTableView
	 */
	QTableView * setupTable(QString tablename);
	/*!
	 * \brief Initializes \ref QTabWidget
	 * \param tabWidget Pointer to \ref QTabWidget to initalize
	 * \return initialized \ref QTabWidget
	 */
	QTabWidget * initTabWidget(QTabWidget * tabWidget);
	/*!
	 * \brief Resets passed Client to defaults
	 * \param client client to reset
	 */
	void resetClient(RT_Client & client);
	/*!
	 * \brief Prepares route state from \ref RT_Client client
	 * \param client client from which to derive route states
	 * \return Routestate string
	 */
	QString prepareRouteState(const RT_Client& client);
	/*!
	 * \brief 
	 * \param client client, according to which to set the icon
	 * \param activeItem \ref QStandardItem for which the Icon is to be set
	 * \param tickImage Image for Tick
	 * \param crossImage Image for Cross
	 */
	void prepareIcon(const RT_Client& client, QStandardItem* activeItem, const QPixmap& tickImage, const QPixmap& crossImage);
	/*!
	 * \brief Resets the columns of a client's table
	 * \param client \ref RT_Client client table, whose columns to reset
	 */
	void resetColumnWidths(RT_Client & client);
	/*!
	 * \brief 
	 * \param client \ref RT_Client client, from which list entry information is derrived
	 * \param tickImage Image for Tick
	 * \param crossImage Image for Cross
	 * \return list of QStandardItem's for groups/client list
	 */
	QList<QStandardItem*> prepareListEntry(const RT_Client& client, const QPixmap& tickImage, const QPixmap& crossImage);
}

#endif // !COMMONVIEWUTILS_H
