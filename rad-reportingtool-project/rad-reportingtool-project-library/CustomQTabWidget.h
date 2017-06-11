#ifndef CUSTOMQTABWIDGET_H
#define CUSTOMQTABWIDGET_H

#include <QTabWidget>
#include <QWidget>
#include <QDragMoveEvent>

/*!
 * \class CustomQTabWidget
 *\inherits QTabWidget
 * Subclassed QTabWidget, to provide Drag & Drop functionalitites within
 * the MainWindow's Tab Views
 * \brief CustomQTabWidget
 * \author Zafer Dogan, <a href="mailto:zdogan@hsr.ch">Zafer Dogan</a>
 * \version 1.2
 * \since 1.0
 */
class CustomQTabWidget : public QTabWidget {
	Q_OBJECT
public:
	explicit CustomQTabWidget(QWidget * parent = 0);
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
	/*!
	* Handles Drop Operations on this class,
	* overrides \ref QWidget 's dropEvent
	* \since 1.0
	*
	* \param dropEvent The drop event of type \ref QDropEvent
	*/
	void dropEvent(QDropEvent * dropEvent) override;
signals:
	/*!
	* Signal definition, for initiating the conversation from 
	* Main window Tab to independent Floating Window
	* \since 1.0
	*
	* \param tableName Name of the table, that is to be converted to a floating Window
	* \param startPosition Location Information of the Mouse on drop, for repositioning where the new window is started
	*/
	void floatWindowInitiated(QString tableName, QPoint startPosition);
	/*!
	* Signal definition, for initiating the conversation from
	* Floating Window to a Tab in the Main Window of the Application
	* \since 1.0
	*
	* \param tableName Name of the table, that is to be converted to a tab
	*/
	void tabWindowInitiated(QString tableName);
	/*!
	* Signal definition, for signaling the \RT_LogWindow to close
	* themselves when the drag and drop operation from floating window
	* to tab in the Main Window was successful
	* \since 1.0
	*
	* \param tableName Name of the table, to identify which \ref RT_LogWindow to close
	*/
	void dragFinishedWithSuccess(QString tableName);
	/*!
	 * \brief signals the view update mechanism to adjust its updating interval
	 */
	void updateTimer();
};

#endif // !CUSTOMQTABWIDGET_H
