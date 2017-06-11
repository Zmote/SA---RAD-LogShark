#include "RT_LogWindow.h"
#include <QTabWidget>
#include <QDebug>
#include "CustomWindowQTabWidget.h"
#include "CommonViewUtils.h"
#include "CustomTableModel.h"
#include "RT_LogFilter.h"
#include "CustomFilterProxyModel.h"
#include <QInputDialog>
#include <qdir.h>
#include <QFileDialog>
#include <QUuid>
#include "RT_Settings.h"
#include <QMessageBox>

RT_LogWindow::RT_LogWindow(RT_Client & pClient, bool pIsIndependent) : modell{pClient, pIsIndependent} {
	ui.setupUi(this);
	QTabWidget * tabWidget;
	if (pIsIndependent) {
		tabWidget = new QTabWidget(this);
		ui.fw_clientStateComboBox->setVisible(false);
		ui.fw_newestOnTopCheckBox->setVisible(false);
		ui.fw_scrollToBottomCheckBox->setVisible(false);
		ui.fw_tabModeRadio->setVisible(false);
		ui.fw_windowModeRadio->setVisible(false);
		ui.fw_activeCheckBox->setVisible(false);
		ui.fw_freezeAllButton->setVisible(false);
		ui.fw_freezeButton->setVisible(false);
		ui.fw_freezeState->setVisible(false);
		ui.exportLine->setVisible(false);
		ui.activeClientStateLine->setVisible(false);
		ui.scrollToBottomTabModeLine->setVisible(false);
		ui.clientStateNewestOnTopLine->setVisible(false);
		ui.freezeUnfreezeLine->setVisible(false);
	}
	else {
		tabWidget = new CustomWindowQTabWidget();
		connect(static_cast<CustomWindowQTabWidget *>(tabWidget), &CustomWindowQTabWidget::hideWindow, this, &RT_LogWindow::hideWindow);
		connect(static_cast<CustomWindowQTabWidget *>(tabWidget), &CustomWindowQTabWidget::showWindow, this, &RT_LogWindow::showWindow);
		if(pClient.getClientId() == RT_Constants::GROUP_ID || pClient.getClientId() == RT_Constants::GLOBAL_ID)
		{
			ui.fw_clientStateComboBox->removeItem(ui.fw_clientStateComboBox->findText(RT_Constants::TO_PARENT));
			if(pClient.getClientId() == RT_Constants::GLOBAL_ID)
			{
				ui.fw_clientStateComboBox->removeItem(ui.fw_clientStateComboBox->findText(RT_Constants::TO_GLOBAL));
				ui.fw_clientStateComboBox->removeItem(ui.fw_clientStateComboBox->findText(RT_Constants::LIVE));
			}
		}
		ui.fw_newestOnTopCheckBox->setChecked(pClient.newestOnTop());
		ui.fw_scrollToBottomCheckBox->setChecked(pClient.scrollToBottom());
		ui.fw_tabModeRadio->setChecked(!pClient.windowed());
		ui.fw_windowModeRadio->setChecked(pClient.windowed());
		ui.fw_activeCheckBox->setChecked(pClient.active());
		QString stateToFind{ RT_Constants::EMPTY_STATE };
		if (pClient.live()) stateToFind = RT_Constants::LIVE;
		if (pClient.toFile()) stateToFind = RT_Constants::TO_FILE;
		if (pClient.toRingFile()) stateToFind = RT_Constants::TO_RING_FILE;
		if (pClient.toSharedFile()) stateToFind = RT_Constants::TO_SHARED_FILE;
		if (pClient.toParent()) stateToFind = RT_Constants::TO_PARENT;
		if (pClient.toGlobal()) stateToFind = RT_Constants::TO_GLOBAL;
		ui.fw_clientStateComboBox->setCurrentIndex(ui.fw_clientStateComboBox->findText(stateToFind));
	}
	ui.splitter->setStretchFactor(0, 4);
	ui.splitter->setStretchFactor(1, 1);
	ui.fw_freezeState->setStyleSheet("background-color:green");
	CommonViewUtils::initTabWidget(tabWidget);
	tabWidget->addTab(pClient.getTable(), pClient.getClientName());
	this->setWindowTitle(pClient.getClientName());
	ui.mainContentGrid->addWidget(tabWidget);
}

RT_LogWindow::~RT_LogWindow()
{
}

void RT_LogWindow::closeEvent(QCloseEvent * event)
{
	//Set parent to nullptr or table will be deleted when window is deconstructed
	modell.client.getTable()->setParent(nullptr);
	if (modell.isIndependent)
	{
		delete &modell.client;
	}
	emit logWindowClosed(modell.client.getClientName());
}

void RT_LogWindow::hideWindow(QString tableName)
{
	if (this->windowTitle() == tableName) {
		this->showMinimized();
	}
}

void RT_LogWindow::showWindow(QString tableName)
{
	if (this->windowTitle() == tableName) {
		this->showNormal();
		this->raise();
	}
}

void RT_LogWindow::closeWindow(QString tableName)
{
	//This function is called when window goes to tab mode
	if (this->windowTitle() == tableName) {
		modell.client.windowed(false);
		this->close();
	}
}

void RT_LogWindow::activeCheckBoxClicked()
{
	modell.client.active(ui.fw_activeCheckBox->isChecked());
	emit signalClientActiveState(modell.client.getClientId(), modell.client.active());
}

void RT_LogWindow::clientStateComboBoxChanged(int index)
{
	QString state = ui.fw_clientStateComboBox->currentText();
	bool live = state == RT_Constants::LIVE ? true : false;
	bool toFile = state == RT_Constants::TO_FILE ? true : false;
	bool toRingFile = state == RT_Constants::TO_RING_FILE ? true : false;
	bool toSharedFile = state == RT_Constants::TO_SHARED_FILE ? true : false;
	QString toSharedFileName{ "" };
	bool toParent = state == RT_Constants::TO_PARENT ? true : false;
	bool toGlobal = state == RT_Constants::TO_GLOBAL ? true : false;

	if (toSharedFile)
	{
		bool ok;
		toSharedFileName = QInputDialog::getText(this, tr("Input Shared File Dialog"), tr("Shared File Name"), QLineEdit::Normal, QDir::home().dirName(), &ok);
		if (toSharedFileName.isEmpty()) toSharedFileName = QUuid::createUuid().toString();
		toSharedFileName.prepend(RT_Constants::SHAREDFILE_PREFIX);
		if (!ok)
		{
			toSharedFile = false;
			ui.fw_clientStateComboBox->setCurrentIndex(0);
		}
	}

	modell.client.live(live);
	modell.client.toFile(toFile);
	modell.client.toRingFile(toRingFile);
	modell.client.toSharedFile(toSharedFile);
	modell.client.setSharedFileName(toSharedFileName);
	modell.client.toParent(toParent);
	modell.client.toGlobal(toGlobal);
}

void RT_LogWindow::newestOnTopCheckBoxClicked() const
{
	modell.client.clearModel();
	modell.client.newestOnTop(ui.fw_newestOnTopCheckBox->isChecked());
}

void RT_LogWindow::scrollToBottomCheckBoxClicked() const
{
	modell.client.scrollToBottom(ui.fw_scrollToBottomCheckBox->isChecked());
}

void RT_LogWindow::tabModeRadioClicked()
{
	modell.client.windowed(false);
	this->close();
}

void RT_LogWindow::windowModeRadioClicked() const
{
	modell.client.windowed(ui.fw_windowModeRadio->isChecked());
}

void RT_LogWindow::exportButtonClicked()
{
	const QString filename = QFileDialog::getSaveFileName(this, tr("Save File"), RT_Settings::baseFileSaveLocation(), "Log files (*.txt*);;");
	if(!filename.isEmpty())
	{
		CustomFilterProxyModel * proxyModel = static_cast<CustomFilterProxyModel*>(modell.client.getTable()->model());
		emit prepareSignalToFileLog(filename, proxyModel->getProxyModelContent(), false, false, false, "");
	}
}

void RT_LogWindow::freezeButtonClicked() const
{
	changeFreezeState(modell.client.getTable()->updatesEnabled());
}

void RT_LogWindow::freezeAllButtonClicked()
{
	if(modell.client.getTable()->updatesEnabled())
	{
		emit freezeAll();
	}else
	{
		emit unFreezeAll();
	}
}

void RT_LogWindow::changeFreezeState(bool val) const
{
	if(val)
	{
		ui.fw_freezeState->setStyleSheet("background-color:red");
		modell.client.getTable()->setUpdatesEnabled(!val);
	}else
	{
		modell.client.getTable()->setUpdatesEnabled(!val);
		ui.fw_freezeState->setStyleSheet("background-color:green");
	}
}

void RT_LogWindow::minimizeButtonClicked()
{
	this->showMinimized();
}

void RT_LogWindow::minimizeAllButtonClicked()
{
	emit minimizeAll();
}

void RT_LogWindow::filterInputTextChanged(QString searchTerm)
{
	if (!searchTerm.isEmpty())
	{
		RT_LogFilter filter{ searchTerm, ui.fw_caseSensitiveCheckBox->isChecked()};
		if (filter.isValid())
		{
			ui.fw_inputFilter->setStyleSheet("#fw_inputFilter{background-color:#ccffcc}");
		}
		else
		{
			ui.fw_inputFilter->setStyleSheet("#fw_inputFilter{background-color:#ff9999}");
		}
		modell.filter = filter;
	}
	else
	{
		modell.filter = RT_LogFilter("");
		ui.fw_inputFilter->setStyleSheet("");
	}
}

void RT_LogWindow::inputFilterEnterPressed()
{
	if(modell.filter.isValid())
	{
		CustomFilterProxyModel * proxyModel = static_cast<CustomFilterProxyModel*>(modell.client.getTable()->model());
		proxyModel->clear();
		proxyModel->setFilter(modell.filter);
		proxyModel->invalidate();
		ui.fw_inputFilter->setStyleSheet("#fw_inputFilter{background-color:#b8dff2} #fw_inputFilter:hover{border: 1px solid gray;background-color:#b8dff2}");
	}else
	{
		QMessageBox* messageBox = new QMessageBox(this);
		messageBox->setWindowTitle("Invalid Filter");
		messageBox->setText("Current Filter is invalid. Please adjust your filter until the background lits up green");
		messageBox->show();
	}
}

void RT_LogWindow::clearTable() const
{
	modell.client.clearModel();
}

void RT_LogWindow::arrangeWindowsTriggered()
{
	emit arrangeWindows();
}

void RT_LogWindow::handleTableClicked(const QString & logInput) const
{
	ui.fw_logDetailInput->setPlainText(logInput);
}

