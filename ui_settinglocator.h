/********************************************************************************
** Form generated from reading UI file 'settinglocator.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGLOCATOR_H
#define UI_SETTINGLOCATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SettingLocator
{
public:
    QVBoxLayout *verticalLayout_8;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QComboBox *refComboBox;
    QSpacerItem *horizontalSpacer_15;
    QHBoxLayout *horizontalLayout_14;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *locator1XLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *locator1YLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_18;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *locator1ZLineEdit;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_19;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *locator2XLineEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_20;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *locator2YLineEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_21;
    QSpacerItem *horizontalSpacer_7;
    QLineEdit *locator2ZLineEdit;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_22;
    QSpacerItem *horizontalSpacer_8;
    QLineEdit *locator3XLineEdit;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_23;
    QSpacerItem *horizontalSpacer_9;
    QLineEdit *locator3YLineEdit;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_24;
    QSpacerItem *horizontalSpacer_10;
    QLineEdit *locator3ZLineEdit;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_25;
    QSpacerItem *horizontalSpacer_11;
    QLineEdit *locator4XLineEdit;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_26;
    QSpacerItem *horizontalSpacer_12;
    QLineEdit *locator4YLineEdit;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_27;
    QSpacerItem *horizontalSpacer_13;
    QLineEdit *locator4ZLineEdit;
    QHBoxLayout *horizontalLayout_15;
    QPushButton *okPushButton;
    QPushButton *cancelPushButton;

    void setupUi(QDialog *SettingLocator)
    {
        if (SettingLocator->objectName().isEmpty())
            SettingLocator->setObjectName(QStringLiteral("SettingLocator"));
        SettingLocator->resize(615, 399);
        verticalLayout_8 = new QVBoxLayout(SettingLocator);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        groupBox_2 = new QGroupBox(SettingLocator);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        refComboBox = new QComboBox(groupBox_2);
        refComboBox->setObjectName(QStringLiteral("refComboBox"));

        horizontalLayout->addWidget(refComboBox);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_15);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        groupBox = new QGroupBox(groupBox_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        locator1XLineEdit = new QLineEdit(groupBox);
        locator1XLineEdit->setObjectName(QStringLiteral("locator1XLineEdit"));

        horizontalLayout_2->addWidget(locator1XLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        locator1YLineEdit = new QLineEdit(groupBox);
        locator1YLineEdit->setObjectName(QStringLiteral("locator1YLineEdit"));

        horizontalLayout_3->addWidget(locator1YLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_18 = new QLabel(groupBox);
        label_18->setObjectName(QStringLiteral("label_18"));

        horizontalLayout_4->addWidget(label_18);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        locator1ZLineEdit = new QLineEdit(groupBox);
        locator1ZLineEdit->setObjectName(QStringLiteral("locator1ZLineEdit"));

        horizontalLayout_4->addWidget(locator1ZLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout_6->addWidget(groupBox);

        groupBox_5 = new QGroupBox(groupBox_2);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        verticalLayout_3 = new QVBoxLayout(groupBox_5);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_19 = new QLabel(groupBox_5);
        label_19->setObjectName(QStringLiteral("label_19"));

        horizontalLayout_5->addWidget(label_19);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        locator2XLineEdit = new QLineEdit(groupBox_5);
        locator2XLineEdit->setObjectName(QStringLiteral("locator2XLineEdit"));

        horizontalLayout_5->addWidget(locator2XLineEdit);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_20 = new QLabel(groupBox_5);
        label_20->setObjectName(QStringLiteral("label_20"));

        horizontalLayout_6->addWidget(label_20);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        locator2YLineEdit = new QLineEdit(groupBox_5);
        locator2YLineEdit->setObjectName(QStringLiteral("locator2YLineEdit"));

        horizontalLayout_6->addWidget(locator2YLineEdit);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_21 = new QLabel(groupBox_5);
        label_21->setObjectName(QStringLiteral("label_21"));

        horizontalLayout_7->addWidget(label_21);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        locator2ZLineEdit = new QLineEdit(groupBox_5);
        locator2ZLineEdit->setObjectName(QStringLiteral("locator2ZLineEdit"));

        horizontalLayout_7->addWidget(locator2ZLineEdit);


        verticalLayout_3->addLayout(horizontalLayout_7);


        verticalLayout_6->addWidget(groupBox_5);


        horizontalLayout_14->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        groupBox_6 = new QGroupBox(groupBox_2);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        verticalLayout_4 = new QVBoxLayout(groupBox_6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_22 = new QLabel(groupBox_6);
        label_22->setObjectName(QStringLiteral("label_22"));

        horizontalLayout_8->addWidget(label_22);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);

        locator3XLineEdit = new QLineEdit(groupBox_6);
        locator3XLineEdit->setObjectName(QStringLiteral("locator3XLineEdit"));

        horizontalLayout_8->addWidget(locator3XLineEdit);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_23 = new QLabel(groupBox_6);
        label_23->setObjectName(QStringLiteral("label_23"));

        horizontalLayout_9->addWidget(label_23);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_9);

        locator3YLineEdit = new QLineEdit(groupBox_6);
        locator3YLineEdit->setObjectName(QStringLiteral("locator3YLineEdit"));

        horizontalLayout_9->addWidget(locator3YLineEdit);


        verticalLayout_4->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_24 = new QLabel(groupBox_6);
        label_24->setObjectName(QStringLiteral("label_24"));

        horizontalLayout_10->addWidget(label_24);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_10);

        locator3ZLineEdit = new QLineEdit(groupBox_6);
        locator3ZLineEdit->setObjectName(QStringLiteral("locator3ZLineEdit"));

        horizontalLayout_10->addWidget(locator3ZLineEdit);


        verticalLayout_4->addLayout(horizontalLayout_10);


        verticalLayout_7->addWidget(groupBox_6);

        groupBox_7 = new QGroupBox(groupBox_2);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        verticalLayout_5 = new QVBoxLayout(groupBox_7);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_25 = new QLabel(groupBox_7);
        label_25->setObjectName(QStringLiteral("label_25"));

        horizontalLayout_11->addWidget(label_25);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_11);

        locator4XLineEdit = new QLineEdit(groupBox_7);
        locator4XLineEdit->setObjectName(QStringLiteral("locator4XLineEdit"));

        horizontalLayout_11->addWidget(locator4XLineEdit);


        verticalLayout_5->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_26 = new QLabel(groupBox_7);
        label_26->setObjectName(QStringLiteral("label_26"));

        horizontalLayout_12->addWidget(label_26);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_12);

        locator4YLineEdit = new QLineEdit(groupBox_7);
        locator4YLineEdit->setObjectName(QStringLiteral("locator4YLineEdit"));

        horizontalLayout_12->addWidget(locator4YLineEdit);


        verticalLayout_5->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_27 = new QLabel(groupBox_7);
        label_27->setObjectName(QStringLiteral("label_27"));

        horizontalLayout_13->addWidget(label_27);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_13);

        locator4ZLineEdit = new QLineEdit(groupBox_7);
        locator4ZLineEdit->setObjectName(QStringLiteral("locator4ZLineEdit"));

        horizontalLayout_13->addWidget(locator4ZLineEdit);


        verticalLayout_5->addLayout(horizontalLayout_13);


        verticalLayout_7->addWidget(groupBox_7);


        horizontalLayout_14->addLayout(verticalLayout_7);


        verticalLayout->addLayout(horizontalLayout_14);


        verticalLayout_8->addWidget(groupBox_2);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        okPushButton = new QPushButton(SettingLocator);
        okPushButton->setObjectName(QStringLiteral("okPushButton"));

        horizontalLayout_15->addWidget(okPushButton);

        cancelPushButton = new QPushButton(SettingLocator);
        cancelPushButton->setObjectName(QStringLiteral("cancelPushButton"));

        horizontalLayout_15->addWidget(cancelPushButton);


        verticalLayout_8->addLayout(horizontalLayout_15);

        groupBox_2->raise();
        refComboBox->raise();
        label->raise();

        retranslateUi(SettingLocator);

        QMetaObject::connectSlotsByName(SettingLocator);
    } // setupUi

    void retranslateUi(QDialog *SettingLocator)
    {
        SettingLocator->setWindowTitle(QApplication::translate("SettingLocator", "Dialog", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("SettingLocator", "Distance To Reference", Q_NULLPTR));
        label->setText(QApplication::translate("SettingLocator", "Ref", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("SettingLocator", "Locator 1", Q_NULLPTR));
        label_3->setText(QApplication::translate("SettingLocator", "x", Q_NULLPTR));
        label_4->setText(QApplication::translate("SettingLocator", "y", Q_NULLPTR));
        label_18->setText(QApplication::translate("SettingLocator", "z", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("SettingLocator", "Locator 2", Q_NULLPTR));
        label_19->setText(QApplication::translate("SettingLocator", "x", Q_NULLPTR));
        label_20->setText(QApplication::translate("SettingLocator", "y", Q_NULLPTR));
        label_21->setText(QApplication::translate("SettingLocator", "z", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("SettingLocator", "Locator 3", Q_NULLPTR));
        label_22->setText(QApplication::translate("SettingLocator", "x", Q_NULLPTR));
        label_23->setText(QApplication::translate("SettingLocator", "y", Q_NULLPTR));
        label_24->setText(QApplication::translate("SettingLocator", "z", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("SettingLocator", "Locator 4", Q_NULLPTR));
        label_25->setText(QApplication::translate("SettingLocator", "x", Q_NULLPTR));
        label_26->setText(QApplication::translate("SettingLocator", "y", Q_NULLPTR));
        label_27->setText(QApplication::translate("SettingLocator", "z", Q_NULLPTR));
        okPushButton->setText(QApplication::translate("SettingLocator", "OK", Q_NULLPTR));
        cancelPushButton->setText(QApplication::translate("SettingLocator", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SettingLocator: public Ui_SettingLocator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGLOCATOR_H
