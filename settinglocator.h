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
    void sendLocatorParams(QString x0, QString y0, QString z0,
                           QString x1, QString y1, QString z1,
                           QString x2, QString y2, QString z2,
                           QString x3, QString y3, QString z3,
                           QString x4, QString y4, QString z4,
                           QString x5, QString y5, QString z5,
                           QString x6, QString y6, QString z6,
                           QString x7, QString y7, QString z7);

    void sendRSSI(QString rssi1m, QString rssi2m);

public:
    explicit SettingLocator(QWidget *parent = 0);
    ~SettingLocator();

public Q_SLOTS:
//    void refComboBoxChanged(const QString &ref);
    void applyCalibrationClicked();
    void applyDistanceClicked();

    void zLinesChanged(const QString &newText);

private:
    Ui::SettingLocator *ui;
#define DEFINE_LOCATOR(id)      QLineEdit *locator## id ##XLineEdit; \
                                QLineEdit *locator## id ##YLineEdit; \
                                QLineEdit *locator## id ##ZLineEdit;
    DEFINE_LOCATOR(0)
    DEFINE_LOCATOR(1)
    DEFINE_LOCATOR(2)
    DEFINE_LOCATOR(3)
    DEFINE_LOCATOR(4)
    DEFINE_LOCATOR(5)
    DEFINE_LOCATOR(6)
    DEFINE_LOCATOR(7)


    QLineEdit *rssi1mLineEdit;
    QLineEdit *rssi2mLineEdit;

//    QComboBox *refComboBox;

    QPushButton *applyCalibrationPushButton;
    QPushButton *applyDistancePushButton;

//    QPushButton *okPushButton;
//    QPushButton *cancelPushButton;

    QString currentRef = "Locator 1";



private :
//    void enableCurrentLocatorRef();
//    void disableCurrentLocatorRef();

};

#endif // SETTINGLOCATOR_H
