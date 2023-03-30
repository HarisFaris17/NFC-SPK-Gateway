#include "settinglocator.h"
#include "ui_settinglocator.h"

SettingLocator::SettingLocator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingLocator)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
#define LOCATOR_LINE_EDIT(id)      locator## id ##XLineEdit = ui->locator## id ##XLineEdit; \
                                   locator## id ##YLineEdit = ui->locator## id ##YLineEdit; \
                                   locator## id ##ZLineEdit = ui->locator## id ##ZLineEdit;

    LOCATOR_LINE_EDIT(0)
//    locator1XLineEdit = ui->locator1XLineEdit;
//    locator1YLineEdit = ui->locator1YLineEdit;
//    locator1ZLineEdit = ui->locator1ZLineEdit;
//    locator2XLineEdit = ui->locator2XLineEdit;
//    locator2YLineEdit = ui->locator2YLineEdit;
//    locator2ZLineEdit = ui->locator2ZLineEdit;
//    locator3XLineEdit = ui->locator3XLineEdit;
//    locator3YLineEdit = ui->locator3YLineEdit;
//    locator3ZLineEdit = ui->locator3ZLineEdit;
//    locator4XLineEdit = ui->locator4XLineEdit;
//    locator4YLineEdit = ui->locator4YLineEdit;
//    locator4ZLineEdit = ui->locator4ZLineEdit;
    LOCATOR_LINE_EDIT(1)
    LOCATOR_LINE_EDIT(2)
    LOCATOR_LINE_EDIT(3)
    LOCATOR_LINE_EDIT(4)
    LOCATOR_LINE_EDIT(5)
    LOCATOR_LINE_EDIT(6)
    LOCATOR_LINE_EDIT(7)

    rssi1mLineEdit = ui->rssi1mLineEdit;
    rssi2mLineEdit = ui->rssi2mLineEdit;

    applyCalibrationPushButton = ui->applyCalibrationPushButton;
    applyDistancePushButton = ui->applyDistancePushButton;

//    okPushButton = ui->okPushButton;
//    cancelPushButton = ui->cancelPushButton;

    QDoubleValidator *validator = new QDoubleValidator(this);
    QDoubleValidator *validatorRSSI = new QDoubleValidator(this);

#define SET_VALIDATOR_LINE_EDIT(locator_idx, validator)     locator## locator_idx ##XLineEdit->setValidator(validator); \
                                                            locator## locator_idx ##YLineEdit->setValidator(validator); \
                                                            locator## locator_idx ##ZLineEdit->setValidator(validator);
    SET_VALIDATOR_LINE_EDIT(0, validator)
//    locator1XLineEdit->setValidator(validator);
//    locator1YLineEdit->setValidator(validator);
//    locator1ZLineEdit->setValidator(validator);
//    locator2XLineEdit->setValidator(validator);
//    locator2YLineEdit->setValidator(validator);
//    locator2ZLineEdit->setValidator(validator);
//    locator3XLineEdit->setValidator(validator);
//    locator3YLineEdit->setValidator(validator);
//    locator3ZLineEdit->setValidator(validator);
//    locator4XLineEdit->setValidator(validator);
//    locator4YLineEdit->setValidator(validator);
//    locator4ZLineEdit->setValidator(validator);
    SET_VALIDATOR_LINE_EDIT(1, validator)
    SET_VALIDATOR_LINE_EDIT(2, validator)
    SET_VALIDATOR_LINE_EDIT(3, validator)
    SET_VALIDATOR_LINE_EDIT(4, validator)
    SET_VALIDATOR_LINE_EDIT(5, validator)
    SET_VALIDATOR_LINE_EDIT(6, validator)
    SET_VALIDATOR_LINE_EDIT(7, validator)

    rssi1mLineEdit->setValidator(validatorRSSI);
    rssi2mLineEdit->setValidator(validatorRSSI);

//    refComboBox = ui->refComboBox;
//    refComboBox->addItem("Locator 1");
//    refComboBox->addItem("Locator 2");
//    refComboBox->addItem("Locator 3");
//    refComboBox->addItem("Locator 4");

//    okPushButton =

//    connect(refComboBox, &QComboBox::currentTextChanged, this, &SettingLocator::refComboBoxChanged);
    connect(applyCalibrationPushButton, &QPushButton::clicked, this, &SettingLocator::applyCalibrationClicked);
    connect(applyDistancePushButton, &QPushButton::clicked, this, &SettingLocator::applyDistanceClicked);

#define CONNECT_LOCATOR_Z_LINE_EDIT(locator_idx) connect(locator## locator_idx ##ZLineEdit, &QLineEdit::textEdited, this, &SettingLocator::zLinesChanged);
    connect(locator1ZLineEdit, &QLineEdit::textEdited, this, &SettingLocator::zLinesChanged);
    connect(locator2ZLineEdit, &QLineEdit::textEdited, this, &SettingLocator::zLinesChanged);
    connect(locator3ZLineEdit, &QLineEdit::textEdited, this, &SettingLocator::zLinesChanged);
    connect(locator4ZLineEdit, &QLineEdit::textEdited, this, &SettingLocator::zLinesChanged);

    CONNECT_LOCATOR_Z_LINE_EDIT(0)
    CONNECT_LOCATOR_Z_LINE_EDIT(4)
    CONNECT_LOCATOR_Z_LINE_EDIT(5)
    CONNECT_LOCATOR_Z_LINE_EDIT(6)
    CONNECT_LOCATOR_Z_LINE_EDIT(7)
//    connect(okPushButton, &QPushButton::clicked, this, &SettingLocator::okClicked);
//    connect(cancelPushButton, &QPushButton::clicked, this, &SettingLocator::cancelClicked);


//    QString ref;
#define COORD(locator_idx)      QString x##locator_idx; \
                                QString y##locator_idx; \
                                QString z##locator_idx;
//    QString x2;
//    QString y2;
//    QString z2;
//    QString x3;
//    QString y3;
//    QString z3;
//    QString x4;
//    QString y4;
//    QString z4;
    COORD(0)
    COORD(1)
    COORD(2)
    COORD(3)
    COORD(4)
    COORD(5)
    COORD(6)
    COORD(7)

    File file;
    file.parseLocatorParams(x0, y0, z0, x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, x5, y5, z5, x6, y6, z6, x7, y7, z7);
//    qDebug() << x0 << x1 << x2 << x3 << x4 << x5 << x6 << x7;

//    int refInt = ref.toInt();
//    refComboBox->setCurrentIndex(refInt);

//    currentRef = refComboBox->currentText();
//    disableCurrentLocatorRef();
#define SET_TEXT_LOCATOR(locator_idx)       locator## locator_idx ##XLineEdit->setText(x## locator_idx); \
                                            locator## locator_idx ##YLineEdit->setText(y## locator_idx); \
                                            locator## locator_idx ##ZLineEdit->setText(z## locator_idx);
//    locator1YLineEdit->setText(y1);
//    locator1ZLineEdit->setText(z1);
//    locator1XLineEdit->setText(x1);
//    locator1YLineEdit->setText(y1);
//    locator1ZLineEdit->setText(z1);
//    locator2XLineEdit->setText(x2);
//    locator2YLineEdit->setText(y2);
//    locator2ZLineEdit->setText(z2);
//    locator3XLineEdit->setText(x3);
//    locator3YLineEdit->setText(y3);
//    locator3ZLineEdit->setText(z3);
//    locator4XLineEdit->setText(x4);
//    locator4YLineEdit->setText(y4);
//    locator4ZLineEdit->setText(z4);
    SET_TEXT_LOCATOR(0)
    SET_TEXT_LOCATOR(1)
    SET_TEXT_LOCATOR(2)
    SET_TEXT_LOCATOR(3)
    SET_TEXT_LOCATOR(4)
    SET_TEXT_LOCATOR(5)
    SET_TEXT_LOCATOR(6)
    SET_TEXT_LOCATOR(7)

    QString RSSI1m;
    QString RSSI2m;

    file.parseRSSI(RSSI1m, RSSI2m);
    rssi1mLineEdit->setText(RSSI1m);
    rssi2mLineEdit->setText(RSSI2m);
}

SettingLocator::~SettingLocator()
{
    delete ui;
}

#define ENABLE_LOCATOR(_locator) ((_locator)->setEnabled(true))
#define DISABLE_LOCATOR(_locator) ((_locator)->setEnabled(false))
#define SET_TEXT_0_LOCATOR(_locator) ((_locator)->setText("0"))


//void SettingLocator::refComboBoxChanged(const QString &ref){
//    int indexLocator = refComboBox->currentIndex() + 1;

//    enableCurrentLocatorRef();

//    if (ref == "Locator 1"){
//        SET_TEXT_0_LOCATOR(locator1XLineEdit);
//        SET_TEXT_0_LOCATOR(locator1YLineEdit);
//        SET_TEXT_0_LOCATOR(locator1ZLineEdit);
//        DISABLE_LOCATOR(locator1XLineEdit);
//        DISABLE_LOCATOR(locator1YLineEdit);
//        DISABLE_LOCATOR(locator1ZLineEdit);
//    }
//    else if (ref == "Locator 2"){
//        SET_TEXT_0_LOCATOR(locator2XLineEdit);
//        SET_TEXT_0_LOCATOR(locator2YLineEdit);
//        SET_TEXT_0_LOCATOR(locator2ZLineEdit);
//        DISABLE_LOCATOR(locator2XLineEdit);
//        DISABLE_LOCATOR(locator2YLineEdit);
//        DISABLE_LOCATOR(locator2ZLineEdit);
//    }
//    else if (ref == "Locator 3"){
//        SET_TEXT_0_LOCATOR(locator3XLineEdit);
//        SET_TEXT_0_LOCATOR(locator3YLineEdit);
//        SET_TEXT_0_LOCATOR(locator3ZLineEdit);
//        DISABLE_LOCATOR(locator3XLineEdit);
//        DISABLE_LOCATOR(locator3YLineEdit);
//        DISABLE_LOCATOR(locator3ZLineEdit);
//    }
//    else if (ref == "Locator 4"){
//        SET_TEXT_0_LOCATOR(locator4XLineEdit);
//        SET_TEXT_0_LOCATOR(locator4YLineEdit);
//        SET_TEXT_0_LOCATOR(locator4ZLineEdit);
//        DISABLE_LOCATOR(locator4XLineEdit);
//        DISABLE_LOCATOR(locator4YLineEdit);
//        DISABLE_LOCATOR(locator4ZLineEdit);
//    }else {
//        qDebug()<<"Locator not recognized";
//        return;
//    }

//    currentRef = ref;
//}

void SettingLocator::applyCalibrationClicked(){
    bool isSuccedd = true;
    float rssi1m = rssi1mLineEdit->text().toFloat(&isSuccedd);

    if (!isSuccedd){
        qDebug()<<"Failed to convert rssi1m";
        return;
    }

    float rssi2m = rssi2mLineEdit->text().toFloat(&isSuccedd);
    if (!isSuccedd){
        qDebug()<<"Failed to convert rssi1m";
        return;
    }

    if (rssi2m > rssi1m){
        qDebug()<<"RSSI 2m must be larger than RSSI 1m";
        return;
    }

    QString rssi1mString = QString::number(rssi1m);
    QString rssi2mString = QString::number(rssi2m);

    Q_EMIT sendRSSI(rssi1mString, rssi2mString);
}

void SettingLocator::applyDistanceClicked(){
    bool isSuccess = true;

#define GET_AXIS_VALUE(axis, locator_idx)       QString axis ## locator_idx = QString::number(locator## locator_idx ## axis ##LineEdit->text().toFloat(&isSuccess)); \
                                                if (!isSuccess){ \
                                                    qDebug()<<"Error axis ## locator_idx ## value"; \
                                                    return; \
                                                }

#define GET_COORD_VALUE(locator_idx)            GET_AXIS_VALUE(X, locator_idx) \
                                                GET_AXIS_VALUE(Y, locator_idx) \
                                                GET_AXIS_VALUE(Z, locator_idx)

    QString x1 = QString::number(locator1XLineEdit->text().toFloat(&isSuccess));
    if (!isSuccess){
        qDebug()<<"Error x1 value";
        return;
    }

    QString y1 = QString::number(locator1YLineEdit->text().toFloat(&isSuccess));
    if (!isSuccess){
        qDebug()<<"Error y1 value";
        return;
    }

    QString z1 = QString::number(locator1ZLineEdit->text().toFloat(&isSuccess));
    if (!isSuccess){
        qDebug()<<"Error z1 value";
        return;
    }

    QString x2 = QString::number(locator2XLineEdit->text().toFloat(&isSuccess));
    if (!isSuccess){
        qDebug()<<"Error x2 value";
        return;
    }

    QString y2 = QString::number(locator2YLineEdit->text().toFloat(&isSuccess));
    if (!isSuccess){
        qDebug()<<"Error y2 value";
        return;
    }

    QString z2 = QString::number(locator2ZLineEdit->text().toFloat(&isSuccess));
    if (!isSuccess){
        qDebug()<<"Error z2 value";
        return;
    }

    QString x3 = QString::number(locator3XLineEdit->text().toFloat(&isSuccess));
    if (!isSuccess){
        qDebug()<<"Error x3 value";
        return;
    }

    QString y3 = QString::number(locator3YLineEdit->text().toFloat(&isSuccess));
    if (!isSuccess){
        qDebug()<<"Error y3 value";
        return;
    }

    QString z3 = QString::number(locator3ZLineEdit->text().toFloat(&isSuccess));
    if (!isSuccess){
        qDebug()<<"Error z3 value";
        return;
    }

    QString x4 = QString::number(locator4XLineEdit->text().toFloat(&isSuccess));
    if (!isSuccess){
        qDebug()<<"Error x4 value";
        return;
    }

    QString y4 = QString::number(locator4YLineEdit->text().toFloat(&isSuccess));
    if (!isSuccess){
        qDebug()<<"Error y4 value";
        return;
    }

    QString z4 = QString::number(locator4ZLineEdit->text().toFloat(&isSuccess));
    if (!isSuccess){
        qDebug()<<"Error z4 value";
        return;
    }

//    int locatorIndex = refComboBox->currentIndex();

//    sendLocatorParams(locatorIndex, x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4);
    GET_COORD_VALUE(0);
    GET_COORD_VALUE(1);
    GET_COORD_VALUE(2);
    GET_COORD_VALUE(3);
    GET_COORD_VALUE(4);
    GET_COORD_VALUE(5);
    GET_COORD_VALUE(6);
    GET_COORD_VALUE(7);
    sendLocatorParams(X0, Y0, Z0, X1, Y1, Z1, X2, Y2, Z2, X3, Y3, Z3, X4, Y4, Z4, X5, Y5, Z5, X6, Y6, Z6, X7, Y7, Z7);
}

void SettingLocator::zLinesChanged(const QString &newText){
    QLineEdit *lineChanged = qobject_cast<QLineEdit *>(sender());
    locator0ZLineEdit->setText(newText);
    locator1ZLineEdit->setText(newText);
    locator2ZLineEdit->setText(newText);
    locator3ZLineEdit->setText(newText);
    locator4ZLineEdit->setText(newText);
    locator5ZLineEdit->setText(newText);
    locator6ZLineEdit->setText(newText);
    locator7ZLineEdit->setText(newText);
}

//void SettingLocator::enableCurrentLocatorRef(){
//    if (currentRef == "Locator 1"){
//        ENABLE_LOCATOR(locator1XLineEdit);
//        ENABLE_LOCATOR(locator1YLineEdit);
//        ENABLE_LOCATOR(locator1ZLineEdit);
//    }else if (currentRef == "Locator 2"){
//        ENABLE_LOCATOR(locator2XLineEdit);
//        ENABLE_LOCATOR(locator2YLineEdit);
//        ENABLE_LOCATOR(locator2ZLineEdit);
//    }else if (currentRef == "Locator 3"){
//        ENABLE_LOCATOR(locator3XLineEdit);
//        ENABLE_LOCATOR(locator3YLineEdit);
//        ENABLE_LOCATOR(locator3ZLineEdit);
//    }else if (currentRef == "Locator 4"){
//        ENABLE_LOCATOR(locator4XLineEdit);
//        ENABLE_LOCATOR(locator4YLineEdit);
//        ENABLE_LOCATOR(locator4ZLineEdit);
//    }
//}

//void SettingLocator::disableCurrentLocatorRef(){
//    if (currentRef == "Locator 1"){
//        DISABLE_LOCATOR(locator1XLineEdit);
//        DISABLE_LOCATOR(locator1YLineEdit);
//        DISABLE_LOCATOR(locator1ZLineEdit);
//    }else if (currentRef == "Locator 2"){
//        DISABLE_LOCATOR(locator2XLineEdit);
//        DISABLE_LOCATOR(locator2YLineEdit);
//        DISABLE_LOCATOR(locator2ZLineEdit);
//    }else if (currentRef == "Locator 3"){
//        DISABLE_LOCATOR(locator3XLineEdit);
//        DISABLE_LOCATOR(locator3YLineEdit);
//        DISABLE_LOCATOR(locator3ZLineEdit);
//    }else if (currentRef == "Locator 4"){
//        DISABLE_LOCATOR(locator4XLineEdit);
//        DISABLE_LOCATOR(locator4YLineEdit);
//        DISABLE_LOCATOR(locator4ZLineEdit);
//    }
//}


