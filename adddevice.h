#ifndef ADDDEVICE_H
#define ADDDEVICE_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QRegularExpressionValidator>
#include <QDebug>

namespace Ui {
class AddDevice;
}

class AddDevice : public QDialog
{
    Q_OBJECT

Q_SIGNALS:
    sendDeviceID(const QString &mac);

public:
    explicit AddDevice(QWidget *parent = 0);
    ~AddDevice();

private Q_SLOTS:
    void addClicked();

private:
    Ui::AddDevice *ui;

    QPushButton *addDevicePushbutton;
    QLineEdit *deviceIDLineEdit;
};

#endif // ADDDEVICE_H
