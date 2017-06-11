#ifndef CUSTOWINDOWMQTABWIDGET_H
#define CUSTOWINDOWMQTABWIDGET_H

#include <QTabWidget>
#include <QDragEnterEvent>

/*!
* \class CustomWindowQTabWidget
* \inherits QTabWidget
* Subclassed QTabWidget, to provide Drag & Drop functionalitites within
* independent floating windows of type \ref RT_LogWindow
* \brief CustomWindowQTabWidget
* \author Zafer Dogan, <a href="mailto:zdogan@hsr.ch">Zafer Dogan</a>
* \version 1.0
* \since 1.0
*/
class CustomWindowQTabWidget : public QTabWidget {
	Q_OBJECT
public:
	CustomWindowQTabWidget();
protected:
	/*!
	* Starts a Drag & Drop Operation when Middle or Right Mouse Button
	* is pressed, overrides \ref QWidget 's mousePressEvent
	* \since 1.0
	*
	* \param mouseEvent The mouse event of type \ref QMouseEvent
	*/
	void mousePressEvent(QMouseEvent * mouseEvent) override;
	/*!
	* Accepts a Drag & Drop Operation when Middle or Right Mouse Button
	* is pressed, overrides \ref QWidget 's dragEnterEvent
	* \since 1.0
	*
	* \param dragEvent The drag event of type \ref QDragEnterEvent
	*/
	void dragEnterEvent(QDragEnterEvent * dragEvent) override;
	void dropEvent(QDropEvent * dropEvent) override;
	void closeEvent(QCloseEvent * closeEvent) override;
signals:
	/*!
	* Signal definition, for signaling the owning window
	* of type \ref RT_LogWindow to hide itself during the Drag & Drop operation
	* Hide means minimize in this context
	* \param tableName Name of the table, according to which the Window to be hidden is identified
	*/
	void hideWindow(QString tableName);
	/*!
	* Signal definition, for signaling the owning window
	* of type \ref RT_LogWindow to show itself after an aborted Drag & Drop operation
	* \param tableName Name of the table, according to which the Window to be hidden is identified
	*/
	void showWindow(QString tableName);
};

#endif // !CUSTOWINDOWMQTABWIDGET_H
