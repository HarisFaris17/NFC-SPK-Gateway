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
    QHBoxLayout *horizontalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *clearConsoleSerialButton;
    QTextBrowser *console;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout_2;
    QLabel *label;
    QLineEdit *ipAddressTCPLineEdit;
    QLabel *label_2;
    QLineEdit *portTCPLineEdit;
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
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableWidget;
    QTableWidget *tableWidgetCounting;
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
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(720, 20, 258, 231));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_3->addWidget(label_8);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_11);

        clearConsoleSerialButton = new QPushButton(layoutWidget);
        clearConsoleSerialButton->setObjectName(QStringLiteral("clearConsoleSerialButton"));

        horizontalLayout_3->addWidget(clearConsoleSerialButton);


        verticalLayout_2->addLayout(horizontalLayout_3);

        console = new QTextBrowser(layoutWidget);
        console->setObjectName(QStringLiteral("console"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(console->sizePolicy().hasHeightForWidth());
        console->setSizePolicy(sizePolicy);
        console->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_2->addWidget(console);

        verticalLayoutWidget = new QWidget(tab);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 30, 561, 586));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        groupBox_2 = new QGroupBox(verticalLayoutWidget);
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
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        ipAddressTCPLineEdit = new QLineEdit(groupBox);
        ipAddressTCPLineEdit->setObjectName(QStringLiteral("ipAddressTCPLineEdit"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, ipAddressTCPLineEdit);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_2);

        portTCPLineEdit = new QLineEdit(groupBox);
        portTCPLineEdit->setObjectName(QStringLiteral("portTCPLineEdit"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, portTCPLineEdit);


        horizontalLayout->addWidget(groupBox);

        connectTCPPushButton = new QPushButton(groupBox_2);
        connectTCPPushButton->setObjectName(QStringLiteral("connectTCPPushButton"));

        horizontalLayout->addWidget(connectTCPPushButton);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(verticalLayoutWidget);
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

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        tableWidget = new QTableWidget(tab_2);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font);
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        if (tableWidget->rowCount() < 5)
            tableWidget->setRowCount(5);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setRowCount(5);

        verticalLayout_3->addWidget(tableWidget);

        tableWidgetCounting = new QTableWidget(tab_2);
        if (tableWidgetCounting->columnCount() < 17)
            tableWidgetCounting->setColumnCount(17);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font);
        tableWidgetCounting->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font);
        tableWidgetCounting->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font);
        tableWidgetCounting->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font);
        tableWidgetCounting->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFont(font);
        tableWidgetCounting->setHorizontalHeaderItem(4, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font);
        tableWidgetCounting->setHorizontalHeaderItem(5, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setFont(font);
        tableWidgetCounting->setHorizontalHeaderItem(6, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setFont(font);
        tableWidgetCounting->setHorizontalHeaderItem(7, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setFont(font);
        tableWidgetCounting->setHorizontalHeaderItem(8, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setFont(font);
        tableWidgetCounting->setHorizontalHeaderItem(9, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setFont(font);
        tableWidgetCounting->setHorizontalHeaderItem(10, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setFont(font);
        tableWidgetCounting->setHorizontalHeaderItem(11, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setFont(font);
        tableWidgetCounting->setHorizontalHeaderItem(12, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setFont(font);
        tableWidgetCounting->setHorizontalHeaderItem(13, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setFont(font);
        tableWidgetCounting->setHorizontalHeaderItem(14, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setFont(font);
        tableWidgetCounting->setHorizontalHeaderItem(15, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setFont(font);
        tableWidgetCounting->setHorizontalHeaderItem(16, __qtablewidgetitem21);
        if (tableWidgetCounting->rowCount() < 5)
            tableWidgetCounting->setRowCount(5);
        tableWidgetCounting->setObjectName(QStringLiteral("tableWidgetCounting"));
        tableWidgetCounting->setRowCount(5);

        verticalLayout_3->addWidget(tableWidgetCounting);

        tabWidget->addTab(tab_2, QString());

        horizontalLayout_2->addWidget(tabWidget);

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

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Console", Q_NULLPTR));
        clearConsoleSerialButton->setText(QApplication::translate("MainWindow", "Clear Console", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "TCP Server", Q_NULLPTR));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("MainWindow", "IP Address", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Port", Q_NULLPTR));
        connectTCPPushButton->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Database", Q_NULLPTR));
        groupBox_4->setTitle(QString());
        HostLabel->setText(QApplication::translate("MainWindow", "Host", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Port", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Database Name", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Username", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Password", Q_NULLPTR));
        connectDatabasePushButton->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Main", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Device ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Tag ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "SPK", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Counter", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Last Update", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetCounting->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Device ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetCounting->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Tag ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidgetCounting->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "SPK", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidgetCounting->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "Counter", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidgetCounting->horizontalHeaderItem(4);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "AR1 X", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidgetCounting->horizontalHeaderItem(5);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "AR1 Y", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidgetCounting->horizontalHeaderItem(6);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "AR1 Z", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidgetCounting->horizontalHeaderItem(7);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "AR2 X", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidgetCounting->horizontalHeaderItem(8);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "AR2 Y", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidgetCounting->horizontalHeaderItem(9);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "AR2 Z", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidgetCounting->horizontalHeaderItem(10);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "AR3 X", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidgetCounting->horizontalHeaderItem(11);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "AR3 Y", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidgetCounting->horizontalHeaderItem(12);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "AR3 Z", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidgetCounting->horizontalHeaderItem(13);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "AR4 X", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidgetCounting->horizontalHeaderItem(14);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "AR4 Y", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidgetCounting->horizontalHeaderItem(15);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "AR4 Z", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidgetCounting->horizontalHeaderItem(16);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWindow", "Last Update", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Table", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
