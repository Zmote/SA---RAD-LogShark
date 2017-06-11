/********************************************************************************
** Form generated from reading UI file 'RT_SettingsWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RT_SETTINGSWINDOW_H
#define UI_RT_SETTINGSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *configurationLabel;
    QLabel *configurationNameLabel;
    QLabel *baseSaveLocationLabel;
    QHBoxLayout *baseSaveLocationVerticalLayout;
    QLineEdit *baseSaveLocationInput;
    QToolButton *baseSaveLocationBrowserButton;
    QLabel *toFileSaveLocationLabel;
    QHBoxLayout *toFileSaveLocationVerticalLayout;
    QLineEdit *toFileSaveLocationInput;
    QToolButton *toFileSaveLocationBrowserButton;
    QLabel *toSharedSaveLocationLabel;
    QHBoxLayout *toSharedFileSaveLocationVerticalLayout;
    QLineEdit *toSharedSaveLocationInput;
    QToolButton *toSharedSaveLocationBrowserButton;
    QLabel *toRingFileSaveLocationLabel;
    QHBoxLayout *toRingFileSavelocationVerticalLayout;
    QLineEdit *toRingFileSaveLocationInput;
    QToolButton *toRingFileSaveLocationBrowserButton;
    QFrame *locationDivider;
    QLabel *tableLogBufferLimitLabel;
    QLineEdit *logBufferLimitInput;
    QLabel *ringBufferLimitLabel;
    QLineEdit *ringBufferLimitInput;
    QLabel *messageBufferLimitLabel;
    QLineEdit *messageBufferLimitInput;
    QLabel *allowAutoRegistrationLabel;
    QCheckBox *allowAutoRegistrationCheckBox;
    QFrame *frame;
    QGroupBox *groupBox;
    QLabel *persistInfoEmptyLabel;
    QLabel *persistSettingsInfoLabel;
    QLabel *persistSettingsLabel;
    QCheckBox *persistSettingsCheckBox;
    QGroupBox *clientSettingsBox;
    QRadioButton *onlyActiveClientsRadio;
    QRadioButton *onlySelectedClientsRadio;
    QRadioButton *allClientsRadio;
    QRadioButton *noClientsRadio;
    QGroupBox *groupSettingsBox;
    QRadioButton *allGroupsRadio;
    QRadioButton *onlySelectedGroupsRadio;
    QRadioButton *onlyActiveGroupsRadio;
    QRadioButton *noGroupsRadio;
    QLabel *persistFileNameLabel;
    QHBoxLayout *persistFileVerticalLayout;
    QLineEdit *persistFileNameInput;
    QLabel *globalLogSettingsLabel;
    QCheckBox *globalLogSettingsCheckBox;
    QLabel *viewSettingsLabel;
    QCheckBox *viewSettingsCheckBox;
    QLabel *label;
    QLineEdit *masterHostInput;
    QLabel *label_2;
    QLineEdit *masterPortInput;
    QHBoxLayout *horizontalLayout;
    QPushButton *saveButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(560, 544);
        Form->setMinimumSize(QSize(560, 0));
        gridLayout = new QGridLayout(Form);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        configurationLabel = new QLabel(Form);
        configurationLabel->setObjectName(QStringLiteral("configurationLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, configurationLabel);

        configurationNameLabel = new QLabel(Form);
        configurationNameLabel->setObjectName(QStringLiteral("configurationNameLabel"));

        formLayout->setWidget(0, QFormLayout::FieldRole, configurationNameLabel);

        baseSaveLocationLabel = new QLabel(Form);
        baseSaveLocationLabel->setObjectName(QStringLiteral("baseSaveLocationLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, baseSaveLocationLabel);

        baseSaveLocationVerticalLayout = new QHBoxLayout();
        baseSaveLocationVerticalLayout->setObjectName(QStringLiteral("baseSaveLocationVerticalLayout"));
        baseSaveLocationInput = new QLineEdit(Form);
        baseSaveLocationInput->setObjectName(QStringLiteral("baseSaveLocationInput"));

        baseSaveLocationVerticalLayout->addWidget(baseSaveLocationInput);

        baseSaveLocationBrowserButton = new QToolButton(Form);
        baseSaveLocationBrowserButton->setObjectName(QStringLiteral("baseSaveLocationBrowserButton"));

        baseSaveLocationVerticalLayout->addWidget(baseSaveLocationBrowserButton);


        formLayout->setLayout(1, QFormLayout::FieldRole, baseSaveLocationVerticalLayout);

        toFileSaveLocationLabel = new QLabel(Form);
        toFileSaveLocationLabel->setObjectName(QStringLiteral("toFileSaveLocationLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, toFileSaveLocationLabel);

        toFileSaveLocationVerticalLayout = new QHBoxLayout();
        toFileSaveLocationVerticalLayout->setObjectName(QStringLiteral("toFileSaveLocationVerticalLayout"));
        toFileSaveLocationInput = new QLineEdit(Form);
        toFileSaveLocationInput->setObjectName(QStringLiteral("toFileSaveLocationInput"));

        toFileSaveLocationVerticalLayout->addWidget(toFileSaveLocationInput);

        toFileSaveLocationBrowserButton = new QToolButton(Form);
        toFileSaveLocationBrowserButton->setObjectName(QStringLiteral("toFileSaveLocationBrowserButton"));

        toFileSaveLocationVerticalLayout->addWidget(toFileSaveLocationBrowserButton);


        formLayout->setLayout(2, QFormLayout::FieldRole, toFileSaveLocationVerticalLayout);

        toSharedSaveLocationLabel = new QLabel(Form);
        toSharedSaveLocationLabel->setObjectName(QStringLiteral("toSharedSaveLocationLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, toSharedSaveLocationLabel);

        toSharedFileSaveLocationVerticalLayout = new QHBoxLayout();
        toSharedFileSaveLocationVerticalLayout->setObjectName(QStringLiteral("toSharedFileSaveLocationVerticalLayout"));
        toSharedSaveLocationInput = new QLineEdit(Form);
        toSharedSaveLocationInput->setObjectName(QStringLiteral("toSharedSaveLocationInput"));

        toSharedFileSaveLocationVerticalLayout->addWidget(toSharedSaveLocationInput);

        toSharedSaveLocationBrowserButton = new QToolButton(Form);
        toSharedSaveLocationBrowserButton->setObjectName(QStringLiteral("toSharedSaveLocationBrowserButton"));

        toSharedFileSaveLocationVerticalLayout->addWidget(toSharedSaveLocationBrowserButton);


        formLayout->setLayout(4, QFormLayout::FieldRole, toSharedFileSaveLocationVerticalLayout);

        toRingFileSaveLocationLabel = new QLabel(Form);
        toRingFileSaveLocationLabel->setObjectName(QStringLiteral("toRingFileSaveLocationLabel"));

        formLayout->setWidget(5, QFormLayout::LabelRole, toRingFileSaveLocationLabel);

        toRingFileSavelocationVerticalLayout = new QHBoxLayout();
        toRingFileSavelocationVerticalLayout->setObjectName(QStringLiteral("toRingFileSavelocationVerticalLayout"));
        toRingFileSaveLocationInput = new QLineEdit(Form);
        toRingFileSaveLocationInput->setObjectName(QStringLiteral("toRingFileSaveLocationInput"));

        toRingFileSavelocationVerticalLayout->addWidget(toRingFileSaveLocationInput);

        toRingFileSaveLocationBrowserButton = new QToolButton(Form);
        toRingFileSaveLocationBrowserButton->setObjectName(QStringLiteral("toRingFileSaveLocationBrowserButton"));

        toRingFileSavelocationVerticalLayout->addWidget(toRingFileSaveLocationBrowserButton);


        formLayout->setLayout(5, QFormLayout::FieldRole, toRingFileSavelocationVerticalLayout);

        locationDivider = new QFrame(Form);
        locationDivider->setObjectName(QStringLiteral("locationDivider"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(locationDivider->sizePolicy().hasHeightForWidth());
        locationDivider->setSizePolicy(sizePolicy);
        locationDivider->setFrameShape(QFrame::HLine);
        locationDivider->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(6, QFormLayout::LabelRole, locationDivider);

        tableLogBufferLimitLabel = new QLabel(Form);
        tableLogBufferLimitLabel->setObjectName(QStringLiteral("tableLogBufferLimitLabel"));

        formLayout->setWidget(7, QFormLayout::LabelRole, tableLogBufferLimitLabel);

        logBufferLimitInput = new QLineEdit(Form);
        logBufferLimitInput->setObjectName(QStringLiteral("logBufferLimitInput"));
        logBufferLimitInput->setMaximumSize(QSize(200, 16777215));

        formLayout->setWidget(7, QFormLayout::FieldRole, logBufferLimitInput);

        ringBufferLimitLabel = new QLabel(Form);
        ringBufferLimitLabel->setObjectName(QStringLiteral("ringBufferLimitLabel"));

        formLayout->setWidget(8, QFormLayout::LabelRole, ringBufferLimitLabel);

        ringBufferLimitInput = new QLineEdit(Form);
        ringBufferLimitInput->setObjectName(QStringLiteral("ringBufferLimitInput"));
        ringBufferLimitInput->setMaximumSize(QSize(200, 16777215));

        formLayout->setWidget(8, QFormLayout::FieldRole, ringBufferLimitInput);

        messageBufferLimitLabel = new QLabel(Form);
        messageBufferLimitLabel->setObjectName(QStringLiteral("messageBufferLimitLabel"));

        formLayout->setWidget(9, QFormLayout::LabelRole, messageBufferLimitLabel);

        messageBufferLimitInput = new QLineEdit(Form);
        messageBufferLimitInput->setObjectName(QStringLiteral("messageBufferLimitInput"));
        messageBufferLimitInput->setMaximumSize(QSize(200, 16777215));

        formLayout->setWidget(9, QFormLayout::FieldRole, messageBufferLimitInput);

        allowAutoRegistrationLabel = new QLabel(Form);
        allowAutoRegistrationLabel->setObjectName(QStringLiteral("allowAutoRegistrationLabel"));

        formLayout->setWidget(12, QFormLayout::LabelRole, allowAutoRegistrationLabel);

        allowAutoRegistrationCheckBox = new QCheckBox(Form);
        allowAutoRegistrationCheckBox->setObjectName(QStringLiteral("allowAutoRegistrationCheckBox"));

        formLayout->setWidget(12, QFormLayout::FieldRole, allowAutoRegistrationCheckBox);

        frame = new QFrame(Form);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(0, 5));
        frame->setAutoFillBackground(false);
        frame->setStyleSheet(QStringLiteral(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        formLayout->setWidget(13, QFormLayout::LabelRole, frame);

        groupBox = new QGroupBox(Form);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setAlignment(Qt::AlignCenter);
        groupBox->setFlat(true);
        groupBox->setCheckable(false);

        formLayout->setWidget(14, QFormLayout::SpanningRole, groupBox);

        persistInfoEmptyLabel = new QLabel(Form);
        persistInfoEmptyLabel->setObjectName(QStringLiteral("persistInfoEmptyLabel"));

        formLayout->setWidget(15, QFormLayout::LabelRole, persistInfoEmptyLabel);

        persistSettingsInfoLabel = new QLabel(Form);
        persistSettingsInfoLabel->setObjectName(QStringLiteral("persistSettingsInfoLabel"));

        formLayout->setWidget(15, QFormLayout::FieldRole, persistSettingsInfoLabel);

        persistSettingsLabel = new QLabel(Form);
        persistSettingsLabel->setObjectName(QStringLiteral("persistSettingsLabel"));

        formLayout->setWidget(16, QFormLayout::LabelRole, persistSettingsLabel);

        persistSettingsCheckBox = new QCheckBox(Form);
        persistSettingsCheckBox->setObjectName(QStringLiteral("persistSettingsCheckBox"));

        formLayout->setWidget(16, QFormLayout::FieldRole, persistSettingsCheckBox);

        clientSettingsBox = new QGroupBox(Form);
        clientSettingsBox->setObjectName(QStringLiteral("clientSettingsBox"));
        clientSettingsBox->setEnabled(false);
        clientSettingsBox->setMinimumSize(QSize(0, 50));
        clientSettingsBox->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setPointSize(8);
        clientSettingsBox->setFont(font);
        clientSettingsBox->setStyleSheet(QStringLiteral(""));
        clientSettingsBox->setAlignment(Qt::AlignCenter);
        clientSettingsBox->setFlat(true);
        onlyActiveClientsRadio = new QRadioButton(clientSettingsBox);
        onlyActiveClientsRadio->setObjectName(QStringLiteral("onlyActiveClientsRadio"));
        onlyActiveClientsRadio->setGeometry(QRect(210, 20, 121, 17));
        onlySelectedClientsRadio = new QRadioButton(clientSettingsBox);
        onlySelectedClientsRadio->setObjectName(QStringLiteral("onlySelectedClientsRadio"));
        onlySelectedClientsRadio->setGeometry(QRect(80, 20, 131, 17));
        allClientsRadio = new QRadioButton(clientSettingsBox);
        allClientsRadio->setObjectName(QStringLiteral("allClientsRadio"));
        allClientsRadio->setGeometry(QRect(1, 20, 91, 20));
        allClientsRadio->setChecked(true);
        noClientsRadio = new QRadioButton(clientSettingsBox);
        noClientsRadio->setObjectName(QStringLiteral("noClientsRadio"));
        noClientsRadio->setGeometry(QRect(330, 20, 82, 17));

        formLayout->setWidget(17, QFormLayout::FieldRole, clientSettingsBox);

        groupSettingsBox = new QGroupBox(Form);
        groupSettingsBox->setObjectName(QStringLiteral("groupSettingsBox"));
        groupSettingsBox->setEnabled(false);
        groupSettingsBox->setMinimumSize(QSize(0, 50));
        groupSettingsBox->setMaximumSize(QSize(16777215, 50));
        groupSettingsBox->setAlignment(Qt::AlignCenter);
        groupSettingsBox->setFlat(true);
        groupSettingsBox->setCheckable(false);
        allGroupsRadio = new QRadioButton(groupSettingsBox);
        allGroupsRadio->setObjectName(QStringLiteral("allGroupsRadio"));
        allGroupsRadio->setGeometry(QRect(1, 20, 91, 20));
        allGroupsRadio->setChecked(true);
        onlySelectedGroupsRadio = new QRadioButton(groupSettingsBox);
        onlySelectedGroupsRadio->setObjectName(QStringLiteral("onlySelectedGroupsRadio"));
        onlySelectedGroupsRadio->setGeometry(QRect(80, 20, 121, 17));
        onlyActiveGroupsRadio = new QRadioButton(groupSettingsBox);
        onlyActiveGroupsRadio->setObjectName(QStringLiteral("onlyActiveGroupsRadio"));
        onlyActiveGroupsRadio->setGeometry(QRect(210, 20, 121, 17));
        noGroupsRadio = new QRadioButton(groupSettingsBox);
        noGroupsRadio->setObjectName(QStringLiteral("noGroupsRadio"));
        noGroupsRadio->setGeometry(QRect(330, 20, 82, 17));

        formLayout->setWidget(18, QFormLayout::FieldRole, groupSettingsBox);

        persistFileNameLabel = new QLabel(Form);
        persistFileNameLabel->setObjectName(QStringLiteral("persistFileNameLabel"));
        persistFileNameLabel->setEnabled(false);

        formLayout->setWidget(21, QFormLayout::LabelRole, persistFileNameLabel);

        persistFileVerticalLayout = new QHBoxLayout();
        persistFileVerticalLayout->setObjectName(QStringLiteral("persistFileVerticalLayout"));
        persistFileNameInput = new QLineEdit(Form);
        persistFileNameInput->setObjectName(QStringLiteral("persistFileNameInput"));
        persistFileNameInput->setEnabled(false);

        persistFileVerticalLayout->addWidget(persistFileNameInput);


        formLayout->setLayout(21, QFormLayout::FieldRole, persistFileVerticalLayout);

        globalLogSettingsLabel = new QLabel(Form);
        globalLogSettingsLabel->setObjectName(QStringLiteral("globalLogSettingsLabel"));
        globalLogSettingsLabel->setEnabled(false);

        formLayout->setWidget(19, QFormLayout::LabelRole, globalLogSettingsLabel);

        globalLogSettingsCheckBox = new QCheckBox(Form);
        globalLogSettingsCheckBox->setObjectName(QStringLiteral("globalLogSettingsCheckBox"));
        globalLogSettingsCheckBox->setEnabled(false);

        formLayout->setWidget(19, QFormLayout::FieldRole, globalLogSettingsCheckBox);

        viewSettingsLabel = new QLabel(Form);
        viewSettingsLabel->setObjectName(QStringLiteral("viewSettingsLabel"));
        viewSettingsLabel->setEnabled(false);

        formLayout->setWidget(20, QFormLayout::LabelRole, viewSettingsLabel);

        viewSettingsCheckBox = new QCheckBox(Form);
        viewSettingsCheckBox->setObjectName(QStringLiteral("viewSettingsCheckBox"));
        viewSettingsCheckBox->setEnabled(false);

        formLayout->setWidget(20, QFormLayout::FieldRole, viewSettingsCheckBox);

        label = new QLabel(Form);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(10, QFormLayout::LabelRole, label);

        masterHostInput = new QLineEdit(Form);
        masterHostInput->setObjectName(QStringLiteral("masterHostInput"));
        masterHostInput->setMaximumSize(QSize(200, 16777215));

        formLayout->setWidget(10, QFormLayout::FieldRole, masterHostInput);

        label_2 = new QLabel(Form);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(11, QFormLayout::LabelRole, label_2);

        masterPortInput = new QLineEdit(Form);
        masterPortInput->setObjectName(QStringLiteral("masterPortInput"));
        masterPortInput->setMaximumSize(QSize(100, 16777215));
        masterPortInput->setInputMethodHints(Qt::ImhNone);

        formLayout->setWidget(11, QFormLayout::FieldRole, masterPortInput);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        saveButton = new QPushButton(Form);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(saveButton);

        cancelButton = new QPushButton(Form);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(cancelButton);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(Form);
        QObject::connect(saveButton, SIGNAL(clicked()), Form, SLOT(saveTriggered()));
        QObject::connect(cancelButton, SIGNAL(clicked()), Form, SLOT(cancelTriggered()));
        QObject::connect(baseSaveLocationBrowserButton, SIGNAL(clicked()), Form, SLOT(baseSaveLocationBrowserButtonClicked()));
        QObject::connect(toFileSaveLocationBrowserButton, SIGNAL(clicked()), Form, SLOT(toFileSaveLocationBrowserButtonClicked()));
        QObject::connect(toSharedSaveLocationBrowserButton, SIGNAL(clicked()), Form, SLOT(toSharedSaveLocationBrowserButtonClicked()));
        QObject::connect(toRingFileSaveLocationBrowserButton, SIGNAL(clicked()), Form, SLOT(toRingFileSaveLocationBrowserButtonClicked()));
        QObject::connect(persistSettingsCheckBox, SIGNAL(clicked()), Form, SLOT(persistSettingsCheckBoxClicked()));
        QObject::connect(allowAutoRegistrationCheckBox, SIGNAL(clicked()), Form, SLOT(allowAutoRegistrationCheckBoxClicked()));

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Settings", 0));
        configurationLabel->setText(QApplication::translate("Form", "Configuration:", 0));
        configurationNameLabel->setText(QString());
        baseSaveLocationLabel->setText(QApplication::translate("Form", "Base Save Location:", 0));
        baseSaveLocationBrowserButton->setText(QApplication::translate("Form", "...", 0));
        toFileSaveLocationLabel->setText(QApplication::translate("Form", "To File Save Location:", 0));
        toFileSaveLocationBrowserButton->setText(QApplication::translate("Form", "...", 0));
        toSharedSaveLocationLabel->setText(QApplication::translate("Form", "To Shared Save Location: ", 0));
        toSharedSaveLocationBrowserButton->setText(QApplication::translate("Form", "...", 0));
        toRingFileSaveLocationLabel->setText(QApplication::translate("Form", "To Ring File Save Location: ", 0));
        toRingFileSaveLocationBrowserButton->setText(QApplication::translate("Form", "...", 0));
        tableLogBufferLimitLabel->setText(QApplication::translate("Form", "Table Log Buffer Limit: ", 0));
        ringBufferLimitLabel->setText(QApplication::translate("Form", "Ring Buffer Limit:", 0));
        messageBufferLimitLabel->setText(QApplication::translate("Form", "Message Buffer Limit:", 0));
        allowAutoRegistrationLabel->setText(QApplication::translate("Form", "Allow Auto Reigstration:", 0));
        allowAutoRegistrationCheckBox->setText(QString());
        groupBox->setTitle(QApplication::translate("Form", "Persistency", 0));
        persistInfoEmptyLabel->setText(QString());
        persistSettingsInfoLabel->setText(QApplication::translate("Form", "Checking this will persist your settings in an external file.\n"
"You can choose what to persist below.", 0));
        persistSettingsLabel->setText(QApplication::translate("Form", "Persist Settings:", 0));
        persistSettingsCheckBox->setText(QString());
        clientSettingsBox->setTitle(QApplication::translate("Form", "Client Settings", 0));
        onlyActiveClientsRadio->setText(QApplication::translate("Form", "Only Active Clients", 0));
        onlySelectedClientsRadio->setText(QApplication::translate("Form", "Only Selected Clients", 0));
        allClientsRadio->setText(QApplication::translate("Form", "All Clients", 0));
        noClientsRadio->setText(QApplication::translate("Form", "No Clients", 0));
        groupSettingsBox->setTitle(QApplication::translate("Form", "Group Settings", 0));
        allGroupsRadio->setText(QApplication::translate("Form", "All Groups", 0));
        onlySelectedGroupsRadio->setText(QApplication::translate("Form", "Only Selected Groups", 0));
        onlyActiveGroupsRadio->setText(QApplication::translate("Form", "Only Active Groups", 0));
        noGroupsRadio->setText(QApplication::translate("Form", "No Groups", 0));
        persistFileNameLabel->setText(QApplication::translate("Form", "Persistent Filename", 0));
        globalLogSettingsLabel->setText(QApplication::translate("Form", "Global Log Settings", 0));
        globalLogSettingsCheckBox->setText(QString());
        viewSettingsLabel->setText(QApplication::translate("Form", "View Settings", 0));
        viewSettingsCheckBox->setText(QString());
        label->setText(QApplication::translate("Form", "Master Host:", 0));
        label_2->setText(QApplication::translate("Form", "Master Port:", 0));
        saveButton->setText(QApplication::translate("Form", "Save", 0));
        cancelButton->setText(QApplication::translate("Form", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RT_SETTINGSWINDOW_H
