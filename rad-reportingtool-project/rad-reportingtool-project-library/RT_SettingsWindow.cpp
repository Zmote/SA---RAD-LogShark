#include "RT_SettingsWindow.h"
#include "RT_Settings.h"
#include "RT_Main_Modell.h"
#include <QFileDialog>
#include <QInputDialog>
#include <QSortFilterProxyModel>
#include <QMessageBox>

RT_SettingsWindow::RT_SettingsWindow(RT_Main_Modell& pModell, QTreeView* pGroupList, QTreeView* pClientList, QWidget* parent)
	: QDialog(parent), modell(pModell), groupList(pGroupList), clientList(pClientList)
{
	ui.setupUi(this);
	if(!RT_Settings::currentConfigurationFileName().isEmpty())
	{
		ui.persistSettingsCheckBox->setChecked(true);
		persistSettingsCheckBoxClicked();
		ui.globalLogSettingsCheckBox->setChecked(RT_Settings::persistGlobalSettings);
		ui.viewSettingsCheckBox->setChecked(RT_Settings::persistViewSettings);
		ui.persistFileNameInput->setText(RT_Settings::currentConfigurationFileName());
	}
	ui.configurationNameLabel->setText(RT_Settings::currentConfigurationFileName());
	ui.baseSaveLocationInput->setText(RT_Settings::baseFileSaveLocation());
	ui.toFileSaveLocationInput->setText(RT_Settings::toFileSaveLocation());
	ui.toSharedSaveLocationInput->setText(RT_Settings::toSharedFileSaveLocation());
	ui.toRingFileSaveLocationInput->setText(RT_Settings::toRingFileSaveLocation());
	ui.logBufferLimitInput->setText(QString::number(RT_Settings::logBufferLimit()));
	ui.messageBufferLimitInput->setText(QString::number(RT_Settings::messageBufferLimit()));
	ui.ringBufferLimitInput->setText(QString::number(RT_Settings::ringBufferLimit()));
	ui.allowAutoRegistrationCheckBox->setChecked(RT_Settings::autoRegistrationAllowed());
	ui.masterHostInput->setText(RT_Settings::masterHost);
	ui.masterPortInput->setText(QString::number(RT_Settings::masterPort));
}

void RT_SettingsWindow::prepareClients() const
{
	if (ui.allClientsRadio->isChecked())
	{
		RT_Settings::clients = modell.getClients();
	}
	if (ui.onlySelectedClientsRadio->isChecked())
	{
		const QStandardItemModel* clientModel = modell.getClientsModel();
		const QSortFilterProxyModel* proxyModel = static_cast<QSortFilterProxyModel*>(clientList->model());
		const QModelIndexList selectedClientList = clientList->selectionModel()->selectedRows();
		QList<RT_Client> selectedClients{};
		for (const QModelIndex& index : selectedClientList)
		{
			const QModelIndex& sourceIndex = proxyModel->mapToSource(index);
			const QStandardItem* clientNameItem = clientModel->item(sourceIndex.row(), 2);
			selectedClients.append(modell.getClient(clientNameItem->text()));
		}
		RT_Settings::clients = selectedClients;
	}
	if (ui.onlyActiveClientsRadio->isChecked())
	{
		QList<RT_Client> activeClients{};
		for (RT_Client& client : modell.getClients())
		{
			if (client.active()) activeClients.append(client);
		}
		RT_Settings::clients = activeClients;
	}
	if (ui.noClientsRadio->isChecked()) RT_Settings::clients.clear();
}

void RT_SettingsWindow::prepareGroupClients() const
{
	if (ui.allClientsRadio->isChecked())
	{
		RT_Settings::groups = modell.getGroupClients();
	}
	if (ui.onlySelectedClientsRadio->isChecked())
	{
		const QStandardItemModel* groupClientModel = modell.getGroupsModel();
		const QSortFilterProxyModel* proxyModel = static_cast<QSortFilterProxyModel*>(groupList->model());
		const QModelIndexList selectedGroupClientList = groupList->selectionModel()->selectedRows();
		QList<RT_Client> selectedGroupClients{};
		for (const QModelIndex& index : selectedGroupClientList)
		{
			const QModelIndex& sourceIndex = proxyModel->mapToSource(index);
			const QStandardItem* groupClientNameItem = groupClientModel->item(sourceIndex.row(), 2);
			selectedGroupClients.append(modell.getGroupClient(groupClientNameItem->text()));
		}
		RT_Settings::groups = selectedGroupClients;
	}
	if (ui.onlyActiveGroupsRadio->isChecked())
	{
		QList<RT_Client> activeGroupClients{};
		for (RT_Client& groupClient : modell.getGroupClients())
		{
			if (groupClient.active()) activeGroupClients.append(groupClient);
		}
		RT_Settings::groups = activeGroupClients;
	}
	if (ui.noGroupsRadio->isChecked()) RT_Settings::groups.clear();
}

void RT_SettingsWindow::preparePersistencytIndependent()
{
	RT_Settings::baseFileSaveLocation(ui.baseSaveLocationInput->text());
	RT_Settings::toFileSaveLocation(ui.toFileSaveLocationInput->text());
	RT_Settings::toSharedFileSaveLocation(ui.toSharedSaveLocationInput->text());
	RT_Settings::toRingFileSaveLocation(ui.toRingFileSaveLocationInput->text());

	bool ok = false;
	int settingsLogBufferLimit = ui.logBufferLimitInput->text().toInt(&ok);
	if (ok) RT_Settings::logBufferLimit(settingsLogBufferLimit);
	ok = false;
	int settingsMessageBufferLimit = ui.messageBufferLimitInput->text().toInt(&ok);
	if (ok) RT_Settings::messageBufferLimit(settingsMessageBufferLimit);

	ok = false;
	int settingsRingBufferLimit = ui.ringBufferLimitInput->text().toInt(&ok);
	if (ok) RT_Settings::ringBufferLimit(settingsRingBufferLimit);

	bool masterRestartNeeded = false;
	QString masterHost = ui.masterHostInput->text();
	if(masterHost != RT_Settings::masterHost)
	{
		masterRestartNeeded = true;
		RT_Settings::masterHost = masterHost;
	}
	ok = false;
	int port = ui.masterPortInput->text().toInt(&ok);
	if (ok) {
		if(port != RT_Settings::masterPort)
		{
			masterRestartNeeded = true;
			RT_Settings::masterPort = port;
		}
	}
	if (masterRestartNeeded) emit signalMasterRestart();

	RT_Settings::autoRegistrationAllowed(ui.allowAutoRegistrationCheckBox->isChecked());
}

bool RT_SettingsWindow::checkPersistFileName()
{
	if (ui.persistFileNameInput->text().isEmpty())
	{
		bool ok;
		QString fileName = QInputDialog::getText(this, tr("Please specify filename for persistent file"), tr("Persistent File Name Input"), QLineEdit::Normal, "", &ok);
		if (ok)
		{
			if (!fileName.isEmpty())
			{
				ui.persistFileNameInput->setText(fileName);
			}
			else
			{
				return false;
			}
		}
		return ok;
	}
	return true;
}

void RT_SettingsWindow::persistSettingsCheckBoxClicked() const
{
	bool isPersist = ui.persistSettingsCheckBox->isChecked();
	ui.groupSettingsBox->setEnabled(isPersist);
	ui.clientSettingsBox->setEnabled(isPersist);
	ui.persistFileNameInput->setEnabled(isPersist);
	ui.persistFileNameLabel->setEnabled(isPersist);
	ui.globalLogSettingsLabel->setEnabled(isPersist);
	ui.globalLogSettingsCheckBox->setEnabled(isPersist);
	ui.viewSettingsLabel->setEnabled(isPersist);
	ui.viewSettingsCheckBox->setEnabled(isPersist);
}

void RT_SettingsWindow::allowAutoRegistrationCheckBoxClicked() const
{
	RT_Settings::autoRegistrationAllowed(ui.allowAutoRegistrationCheckBox->isChecked());
}

void RT_SettingsWindow::saveTriggered()
{
	if (ui.persistSettingsCheckBox->isChecked())
	{
		if (checkPersistFileName())
		{
			preparePersistencytIndependent();
			prepareClients();
			prepareGroupClients();
			RT_Settings::persistGlobalSettings = ui.globalLogSettingsCheckBox->isChecked();
			RT_Settings::persistViewSettings = ui.viewSettingsCheckBox->isChecked();
			RT_Settings::currentConfigurationFileName(ui.persistFileNameInput->text());
			RT_Settings::save();
			this->close();
		}
		else
		{
			QMessageBox* messageBox = new QMessageBox(this);
			messageBox->setWindowTitle("Error");
			messageBox->setText("You need to define a filename to persist to.\nPlease try again.");
			messageBox->show();
		}
	}
	else
	{
		preparePersistencytIndependent();
		this->close();
	}
}

void RT_SettingsWindow::cancelTriggered()
{
	this->close();
}

void RT_SettingsWindow::setDirectory(QLineEdit* inputField)
{
	QString filePath = QFileDialog::getExistingDirectory(this, tr("Select Directory"), RT_Settings::baseFileSaveLocation());
	if (!filePath.isEmpty())
	{
		inputField->setText(filePath);
	}
}

void RT_SettingsWindow::baseSaveLocationBrowserButtonClicked()
{
	setDirectory(ui.baseSaveLocationInput);
}

void RT_SettingsWindow::toFileSaveLocationBrowserButtonClicked()
{
	setDirectory(ui.toFileSaveLocationInput);
}

void RT_SettingsWindow::toSharedSaveLocationBrowserButtonClicked()
{
	setDirectory(ui.toSharedSaveLocationInput);
}

void RT_SettingsWindow::toRingFileSaveLocationBrowserButtonClicked()
{
	setDirectory(ui.toRingFileSaveLocationInput);
}
