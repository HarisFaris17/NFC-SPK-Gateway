#ifndef SETTINGLOCATOR_H
#define SETTINGLOCATOR_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QDoubleValidator>
#include <QComboBox>
#include <QList>
#include <QDebug>

namespace Ui {
class SettingLocator;
}

class SettingLocator : public QDialog
{
    Q_OBJECT

public:
    explicit SettingLocator(QWidget *parent = 0);
    ~SettingLocator();

public Q_SLOTS:
    void refComboBoxChanged(const QString &ref);
    void okClicked();
    void cancelClicked();

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

    QComboBox *refComboBox;

    QPushButton *okPushButton;
    QPushButton *cancelPushButton;

    QString currentRef = "Locator 1";

private :
    void enableCurrentLocatorRef();

};

#endif // SETTINGLOCATOR_H
