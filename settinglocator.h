#ifndef SETTINGLOCATOR_H
#define SETTINGLOCATOR_H

#include "file.h"
#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QDoubleValidator>
#include <QComboBox>
#include <QList>
#include <QDebug>
#include <QPushButton>

namespace Ui {
class SettingLocator;
}

class SettingLocator : public QDialog
{
    Q_OBJECT
Q_SIGNALS:
    void sendLocatorParams(int ref,
                           QString x1, QString y1, QString z1,
                           QString x2, QString y2, QString z2,
                           QString x3, QString y3, QString z3,
                           QString x4, QString y4, QString z4);

    void sendRSSI(QString rssi1m, QString rssi2m);

public:
    explicit SettingLocator(QWidget *parent = 0);
    ~SettingLocator();

public Q_SLOTS:
    void refComboBoxChanged(const QString &ref);
    void applyCalibrationClicked();
    void applyDistanceClicked();

    void zLinesChanged(const QString &newText);

private:
    Ui::SettingLocator *ui;

    QLineEdit *locator1XLineEdit;
    QLineEdit *locator1YLineEdit;
    QLineEdit *locator1ZLineEdit;
    QLineEdit *locator2XLineEdit;
    QLineEdit *locator2YLineEdit;
    QLineEdit *locator2ZLineEdit;
    QLineEdit *locator3XLineEdit;
    QLineEdit *locator3YLineEdit;
    QLineEdit *locator3ZLineEdit;
    QLineEdit *locator4XLineEdit;
    QLineEdit *locator4YLineEdit;
    QLineEdit *locator4ZLineEdit;

    QLineEdit *rssi1mLineEdit;
    QLineEdit *rssi2mLineEdit;

    QComboBox *refComboBox;

    QPushButton *applyCalibrationPushButton;
    QPushButton *applyDistancePushButton;

//    QPushButton *okPushButton;
//    QPushButton *cancelPushButton;

    QString currentRef = "Locator 1";



private :
    void enableCurrentLocatorRef();
    void disableCurrentLocatorRef();

};

#endif // SETTINGLOCATOR_H
