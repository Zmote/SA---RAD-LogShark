/********************************************************************************
** Form generated from reading UI file 'RT_LogWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RT_LOGWINDOW_H
#define UI_RT_LOGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
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
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExport;
    QAction *actionClose;
    QAction *actionClear;
    QAction *actionMinimize;
    QAction *actionMinimize_All;
    QAction *actionArrange_Windows;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *fw_taskBarLayout;
    QCheckBox *fw_activeCheckBox;
    QFrame *activeClientStateLine;
    QComboBox *fw_clientStateComboBox;
    QFrame *clientStateNewestOnTopLine;
    QCheckBox *fw_newestOnTopCheckBox;
    QCheckBox *fw_scrollToBottomCheckBox;
    QFrame *scrollToBottomTabModeLine;
    QRadioButton *fw_tabModeRadio;
    QRadioButton *fw_windowModeRadio;
    QFrame *line;
    QLabel *label;
    QCheckBox *fw_caseSensitiveCheckBox;
    QLineEdit *fw_inputFilter;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QGridLayout *mainContentGrid;
    QPlainTextEdit *fw_logDetailInput;
    QHBoxLayout *fw_buttonBarLayout;
    QPushButton *fw_exportButton;
    QFrame *exportLine;
    QPushButton *fw_freezeButton;
    QPlainTextEdit *fw_freezeState;
    QFrame *freezeUnfreezeLine;
    QPushButton *fw_freezeAllButton;
    QFrame *line_8;
    QPushButton *fw_minimizeButton;
    QFrame *line_9;
    QPushButton *fw_minimizeAllButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1116, 734);
        actionExport = new QAction(MainWindow);
        actionExport->setObjectName(QStringLiteral("actionExport"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        actionMinimize = new QAction(MainWindow);
        actionMinimize->setObjectName(QStringLiteral("actionMinimize"));
        actionMinimize_All = new QAction(MainWindow);
        actionMinimize_All->setObjectName(QStringLiteral("actionMinimize_All"));
        actionArrange_Windows = new QAction(MainWindow);
        actionArrange_Windows->setObjectName(QStringLiteral("actionArrange_Windows"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        fw_taskBarLayout = new QHBoxLayout();
        fw_taskBarLayout->setObjectName(QStringLiteral("fw_taskBarLayout"));
        fw_activeCheckBox = new QCheckBox(centralwidget);
        fw_activeCheckBox->setObjectName(QStringLiteral("fw_activeCheckBox"));
        fw_activeCheckBox->setMaximumSize(QSize(16777215, 25));

        fw_taskBarLayout->addWidget(fw_activeCheckBox);

        activeClientStateLine = new QFrame(centralwidget);
        activeClientStateLine->setObjectName(QStringLiteral("activeClientStateLine"));
        activeClientStateLine->setMaximumSize(QSize(16777215, 15));
        activeClientStateLine->setFrameShape(QFrame::VLine);
        activeClientStateLine->setFrameShadow(QFrame::Sunken);

        fw_taskBarLayout->addWidget(activeClientStateLine);

        fw_clientStateComboBox = new QComboBox(centralwidget);
        fw_clientStateComboBox->setObjectName(QStringLiteral("fw_clientStateComboBox"));
        fw_clientStateComboBox->setMaximumSize(QSize(16777215, 20));

        fw_taskBarLayout->addWidget(fw_clientStateComboBox);

        clientStateNewestOnTopLine = new QFrame(centralwidget);
        clientStateNewestOnTopLine->setObjectName(QStringLiteral("clientStateNewestOnTopLine"));
        clientStateNewestOnTopLine->setMaximumSize(QSize(16777215, 15));
        clientStateNewestOnTopLine->setFrameShape(QFrame::VLine);
        clientStateNewestOnTopLine->setFrameShadow(QFrame::Sunken);

        fw_taskBarLayout->addWidget(clientStateNewestOnTopLine);

        fw_newestOnTopCheckBox = new QCheckBox(centralwidget);
        fw_newestOnTopCheckBox->setObjectName(QStringLiteral("fw_newestOnTopCheckBox"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(fw_newestOnTopCheckBox->sizePolicy().hasHeightForWidth());
        fw_newestOnTopCheckBox->setSizePolicy(sizePolicy);
        fw_newestOnTopCheckBox->setMaximumSize(QSize(16777215, 25));

        fw_taskBarLayout->addWidget(fw_newestOnTopCheckBox);

        fw_scrollToBottomCheckBox = new QCheckBox(centralwidget);
        fw_scrollToBottomCheckBox->setObjectName(QStringLiteral("fw_scrollToBottomCheckBox"));
        sizePolicy.setHeightForWidth(fw_scrollToBottomCheckBox->sizePolicy().hasHeightForWidth());
        fw_scrollToBottomCheckBox->setSizePolicy(sizePolicy);
        fw_scrollToBottomCheckBox->setMaximumSize(QSize(16777215, 25));

        fw_taskBarLayout->addWidget(fw_scrollToBottomCheckBox);

        scrollToBottomTabModeLine = new QFrame(centralwidget);
        scrollToBottomTabModeLine->setObjectName(QStringLiteral("scrollToBottomTabModeLine"));
        scrollToBottomTabModeLine->setMaximumSize(QSize(16777215, 15));
        scrollToBottomTabModeLine->setFrameShape(QFrame::VLine);
        scrollToBottomTabModeLine->setFrameShadow(QFrame::Sunken);

        fw_taskBarLayout->addWidget(scrollToBottomTabModeLine);

        fw_tabModeRadio = new QRadioButton(centralwidget);
        fw_tabModeRadio->setObjectName(QStringLiteral("fw_tabModeRadio"));
        sizePolicy.setHeightForWidth(fw_tabModeRadio->sizePolicy().hasHeightForWidth());
        fw_tabModeRadio->setSizePolicy(sizePolicy);
        fw_tabModeRadio->setMaximumSize(QSize(16777215, 25));

        fw_taskBarLayout->addWidget(fw_tabModeRadio);

        fw_windowModeRadio = new QRadioButton(centralwidget);
        fw_windowModeRadio->setObjectName(QStringLiteral("fw_windowModeRadio"));
        sizePolicy.setHeightForWidth(fw_windowModeRadio->sizePolicy().hasHeightForWidth());
        fw_windowModeRadio->setSizePolicy(sizePolicy);
        fw_windowModeRadio->setMaximumSize(QSize(16777215, 25));

        fw_taskBarLayout->addWidget(fw_windowModeRadio);

        line = new QFrame(centralwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setMaximumSize(QSize(16777215, 15));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        fw_taskBarLayout->addWidget(line);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 25));

        fw_taskBarLayout->addWidget(label);

        fw_caseSensitiveCheckBox = new QCheckBox(centralwidget);
        fw_caseSensitiveCheckBox->setObjectName(QStringLiteral("fw_caseSensitiveCheckBox"));
        fw_caseSensitiveCheckBox->setMaximumSize(QSize(16777215, 25));

        fw_taskBarLayout->addWidget(fw_caseSensitiveCheckBox);

        fw_inputFilter = new QLineEdit(centralwidget);
        fw_inputFilter->setObjectName(QStringLiteral("fw_inputFilter"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(fw_inputFilter->sizePolicy().hasHeightForWidth());
        fw_inputFilter->setSizePolicy(sizePolicy1);
        fw_inputFilter->setMinimumSize(QSize(150, 25));
        fw_inputFilter->setMaximumSize(QSize(1650505, 25));
        QFont font;
        font.setPointSize(10);
        fw_inputFilter->setFont(font);

        fw_taskBarLayout->addWidget(fw_inputFilter);


        verticalLayout->addLayout(fw_taskBarLayout);

        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        mainContentGrid = new QGridLayout(layoutWidget);
        mainContentGrid->setObjectName(QStringLiteral("mainContentGrid"));
        mainContentGrid->setSizeConstraint(QLayout::SetDefaultConstraint);
        mainContentGrid->setContentsMargins(0, 0, 0, 0);
        splitter->addWidget(layoutWidget);
        fw_logDetailInput = new QPlainTextEdit(splitter);
        fw_logDetailInput->setObjectName(QStringLiteral("fw_logDetailInput"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(5);
        sizePolicy2.setHeightForWidth(fw_logDetailInput->sizePolicy().hasHeightForWidth());
        fw_logDetailInput->setSizePolicy(sizePolicy2);
        fw_logDetailInput->setMinimumSize(QSize(0, 80));
        fw_logDetailInput->setMaximumSize(QSize(16777215, 16777215));
        splitter->addWidget(fw_logDetailInput);

        verticalLayout->addWidget(splitter);

        fw_buttonBarLayout = new QHBoxLayout();
        fw_buttonBarLayout->setObjectName(QStringLiteral("fw_buttonBarLayout"));
        fw_buttonBarLayout->setSizeConstraint(QLayout::SetFixedSize);
        fw_exportButton = new QPushButton(centralwidget);
        fw_exportButton->setObjectName(QStringLiteral("fw_exportButton"));
        fw_exportButton->setMaximumSize(QSize(16777215, 30));

        fw_buttonBarLayout->addWidget(fw_exportButton);

        exportLine = new QFrame(centralwidget);
        exportLine->setObjectName(QStringLiteral("exportLine"));
        exportLine->setMaximumSize(QSize(16777215, 30));
        exportLine->setFrameShape(QFrame::VLine);
        exportLine->setFrameShadow(QFrame::Sunken);

        fw_buttonBarLayout->addWidget(exportLine);

        fw_freezeButton = new QPushButton(centralwidget);
        fw_freezeButton->setObjectName(QStringLiteral("fw_freezeButton"));
        fw_freezeButton->setMaximumSize(QSize(16777215, 30));

        fw_buttonBarLayout->addWidget(fw_freezeButton);

        fw_freezeState = new QPlainTextEdit(centralwidget);
        fw_freezeState->setObjectName(QStringLiteral("fw_freezeState"));
        fw_freezeState->setEnabled(true);
        fw_freezeState->setMaximumSize(QSize(10, 25));
        QFont font1;
        font1.setKerning(false);
        fw_freezeState->setFont(font1);
        fw_freezeState->setFocusPolicy(Qt::NoFocus);
        fw_freezeState->setAcceptDrops(false);
        fw_freezeState->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        fw_freezeState->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        fw_freezeState->setDocumentTitle(QStringLiteral(""));
        fw_freezeState->setUndoRedoEnabled(false);
        fw_freezeState->setLineWrapMode(QPlainTextEdit::NoWrap);
        fw_freezeState->setReadOnly(true);
        fw_freezeState->setTextInteractionFlags(Qt::NoTextInteraction);

        fw_buttonBarLayout->addWidget(fw_freezeState);

        freezeUnfreezeLine = new QFrame(centralwidget);
        freezeUnfreezeLine->setObjectName(QStringLiteral("freezeUnfreezeLine"));
        freezeUnfreezeLine->setMaximumSize(QSize(16777215, 30));
        freezeUnfreezeLine->setFrameShape(QFrame::VLine);
        freezeUnfreezeLine->setFrameShadow(QFrame::Sunken);

        fw_buttonBarLayout->addWidget(freezeUnfreezeLine);

        fw_freezeAllButton = new QPushButton(centralwidget);
        fw_freezeAllButton->setObjectName(QStringLiteral("fw_freezeAllButton"));
        fw_freezeAllButton->setMaximumSize(QSize(16777215, 30));

        fw_buttonBarLayout->addWidget(fw_freezeAllButton);

        line_8 = new QFrame(centralwidget);
        line_8->setObjectName(QStringLiteral("line_8"));
        line_8->setMaximumSize(QSize(16777215, 30));
        line_8->setFrameShape(QFrame::VLine);
        line_8->setFrameShadow(QFrame::Sunken);

        fw_buttonBarLayout->addWidget(line_8);

        fw_minimizeButton = new QPushButton(centralwidget);
        fw_minimizeButton->setObjectName(QStringLiteral("fw_minimizeButton"));
        fw_minimizeButton->setMaximumSize(QSize(16777215, 30));

        fw_buttonBarLayout->addWidget(fw_minimizeButton);

        line_9 = new QFrame(centralwidget);
        line_9->setObjectName(QStringLiteral("line_9"));
        line_9->setMaximumSize(QSize(16777215, 30));
        line_9->setFrameShape(QFrame::VLine);
        line_9->setFrameShadow(QFrame::Sunken);

        fw_buttonBarLayout->addWidget(line_9);

        fw_minimizeAllButton = new QPushButton(centralwidget);
        fw_minimizeAllButton->setObjectName(QStringLiteral("fw_minimizeAllButton"));
        fw_minimizeAllButton->setMaximumSize(QSize(16777215, 30));

        fw_buttonBarLayout->addWidget(fw_minimizeAllButton);


        verticalLayout->addLayout(fw_buttonBarLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1116, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QStringLiteral("menuView"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuView->menuAction());
        menuFile->addAction(actionExport);
        menuFile->addAction(actionClose);
        menuEdit->addAction(actionClear);
        menuView->addAction(actionMinimize);
        menuView->addAction(actionMinimize_All);
        menuView->addSeparator();
        menuView->addAction(actionArrange_Windows);

        retranslateUi(MainWindow);
        QObject::connect(fw_activeCheckBox, SIGNAL(clicked()), MainWindow, SLOT(activeCheckBoxClicked()));
        QObject::connect(fw_newestOnTopCheckBox, SIGNAL(clicked()), MainWindow, SLOT(newestOnTopCheckBoxClicked()));
        QObject::connect(fw_scrollToBottomCheckBox, SIGNAL(clicked()), MainWindow, SLOT(scrollToBottomCheckBoxClicked()));
        QObject::connect(fw_tabModeRadio, SIGNAL(clicked()), MainWindow, SLOT(tabModeRadioClicked()));
        QObject::connect(fw_windowModeRadio, SIGNAL(clicked()), MainWindow, SLOT(windowModeRadioClicked()));
        QObject::connect(fw_exportButton, SIGNAL(clicked()), MainWindow, SLOT(exportButtonClicked()));
        QObject::connect(fw_freezeButton, SIGNAL(clicked()), MainWindow, SLOT(freezeButtonClicked()));
        QObject::connect(fw_freezeAllButton, SIGNAL(clicked()), MainWindow, SLOT(freezeAllButtonClicked()));
        QObject::connect(fw_minimizeButton, SIGNAL(clicked()), MainWindow, SLOT(minimizeButtonClicked()));
        QObject::connect(fw_minimizeAllButton, SIGNAL(clicked()), MainWindow, SLOT(minimizeAllButtonClicked()));
        QObject::connect(fw_inputFilter, SIGNAL(textChanged(QString)), MainWindow, SLOT(filterInputTextChanged(QString)));
        QObject::connect(fw_inputFilter, SIGNAL(returnPressed()), MainWindow, SLOT(inputFilterEnterPressed()));
        QObject::connect(actionClose, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(actionClear, SIGNAL(triggered()), MainWindow, SLOT(clearTable()));
        QObject::connect(actionExport, SIGNAL(triggered()), MainWindow, SLOT(exportButtonClicked()));
        QObject::connect(actionMinimize, SIGNAL(triggered()), MainWindow, SLOT(minimizeButtonClicked()));
        QObject::connect(actionMinimize_All, SIGNAL(triggered()), MainWindow, SLOT(minimizeAllButtonClicked()));
        QObject::connect(actionArrange_Windows, SIGNAL(triggered()), MainWindow, SLOT(arrangeWindowsTriggered()));
        QObject::connect(fw_clientStateComboBox, SIGNAL(activated(int)), MainWindow, SLOT(clientStateComboBoxChanged(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionExport->setText(QApplication::translate("MainWindow", "Export", 0));
        actionExport->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        actionClose->setText(QApplication::translate("MainWindow", "Close", 0));
        actionClose->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        actionClear->setText(QApplication::translate("MainWindow", "Clear Table", 0));
        actionClear->setShortcut(QApplication::translate("MainWindow", "Ctrl+E", 0));
        actionMinimize->setText(QApplication::translate("MainWindow", "Minimize", 0));
        actionMinimize->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        actionMinimize_All->setText(QApplication::translate("MainWindow", "Minimize All", 0));
        actionMinimize_All->setShortcut(QApplication::translate("MainWindow", "Ctrl+W", 0));
        actionArrange_Windows->setText(QApplication::translate("MainWindow", "Arrange Windows", 0));
        actionArrange_Windows->setShortcut(QApplication::translate("MainWindow", "F9", 0));
        fw_activeCheckBox->setText(QApplication::translate("MainWindow", "Active", 0));
        fw_clientStateComboBox->clear();
        fw_clientStateComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "-", 0)
         << QApplication::translate("MainWindow", "Live", 0)
         << QApplication::translate("MainWindow", "To File", 0)
         << QApplication::translate("MainWindow", "To Ring File", 0)
         << QApplication::translate("MainWindow", "To Shared File", 0)
         << QApplication::translate("MainWindow", "To Parent", 0)
         << QApplication::translate("MainWindow", "To Global", 0)
        );
        fw_newestOnTopCheckBox->setText(QApplication::translate("MainWindow", "Newest on Top", 0));
        fw_scrollToBottomCheckBox->setText(QApplication::translate("MainWindow", "Scroll To Bottom", 0));
        fw_tabModeRadio->setText(QApplication::translate("MainWindow", "Tab Mode", 0));
        fw_windowModeRadio->setText(QApplication::translate("MainWindow", "Window Mode", 0));
        label->setText(QApplication::translate("MainWindow", "Search:", 0));
        fw_caseSensitiveCheckBox->setText(QApplication::translate("MainWindow", "Case Sensitive", 0));
        fw_inputFilter->setPlaceholderText(QApplication::translate("MainWindow", "Filter expression here.", 0));
        fw_exportButton->setText(QApplication::translate("MainWindow", "Export", 0));
        fw_freezeButton->setText(QApplication::translate("MainWindow", "Freeze/Unfreeze", 0));
        fw_freezeAllButton->setText(QApplication::translate("MainWindow", "Freeze/Unfreeze all", 0));
        fw_minimizeButton->setText(QApplication::translate("MainWindow", "Minimize", 0));
        fw_minimizeAllButton->setText(QApplication::translate("MainWindow", "Minimize all", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RT_LOGWINDOW_H
