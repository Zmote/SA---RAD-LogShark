#ifndef RT_MAIN_H
#define RT_MAIN_H

#include <QtWidgets/QFileDialog>
#include <functional>
#include <ReportingTool/ProxyProtocol/Messages/RegisterClientMsg.hpp>
#include <QThread>

#include "ui_rt_main.h"
#include "RT_Main_Modell.h"
#include "RT_LogWindow.h"
#include "RT_ToFileWorker.h"

class RT_Main : public QMainWindow
{
	Q_OBJECT
public slots:
	/***********************/
	/*** GLOBAL SETTINGS ***/
	/***********************/

	/*** MESSAGE STATE SLOTS ***/
	/**
	* \brief Tells Client to enable/disable info logs
	*/
	void enableInfoCheckBoxClicked() const;
	/**
	 * \brief Tells Client to enable/disable warning logs
	 */
	void enableWarningCheckBoxClicked() const;
	/**
	* \brief Tells Client to enable/disable error logs
	*/
	void enableErrorCheckBoxClicked() const;
	/**
	* \brief Tells Client to enable/disable exception logs
	*/
	void enableExceptionCheckBoxClicked() const;
	/**
	* \brief Tells Client to enable/disable fatal logs
	*/
	void enableFatalCheckBoxClicked() const;
	/**
	* \brief Tells Client to enable/disable binary logs
	*/
	void enableBinaryCheckBoxClicked() const;

	/*** STAMP SLOTS ***/
	/**
	* \brief Enables/Disables visibility of Date column
	*/
	void useDateStampCheckBoxClicked() const;
	/**
	 * \brief Enables/Disables visibility of Time column
	 */
	void useTimeStampCheckBoxClicked() const;
	/**
	* \brief Enables/Disables visibility of Group column
	*/
	void useGroupStampCheckBoxClicked() const;
	/**
	* \brief Enables/Disables visibility of Client column
	*/
	void useClientStampCheckBoxClicked() const;
	/**
	* \brief Enables/Disables visibility of Kind column
	*/
	void useMessageHeaderCheckBoxClicked() const;
	/**
	* \brief Enables/Disables visibility of Content column
	*/
	void useContentStampCheckBoxClicked() const;
	
	/*** BUFFER TRIGGER SLOTS***/
	/**
	* \brief Enables/Disables buffering for info messages
	*/
	void infoMessageCheckBoxClicked() const;
	/**
	 * \brief Enables/Disables buffering for warning messages
	 */
	void warningMessageCheckBoxClicked() const;
	/**
	* \brief Enables/Disables buffering for error messages
	*/
	void errorMessageCheckBoxClicked() const;
	/**
	* \brief Enables/Disables buffering for exception messages
	*/
	void exceptionMessageCheckBoxClicked() const;
	/**
	* \brief Enables/Disables buffering for fatal messages
	*/
	void fatalMessageCheckBoxClicked() const;
	/**
	* \brief Adjusts Main Spliter, when client and group list visibility
	* is turned off
	*/
	void adjustMainSplitter() const;

	/***********************/
	/*** VIEW SETTINGS ***/
	/***********************/

	void showGroupSection() const;
	void showClientSection() const;

	/*** CONTENT SECTION ***/

	/**
	 * \brief Enables/Disables visibility of Filter expression area 
	 */
	void showFilterArea() const;
	/**
	 * \brief Enables/Disables visibility of Log Detail Input Area
	 */
	void showLogDetailCheckBoxClicked() const;

	/*** ACTIONS ***/
	//File

	/**
	 * \brief Opens up a File Dialog to choose file to import
	 * and imports that file afterwards to seperate, independent log window 
	 */
	void importFileTriggered();
	/**
	 * \brief Opens up a File Dialog to choose location where to output log file
	 * and after choosing a location, saves current log view to chosen location
	 */
	void exportFileTriggered();
	void clearClientsAndGroups();
	/**
	 * \brief Refreshes Application state, like setting view settings
	 * global log settings etc. according to loaded configuration file.
	 * This function will also initiate log windows or tabs if clients are
	 * in that particular state
	 */
	void refreshApplicationState();
	void initMasterRestart();
	void rapplicationInitialized();
	void restartMasterTriggered();
	/**
	 * \brief Opens up a File Dialog, from where the configuration file can be chosen
	 * and upon finishing, sets that configuration for the application
	 */
	void loadConfigTriggered();
	/**
	 * \brief Calls QApplication::quit to close the application
	 */
	static void closeAppTriggered();

	//Edit
	void selectAllGroups() const;
	void selectAllClients() const;
	void selectAllActive() const;
	void freezeAllTriggered() const;
	void unfreezeAllTriggered() const;
	void clearCurrentTableTriggered() const;
	void clearAllTablesTriggered() const;
	void clearAllMergeViews();

	//View
	void showInactiveClientsTriggered();
	void showBinaryClientsTriggered();
	void showTextClientsTriggered();
	void arrangeWindowsTriggered();
	void resetSelectedClientsTriggered();
	void resetAllClientsTriggered();
	void assignColor();
	void minimizeAllTriggered() const;
	void maximizeAllTriggered();
	void closeAllTabsTriggered();
	void closeAllWindows();

	//System
	/**
	 * \brief Opens RT_SettingsWindow for Settings manipulation 
	 */
	void settingsTriggered();
	/**
	 * \brief Restores values of RT_Settings to its default values
	 * Also, refreshes application state.
	 */
	void restoreDefaultSettings();

	//About
	void aboutTriggered();
	static void helpTriggered();

	/*** GLOBAL SLOTS ***/
	int setupClientTabIcon(RT_Client& client) const;
	void globalSearchTermChanged(QString searchTerm);
	void executeFilterClicked();
	void clientListSearchTextChanged(QString searchTerm) const;
	void groupListSearchTextChanged(QString searchTerm) const;
	void handleGroupListPressed(QModelIndex index);
	void handleGroupListSelectionChanged();
	void setCurrentClientName(int selectionAmount, const RT_Client& client) const;
	void handleClientListPressed(QModelIndex index);
	void registerClient(const REP::PROTO::RegisterClientMsg& msg);
	void handleClientListSelectionChanged();

	/*** CUSTOM SLOTS ***/
	void minimizeAll() const;
	void freezeAll() const;
	void unFreezeAll() const;
	/**
	 * \brief Handles a click event on the client table
	 * Retrieves clicked index and outputs row information to log detail input area
	 * \param index Index of clicked row of client table
	 */
	void handleTableClicked(const QModelIndex & index);
	/**
	 * \brief Handles a selection event on the client table
	 * \param selected Current selections
	 * \param deselected Previous selections
	 */
	void handleTableSelectionChanged(const QItemSelection& selected, const QItemSelection & deselected);
	void createLogWindow(QString tableName, QPoint startPosition);
	void createTabWindow(QString tableName);
	/**
	 * \brief Handles client state updates for selected clients
	 * \param function Function that contains algorithm to be executed for the selected clients
	 */
	void handleClientsUpdate(std::function<void(RT_Client&)> function);
	/**
	 * \brief Handles group client state updates for selected group clients
	 * \param function Function that contains algorithm to be executed for the selected group clients
	 */
	void handleGroupClientsUpdate(std::function<void(RT_Client&)> function);
	/**
	 * \brief Similar to handleGroupClientsUpdate, this function also refreshes the group client state view
	 * \param function Function that contains algorithm to be executed for the selected group clients
	 */
	void updateGroupClients(std::function<void(RT_Client&)> function);
	void closeTabClicked(int index);
	void logWindowClosed(QString tableName);
	void independentLogWindowClosed(QString tableName);
	/**
	 * \brief Processes logs read from a file and assigns them to appropriate table
	 * \param readLogs Logs read from file
	 * \param tableName Name of table to be created for read logs, usually filename
	 */
	void processReadLogs(const QList<QList<QString>> & readLogs, const QString & tableName);
	void closeEvent(QCloseEvent * event) override;
	
	/*** GROUP STATE SLOTS ***/
	void groupStateComboBoxChanged(int currentIndex);
	void activeCheckBoxClicked();
	void newestOnTopCheckBoxClicked();
	void tabModeRadioClicked();
	void windowModeRadioClicked();
	void scrollToBottomCheckBoxClicked();

	/*** CLIENT STATE SLOTS ***/
	void clientsStateComboBoxChanged(int currentIndex);
	void clientActiveCheckBoxClicked();
	void updateState(QString state, bool isGroup);
	void clientNewestOnTopCheckBoxClicked();
	void clientTabModeRadioClicked();
	void clientWindowModeRadioClicked();
	void registerGroupClient(QString mergeViewName);
	void clientScrollToBottomCheckBoxClicked();

	/**
	 * \brief Adjusts Update Signal interval for client logs
	 */
	void adjustUpdateInterval() const;
	void initSignalClientActiveState(int pClientId, bool pIsActive);

	/*** LOGGING RELATED SLOTS***/
	void registerClientLog(const REP::PROTO::RegisterClientMsg & msg);
	/**
	 * \brief Slots that is called after \ref RT_CaptureWorker receives signal to update
	 * \param clientName Name of client logs belong to
	 * \param rows logs prepared as rows for client table
	 */
	void handleProcessedLogs(const QString& clientName, const QList<QList<QString>>& rows);
	static bool isGroup(const RT_Client& client);
	static bool isGlobal(const RT_Client& client);
	/**
	 * \brief Handles logs arriving from \ref RT_CaptureWorker and assigns them to the appropriate client/group table
	 * \param client client logs belong to
	 * \param logs processed logs
	 */
	void handleClientLog(RT_Client& client, const QList<QList<QString>>& logs);
	void prepareSignalToFileLog(const QString& fileName, const QList<QList<QString>>& logs, bool toFile = false, 
		bool toRingFile = false, bool toSharedFile = false, const QString& sharedFileName = "");
	signals:
	void windowCloseRequested(QString windowName);
	void signalOpenFileTriggered(const QString & fileName);
	void restartMaster();
	void signalUpdateClientActivestate(int clientId, bool pIsActive);
public:
	explicit RT_Main(QWidget *parent = nullptr);
	~RT_Main();

	void setupFileThread();
	void setupMainConnections();
	void setApplicationOutput(QString text) const;
	void setupConfiguration();
	void setupGroupList() const;
	void setupClientList() const;
	void setupGlobalSettings() const;
	void setupViewSettings() const;
	void setupStatusBar() const;
	void setupMetaTypes() const;
	void setupContentArea() const;
	void initGlobalClient();
	void initStartUpValues();

	RT_Main_Modell & getModel();
	void setColumnVisibility(int column, bool val) const;
	/*!
	 * \brief Creates an independent window for imported file logs
	 * \param tableName name of table of the independent log window, usually filename
	 * \param table QTableView for the imported file log
	 */
	void createIndependentLogWindow(QString tableName, QTableView * table);
	void signalToFileLog(const QList<QList<QString>>& logs, const RT_Client& client);
	static QString getClientState(const RT_Client& client);
	void initTabBarWithClient(const RT_Client& client) const;
	void initTabBarWithGroupClient(const RT_Client & client) const;
	void updateClients(std::function<void(RT_Client&)> function);
	/*!
	 * \brief Refreshes Client View, ie. creates Tab or Window on active \ref RT_Client client
	 * \param client \ref RT_Client to refresh view for
	 */
	void refreshClientView(RT_Client & client);
	void refreshClientList() const;
	void refreshGroupList() const;
	bool subWindowExists(QString windowName) const;
	bool tabExists(QString tabName) const;
	int tabAt(QString tabName) const;
private:
	Ui::RT_MainClass ui;
	RT_Main_Modell modell;
	QMap<QString, RT_LogWindow *> subWindows{};
	QThread *  fromFileThread;
	RT_ToFileWorker * fromFileWorker;
	QPair<int, QList<QPointer<RT_ToFileWorker>>> toFileWorkers{};
	QPixmap tickImage{ QPixmap::fromImage(QImage(QApplication::applicationDirPath() + "/img/tick.png")) };
	QPixmap crossImage{ QPixmap::fromImage(QImage(QApplication::applicationDirPath() + "/img/cross.png")) };
	QPixmap radlogoImage{ QPixmap::fromImage(QImage(QApplication::applicationDirPath() + "/img/rmlogo.png")) };
	QLabel * currentSelectedClients = new QLabel("None");
	QLabel * currentClientGroup = new QLabel("None");
	QLabel * currentClientMergeView = new QLabel("None");
};

#endif // RT_MAIN_H
