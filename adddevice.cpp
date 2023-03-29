#include "adddevice.h"
#include "ui_adddevice.h"

AddDevice::AddDevice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDevice)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    deviceIDLineEdit = ui->deviceIDLineEdit;
    addDevicePushbutton = ui->addDevicePushButton;

    QRegularExpression re("[0-9a-fA-F]+");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(re, this);

    deviceIDLineEdit->setValidator(validator);

    connect(addDevicePushbutton, &QPushButton::clicked, this, &AddDevice::addClicked);
}

void AddDevice::addClicked(){
    QString deviceID = deviceIDLineEdit->text();
    if (deviceID.isEmpty()){
        qDebug() << "The Device ID shouldn't be empty";
        return;
    }
    deviceID = deviceID.toUpper();
    sendDeviceID(deviceID);
    deleteLater();
}

AddDevice::~AddDevice()
{
    delete ui;
}
