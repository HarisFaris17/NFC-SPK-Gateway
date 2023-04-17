/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_7;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_18;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox_6;
    QFormLayout *formLayout_3;
    QLabel *label_3;
    QLineEdit *gateway1MACLineEdit;
    QLabel *label_9;
    QLineEdit *gateway2MACLineEdit;
    QPushButton *saveGatewayMACPushButton;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout_2;
    QLineEdit *portTCPLineEdit;
    QLabel *label_2;
    QLineEdit *ipAddressTCPLineEdit;
    QLabel *label;
    QPushButton *connectTCPPushButton;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBox_4;
    QFormLayout *formLayout;
    QLabel *HostLabel;
    QLineEdit *hostDatabaseLineEdit;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *portDatabaseLineEdit;
    QLineEdit *databaseNameDatabaseLineEdit;
    QLineEdit *usernameDatabaseLineEdit;
    QLineEdit *passwordDatabaseLineEdit;
    QPushButton *connectDatabasePushButton;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *clearConsoleSerialButton;
    QTextBrowser *console;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *coordinatesPushButton;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *addDevicePushButton;
    QPushButton *settingPushButton;
    QTableWidget *tableWidgetCounting;
    QTableWidget *tableWidgetHistoryCounting;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_7;
    QHBoxLayout *horizontalLayout_8;
    QTableWidget *tableWidget;
    QGroupBox *groupBox_8;
    QHBoxLayout *horizontalLayout_19;
    QTableWidget *tableWidget_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1094, 673);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_7 = new QHBoxLayout(centralWidget);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        horizontalLayout_18 = new QHBoxLayout(tab);
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        groupBox_5 = new QGroupBox(tab);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_5);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        groupBox_6 = new QGroupBox(groupBox_5);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        formLayout_3 = new QFormLayout(groupBox_6);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        label_3 = new QLabel(groupBox_6);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_3);

        gateway1MACLineEdit = new QLineEdit(groupBox_6);
        gateway1MACLineEdit->setObjectName(QStringLiteral("gateway1MACLineEdit"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, gateway1MACLineEdit);

        label_9 = new QLabel(groupBox_6);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_9);

        gateway2MACLineEdit = new QLineEdit(groupBox_6);
        gateway2MACLineEdit->setObjectName(QStringLiteral("gateway2MACLineEdit"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, gateway2MACLineEdit);


        horizontalLayout_4->addWidget(groupBox_6);

        saveGatewayMACPushButton = new QPushButton(groupBox_5);
        saveGatewayMACPushButton->setObjectName(QStringLiteral("saveGatewayMACPushButton"));

        horizontalLayout_4->addWidget(saveGatewayMACPushButton);


        verticalLayout->addWidget(groupBox_5);

        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(groupBox_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        formLayout_2 = new QFormLayout(groupBox);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        portTCPLineEdit = new QLineEdit(groupBox);
        portTCPLineEdit->setObjectName(QStringLiteral("portTCPLineEdit"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, portTCPLineEdit);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_2);

        ipAddressTCPLineEdit = new QLineEdit(groupBox);
        ipAddressTCPLineEdit->setObjectName(QStringLiteral("ipAddressTCPLineEdit"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, ipAddressTCPLineEdit);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        label->raise();
        ipAddressTCPLineEdit->raise();
        label_2->raise();
        portTCPLineEdit->raise();

        horizontalLayout->addWidget(groupBox);

        connectTCPPushButton = new QPushButton(groupBox_2);
        connectTCPPushButton->setObjectName(QStringLiteral("connectTCPPushButton"));

        horizontalLayout->addWidget(connectTCPPushButton);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        horizontalLayout_5 = new QHBoxLayout(groupBox_3);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        groupBox_4 = new QGroupBox(groupBox_3);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        formLayout = new QFormLayout(groupBox_4);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        HostLabel = new QLabel(groupBox_4);
        HostLabel->setObjectName(QStringLiteral("HostLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, HostLabel);

        hostDatabaseLineEdit = new QLineEdit(groupBox_4);
        hostDatabaseLineEdit->setObjectName(QStringLiteral("hostDatabaseLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, hostDatabaseLineEdit);

        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);

        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_7);

        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        portDatabaseLineEdit = new QLineEdit(groupBox_4);
        portDatabaseLineEdit->setObjectName(QStringLiteral("portDatabaseLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, portDatabaseLineEdit);

        databaseNameDatabaseLineEdit = new QLineEdit(groupBox_4);
        databaseNameDatabaseLineEdit->setObjectName(QStringLiteral("databaseNameDatabaseLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, databaseNameDatabaseLineEdit);

        usernameDatabaseLineEdit = new QLineEdit(groupBox_4);
        usernameDatabaseLineEdit->setObjectName(QStringLiteral("usernameDatabaseLineEdit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, usernameDatabaseLineEdit);

        passwordDatabaseLineEdit = new QLineEdit(groupBox_4);
        passwordDatabaseLineEdit->setObjectName(QStringLiteral("passwordDatabaseLineEdit"));

        formLayout->setWidget(5, QFormLayout::FieldRole, passwordDatabaseLineEdit);


        horizontalLayout_5->addWidget(groupBox_4);

        connectDatabasePushButton = new QPushButton(groupBox_3);
        connectDatabasePushButton->setObjectName(QStringLiteral("connectDatabasePushButton"));

        horizontalLayout_5->addWidget(connectDatabasePushButton);


        verticalLayout->addWidget(groupBox_3);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        horizontalLayout_18->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_3->addWidget(label_8);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_11);

        clearConsoleSerialButton = new QPushButton(tab);
        clearConsoleSerialButton->setObjectName(QStringLiteral("clearConsoleSerialButton"));

        horizontalLayout_3->addWidget(clearConsoleSerialButton);


        verticalLayout_2->addLayout(horizontalLayout_3);

        console = new QTextBrowser(tab);
        console->setObjectName(QStringLiteral("console"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(console->sizePolicy().hasHeightForWidth());
        console->setSizePolicy(sizePolicy);
        console->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_2->addWidget(console);


        horizontalLayout_18->addLayout(verticalLayout_2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        coordinatesPushButton = new QPushButton(tab_2);
        coordinatesPushButton->setObjectName(QStringLiteral("coordinatesPushButton"));

        horizontalLayout_6->addWidget(coordinatesPushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        addDevicePushButton = new QPushButton(tab_2);
        addDevicePushButton->setObjectName(QStringLiteral("addDevicePushButton"));

        horizontalLayout_2->addWidget(addDevicePushButton);

        settingPushButton = new QPushButton(tab_2);
        settingPushButton->setObjectName(QStringLiteral("settingPushButton"));

        horizontalLayout_2->addWidget(settingPushButton);


        horizontalLayout_6->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_6);

        tableWidgetCounting = new QTableWidget(tab_2);
        if (tableWidgetCounting->columnCount() < 20)
            tableWidgetCounting->setColumnCount(20);
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        tableWidgetCounting->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        tableWidgetCounting->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        tableWidgetCounting->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        tableWidgetCounting->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font);
        tableWidgetCounting->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font);
        tableWidgetCounting->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font);
        tableWidgetCounting->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font);
        tableWidgetCounting->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font);
        tableWidgetCounting->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFont(font);
        tableWidgetCounting->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font);
        tableWidgetCounting->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setFont(font);
        tableWidgetCounting->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setFont(font);
        tableWidgetCounting->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setFont(font);
        tableWidgetCounting->setHorizontalHeaderItem(13, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setFont(font);
        tableWidgetCounting->setHorizontalHeaderItem(14, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setFont(font);
        tableWidgetCounting->setHorizontalHeaderItem(15, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setFont(font);
        tableWidgetCounting->setHorizontalHeaderItem(16, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setFont(font);
        tableWidgetCounting->setHorizontalHeaderItem(17, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setFont(font);
        tableWidgetCounting->setHorizontalHeaderItem(18, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setFont(font);
        tableWidgetCounting->setHorizontalHeaderItem(19, __qtablewidgetitem19);
        tableWidgetCounting->setObjectName(QStringLiteral("tableWidgetCounting"));
        tableWidgetCounting->setRowCount(0);

        verticalLayout_3->addWidget(tableWidgetCounting);

        tableWidgetHistoryCounting = new QTableWidget(tab_2);
        if (tableWidgetHistoryCounting->columnCount() < 20)
            tableWidgetHistoryCounting->setColumnCount(20);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setFont(font);
        tableWidgetHistoryCounting->setHorizontalHeaderItem(0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setFont(font);
        tableWidgetHistoryCounting->setHorizontalHeaderItem(1, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        __qtablewidgetitem22->setFont(font);
        tableWidgetHistoryCounting->setHorizontalHeaderItem(2, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        __qtablewidgetitem23->setFont(font);
        tableWidgetHistoryCounting->setHorizontalHeaderItem(3, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        __qtablewidgetitem24->setFont(font);
        tableWidgetHistoryCounting->setHorizontalHeaderItem(4, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        __qtablewidgetitem25->setFont(font);
        tableWidgetHistoryCounting->setHorizontalHeaderItem(5, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        __qtablewidgetitem26->setFont(font);
        tableWidgetHistoryCounting->setHorizontalHeaderItem(6, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        __qtablewidgetitem27->setFont(font);
        tableWidgetHistoryCounting->setHorizontalHeaderItem(7, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        __qtablewidgetitem28->setFont(font);
        tableWidgetHistoryCounting->setHorizontalHeaderItem(8, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        __qtablewidgetitem29->setFont(font);
        tableWidgetHistoryCounting->setHorizontalHeaderItem(9, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        __qtablewidgetitem30->setFont(font);
        tableWidgetHistoryCounting->setHorizontalHeaderItem(10, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        __qtablewidgetitem31->setFont(font);
        tableWidgetHistoryCounting->setHorizontalHeaderItem(11, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        __qtablewidgetitem32->setFont(font);
        tableWidgetHistoryCounting->setHorizontalHeaderItem(12, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        __qtablewidgetitem33->setFont(font);
        tableWidgetHistoryCounting->setHorizontalHeaderItem(13, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        __qtablewidgetitem34->setFont(font);
        tableWidgetHistoryCounting->setHorizontalHeaderItem(14, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        __qtablewidgetitem35->setFont(font);
        tableWidgetHistoryCounting->setHorizontalHeaderItem(15, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        __qtablewidgetitem36->setFont(font);
        tableWidgetHistoryCounting->setHorizontalHeaderItem(16, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        __qtablewidgetitem37->setFont(font);
        tableWidgetHistoryCounting->setHorizontalHeaderItem(17, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        __qtablewidgetitem38->setFont(font);
        tableWidgetHistoryCounting->setHorizontalHeaderItem(18, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        __qtablewidgetitem39->setFont(font);
        tableWidgetHistoryCounting->setHorizontalHeaderItem(19, __qtablewidgetitem39);
        tableWidgetHistoryCounting->setObjectName(QStringLiteral("tableWidgetHistoryCounting"));
        tableWidgetHistoryCounting->setRowCount(0);

        verticalLayout_3->addWidget(tableWidgetHistoryCounting);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_4 = new QVBoxLayout(tab_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox_7 = new QGroupBox(tab_3);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        horizontalLayout_8 = new QHBoxLayout(groupBox_7);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        tableWidget = new QTableWidget(groupBox_7);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        __qtablewidgetitem40->setFont(font);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        __qtablewidgetitem41->setFont(font);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        __qtablewidgetitem42->setFont(font);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        __qtablewidgetitem43->setFont(font);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        __qtablewidgetitem44->setFont(font);
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem44);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        horizontalLayout_8->addWidget(tableWidget);


        verticalLayout_4->addWidget(groupBox_7);

        groupBox_8 = new QGroupBox(tab_3);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        horizontalLayout_19 = new QHBoxLayout(groupBox_8);
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        tableWidget_2 = new QTableWidget(groupBox_8);
        if (tableWidget_2->columnCount() < 6)
            tableWidget_2->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        __qtablewidgetitem45->setFont(font);
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        __qtablewidgetitem46->setFont(font);
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        __qtablewidgetitem47->setFont(font);
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        __qtablewidgetitem48->setFont(font);
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        __qtablewidgetitem49->setFont(font);
        tableWidget_2->setHorizontalHeaderItem(4, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        __qtablewidgetitem50->setFont(font);
        tableWidget_2->setHorizontalHeaderItem(5, __qtablewidgetitem50);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));

        horizontalLayout_19->addWidget(tableWidget_2);


        verticalLayout_4->addWidget(groupBox_8);

        tabWidget->addTab(tab_3, QString());

        horizontalLayout_7->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1094, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Gateway MAC", Q_NULLPTR));
        groupBox_6->setTitle(QString());
        label_3->setText(QApplication::translate("MainWindow", "Gateway 1 MAC", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Gateway 2 MAC", Q_NULLPTR));
        saveGatewayMACPushButton->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "TCP Server", Q_NULLPTR));
        groupBox->setTitle(QString());
        label_2->setText(QApplication::translate("MainWindow", "Port", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "IP Address", Q_NULLPTR));
        connectTCPPushButton->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Database", Q_NULLPTR));
        groupBox_4->setTitle(QString());
        HostLabel->setText(QApplication::translate("MainWindow", "Host", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Port", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Database Name", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Username", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Password", Q_NULLPTR));
        connectDatabasePushButton->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Console", Q_NULLPTR));
        clearConsoleSerialButton->setText(QApplication::translate("MainWindow", "Clear Console", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Main", Q_NULLPTR));
        coordinatesPushButton->setText(QApplication::translate("MainWindow", "Coordinates", Q_NULLPTR));
        addDevicePushButton->setText(QApplication::translate("MainWindow", "Add Device", Q_NULLPTR));
        settingPushButton->setText(QApplication::translate("MainWindow", "Setting", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetCounting->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Device ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetCounting->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Tag ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetCounting->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "SPK", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetCounting->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Counter", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetCounting->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetCounting->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Y", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetCounting->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Z", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidgetCounting->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Locator0 X", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidgetCounting->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "Locator0 Y", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidgetCounting->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "Locator0 Z", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidgetCounting->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "Locator1 X", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidgetCounting->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "Locator1 Y", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidgetCounting->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "Locator1 Z", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidgetCounting->horizontalHeaderItem(13);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "Locator2 X", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidgetCounting->horizontalHeaderItem(14);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "Locator2 Y", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidgetCounting->horizontalHeaderItem(15);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "Locator2 Z", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidgetCounting->horizontalHeaderItem(16);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "Locator3 X", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidgetCounting->horizontalHeaderItem(17);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "Locator3 Y", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidgetCounting->horizontalHeaderItem(18);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "Locator3 Z", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidgetCounting->horizontalHeaderItem(19);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "Last Update", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidgetHistoryCounting->horizontalHeaderItem(0);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "Device ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidgetHistoryCounting->horizontalHeaderItem(1);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWindow", "Tag ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidgetHistoryCounting->horizontalHeaderItem(2);
        ___qtablewidgetitem22->setText(QApplication::translate("MainWindow", "SPK", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidgetHistoryCounting->horizontalHeaderItem(3);
        ___qtablewidgetitem23->setText(QApplication::translate("MainWindow", "Counter", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidgetHistoryCounting->horizontalHeaderItem(4);
        ___qtablewidgetitem24->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidgetHistoryCounting->horizontalHeaderItem(5);
        ___qtablewidgetitem25->setText(QApplication::translate("MainWindow", "Y", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidgetHistoryCounting->horizontalHeaderItem(6);
        ___qtablewidgetitem26->setText(QApplication::translate("MainWindow", "Z", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidgetHistoryCounting->horizontalHeaderItem(7);
        ___qtablewidgetitem27->setText(QApplication::translate("MainWindow", "Locator0 X", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidgetHistoryCounting->horizontalHeaderItem(8);
        ___qtablewidgetitem28->setText(QApplication::translate("MainWindow", "Locator0 Y", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidgetHistoryCounting->horizontalHeaderItem(9);
        ___qtablewidgetitem29->setText(QApplication::translate("MainWindow", "Locator0 Z", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidgetHistoryCounting->horizontalHeaderItem(10);
        ___qtablewidgetitem30->setText(QApplication::translate("MainWindow", "Locator1 X", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidgetHistoryCounting->horizontalHeaderItem(11);
        ___qtablewidgetitem31->setText(QApplication::translate("MainWindow", "Locator1 Y", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidgetHistoryCounting->horizontalHeaderItem(12);
        ___qtablewidgetitem32->setText(QApplication::translate("MainWindow", "Locator1 Z", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidgetHistoryCounting->horizontalHeaderItem(13);
        ___qtablewidgetitem33->setText(QApplication::translate("MainWindow", "Locator2 X", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidgetHistoryCounting->horizontalHeaderItem(14);
        ___qtablewidgetitem34->setText(QApplication::translate("MainWindow", "Locator2 Y", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidgetHistoryCounting->horizontalHeaderItem(15);
        ___qtablewidgetitem35->setText(QApplication::translate("MainWindow", "Locator2 Z", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidgetHistoryCounting->horizontalHeaderItem(16);
        ___qtablewidgetitem36->setText(QApplication::translate("MainWindow", "Locator3 X", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidgetHistoryCounting->horizontalHeaderItem(17);
        ___qtablewidgetitem37->setText(QApplication::translate("MainWindow", "Locator3 Y", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidgetHistoryCounting->horizontalHeaderItem(18);
        ___qtablewidgetitem38->setText(QApplication::translate("MainWindow", "Locator3 Z", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidgetHistoryCounting->horizontalHeaderItem(19);
        ___qtablewidgetitem39->setText(QApplication::translate("MainWindow", "Timestamp", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Coordinate", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "Device", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem40->setText(QApplication::translate("MainWindow", "Device ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem41 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem41->setText(QApplication::translate("MainWindow", "Call 1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem42 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem42->setText(QApplication::translate("MainWindow", "Call 2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem43 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem43->setText(QApplication::translate("MainWindow", "Call 3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem44 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem44->setText(QApplication::translate("MainWindow", "Call 4", Q_NULLPTR));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "Data", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem45 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem45->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem46 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem46->setText(QApplication::translate("MainWindow", "Device ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem47 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem47->setText(QApplication::translate("MainWindow", "Call", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem48 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem48->setText(QApplication::translate("MainWindow", "Date Time", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem49 = tableWidget_2->horizontalHeaderItem(4);
        ___qtablewidgetitem49->setText(QApplication::translate("MainWindow", "Date Arrival", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem50 = tableWidget_2->horizontalHeaderItem(5);
        ___qtablewidgetitem50->setText(QApplication::translate("MainWindow", "Date Completed", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Andon", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
