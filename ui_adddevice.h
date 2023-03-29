/********************************************************************************
** Form generated from reading UI file 'adddevice.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDEVICE_H
#define UI_ADDDEVICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddDevice
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout_2;
    QLabel *label;
    QLineEdit *deviceIDLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *addDevicePushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *AddDevice)
    {
        if (AddDevice->objectName().isEmpty())
            AddDevice->setObjectName(QStringLiteral("AddDevice"));
        AddDevice->resize(356, 83);
        verticalLayout = new QVBoxLayout(AddDevice);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label = new QLabel(AddDevice);
        label->setObjectName(QStringLiteral("label"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        deviceIDLineEdit = new QLineEdit(AddDevice);
        deviceIDLineEdit->setObjectName(QStringLiteral("deviceIDLineEdit"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, deviceIDLineEdit);


        verticalLayout->addLayout(formLayout_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        addDevicePushButton = new QPushButton(AddDevice);
        addDevicePushButton->setObjectName(QStringLiteral("addDevicePushButton"));

        horizontalLayout_2->addWidget(addDevicePushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(AddDevice);

        QMetaObject::connectSlotsByName(AddDevice);
    } // setupUi

    void retranslateUi(QDialog *AddDevice)
    {
        AddDevice->setWindowTitle(QApplication::translate("AddDevice", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("AddDevice", "Device ID", Q_NULLPTR));
        addDevicePushButton->setText(QApplication::translate("AddDevice", "Add", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddDevice: public Ui_AddDevice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDEVICE_H
