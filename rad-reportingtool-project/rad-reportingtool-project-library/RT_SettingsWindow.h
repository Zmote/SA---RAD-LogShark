#ifndef RT_SETTINGSWINDOW_H
#define RT_SETTINGSWINDOW_H
#include "ui_RT_SettingsWindow.h"
#include <QDialog>
#include <QTreeView>
#include "RT_Main_Modell.h"

/*!
 * \class RT_SettingsWindow
 * \brief Window for Settings management
 * \author Zafer Dogan, <a href="mailto:zdogan@hsr.ch">Zafer Dogan</a>
 * \version 1.1
 * \since 1.4
 */
class RT_SettingsWindow:public QDialog
{
	Q_OBJECT

public:
	RT_SettingsWindow(RT_Main_Modell& pModell, QTreeView* pGroupList, QTreeView* pClientList, QWidget* parent = 0);
public slots:
	void saveTriggered();
	void cancelTriggered();
	void baseSaveLocationBrowserButtonClicked();
	void toFileSaveLocationBrowserButtonClicked();
	void toSharedSaveLocationBrowserButtonClicked();
	void toRingFileSaveLocationBrowserButtonClicked();
	bool checkPersistFileName();
	void persistSettingsCheckBoxClicked() const;
	void allowAutoRegistrationCheckBoxClicked() const;
	signals:
	void signalMasterRestart();
private:
	/**
	 * \brief Sets directory to the appropriate inputField
	 * \param inputField InputField to set file path to
	 */
	void setDirectory(QLineEdit* inputField);
	/**
	 * \brief Prepares clients to persist
	 */
	void prepareClients() const;
	/**
	 * \brief Prepares group clients to persist
	 */
	void prepareGroupClients() const;
	void preparePersistencytIndependent();

	RT_Main_Modell& modell;
	Ui::Form ui;
	QTreeView* groupList;
	QTreeView* clientList;
};

#endif //!RT_SETTINGSWINDOW_H
