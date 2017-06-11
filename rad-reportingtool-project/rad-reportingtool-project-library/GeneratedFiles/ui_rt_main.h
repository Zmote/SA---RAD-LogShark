/********************************************************************************
** Form generated from reading UI file 'rt_main.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RT_MAIN_H
#define UI_RT_MAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RT_MainClass
{
public:
    QAction *closeAppAction;
    QAction *importFileAction;
    QAction *actionExport;
    QAction *actionAbout;
    QAction *actionSettings;
    QAction *actionShow_Inactive_Clients;
    QAction *actionShow_Binary_Clients;
    QAction *actionShow_Text_Clients;
    QAction *actionHelp;
    QAction *actionArrange_Windows;
    QAction *actionSelect_All_Groups;
    QAction *actionSelect_All_Clients;
    QAction *actionSelect_All_active;
    QAction *actionReset_Selected_Clients;
    QAction *actionReset_All_Clients;
    QAction *actionAssign_Color;
    QAction *actionFreeze_All;
    QAction *actionUnfreeze_All;
    QAction *actionMinimize_All;
    QAction *actionMaximize_All;
    QAction *actionClear_Current_Table;
    QAction *actionClear_All_Tables;
    QAction *actionClose_All_Tabs;
    QAction *actionLoad_Configuration;
    QAction *actionClose_All_Windows;
    QAction *actionClear_All_MergeViews;
    QAction *actionRestore_Default_Settings;
    QAction *actionRestart_Master;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSplitter *mainSplitter;
    QSplitter *splitter;
    QWidget *layoutWidget2;
    QVBoxLayout *groupListLayout;
    QWidget *groupSearchWidget;
    QHBoxLayout *groupSearchInputLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *groupSearchInput;
    QWidget *groupSettingsWidget;
    QVBoxLayout *groupSettingsLayout;
    QHBoxLayout *groupSettingsTopSection;
    QCheckBox *activeCheckBox;
    QComboBox *groupStateComboBox;
    QHBoxLayout *groupSettingsMidSection;
    QCheckBox *newestOnTopCheckBox;
    QCheckBox *scrollToBottomCheckBox;
    QHBoxLayout *groupSettingsLowerSection;
    QRadioButton *tabModeRadio;
    QRadioButton *windowModeRadio;
    QTreeView *groupList;
    QWidget *layoutWidget1;
    QVBoxLayout *clientListLayout;
    QWidget *clientSearchWidget;
    QHBoxLayout *clientSearchInputLayout;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *clientInput;
    QWidget *clientSettingsWidget;
    QVBoxLayout *clientSettingsLayout;
    QHBoxLayout *clientSettingsTopSection;
    QCheckBox *clientActiveCheckBox;
    QComboBox *clientsStateComboBox;
    QHBoxLayout *clientSettingsMidSection;
    QCheckBox *clientNewestOnTopCheckBox;
    QCheckBox *clientScrollToBottomCheckBox;
    QHBoxLayout *clientSettingsLowerSection;
    QRadioButton *clientTabModeRadio;
    QRadioButton *clientWindowModeRadio;
    QTreeView *clientList;
    QSplitter *contentSplitter;
    QWidget *filterWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *inputField;
    QCheckBox *globalSearchCheckBox;
    QCheckBox *caseSensitiveCheckBox;
    QWidget *gridLayoutWidget;
    QGridLayout *mainContentLayout;
    QPlainTextEdit *logDetailInput;
    QWidget *mainGroupLayoutWidgetSettings;
    QGridLayout *rightPaneGrid;
    QToolBox *toolBox;
    QWidget *standardFiltersPage;
    QGroupBox *messageStatesBox;
    QCheckBox *enableInfoCheckBox;
    QCheckBox *enableWarningCheckBox;
    QCheckBox *enableErrorCheckBox;
    QCheckBox *enableExceptionCheckBox;
    QCheckBox *enableFatalCheckBox;
    QCheckBox *enableBinaryCheckBox;
    QGroupBox *stampsBox;
    QCheckBox *useMessageHeaderCheckBox;
    QCheckBox *useTimeStampCheckBox;
    QCheckBox *useDateStampCheckBox;
    QCheckBox *useContentStampCheckBox;
    QCheckBox *useGroupStampCheckBox;
    QCheckBox *useClientStampCheckBox;
    QGroupBox *bufferTriggersBox;
    QCheckBox *infoMessageCheckBox;
    QCheckBox *warningMessageCheckBox;
    QCheckBox *errorMessageCheckBox;
    QCheckBox *exceptionMessageCheckBox;
    QCheckBox *fatalMessageCheckBox;
    QGroupBox *groupBox;
    QPlainTextEdit *applicationOutput;
    QWidget *page;
    QGroupBox *contentSectionBox;
    QCheckBox *showLogDetailCheckBox;
    QCheckBox *showFilterAreaCheckBox;
    QPushButton *assignColorButton;
    QCheckBox *showGroupSectionCheckBox;
    QCheckBox *showClientSectionCheckBox;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuSystem;
    QMenu *menuEdit;
    QMenu *menuView;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RT_MainClass)
    {
        if (RT_MainClass->objectName().isEmpty())
            RT_MainClass->setObjectName(QStringLiteral("RT_MainClass"));
        RT_MainClass->resize(1247, 812);
        QIcon icon;
        icon.addFile(QStringLiteral(":/RT_Main/Resources/rmlogo.png"), QSize(), QIcon::Normal, QIcon::Off);
        RT_MainClass->setWindowIcon(icon);
        RT_MainClass->setStyleSheet(QLatin1String("QWidget#clientSettingsWidget{\n"
"background-color:white;\n"
"border-color:grey;\n"
"border-style:outset;\n"
"border-width:1px;\n"
"}\n"
"\n"
"QWidget#groupSettingsWidget{\n"
"background-color:white;\n"
"border-color:grey;\n"
"border-style:outset;\n"
"border-width:1px;\n"
"}"));
        RT_MainClass->setDocumentMode(false);
        closeAppAction = new QAction(RT_MainClass);
        closeAppAction->setObjectName(QStringLiteral("closeAppAction"));
        importFileAction = new QAction(RT_MainClass);
        importFileAction->setObjectName(QStringLiteral("importFileAction"));
        actionExport = new QAction(RT_MainClass);
        actionExport->setObjectName(QStringLiteral("actionExport"));
        actionAbout = new QAction(RT_MainClass);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionSettings = new QAction(RT_MainClass);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        actionShow_Inactive_Clients = new QAction(RT_MainClass);
        actionShow_Inactive_Clients->setObjectName(QStringLiteral("actionShow_Inactive_Clients"));
        actionShow_Binary_Clients = new QAction(RT_MainClass);
        actionShow_Binary_Clients->setObjectName(QStringLiteral("actionShow_Binary_Clients"));
        actionShow_Text_Clients = new QAction(RT_MainClass);
        actionShow_Text_Clients->setObjectName(QStringLiteral("actionShow_Text_Clients"));
        actionHelp = new QAction(RT_MainClass);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionArrange_Windows = new QAction(RT_MainClass);
        actionArrange_Windows->setObjectName(QStringLiteral("actionArrange_Windows"));
        actionSelect_All_Groups = new QAction(RT_MainClass);
        actionSelect_All_Groups->setObjectName(QStringLiteral("actionSelect_All_Groups"));
        actionSelect_All_Clients = new QAction(RT_MainClass);
        actionSelect_All_Clients->setObjectName(QStringLiteral("actionSelect_All_Clients"));
        actionSelect_All_active = new QAction(RT_MainClass);
        actionSelect_All_active->setObjectName(QStringLiteral("actionSelect_All_active"));
        actionReset_Selected_Clients = new QAction(RT_MainClass);
        actionReset_Selected_Clients->setObjectName(QStringLiteral("actionReset_Selected_Clients"));
        actionReset_All_Clients = new QAction(RT_MainClass);
        actionReset_All_Clients->setObjectName(QStringLiteral("actionReset_All_Clients"));
        actionAssign_Color = new QAction(RT_MainClass);
        actionAssign_Color->setObjectName(QStringLiteral("actionAssign_Color"));
        actionFreeze_All = new QAction(RT_MainClass);
        actionFreeze_All->setObjectName(QStringLiteral("actionFreeze_All"));
        actionUnfreeze_All = new QAction(RT_MainClass);
        actionUnfreeze_All->setObjectName(QStringLiteral("actionUnfreeze_All"));
        actionMinimize_All = new QAction(RT_MainClass);
        actionMinimize_All->setObjectName(QStringLiteral("actionMinimize_All"));
        actionMaximize_All = new QAction(RT_MainClass);
        actionMaximize_All->setObjectName(QStringLiteral("actionMaximize_All"));
        actionClear_Current_Table = new QAction(RT_MainClass);
        actionClear_Current_Table->setObjectName(QStringLiteral("actionClear_Current_Table"));
        actionClear_All_Tables = new QAction(RT_MainClass);
        actionClear_All_Tables->setObjectName(QStringLiteral("actionClear_All_Tables"));
        actionClose_All_Tabs = new QAction(RT_MainClass);
        actionClose_All_Tabs->setObjectName(QStringLiteral("actionClose_All_Tabs"));
        actionLoad_Configuration = new QAction(RT_MainClass);
        actionLoad_Configuration->setObjectName(QStringLiteral("actionLoad_Configuration"));
        actionClose_All_Windows = new QAction(RT_MainClass);
        actionClose_All_Windows->setObjectName(QStringLiteral("actionClose_All_Windows"));
        actionClear_All_MergeViews = new QAction(RT_MainClass);
        actionClear_All_MergeViews->setObjectName(QStringLiteral("actionClear_All_MergeViews"));
        actionRestore_Default_Settings = new QAction(RT_MainClass);
        actionRestore_Default_Settings->setObjectName(QStringLiteral("actionRestore_Default_Settings"));
        actionRestart_Master = new QAction(RT_MainClass);
        actionRestart_Master->setObjectName(QStringLiteral("actionRestart_Master"));
        centralWidget = new QWidget(RT_MainClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        mainSplitter = new QSplitter(centralWidget);
        mainSplitter->setObjectName(QStringLiteral("mainSplitter"));
        mainSplitter->setOrientation(Qt::Horizontal);
        splitter = new QSplitter(mainSplitter);
        splitter->setObjectName(QStringLiteral("splitter"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy1);
        splitter->setFrameShadow(QFrame::Plain);
        splitter->setLineWidth(1);
        splitter->setMidLineWidth(0);
        splitter->setOrientation(Qt::Vertical);
        splitter->setHandleWidth(0);
        layoutWidget2 = new QWidget(splitter);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        groupListLayout = new QVBoxLayout(layoutWidget2);
        groupListLayout->setSpacing(6);
        groupListLayout->setContentsMargins(11, 11, 11, 11);
        groupListLayout->setObjectName(QStringLiteral("groupListLayout"));
        groupListLayout->setSizeConstraint(QLayout::SetMaximumSize);
        groupListLayout->setContentsMargins(0, 0, 0, 6);
        groupSearchWidget = new QWidget(layoutWidget2);
        groupSearchWidget->setObjectName(QStringLiteral("groupSearchWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(groupSearchWidget->sizePolicy().hasHeightForWidth());
        groupSearchWidget->setSizePolicy(sizePolicy2);
        groupSearchInputLayout = new QHBoxLayout(groupSearchWidget);
        groupSearchInputLayout->setSpacing(3);
        groupSearchInputLayout->setContentsMargins(11, 11, 11, 11);
        groupSearchInputLayout->setObjectName(QStringLiteral("groupSearchInputLayout"));
        groupSearchInputLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        groupSearchInputLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(groupSearchWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(40, 16777215));
        QFont font;
        font.setPointSize(8);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        groupSearchInputLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        groupSearchInputLayout->addItem(horizontalSpacer_2);

        groupSearchInput = new QLineEdit(groupSearchWidget);
        groupSearchInput->setObjectName(QStringLiteral("groupSearchInput"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(groupSearchInput->sizePolicy().hasHeightForWidth());
        groupSearchInput->setSizePolicy(sizePolicy3);
        groupSearchInput->setMinimumSize(QSize(200, 25));
        groupSearchInput->setMaximumSize(QSize(16777215, 25));
        QFont font1;
        font1.setPointSize(10);
        groupSearchInput->setFont(font1);
        groupSearchInput->setFocusPolicy(Qt::StrongFocus);

        groupSearchInputLayout->addWidget(groupSearchInput);


        groupListLayout->addWidget(groupSearchWidget);

        groupSettingsWidget = new QWidget(layoutWidget2);
        groupSettingsWidget->setObjectName(QStringLiteral("groupSettingsWidget"));
        sizePolicy2.setHeightForWidth(groupSettingsWidget->sizePolicy().hasHeightForWidth());
        groupSettingsWidget->setSizePolicy(sizePolicy2);
        groupSettingsWidget->setMinimumSize(QSize(250, 70));
        groupSettingsWidget->setMaximumSize(QSize(16777215, 16777215));
        groupSettingsWidget->setMouseTracking(true);
        groupSettingsWidget->setStyleSheet(QStringLiteral(""));
        groupSettingsLayout = new QVBoxLayout(groupSettingsWidget);
        groupSettingsLayout->setSpacing(3);
        groupSettingsLayout->setContentsMargins(11, 11, 11, 11);
        groupSettingsLayout->setObjectName(QStringLiteral("groupSettingsLayout"));
        groupSettingsLayout->setContentsMargins(3, 3, 3, 3);
        groupSettingsTopSection = new QHBoxLayout();
        groupSettingsTopSection->setSpacing(0);
        groupSettingsTopSection->setObjectName(QStringLiteral("groupSettingsTopSection"));
        groupSettingsTopSection->setSizeConstraint(QLayout::SetMinAndMaxSize);
        groupSettingsTopSection->setContentsMargins(0, -1, -1, 0);
        activeCheckBox = new QCheckBox(groupSettingsWidget);
        activeCheckBox->setObjectName(QStringLiteral("activeCheckBox"));
        activeCheckBox->setMaximumSize(QSize(16777215, 20));
        activeCheckBox->setFocusPolicy(Qt::NoFocus);

        groupSettingsTopSection->addWidget(activeCheckBox);

        groupStateComboBox = new QComboBox(groupSettingsWidget);
        groupStateComboBox->setObjectName(QStringLiteral("groupStateComboBox"));
        groupStateComboBox->setFocusPolicy(Qt::NoFocus);

        groupSettingsTopSection->addWidget(groupStateComboBox);


        groupSettingsLayout->addLayout(groupSettingsTopSection);

        groupSettingsMidSection = new QHBoxLayout();
        groupSettingsMidSection->setSpacing(6);
        groupSettingsMidSection->setObjectName(QStringLiteral("groupSettingsMidSection"));
        newestOnTopCheckBox = new QCheckBox(groupSettingsWidget);
        newestOnTopCheckBox->setObjectName(QStringLiteral("newestOnTopCheckBox"));
        newestOnTopCheckBox->setFocusPolicy(Qt::NoFocus);

        groupSettingsMidSection->addWidget(newestOnTopCheckBox);

        scrollToBottomCheckBox = new QCheckBox(groupSettingsWidget);
        scrollToBottomCheckBox->setObjectName(QStringLiteral("scrollToBottomCheckBox"));
        scrollToBottomCheckBox->setFocusPolicy(Qt::NoFocus);

        groupSettingsMidSection->addWidget(scrollToBottomCheckBox);


        groupSettingsLayout->addLayout(groupSettingsMidSection);

        groupSettingsLowerSection = new QHBoxLayout();
        groupSettingsLowerSection->setSpacing(6);
        groupSettingsLowerSection->setObjectName(QStringLiteral("groupSettingsLowerSection"));
        tabModeRadio = new QRadioButton(groupSettingsWidget);
        tabModeRadio->setObjectName(QStringLiteral("tabModeRadio"));
        tabModeRadio->setFocusPolicy(Qt::NoFocus);
        tabModeRadio->setChecked(true);

        groupSettingsLowerSection->addWidget(tabModeRadio);

        windowModeRadio = new QRadioButton(groupSettingsWidget);
        windowModeRadio->setObjectName(QStringLiteral("windowModeRadio"));
        windowModeRadio->setFocusPolicy(Qt::NoFocus);

        groupSettingsLowerSection->addWidget(windowModeRadio);


        groupSettingsLayout->addLayout(groupSettingsLowerSection);


        groupListLayout->addWidget(groupSettingsWidget);

        groupList = new QTreeView(layoutWidget2);
        groupList->setObjectName(QStringLiteral("groupList"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(1);
        sizePolicy4.setVerticalStretch(20);
        sizePolicy4.setHeightForWidth(groupList->sizePolicy().hasHeightForWidth());
        groupList->setSizePolicy(sizePolicy4);
        groupList->setMinimumSize(QSize(200, 0));
        groupList->setMaximumSize(QSize(16777215, 16777215));
        QFont font2;
        font2.setPointSize(8);
        groupList->setFont(font2);
        groupList->setFocusPolicy(Qt::StrongFocus);
        groupList->setEditTriggers(QAbstractItemView::NoEditTriggers);

        groupListLayout->addWidget(groupList);

        groupListLayout->setStretch(0, 1);
        groupListLayout->setStretch(1, 1);
        groupListLayout->setStretch(2, 10);
        splitter->addWidget(layoutWidget2);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        clientListLayout = new QVBoxLayout(layoutWidget1);
        clientListLayout->setSpacing(6);
        clientListLayout->setContentsMargins(11, 11, 11, 11);
        clientListLayout->setObjectName(QStringLiteral("clientListLayout"));
        clientListLayout->setSizeConstraint(QLayout::SetMaximumSize);
        clientListLayout->setContentsMargins(0, 0, 0, 0);
        clientSearchWidget = new QWidget(layoutWidget1);
        clientSearchWidget->setObjectName(QStringLiteral("clientSearchWidget"));
        sizePolicy2.setHeightForWidth(clientSearchWidget->sizePolicy().hasHeightForWidth());
        clientSearchWidget->setSizePolicy(sizePolicy2);
        clientSearchInputLayout = new QHBoxLayout(clientSearchWidget);
        clientSearchInputLayout->setSpacing(3);
        clientSearchInputLayout->setContentsMargins(11, 11, 11, 11);
        clientSearchInputLayout->setObjectName(QStringLiteral("clientSearchInputLayout"));
        clientSearchInputLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        clientSearchInputLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(clientSearchWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(40, 16777215));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        clientSearchInputLayout->addWidget(label_2);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        clientSearchInputLayout->addItem(horizontalSpacer_3);

        clientInput = new QLineEdit(clientSearchWidget);
        clientInput->setObjectName(QStringLiteral("clientInput"));
        sizePolicy3.setHeightForWidth(clientInput->sizePolicy().hasHeightForWidth());
        clientInput->setSizePolicy(sizePolicy3);
        clientInput->setMinimumSize(QSize(200, 25));
        clientInput->setMaximumSize(QSize(16777215, 25));
        clientInput->setFont(font1);
        clientInput->setFocusPolicy(Qt::StrongFocus);

        clientSearchInputLayout->addWidget(clientInput);


        clientListLayout->addWidget(clientSearchWidget);

        clientSettingsWidget = new QWidget(layoutWidget1);
        clientSettingsWidget->setObjectName(QStringLiteral("clientSettingsWidget"));
        sizePolicy2.setHeightForWidth(clientSettingsWidget->sizePolicy().hasHeightForWidth());
        clientSettingsWidget->setSizePolicy(sizePolicy2);
        clientSettingsWidget->setMinimumSize(QSize(250, 70));
        clientSettingsWidget->setMaximumSize(QSize(16777215, 16777215));
        clientSettingsWidget->setStyleSheet(QStringLiteral(""));
        clientSettingsLayout = new QVBoxLayout(clientSettingsWidget);
        clientSettingsLayout->setSpacing(3);
        clientSettingsLayout->setContentsMargins(11, 11, 11, 11);
        clientSettingsLayout->setObjectName(QStringLiteral("clientSettingsLayout"));
        clientSettingsLayout->setContentsMargins(3, 3, 3, 3);
        clientSettingsTopSection = new QHBoxLayout();
        clientSettingsTopSection->setSpacing(0);
        clientSettingsTopSection->setObjectName(QStringLiteral("clientSettingsTopSection"));
        clientSettingsTopSection->setSizeConstraint(QLayout::SetDefaultConstraint);
        clientSettingsTopSection->setContentsMargins(0, -1, -1, 0);
        clientActiveCheckBox = new QCheckBox(clientSettingsWidget);
        clientActiveCheckBox->setObjectName(QStringLiteral("clientActiveCheckBox"));
        clientActiveCheckBox->setMaximumSize(QSize(16777215, 20));
        clientActiveCheckBox->setMouseTracking(true);
        clientActiveCheckBox->setFocusPolicy(Qt::ClickFocus);

        clientSettingsTopSection->addWidget(clientActiveCheckBox);

        clientsStateComboBox = new QComboBox(clientSettingsWidget);
        clientsStateComboBox->setObjectName(QStringLiteral("clientsStateComboBox"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(clientsStateComboBox->sizePolicy().hasHeightForWidth());
        clientsStateComboBox->setSizePolicy(sizePolicy5);
        clientsStateComboBox->setMouseTracking(true);
        clientsStateComboBox->setFocusPolicy(Qt::ClickFocus);

        clientSettingsTopSection->addWidget(clientsStateComboBox);


        clientSettingsLayout->addLayout(clientSettingsTopSection);

        clientSettingsMidSection = new QHBoxLayout();
        clientSettingsMidSection->setSpacing(6);
        clientSettingsMidSection->setObjectName(QStringLiteral("clientSettingsMidSection"));
        clientNewestOnTopCheckBox = new QCheckBox(clientSettingsWidget);
        clientNewestOnTopCheckBox->setObjectName(QStringLiteral("clientNewestOnTopCheckBox"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(clientNewestOnTopCheckBox->sizePolicy().hasHeightForWidth());
        clientNewestOnTopCheckBox->setSizePolicy(sizePolicy6);
        clientNewestOnTopCheckBox->setMouseTracking(true);
        clientNewestOnTopCheckBox->setFocusPolicy(Qt::ClickFocus);

        clientSettingsMidSection->addWidget(clientNewestOnTopCheckBox);

        clientScrollToBottomCheckBox = new QCheckBox(clientSettingsWidget);
        clientScrollToBottomCheckBox->setObjectName(QStringLiteral("clientScrollToBottomCheckBox"));
        sizePolicy6.setHeightForWidth(clientScrollToBottomCheckBox->sizePolicy().hasHeightForWidth());
        clientScrollToBottomCheckBox->setSizePolicy(sizePolicy6);
        clientScrollToBottomCheckBox->setMouseTracking(true);
        clientScrollToBottomCheckBox->setFocusPolicy(Qt::ClickFocus);

        clientSettingsMidSection->addWidget(clientScrollToBottomCheckBox);


        clientSettingsLayout->addLayout(clientSettingsMidSection);

        clientSettingsLowerSection = new QHBoxLayout();
        clientSettingsLowerSection->setSpacing(6);
        clientSettingsLowerSection->setObjectName(QStringLiteral("clientSettingsLowerSection"));
        clientTabModeRadio = new QRadioButton(clientSettingsWidget);
        clientTabModeRadio->setObjectName(QStringLiteral("clientTabModeRadio"));
        sizePolicy6.setHeightForWidth(clientTabModeRadio->sizePolicy().hasHeightForWidth());
        clientTabModeRadio->setSizePolicy(sizePolicy6);
        clientTabModeRadio->setMouseTracking(true);
        clientTabModeRadio->setFocusPolicy(Qt::ClickFocus);
        clientTabModeRadio->setChecked(true);

        clientSettingsLowerSection->addWidget(clientTabModeRadio);

        clientWindowModeRadio = new QRadioButton(clientSettingsWidget);
        clientWindowModeRadio->setObjectName(QStringLiteral("clientWindowModeRadio"));
        sizePolicy6.setHeightForWidth(clientWindowModeRadio->sizePolicy().hasHeightForWidth());
        clientWindowModeRadio->setSizePolicy(sizePolicy6);
        clientWindowModeRadio->setMouseTracking(true);
        clientWindowModeRadio->setFocusPolicy(Qt::ClickFocus);

        clientSettingsLowerSection->addWidget(clientWindowModeRadio);


        clientSettingsLayout->addLayout(clientSettingsLowerSection);


        clientListLayout->addWidget(clientSettingsWidget);

        clientList = new QTreeView(layoutWidget1);
        clientList->setObjectName(QStringLiteral("clientList"));
        sizePolicy4.setHeightForWidth(clientList->sizePolicy().hasHeightForWidth());
        clientList->setSizePolicy(sizePolicy4);
        clientList->setMinimumSize(QSize(200, 0));
        clientList->setMaximumSize(QSize(16777215, 16777215));
        clientList->setFont(font2);
        clientList->setStyleSheet(QStringLiteral(""));

        clientListLayout->addWidget(clientList);

        clientListLayout->setStretch(0, 1);
        clientListLayout->setStretch(1, 1);
        clientListLayout->setStretch(2, 10);
        splitter->addWidget(layoutWidget1);
        mainSplitter->addWidget(splitter);
        contentSplitter = new QSplitter(mainSplitter);
        contentSplitter->setObjectName(QStringLiteral("contentSplitter"));
        contentSplitter->setOrientation(Qt::Vertical);
        filterWidget = new QWidget(contentSplitter);
        filterWidget->setObjectName(QStringLiteral("filterWidget"));
        sizePolicy5.setHeightForWidth(filterWidget->sizePolicy().hasHeightForWidth());
        filterWidget->setSizePolicy(sizePolicy5);
        filterWidget->setMaximumSize(QSize(16777215, 25));
        horizontalLayout = new QHBoxLayout(filterWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        inputField = new QLineEdit(filterWidget);
        inputField->setObjectName(QStringLiteral("inputField"));
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy7.setHorizontalStretch(1);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(inputField->sizePolicy().hasHeightForWidth());
        inputField->setSizePolicy(sizePolicy7);
        inputField->setMinimumSize(QSize(150, 25));
        inputField->setMaximumSize(QSize(16777215, 25));
        inputField->setFont(font1);
        inputField->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(inputField);

        globalSearchCheckBox = new QCheckBox(filterWidget);
        globalSearchCheckBox->setObjectName(QStringLiteral("globalSearchCheckBox"));
        QSizePolicy sizePolicy8(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(globalSearchCheckBox->sizePolicy().hasHeightForWidth());
        globalSearchCheckBox->setSizePolicy(sizePolicy8);
        globalSearchCheckBox->setMinimumSize(QSize(0, 15));
        globalSearchCheckBox->setMaximumSize(QSize(90, 15));

        horizontalLayout->addWidget(globalSearchCheckBox);

        caseSensitiveCheckBox = new QCheckBox(filterWidget);
        caseSensitiveCheckBox->setObjectName(QStringLiteral("caseSensitiveCheckBox"));
        caseSensitiveCheckBox->setMaximumSize(QSize(100, 15));

        horizontalLayout->addWidget(caseSensitiveCheckBox);

        contentSplitter->addWidget(filterWidget);
        gridLayoutWidget = new QWidget(contentSplitter);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        mainContentLayout = new QGridLayout(gridLayoutWidget);
        mainContentLayout->setSpacing(6);
        mainContentLayout->setContentsMargins(11, 11, 11, 11);
        mainContentLayout->setObjectName(QStringLiteral("mainContentLayout"));
        mainContentLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        mainContentLayout->setHorizontalSpacing(0);
        mainContentLayout->setVerticalSpacing(3);
        mainContentLayout->setContentsMargins(0, 0, 0, 0);
        contentSplitter->addWidget(gridLayoutWidget);
        logDetailInput = new QPlainTextEdit(contentSplitter);
        logDetailInput->setObjectName(QStringLiteral("logDetailInput"));
        QSizePolicy sizePolicy9(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy9.setHorizontalStretch(6);
        sizePolicy9.setVerticalStretch(1);
        sizePolicy9.setHeightForWidth(logDetailInput->sizePolicy().hasHeightForWidth());
        logDetailInput->setSizePolicy(sizePolicy9);
        logDetailInput->setMinimumSize(QSize(0, 50));
        logDetailInput->setMaximumSize(QSize(16777215, 16777215));
        logDetailInput->setReadOnly(true);
        contentSplitter->addWidget(logDetailInput);
        mainSplitter->addWidget(contentSplitter);
        mainGroupLayoutWidgetSettings = new QWidget(mainSplitter);
        mainGroupLayoutWidgetSettings->setObjectName(QStringLiteral("mainGroupLayoutWidgetSettings"));
        rightPaneGrid = new QGridLayout(mainGroupLayoutWidgetSettings);
        rightPaneGrid->setSpacing(6);
        rightPaneGrid->setContentsMargins(11, 11, 11, 11);
        rightPaneGrid->setObjectName(QStringLiteral("rightPaneGrid"));
        rightPaneGrid->setSizeConstraint(QLayout::SetMaximumSize);
        rightPaneGrid->setContentsMargins(0, 0, 0, 0);
        toolBox = new QToolBox(mainGroupLayoutWidgetSettings);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        sizePolicy3.setHeightForWidth(toolBox->sizePolicy().hasHeightForWidth());
        toolBox->setSizePolicy(sizePolicy3);
        toolBox->setMinimumSize(QSize(150, 0));
        toolBox->setMaximumSize(QSize(150, 16777215));
        toolBox->setAutoFillBackground(true);
        toolBox->setStyleSheet(QStringLiteral(""));
        toolBox->setFrameShape(QFrame::NoFrame);
        standardFiltersPage = new QWidget();
        standardFiltersPage->setObjectName(QStringLiteral("standardFiltersPage"));
        standardFiltersPage->setGeometry(QRect(0, 0, 150, 697));
        QSizePolicy sizePolicy10(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(standardFiltersPage->sizePolicy().hasHeightForWidth());
        standardFiltersPage->setSizePolicy(sizePolicy10);
        standardFiltersPage->setMinimumSize(QSize(150, 0));
        standardFiltersPage->setMaximumSize(QSize(150, 16777215));
        messageStatesBox = new QGroupBox(standardFiltersPage);
        messageStatesBox->setObjectName(QStringLiteral("messageStatesBox"));
        messageStatesBox->setGeometry(QRect(0, 0, 150, 151));
        QSizePolicy sizePolicy11(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy11.setHorizontalStretch(0);
        sizePolicy11.setVerticalStretch(0);
        sizePolicy11.setHeightForWidth(messageStatesBox->sizePolicy().hasHeightForWidth());
        messageStatesBox->setSizePolicy(sizePolicy11);
        messageStatesBox->setMinimumSize(QSize(150, 0));
        messageStatesBox->setMaximumSize(QSize(150, 16777215));
        enableInfoCheckBox = new QCheckBox(messageStatesBox);
        enableInfoCheckBox->setObjectName(QStringLiteral("enableInfoCheckBox"));
        enableInfoCheckBox->setGeometry(QRect(10, 20, 120, 17));
        sizePolicy8.setHeightForWidth(enableInfoCheckBox->sizePolicy().hasHeightForWidth());
        enableInfoCheckBox->setSizePolicy(sizePolicy8);
        enableInfoCheckBox->setMinimumSize(QSize(120, 0));
        enableInfoCheckBox->setMaximumSize(QSize(120, 16777215));
        enableInfoCheckBox->setChecked(true);
        enableWarningCheckBox = new QCheckBox(messageStatesBox);
        enableWarningCheckBox->setObjectName(QStringLiteral("enableWarningCheckBox"));
        enableWarningCheckBox->setGeometry(QRect(10, 40, 120, 17));
        sizePolicy8.setHeightForWidth(enableWarningCheckBox->sizePolicy().hasHeightForWidth());
        enableWarningCheckBox->setSizePolicy(sizePolicy8);
        enableWarningCheckBox->setMinimumSize(QSize(120, 0));
        enableWarningCheckBox->setMaximumSize(QSize(120, 16777215));
        enableWarningCheckBox->setChecked(true);
        enableErrorCheckBox = new QCheckBox(messageStatesBox);
        enableErrorCheckBox->setObjectName(QStringLiteral("enableErrorCheckBox"));
        enableErrorCheckBox->setGeometry(QRect(10, 60, 120, 17));
        sizePolicy8.setHeightForWidth(enableErrorCheckBox->sizePolicy().hasHeightForWidth());
        enableErrorCheckBox->setSizePolicy(sizePolicy8);
        enableErrorCheckBox->setMinimumSize(QSize(120, 0));
        enableErrorCheckBox->setMaximumSize(QSize(120, 16777215));
        enableErrorCheckBox->setChecked(true);
        enableExceptionCheckBox = new QCheckBox(messageStatesBox);
        enableExceptionCheckBox->setObjectName(QStringLiteral("enableExceptionCheckBox"));
        enableExceptionCheckBox->setGeometry(QRect(10, 80, 120, 17));
        sizePolicy8.setHeightForWidth(enableExceptionCheckBox->sizePolicy().hasHeightForWidth());
        enableExceptionCheckBox->setSizePolicy(sizePolicy8);
        enableExceptionCheckBox->setMinimumSize(QSize(120, 0));
        enableExceptionCheckBox->setMaximumSize(QSize(120, 16777215));
        enableExceptionCheckBox->setChecked(true);
        enableFatalCheckBox = new QCheckBox(messageStatesBox);
        enableFatalCheckBox->setObjectName(QStringLiteral("enableFatalCheckBox"));
        enableFatalCheckBox->setGeometry(QRect(10, 100, 120, 17));
        sizePolicy8.setHeightForWidth(enableFatalCheckBox->sizePolicy().hasHeightForWidth());
        enableFatalCheckBox->setSizePolicy(sizePolicy8);
        enableFatalCheckBox->setMinimumSize(QSize(120, 0));
        enableFatalCheckBox->setMaximumSize(QSize(120, 16777215));
        enableFatalCheckBox->setChecked(true);
        enableBinaryCheckBox = new QCheckBox(messageStatesBox);
        enableBinaryCheckBox->setObjectName(QStringLiteral("enableBinaryCheckBox"));
        enableBinaryCheckBox->setGeometry(QRect(10, 120, 120, 17));
        sizePolicy8.setHeightForWidth(enableBinaryCheckBox->sizePolicy().hasHeightForWidth());
        enableBinaryCheckBox->setSizePolicy(sizePolicy8);
        enableBinaryCheckBox->setMinimumSize(QSize(120, 0));
        enableBinaryCheckBox->setMaximumSize(QSize(120, 16777215));
        enableBinaryCheckBox->setChecked(true);
        stampsBox = new QGroupBox(standardFiltersPage);
        stampsBox->setObjectName(QStringLiteral("stampsBox"));
        stampsBox->setGeometry(QRect(0, 160, 150, 151));
        sizePolicy11.setHeightForWidth(stampsBox->sizePolicy().hasHeightForWidth());
        stampsBox->setSizePolicy(sizePolicy11);
        stampsBox->setMinimumSize(QSize(150, 0));
        stampsBox->setMaximumSize(QSize(150, 16777215));
        useMessageHeaderCheckBox = new QCheckBox(stampsBox);
        useMessageHeaderCheckBox->setObjectName(QStringLiteral("useMessageHeaderCheckBox"));
        useMessageHeaderCheckBox->setGeometry(QRect(10, 100, 120, 16));
        sizePolicy8.setHeightForWidth(useMessageHeaderCheckBox->sizePolicy().hasHeightForWidth());
        useMessageHeaderCheckBox->setSizePolicy(sizePolicy8);
        useMessageHeaderCheckBox->setMinimumSize(QSize(120, 0));
        useMessageHeaderCheckBox->setMaximumSize(QSize(120, 16777215));
        useMessageHeaderCheckBox->setChecked(true);
        useTimeStampCheckBox = new QCheckBox(stampsBox);
        useTimeStampCheckBox->setObjectName(QStringLiteral("useTimeStampCheckBox"));
        useTimeStampCheckBox->setGeometry(QRect(10, 40, 120, 17));
        sizePolicy8.setHeightForWidth(useTimeStampCheckBox->sizePolicy().hasHeightForWidth());
        useTimeStampCheckBox->setSizePolicy(sizePolicy8);
        useTimeStampCheckBox->setMinimumSize(QSize(120, 0));
        useTimeStampCheckBox->setMaximumSize(QSize(120, 16777215));
        useTimeStampCheckBox->setChecked(true);
        useDateStampCheckBox = new QCheckBox(stampsBox);
        useDateStampCheckBox->setObjectName(QStringLiteral("useDateStampCheckBox"));
        useDateStampCheckBox->setGeometry(QRect(10, 20, 120, 17));
        sizePolicy8.setHeightForWidth(useDateStampCheckBox->sizePolicy().hasHeightForWidth());
        useDateStampCheckBox->setSizePolicy(sizePolicy8);
        useDateStampCheckBox->setMinimumSize(QSize(120, 0));
        useDateStampCheckBox->setMaximumSize(QSize(120, 16777215));
        useDateStampCheckBox->setChecked(true);
        useContentStampCheckBox = new QCheckBox(stampsBox);
        useContentStampCheckBox->setObjectName(QStringLiteral("useContentStampCheckBox"));
        useContentStampCheckBox->setGeometry(QRect(10, 120, 120, 17));
        sizePolicy8.setHeightForWidth(useContentStampCheckBox->sizePolicy().hasHeightForWidth());
        useContentStampCheckBox->setSizePolicy(sizePolicy8);
        useContentStampCheckBox->setMinimumSize(QSize(120, 0));
        useContentStampCheckBox->setMaximumSize(QSize(120, 16777215));
        useContentStampCheckBox->setChecked(true);
        useGroupStampCheckBox = new QCheckBox(stampsBox);
        useGroupStampCheckBox->setObjectName(QStringLiteral("useGroupStampCheckBox"));
        useGroupStampCheckBox->setGeometry(QRect(10, 60, 120, 17));
        sizePolicy8.setHeightForWidth(useGroupStampCheckBox->sizePolicy().hasHeightForWidth());
        useGroupStampCheckBox->setSizePolicy(sizePolicy8);
        useGroupStampCheckBox->setMinimumSize(QSize(120, 0));
        useGroupStampCheckBox->setMaximumSize(QSize(120, 16777215));
        useGroupStampCheckBox->setChecked(true);
        useClientStampCheckBox = new QCheckBox(stampsBox);
        useClientStampCheckBox->setObjectName(QStringLiteral("useClientStampCheckBox"));
        useClientStampCheckBox->setGeometry(QRect(10, 80, 120, 17));
        sizePolicy8.setHeightForWidth(useClientStampCheckBox->sizePolicy().hasHeightForWidth());
        useClientStampCheckBox->setSizePolicy(sizePolicy8);
        useClientStampCheckBox->setMinimumSize(QSize(120, 0));
        useClientStampCheckBox->setMaximumSize(QSize(120, 16777215));
        useClientStampCheckBox->setChecked(true);
        bufferTriggersBox = new QGroupBox(standardFiltersPage);
        bufferTriggersBox->setObjectName(QStringLiteral("bufferTriggersBox"));
        bufferTriggersBox->setGeometry(QRect(0, 320, 150, 131));
        sizePolicy11.setHeightForWidth(bufferTriggersBox->sizePolicy().hasHeightForWidth());
        bufferTriggersBox->setSizePolicy(sizePolicy11);
        bufferTriggersBox->setMinimumSize(QSize(150, 0));
        bufferTriggersBox->setMaximumSize(QSize(150, 16777215));
        infoMessageCheckBox = new QCheckBox(bufferTriggersBox);
        infoMessageCheckBox->setObjectName(QStringLiteral("infoMessageCheckBox"));
        infoMessageCheckBox->setGeometry(QRect(10, 20, 120, 17));
        sizePolicy8.setHeightForWidth(infoMessageCheckBox->sizePolicy().hasHeightForWidth());
        infoMessageCheckBox->setSizePolicy(sizePolicy8);
        infoMessageCheckBox->setMinimumSize(QSize(120, 0));
        infoMessageCheckBox->setMaximumSize(QSize(120, 16777215));
        warningMessageCheckBox = new QCheckBox(bufferTriggersBox);
        warningMessageCheckBox->setObjectName(QStringLiteral("warningMessageCheckBox"));
        warningMessageCheckBox->setGeometry(QRect(10, 40, 120, 17));
        sizePolicy8.setHeightForWidth(warningMessageCheckBox->sizePolicy().hasHeightForWidth());
        warningMessageCheckBox->setSizePolicy(sizePolicy8);
        warningMessageCheckBox->setMinimumSize(QSize(120, 0));
        warningMessageCheckBox->setMaximumSize(QSize(120, 16777215));
        errorMessageCheckBox = new QCheckBox(bufferTriggersBox);
        errorMessageCheckBox->setObjectName(QStringLiteral("errorMessageCheckBox"));
        errorMessageCheckBox->setGeometry(QRect(10, 60, 120, 17));
        sizePolicy8.setHeightForWidth(errorMessageCheckBox->sizePolicy().hasHeightForWidth());
        errorMessageCheckBox->setSizePolicy(sizePolicy8);
        errorMessageCheckBox->setMinimumSize(QSize(120, 0));
        errorMessageCheckBox->setMaximumSize(QSize(120, 16777215));
        errorMessageCheckBox->setChecked(true);
        exceptionMessageCheckBox = new QCheckBox(bufferTriggersBox);
        exceptionMessageCheckBox->setObjectName(QStringLiteral("exceptionMessageCheckBox"));
        exceptionMessageCheckBox->setGeometry(QRect(10, 80, 120, 17));
        sizePolicy8.setHeightForWidth(exceptionMessageCheckBox->sizePolicy().hasHeightForWidth());
        exceptionMessageCheckBox->setSizePolicy(sizePolicy8);
        exceptionMessageCheckBox->setMinimumSize(QSize(120, 0));
        exceptionMessageCheckBox->setMaximumSize(QSize(120, 16777215));
        exceptionMessageCheckBox->setChecked(true);
        fatalMessageCheckBox = new QCheckBox(bufferTriggersBox);
        fatalMessageCheckBox->setObjectName(QStringLiteral("fatalMessageCheckBox"));
        fatalMessageCheckBox->setGeometry(QRect(10, 100, 120, 17));
        sizePolicy8.setHeightForWidth(fatalMessageCheckBox->sizePolicy().hasHeightForWidth());
        fatalMessageCheckBox->setSizePolicy(sizePolicy8);
        fatalMessageCheckBox->setMinimumSize(QSize(120, 0));
        fatalMessageCheckBox->setMaximumSize(QSize(120, 16777215));
        fatalMessageCheckBox->setChecked(true);
        groupBox = new QGroupBox(standardFiltersPage);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 460, 150, 231));
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setMaximumSize(QSize(150, 16777215));
        applicationOutput = new QPlainTextEdit(groupBox);
        applicationOutput->setObjectName(QStringLiteral("applicationOutput"));
        applicationOutput->setGeometry(QRect(10, 20, 131, 201));
        applicationOutput->setStyleSheet(QStringLiteral("background-color:#f2f2f2"));
        applicationOutput->setReadOnly(true);
        toolBox->addItem(standardFiltersPage, QStringLiteral("Global Log Settings"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 100, 30));
        contentSectionBox = new QGroupBox(page);
        contentSectionBox->setObjectName(QStringLiteral("contentSectionBox"));
        contentSectionBox->setGeometry(QRect(0, 60, 150, 71));
        contentSectionBox->setMinimumSize(QSize(150, 0));
        contentSectionBox->setMaximumSize(QSize(150, 16777215));
        contentSectionBox->setFlat(false);
        showLogDetailCheckBox = new QCheckBox(contentSectionBox);
        showLogDetailCheckBox->setObjectName(QStringLiteral("showLogDetailCheckBox"));
        showLogDetailCheckBox->setGeometry(QRect(10, 40, 120, 17));
        showLogDetailCheckBox->setMinimumSize(QSize(120, 0));
        showLogDetailCheckBox->setMaximumSize(QSize(120, 16777215));
        showLogDetailCheckBox->setChecked(true);
        showFilterAreaCheckBox = new QCheckBox(contentSectionBox);
        showFilterAreaCheckBox->setObjectName(QStringLiteral("showFilterAreaCheckBox"));
        showFilterAreaCheckBox->setGeometry(QRect(10, 20, 101, 17));
        showFilterAreaCheckBox->setMaximumSize(QSize(120, 16777215));
        showFilterAreaCheckBox->setChecked(true);
        assignColorButton = new QPushButton(page);
        assignColorButton->setObjectName(QStringLiteral("assignColorButton"));
        assignColorButton->setGeometry(QRect(0, 140, 150, 23));
        assignColorButton->setMinimumSize(QSize(150, 0));
        assignColorButton->setMaximumSize(QSize(150, 16777215));
        showGroupSectionCheckBox = new QCheckBox(page);
        showGroupSectionCheckBox->setObjectName(QStringLiteral("showGroupSectionCheckBox"));
        showGroupSectionCheckBox->setGeometry(QRect(10, 10, 120, 17));
        showGroupSectionCheckBox->setMaximumSize(QSize(120, 16777215));
        showGroupSectionCheckBox->setChecked(true);
        showClientSectionCheckBox = new QCheckBox(page);
        showClientSectionCheckBox->setObjectName(QStringLiteral("showClientSectionCheckBox"));
        showClientSectionCheckBox->setGeometry(QRect(10, 30, 120, 17));
        showClientSectionCheckBox->setMaximumSize(QSize(120, 16777215));
        showClientSectionCheckBox->setChecked(true);
        toolBox->addItem(page, QStringLiteral("View Settings"));

        rightPaneGrid->addWidget(toolBox, 0, 0, 1, 1);

        mainSplitter->addWidget(mainGroupLayoutWidgetSettings);

        gridLayout->addWidget(mainSplitter, 0, 0, 1, 1);

        RT_MainClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(RT_MainClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1247, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuSystem = new QMenu(menuBar);
        menuSystem->setObjectName(QStringLiteral("menuSystem"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        RT_MainClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(RT_MainClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        sizePolicy6.setHeightForWidth(statusBar->sizePolicy().hasHeightForWidth());
        statusBar->setSizePolicy(sizePolicy6);
        statusBar->setMinimumSize(QSize(0, 20));
        statusBar->setMaximumSize(QSize(16777215, 20));
        statusBar->setStyleSheet(QLatin1String("#statusBar{\n"
"border-top:2px solid #E8E7E7\n"
"}"));
        RT_MainClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuSystem->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(importFileAction);
        menuFile->addAction(actionExport);
        menuFile->addSeparator();
        menuFile->addAction(actionLoad_Configuration);
        menuFile->addSeparator();
        menuFile->addAction(closeAppAction);
        menuHelp->addAction(actionHelp);
        menuHelp->addAction(actionAbout);
        menuSystem->addAction(actionSettings);
        menuSystem->addAction(actionRestore_Default_Settings);
        menuEdit->addAction(actionSelect_All_Groups);
        menuEdit->addAction(actionSelect_All_Clients);
        menuEdit->addSeparator();
        menuEdit->addAction(actionSelect_All_active);
        menuEdit->addSeparator();
        menuEdit->addAction(actionFreeze_All);
        menuEdit->addAction(actionUnfreeze_All);
        menuEdit->addSeparator();
        menuEdit->addAction(actionClear_Current_Table);
        menuEdit->addAction(actionClear_All_Tables);
        menuEdit->addSeparator();
        menuEdit->addAction(actionClear_All_MergeViews);
        menuEdit->addAction(actionRestart_Master);
        menuView->addAction(actionShow_Inactive_Clients);
        menuView->addSeparator();
        menuView->addAction(actionShow_Binary_Clients);
        menuView->addAction(actionShow_Text_Clients);
        menuView->addSeparator();
        menuView->addAction(actionArrange_Windows);
        menuView->addSeparator();
        menuView->addAction(actionReset_Selected_Clients);
        menuView->addAction(actionReset_All_Clients);
        menuView->addSeparator();
        menuView->addAction(actionAssign_Color);
        menuView->addSeparator();
        menuView->addAction(actionMinimize_All);
        menuView->addAction(actionMaximize_All);
        menuView->addSeparator();
        menuView->addAction(actionClose_All_Tabs);
        menuView->addAction(actionClose_All_Windows);

        retranslateUi(RT_MainClass);
        QObject::connect(closeAppAction, SIGNAL(triggered()), RT_MainClass, SLOT(closeAppTriggered()));
        QObject::connect(importFileAction, SIGNAL(triggered()), RT_MainClass, SLOT(importFileTriggered()));
        QObject::connect(enableInfoCheckBox, SIGNAL(clicked()), RT_MainClass, SLOT(enableInfoCheckBoxClicked()));
        QObject::connect(enableWarningCheckBox, SIGNAL(clicked()), RT_MainClass, SLOT(enableWarningCheckBoxClicked()));
        QObject::connect(enableErrorCheckBox, SIGNAL(clicked()), RT_MainClass, SLOT(enableErrorCheckBoxClicked()));
        QObject::connect(enableExceptionCheckBox, SIGNAL(clicked()), RT_MainClass, SLOT(enableExceptionCheckBoxClicked()));
        QObject::connect(enableFatalCheckBox, SIGNAL(clicked()), RT_MainClass, SLOT(enableFatalCheckBoxClicked()));
        QObject::connect(enableBinaryCheckBox, SIGNAL(clicked()), RT_MainClass, SLOT(enableBinaryCheckBoxClicked()));
        QObject::connect(useMessageHeaderCheckBox, SIGNAL(clicked()), RT_MainClass, SLOT(useMessageHeaderCheckBoxClicked()));
        QObject::connect(useTimeStampCheckBox, SIGNAL(clicked()), RT_MainClass, SLOT(useTimeStampCheckBoxClicked()));
        QObject::connect(useDateStampCheckBox, SIGNAL(clicked()), RT_MainClass, SLOT(useDateStampCheckBoxClicked()));
        QObject::connect(infoMessageCheckBox, SIGNAL(clicked()), RT_MainClass, SLOT(infoMessageCheckBoxClicked()));
        QObject::connect(warningMessageCheckBox, SIGNAL(clicked()), RT_MainClass, SLOT(warningMessageCheckBoxClicked()));
        QObject::connect(errorMessageCheckBox, SIGNAL(clicked()), RT_MainClass, SLOT(errorMessageCheckBoxClicked()));
        QObject::connect(exceptionMessageCheckBox, SIGNAL(clicked()), RT_MainClass, SLOT(exceptionMessageCheckBoxClicked()));
        QObject::connect(fatalMessageCheckBox, SIGNAL(clicked()), RT_MainClass, SLOT(fatalMessageCheckBoxClicked()));
        QObject::connect(actionExport, SIGNAL(triggered()), RT_MainClass, SLOT(exportFileTriggered()));
        QObject::connect(actionSelect_All_Clients, SIGNAL(triggered()), RT_MainClass, SLOT(selectAllClients()));
        QObject::connect(actionSelect_All_Groups, SIGNAL(triggered()), RT_MainClass, SLOT(selectAllGroups()));
        QObject::connect(actionSelect_All_active, SIGNAL(triggered()), RT_MainClass, SLOT(selectAllActive()));
        QObject::connect(useGroupStampCheckBox, SIGNAL(clicked()), RT_MainClass, SLOT(useGroupStampCheckBoxClicked()));
        QObject::connect(useClientStampCheckBox, SIGNAL(clicked()), RT_MainClass, SLOT(useClientStampCheckBoxClicked()));
        QObject::connect(useContentStampCheckBox, SIGNAL(clicked()), RT_MainClass, SLOT(useContentStampCheckBoxClicked()));
        QObject::connect(actionAssign_Color, SIGNAL(triggered()), RT_MainClass, SLOT(assignColor()));
        QObject::connect(actionAbout, SIGNAL(triggered()), RT_MainClass, SLOT(aboutTriggered()));
        QObject::connect(actionHelp, SIGNAL(triggered()), RT_MainClass, SLOT(helpTriggered()));
        QObject::connect(actionSettings, SIGNAL(triggered()), RT_MainClass, SLOT(settingsTriggered()));
        QObject::connect(actionShow_Inactive_Clients, SIGNAL(triggered()), RT_MainClass, SLOT(showInactiveClientsTriggered()));
        QObject::connect(actionShow_Binary_Clients, SIGNAL(triggered()), RT_MainClass, SLOT(showBinaryClientsTriggered()));
        QObject::connect(actionShow_Text_Clients, SIGNAL(triggered()), RT_MainClass, SLOT(showTextClientsTriggered()));
        QObject::connect(actionArrange_Windows, SIGNAL(triggered()), RT_MainClass, SLOT(arrangeWindowsTriggered()));
        QObject::connect(actionReset_All_Clients, SIGNAL(triggered()), RT_MainClass, SLOT(resetAllClientsTriggered()));
        QObject::connect(actionReset_Selected_Clients, SIGNAL(triggered()), RT_MainClass, SLOT(resetSelectedClientsTriggered()));
        QObject::connect(actionClose_All_Tabs, SIGNAL(triggered()), RT_MainClass, SLOT(closeAllTabsTriggered()));
        QObject::connect(actionMinimize_All, SIGNAL(triggered()), RT_MainClass, SLOT(minimizeAllTriggered()));
        QObject::connect(actionMaximize_All, SIGNAL(triggered()), RT_MainClass, SLOT(maximizeAllTriggered()));
        QObject::connect(actionClear_Current_Table, SIGNAL(triggered()), RT_MainClass, SLOT(clearCurrentTableTriggered()));
        QObject::connect(actionClear_All_Tables, SIGNAL(triggered()), RT_MainClass, SLOT(clearAllTablesTriggered()));
        QObject::connect(actionFreeze_All, SIGNAL(triggered()), RT_MainClass, SLOT(freezeAllTriggered()));
        QObject::connect(actionUnfreeze_All, SIGNAL(triggered()), RT_MainClass, SLOT(unfreezeAllTriggered()));
        QObject::connect(actionLoad_Configuration, SIGNAL(triggered()), RT_MainClass, SLOT(loadConfigTriggered()));
        QObject::connect(actionClose_All_Windows, SIGNAL(triggered()), RT_MainClass, SLOT(closeAllWindows()));
        QObject::connect(showLogDetailCheckBox, SIGNAL(clicked()), RT_MainClass, SLOT(showLogDetailCheckBoxClicked()));
        QObject::connect(assignColorButton, SIGNAL(clicked()), RT_MainClass, SLOT(assignColor()));
        QObject::connect(clientActiveCheckBox, SIGNAL(clicked()), RT_MainClass, SLOT(clientActiveCheckBoxClicked()));
        QObject::connect(clientsStateComboBox, SIGNAL(activated(int)), RT_MainClass, SLOT(clientsStateComboBoxChanged(int)));
        QObject::connect(clientNewestOnTopCheckBox, SIGNAL(clicked()), RT_MainClass, SLOT(clientNewestOnTopCheckBoxClicked()));
        QObject::connect(clientScrollToBottomCheckBox, SIGNAL(clicked()), RT_MainClass, SLOT(clientScrollToBottomCheckBoxClicked()));
        QObject::connect(clientTabModeRadio, SIGNAL(clicked()), RT_MainClass, SLOT(clientTabModeRadioClicked()));
        QObject::connect(clientWindowModeRadio, SIGNAL(clicked()), RT_MainClass, SLOT(clientWindowModeRadioClicked()));
        QObject::connect(clientInput, SIGNAL(textChanged(QString)), RT_MainClass, SLOT(clientListSearchTextChanged(QString)));
        QObject::connect(activeCheckBox, SIGNAL(clicked()), RT_MainClass, SLOT(activeCheckBoxClicked()));
        QObject::connect(groupStateComboBox, SIGNAL(activated(int)), RT_MainClass, SLOT(groupStateComboBoxChanged(int)));
        QObject::connect(newestOnTopCheckBox, SIGNAL(clicked()), RT_MainClass, SLOT(newestOnTopCheckBoxClicked()));
        QObject::connect(scrollToBottomCheckBox, SIGNAL(clicked()), RT_MainClass, SLOT(scrollToBottomCheckBoxClicked()));
        QObject::connect(tabModeRadio, SIGNAL(clicked()), RT_MainClass, SLOT(tabModeRadioClicked()));
        QObject::connect(windowModeRadio, SIGNAL(clicked()), RT_MainClass, SLOT(windowModeRadioClicked()));
        QObject::connect(groupSearchInput, SIGNAL(textChanged(QString)), RT_MainClass, SLOT(groupListSearchTextChanged(QString)));
        QObject::connect(actionClear_All_MergeViews, SIGNAL(triggered()), RT_MainClass, SLOT(clearAllMergeViews()));
        QObject::connect(showFilterAreaCheckBox, SIGNAL(clicked()), RT_MainClass, SLOT(showFilterArea()));
        QObject::connect(showClientSectionCheckBox, SIGNAL(clicked()), RT_MainClass, SLOT(showClientSection()));
        QObject::connect(showGroupSectionCheckBox, SIGNAL(clicked()), RT_MainClass, SLOT(showGroupSection()));
        QObject::connect(inputField, SIGNAL(textChanged(QString)), RT_MainClass, SLOT(globalSearchTermChanged(QString)));
        QObject::connect(inputField, SIGNAL(returnPressed()), RT_MainClass, SLOT(executeFilterClicked()));
        QObject::connect(actionRestore_Default_Settings, SIGNAL(triggered()), RT_MainClass, SLOT(restoreDefaultSettings()));
        QObject::connect(actionRestart_Master, SIGNAL(triggered()), RT_MainClass, SLOT(restartMasterTriggered()));

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RT_MainClass);
    } // setupUi

    void retranslateUi(QMainWindow *RT_MainClass)
    {
        RT_MainClass->setWindowTitle(QApplication::translate("RT_MainClass", "RAD LogShark", 0));
        closeAppAction->setText(QApplication::translate("RT_MainClass", "Close", 0));
        closeAppAction->setShortcut(QApplication::translate("RT_MainClass", "Ctrl+Q", 0));
        importFileAction->setText(QApplication::translate("RT_MainClass", "Import", 0));
        importFileAction->setShortcut(QApplication::translate("RT_MainClass", "Ctrl+O", 0));
        actionExport->setText(QApplication::translate("RT_MainClass", "Export", 0));
        actionExport->setShortcut(QApplication::translate("RT_MainClass", "Ctrl+S", 0));
        actionAbout->setText(QApplication::translate("RT_MainClass", "About", 0));
        actionAbout->setShortcut(QApplication::translate("RT_MainClass", "Ctrl+F1", 0));
        actionSettings->setText(QApplication::translate("RT_MainClass", "Settings...", 0));
        actionSettings->setShortcut(QApplication::translate("RT_MainClass", "Ctrl+P", 0));
        actionShow_Inactive_Clients->setText(QApplication::translate("RT_MainClass", "Show Inactive Clients", 0));
        actionShow_Inactive_Clients->setShortcut(QApplication::translate("RT_MainClass", "Ctrl+I", 0));
        actionShow_Binary_Clients->setText(QApplication::translate("RT_MainClass", "Show Binary Clients", 0));
        actionShow_Binary_Clients->setShortcut(QApplication::translate("RT_MainClass", "Ctrl+B", 0));
        actionShow_Text_Clients->setText(QApplication::translate("RT_MainClass", "Show Text Clients", 0));
        actionShow_Text_Clients->setShortcut(QApplication::translate("RT_MainClass", "Ctrl+T", 0));
        actionHelp->setText(QApplication::translate("RT_MainClass", "Help", 0));
        actionHelp->setShortcut(QApplication::translate("RT_MainClass", "F1", 0));
        actionArrange_Windows->setText(QApplication::translate("RT_MainClass", "Arrange Windows", 0));
        actionArrange_Windows->setShortcut(QApplication::translate("RT_MainClass", "F9", 0));
        actionSelect_All_Groups->setText(QApplication::translate("RT_MainClass", "Select All Groups", 0));
        actionSelect_All_Groups->setShortcut(QApplication::translate("RT_MainClass", "F2", 0));
        actionSelect_All_Clients->setText(QApplication::translate("RT_MainClass", "Select All Clients", 0));
        actionSelect_All_Clients->setShortcut(QApplication::translate("RT_MainClass", "F3", 0));
        actionSelect_All_active->setText(QApplication::translate("RT_MainClass", "Select All (active)", 0));
        actionSelect_All_active->setShortcut(QApplication::translate("RT_MainClass", "F4", 0));
        actionReset_Selected_Clients->setText(QApplication::translate("RT_MainClass", "Reset Selected Clients", 0));
        actionReset_Selected_Clients->setShortcut(QApplication::translate("RT_MainClass", "F5", 0));
        actionReset_All_Clients->setText(QApplication::translate("RT_MainClass", "Reset All Clients", 0));
        actionReset_All_Clients->setShortcut(QApplication::translate("RT_MainClass", "F6", 0));
        actionAssign_Color->setText(QApplication::translate("RT_MainClass", "Assign Color To Selected...", 0));
        actionAssign_Color->setShortcut(QApplication::translate("RT_MainClass", "Ctrl+Y", 0));
        actionFreeze_All->setText(QApplication::translate("RT_MainClass", "Freeze All", 0));
        actionFreeze_All->setShortcut(QApplication::translate("RT_MainClass", "Ctrl+F", 0));
        actionUnfreeze_All->setText(QApplication::translate("RT_MainClass", "Unfreeze All", 0));
        actionUnfreeze_All->setShortcut(QApplication::translate("RT_MainClass", "Ctrl+U", 0));
        actionMinimize_All->setText(QApplication::translate("RT_MainClass", "Minimize All", 0));
        actionMinimize_All->setShortcut(QApplication::translate("RT_MainClass", "Ctrl+N", 0));
        actionMaximize_All->setText(QApplication::translate("RT_MainClass", "Maximize All", 0));
        actionMaximize_All->setShortcut(QApplication::translate("RT_MainClass", "Ctrl+M", 0));
        actionClear_Current_Table->setText(QApplication::translate("RT_MainClass", "Clear Current Table", 0));
        actionClear_Current_Table->setShortcut(QApplication::translate("RT_MainClass", "Ctrl+E", 0));
        actionClear_All_Tables->setText(QApplication::translate("RT_MainClass", "Clear All Tables", 0));
        actionClear_All_Tables->setShortcut(QApplication::translate("RT_MainClass", "Ctrl+R", 0));
        actionClose_All_Tabs->setText(QApplication::translate("RT_MainClass", "Close All Tabs", 0));
        actionClose_All_Tabs->setShortcut(QApplication::translate("RT_MainClass", "Alt+W", 0));
        actionLoad_Configuration->setText(QApplication::translate("RT_MainClass", "Load Configuration...", 0));
        actionLoad_Configuration->setShortcut(QApplication::translate("RT_MainClass", "Ctrl+L", 0));
        actionClose_All_Windows->setText(QApplication::translate("RT_MainClass", "Close All Windows", 0));
        actionClose_All_Windows->setShortcut(QApplication::translate("RT_MainClass", "Ctrl+W", 0));
        actionClear_All_MergeViews->setText(QApplication::translate("RT_MainClass", "Clear All MergeViews", 0));
        actionClear_All_MergeViews->setShortcut(QApplication::translate("RT_MainClass", "F7", 0));
        actionRestore_Default_Settings->setText(QApplication::translate("RT_MainClass", "Restore Default Settings", 0));
        actionRestore_Default_Settings->setShortcut(QApplication::translate("RT_MainClass", "Ctrl+Alt+S", 0));
        actionRestart_Master->setText(QApplication::translate("RT_MainClass", "Restart Master", 0));
        actionRestart_Master->setShortcut(QApplication::translate("RT_MainClass", "Shift+F5", 0));
#ifndef QT_NO_TOOLTIP
        centralWidget->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        centralWidget->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        label->setText(QApplication::translate("RT_MainClass", "Groups", 0));
#ifndef QT_NO_STATUSTIP
        groupSearchInput->setStatusTip(QApplication::translate("RT_MainClass", "Enter your group search here...", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        groupSearchInput->setWhatsThis(QApplication::translate("RT_MainClass", "Group search", 0));
#endif // QT_NO_WHATSTHIS
        groupSearchInput->setText(QString());
        groupSearchInput->setPlaceholderText(QApplication::translate("RT_MainClass", "Group Search Term...", 0));
#ifndef QT_NO_STATUSTIP
        activeCheckBox->setStatusTip(QApplication::translate("RT_MainClass", "Activates/Deactivates Group Logging", 0));
#endif // QT_NO_STATUSTIP
        activeCheckBox->setText(QApplication::translate("RT_MainClass", "Active", 0));
        groupStateComboBox->clear();
        groupStateComboBox->insertItems(0, QStringList()
         << QApplication::translate("RT_MainClass", "-", 0)
         << QApplication::translate("RT_MainClass", "Live", 0)
         << QApplication::translate("RT_MainClass", "To File", 0)
         << QApplication::translate("RT_MainClass", "To Ring File", 0)
         << QApplication::translate("RT_MainClass", "To Shared File", 0)
         << QApplication::translate("RT_MainClass", "To Global", 0)
        );
#ifndef QT_NO_STATUSTIP
        groupStateComboBox->setStatusTip(QApplication::translate("RT_MainClass", "Set Group State", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_STATUSTIP
        newestOnTopCheckBox->setStatusTip(QApplication::translate("RT_MainClass", "Activates/Deactivates Newest on Top for Client Log View. Will reset the model.", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        newestOnTopCheckBox->setWhatsThis(QApplication::translate("RT_MainClass", "Newest On Top", 0));
#endif // QT_NO_WHATSTHIS
        newestOnTopCheckBox->setText(QApplication::translate("RT_MainClass", "Newest on Top", 0));
#ifndef QT_NO_STATUSTIP
        scrollToBottomCheckBox->setStatusTip(QApplication::translate("RT_MainClass", "Activates Scroll To Bottom for Client Log View", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        scrollToBottomCheckBox->setWhatsThis(QApplication::translate("RT_MainClass", "Scroll To Bottom", 0));
#endif // QT_NO_WHATSTHIS
        scrollToBottomCheckBox->setText(QApplication::translate("RT_MainClass", "Scroll to Bottom", 0));
#ifndef QT_NO_STATUSTIP
        tabModeRadio->setStatusTip(QApplication::translate("RT_MainClass", "Shows Client in Tabbed Mode", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        tabModeRadio->setWhatsThis(QApplication::translate("RT_MainClass", "Tab Mode", 0));
#endif // QT_NO_WHATSTHIS
        tabModeRadio->setText(QApplication::translate("RT_MainClass", "Tab Mode", 0));
#ifndef QT_NO_STATUSTIP
        windowModeRadio->setStatusTip(QApplication::translate("RT_MainClass", "Shows Client in Windowed Mode", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        windowModeRadio->setWhatsThis(QApplication::translate("RT_MainClass", "Window Mode", 0));
#endif // QT_NO_WHATSTHIS
        windowModeRadio->setText(QApplication::translate("RT_MainClass", "Window Mode", 0));
#ifndef QT_NO_STATUSTIP
        groupList->setStatusTip(QApplication::translate("RT_MainClass", "Available groups list", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        groupList->setWhatsThis(QApplication::translate("RT_MainClass", "Group List", 0));
#endif // QT_NO_WHATSTHIS
        label_2->setText(QApplication::translate("RT_MainClass", "Clients", 0));
#ifndef QT_NO_STATUSTIP
        clientInput->setStatusTip(QApplication::translate("RT_MainClass", "Enter your client search here...", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        clientInput->setWhatsThis(QApplication::translate("RT_MainClass", "Client search", 0));
#endif // QT_NO_WHATSTHIS
        clientInput->setPlaceholderText(QApplication::translate("RT_MainClass", "Client Search Term...", 0));
#ifndef QT_NO_STATUSTIP
        clientActiveCheckBox->setStatusTip(QApplication::translate("RT_MainClass", "Activates/Deactives Client Logging", 0));
#endif // QT_NO_STATUSTIP
        clientActiveCheckBox->setText(QApplication::translate("RT_MainClass", "Active", 0));
        clientsStateComboBox->clear();
        clientsStateComboBox->insertItems(0, QStringList()
         << QApplication::translate("RT_MainClass", "-", 0)
         << QApplication::translate("RT_MainClass", "Live", 0)
         << QApplication::translate("RT_MainClass", "To File", 0)
         << QApplication::translate("RT_MainClass", "To Ring File", 0)
         << QApplication::translate("RT_MainClass", "To Shared File", 0)
         << QApplication::translate("RT_MainClass", "To Parent", 0)
         << QApplication::translate("RT_MainClass", "To Global", 0)
         << QApplication::translate("RT_MainClass", "To MergeView", 0)
        );
#ifndef QT_NO_STATUSTIP
        clientsStateComboBox->setStatusTip(QApplication::translate("RT_MainClass", "Sets Client state", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_STATUSTIP
        clientNewestOnTopCheckBox->setStatusTip(QApplication::translate("RT_MainClass", "Activates/Deactivates Newest on Top for Client Log View. Will reset the model.", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        clientNewestOnTopCheckBox->setWhatsThis(QApplication::translate("RT_MainClass", "Newest On Top", 0));
#endif // QT_NO_WHATSTHIS
        clientNewestOnTopCheckBox->setText(QApplication::translate("RT_MainClass", "Newest on Top", 0));
#ifndef QT_NO_STATUSTIP
        clientScrollToBottomCheckBox->setStatusTip(QApplication::translate("RT_MainClass", "Activates Scroll To Bottom for Client Log View", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        clientScrollToBottomCheckBox->setWhatsThis(QApplication::translate("RT_MainClass", "Scroll To Bottom", 0));
#endif // QT_NO_WHATSTHIS
        clientScrollToBottomCheckBox->setText(QApplication::translate("RT_MainClass", "Scroll to Bottom", 0));
#ifndef QT_NO_STATUSTIP
        clientTabModeRadio->setStatusTip(QApplication::translate("RT_MainClass", "Shows Client in Tabbed Mode", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        clientTabModeRadio->setWhatsThis(QApplication::translate("RT_MainClass", "Tab Mode", 0));
#endif // QT_NO_WHATSTHIS
        clientTabModeRadio->setText(QApplication::translate("RT_MainClass", "Tab Mode", 0));
#ifndef QT_NO_STATUSTIP
        clientWindowModeRadio->setStatusTip(QApplication::translate("RT_MainClass", "Shows Client in Windowed Mode", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        clientWindowModeRadio->setWhatsThis(QApplication::translate("RT_MainClass", "Window Mode", 0));
#endif // QT_NO_WHATSTHIS
        clientWindowModeRadio->setText(QApplication::translate("RT_MainClass", "Window Mode", 0));
#ifndef QT_NO_STATUSTIP
        clientList->setStatusTip(QApplication::translate("RT_MainClass", "Available clients list", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        clientList->setWhatsThis(QApplication::translate("RT_MainClass", "Client list", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        inputField->setToolTip(QApplication::translate("RT_MainClass", "Filter keywords: Date, Time, Client, Group, Kind, Content, ex. Kind=^Info$, The filter accepts regex expressions", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        inputField->setStatusTip(QApplication::translate("RT_MainClass", "Filter keywords: Date, Time, Client, Group, Kind, Content, ex. Kind=^Info$, The filter accepts regex expressions", 0));
#endif // QT_NO_STATUSTIP
        inputField->setPlaceholderText(QApplication::translate("RT_MainClass", "Filter expression here..", 0));
#ifndef QT_NO_STATUSTIP
        globalSearchCheckBox->setStatusTip(QApplication::translate("RT_MainClass", "Enables Global Mode for Filtering", 0));
#endif // QT_NO_STATUSTIP
        globalSearchCheckBox->setText(QApplication::translate("RT_MainClass", "Global Search", 0));
        caseSensitiveCheckBox->setText(QApplication::translate("RT_MainClass", "Case Sensitive", 0));
#ifndef QT_NO_STATUSTIP
        logDetailInput->setStatusTip(QApplication::translate("RT_MainClass", "Log details", 0));
#endif // QT_NO_STATUSTIP
        logDetailInput->setPlaceholderText(QApplication::translate("RT_MainClass", "Log Detail Output...", 0));
        messageStatesBox->setTitle(QApplication::translate("RT_MainClass", "Message States", 0));
#ifndef QT_NO_STATUSTIP
        enableInfoCheckBox->setStatusTip(QApplication::translate("RT_MainClass", "Enables Info Logs", 0));
#endif // QT_NO_STATUSTIP
        enableInfoCheckBox->setText(QApplication::translate("RT_MainClass", "Enable Info", 0));
#ifndef QT_NO_STATUSTIP
        enableWarningCheckBox->setStatusTip(QApplication::translate("RT_MainClass", "Enables Warning Logs", 0));
#endif // QT_NO_STATUSTIP
        enableWarningCheckBox->setText(QApplication::translate("RT_MainClass", "Enable Warning", 0));
#ifndef QT_NO_STATUSTIP
        enableErrorCheckBox->setStatusTip(QApplication::translate("RT_MainClass", "Enables Error Logs", 0));
#endif // QT_NO_STATUSTIP
        enableErrorCheckBox->setText(QApplication::translate("RT_MainClass", "Enable Error", 0));
#ifndef QT_NO_STATUSTIP
        enableExceptionCheckBox->setStatusTip(QApplication::translate("RT_MainClass", "Enalbes Exception Logs", 0));
#endif // QT_NO_STATUSTIP
        enableExceptionCheckBox->setText(QApplication::translate("RT_MainClass", "Enable Exception", 0));
#ifndef QT_NO_STATUSTIP
        enableFatalCheckBox->setStatusTip(QApplication::translate("RT_MainClass", "Enables Fatal Logs", 0));
#endif // QT_NO_STATUSTIP
        enableFatalCheckBox->setText(QApplication::translate("RT_MainClass", "Enable Fatal", 0));
#ifndef QT_NO_STATUSTIP
        enableBinaryCheckBox->setStatusTip(QApplication::translate("RT_MainClass", "Enables Binary Logs", 0));
#endif // QT_NO_STATUSTIP
        enableBinaryCheckBox->setText(QApplication::translate("RT_MainClass", "Enable Binary", 0));
        stampsBox->setTitle(QApplication::translate("RT_MainClass", "Stamps", 0));
#ifndef QT_NO_STATUSTIP
        useMessageHeaderCheckBox->setStatusTip(QApplication::translate("RT_MainClass", "Shows Kind Column", 0));
#endif // QT_NO_STATUSTIP
        useMessageHeaderCheckBox->setText(QApplication::translate("RT_MainClass", "Use Message Header", 0));
#ifndef QT_NO_STATUSTIP
        useTimeStampCheckBox->setStatusTip(QApplication::translate("RT_MainClass", "Shows Time Column", 0));
#endif // QT_NO_STATUSTIP
        useTimeStampCheckBox->setText(QApplication::translate("RT_MainClass", "Use Time Stamp", 0));
#ifndef QT_NO_STATUSTIP
        useDateStampCheckBox->setStatusTip(QApplication::translate("RT_MainClass", "Shows Date Column", 0));
#endif // QT_NO_STATUSTIP
        useDateStampCheckBox->setText(QApplication::translate("RT_MainClass", "Use Date Stamp", 0));
#ifndef QT_NO_STATUSTIP
        useContentStampCheckBox->setStatusTip(QApplication::translate("RT_MainClass", "Shows Content Column", 0));
#endif // QT_NO_STATUSTIP
        useContentStampCheckBox->setText(QApplication::translate("RT_MainClass", "Use Content Stamp", 0));
#ifndef QT_NO_STATUSTIP
        useGroupStampCheckBox->setStatusTip(QApplication::translate("RT_MainClass", "Shows Group Column", 0));
#endif // QT_NO_STATUSTIP
        useGroupStampCheckBox->setText(QApplication::translate("RT_MainClass", "Use Group Stamp", 0));
#ifndef QT_NO_STATUSTIP
        useClientStampCheckBox->setStatusTip(QApplication::translate("RT_MainClass", "Shows Client Column", 0));
#endif // QT_NO_STATUSTIP
        useClientStampCheckBox->setText(QApplication::translate("RT_MainClass", "Use Client Stamp", 0));
        bufferTriggersBox->setTitle(QApplication::translate("RT_MainClass", "Buffer Triggers", 0));
#ifndef QT_NO_STATUSTIP
        infoMessageCheckBox->setStatusTip(QApplication::translate("RT_MainClass", "Enables buffering for Info Logs", 0));
#endif // QT_NO_STATUSTIP
        infoMessageCheckBox->setText(QApplication::translate("RT_MainClass", "Info Message", 0));
#ifndef QT_NO_STATUSTIP
        warningMessageCheckBox->setStatusTip(QApplication::translate("RT_MainClass", "Enables buffering for Warning Logs", 0));
#endif // QT_NO_STATUSTIP
        warningMessageCheckBox->setText(QApplication::translate("RT_MainClass", "Warning Message", 0));
#ifndef QT_NO_STATUSTIP
        errorMessageCheckBox->setStatusTip(QApplication::translate("RT_MainClass", "Enables buffering for Error Logs", 0));
#endif // QT_NO_STATUSTIP
        errorMessageCheckBox->setText(QApplication::translate("RT_MainClass", "Error Message", 0));
#ifndef QT_NO_STATUSTIP
        exceptionMessageCheckBox->setStatusTip(QApplication::translate("RT_MainClass", "Enables buffering for Exception Logs", 0));
#endif // QT_NO_STATUSTIP
        exceptionMessageCheckBox->setText(QApplication::translate("RT_MainClass", "Exception Message", 0));
#ifndef QT_NO_STATUSTIP
        fatalMessageCheckBox->setStatusTip(QApplication::translate("RT_MainClass", "Enables buffering for Fatal Logs", 0));
#endif // QT_NO_STATUSTIP
        fatalMessageCheckBox->setText(QApplication::translate("RT_MainClass", "Fatal Message", 0));
        groupBox->setTitle(QApplication::translate("RT_MainClass", "Application Output", 0));
        toolBox->setItemText(toolBox->indexOf(standardFiltersPage), QApplication::translate("RT_MainClass", "Global Log Settings", 0));
        contentSectionBox->setTitle(QApplication::translate("RT_MainClass", "Content Section", 0));
        showLogDetailCheckBox->setText(QApplication::translate("RT_MainClass", "Show Log Detail", 0));
        showFilterAreaCheckBox->setText(QApplication::translate("RT_MainClass", "Show Filter Area", 0));
        assignColorButton->setText(QApplication::translate("RT_MainClass", "Assign Color To Selected...", 0));
        showGroupSectionCheckBox->setText(QApplication::translate("RT_MainClass", "Show Group Section", 0));
        showClientSectionCheckBox->setText(QApplication::translate("RT_MainClass", "Show Client Section", 0));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("RT_MainClass", "View Settings", 0));
        menuFile->setTitle(QApplication::translate("RT_MainClass", "File", 0));
        menuHelp->setTitle(QApplication::translate("RT_MainClass", "Help", 0));
        menuSystem->setTitle(QApplication::translate("RT_MainClass", "System", 0));
        menuEdit->setTitle(QApplication::translate("RT_MainClass", "Edit", 0));
        menuView->setTitle(QApplication::translate("RT_MainClass", "View", 0));
    } // retranslateUi

};

namespace Ui {
    class RT_MainClass: public Ui_RT_MainClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RT_MAIN_H
