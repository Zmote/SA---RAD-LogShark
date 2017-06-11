#ifndef RT_LOGWINDOW_H
#define RT_LOGWINDOW_H
#include "ui_RT_LogWindow.h"
#include "RT_LogWindow_Modell.h"
#include "RT_Client.h"

/**
 * \class RT_LogWindow
 * \brief Window class for logs in windowed mode
 * \author Zafer Dogan, <a href="mailto:zdogan@hsr.ch">Zafer Dogan</a>
 * \version 1.4
 * \since 1.1
 */
class RT_LogWindow : public QMainWindow {
	Q_OBJECT
public:
	RT_LogWindow(RT_Client & client, bool pIsIndependent);
	~RT_LogWindow();
	void closeEvent(QCloseEvent * event) override;
public slots:
	void hideWindow(QString tableName);
	void showWindow(QString tableName);
	void closeWindow(QString tableName);

	void activeCheckBoxClicked();
	void clientStateComboBoxChanged(int index);
	void newestOnTopCheckBoxClicked() const;
	void scrollToBottomCheckBoxClicked() const;
	void tabModeRadioClicked();
	void windowModeRadioClicked() const;
	void exportButtonClicked();
	void freezeButtonClicked() const;
	void freezeAllButtonClicked();
	void changeFreezeState(bool val) const;
	void minimizeButtonClicked();
	void minimizeAllButtonClicked();
	void filterInputTextChanged(QString searchTerm);
	void inputFilterEnterPressed();
	void clearTable() const;
	void arrangeWindowsTriggered();
	void handleTableClicked(const QString & logInput) const;
signals:
	void minimizeAll();
	void freezeAll();
	void unFreezeAll();
	void arrangeWindows();
	/**
	 * \brief Signal to refresh client/group list
	 * \param clientName Name of client to be updated
	 */
	void refresh(QString clientName) const;
	/**
	 * \brief Signal to prepare signal to log in main window
	 * \param fileName Name of file to log to
	 * \param logs Logs to put into fille
	 * \param toFile clientState toFile
	 * \param toRingFile clientState toRingFile
	 * \param toSharedFile clientState toSharedFile
	 * \param sharedFileName clientState sharedFileName
	 */
	void prepareSignalToFileLog(const QString& fileName, const QList<QList<QString>>& logs, bool toFile, bool toRingFile, bool toSharedFile, const QString& sharedFileName);
	/**
	 * \brief Signals main window to close log window
	 * \param tableName Name of table \ clientName to close
	 */
	void logWindowClosed(QString tableName);
	void signalClientActiveState(int pClientId, bool pIsActive);
private:
	Ui::MainWindow ui;
	RT_LogWindow_Modell modell;
};
#endif // !RT_LOGWINDOW_H
