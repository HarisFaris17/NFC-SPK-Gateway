#include "settinglocator.h"
#include "ui_settinglocator.h"

SettingLocator::SettingLocator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingLocator)
{
    ui->setupUi(this);
    locator1XLineEdit = ui->locator1XLineEdit;
    locator1YLineEdit = ui->locator1YLineEdit;
    locator1ZLineEdit = ui->locator1ZLineEdit;
    locator2XLineEdit = ui->locator2XLineEdit;
    locator2YLineEdit = ui->locator2YLineEdit;
    locator2ZLineEdit = ui->locator2ZLineEdit;
    locator3XLineEdit = ui->locator3XLineEdit;
    locator3YLineEdit = ui->locator3YLineEdit;
    locator3ZLineEdit = ui->locator3ZLineEdit;
    locator4XLineEdit = ui->locator4XLineEdit;
    locator4YLineEdit = ui->locator4YLineEdit;
    locator4ZLineEdit = ui->locator4ZLineEdit;

    okPushButton = ui->okPushButton;
    cancelPushButton = ui->cancelPushButton;

    QDoubleValidator *validator = new QDoubleValidator(this);

    locator1XLineEdit->setValidator(validator);
    locator1YLineEdit->setValidator(validator);
    locator1ZLineEdit->setValidator(validator);
    locator2XLineEdit->setValidator(validator);
    locator2YLineEdit->setValidator(validator);
    locator2ZLineEdit->setValidator(validator);
    locator3XLineEdit->setValidator(validator);
    locator3YLineEdit->setValidator(validator);
    locator3ZLineEdit->setValidator(validator);
    locator4XLineEdit->setValidator(validator);
    locator4YLineEdit->setValidator(validator);
    locator4ZLineEdit->setValidator(validator);

    refComboBox = ui->refComboBox;
    refComboBox->addItem("Locator 1");
    refComboBox->addItem("Locator 2");
    refComboBox->addItem("Locator 3");
    refComboBox->addItem("Locator 4");

//    okPushButton =

    connect(refComboBox, &QComboBox::currentTextChanged, this, &SettingLocator::refComboBoxChanged);
    connect(okPushButton, &QPushButton::clicked, this, &SettingLocator::okClicked);
    connect(cancelPushButton, &QPushButton::clicked, this, &SettingLocator::cancelClicked);

    refComboBoxChanged("Locator 1");
}

SettingLocator::~SettingLocator()
{
    delete ui;
}

#define ENABLE_LOCATOR(_locator) ((_locator)->setEnabled(true))
#define DISABLE_LOcATOR(_locator) ((_locator)->setEnabled(false))
#define SET_TEXT_0_LOCATOR(_locator) ((_locator)->setText("0"))


void SettingLocator::refComboBoxChanged(const QString &ref){
    int indexLocator = refComboBox->currentIndex() + 1;

    enableCurrentLocatorRef();

    if (ref == "Locator 1"){
        SET_TEXT_0_LOCATOR(locator1XLineEdit);
        SET_TEXT_0_LOCATOR(locator1YLineEdit);
        SET_TEXT_0_LOCATOR(locator1ZLineEdit);
        DISABLE_LOcATOR(locator1XLineEdit);
        DISABLE_LOcATOR(locator1YLineEdit);
        DISABLE_LOcATOR(locator1ZLineEdit);
    }
    else if (ref == "Locator 2"){
        SET_TEXT_0_LOCATOR(locator2XLineEdit);
        SET_TEXT_0_LOCATOR(locator2YLineEdit);
        SET_TEXT_0_LOCATOR(locator2ZLineEdit);
        DISABLE_LOcATOR(locator2XLineEdit);
        DISABLE_LOcATOR(locator2YLineEdit);
        DISABLE_LOcATOR(locator2ZLineEdit);
    }
    else if (ref == "Locator 3"){
        SET_TEXT_0_LOCATOR(locator3XLineEdit);
        SET_TEXT_0_LOCATOR(locator3YLineEdit);
        SET_TEXT_0_LOCATOR(locator3ZLineEdit);
        DISABLE_LOcATOR(locator3XLineEdit);
        DISABLE_LOcATOR(locator3YLineEdit);
        DISABLE_LOcATOR(locator3ZLineEdit);
    }
    else if (ref == "Locator 4"){
        SET_TEXT_0_LOCATOR(locator4XLineEdit);
        SET_TEXT_0_LOCATOR(locator4YLineEdit);
        SET_TEXT_0_LOCATOR(locator4ZLineEdit);
        DISABLE_LOcATOR(locator4XLineEdit);
        DISABLE_LOcATOR(locator4YLineEdit);
        DISABLE_LOcATOR(locator4ZLineEdit);
    }else {
        qDebug()<<"Locator not recognized";
        return;
    }

    currentRef = ref;
}

void SettingLocator::okClicked(){

}

void SettingLocator::cancelClicked(){

}

void SettingLocator::enableCurrentLocatorRef(){
    if (currentRef == "Locator 1"){
        ENABLE_LOCATOR(locator1XLineEdit);
        ENABLE_LOCATOR(locator1YLineEdit);
        ENABLE_LOCATOR(locator1ZLineEdit);
    }else if (currentRef == "Locator 2"){
        ENABLE_LOCATOR(locator2XLineEdit);
        ENABLE_LOCATOR(locator2YLineEdit);
        ENABLE_LOCATOR(locator2ZLineEdit);
    }else if (currentRef == "Locator 3"){
        ENABLE_LOCATOR(locator3XLineEdit);
        ENABLE_LOCATOR(locator3YLineEdit);
        ENABLE_LOCATOR(locator3ZLineEdit);
    }else if (currentRef == "Locator 4"){
        ENABLE_LOCATOR(locator4XLineEdit);
        ENABLE_LOCATOR(locator4YLineEdit);
        ENABLE_LOCATOR(locator4ZLineEdit);
    }
}


