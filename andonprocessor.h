#ifndef ANDONPROCESSOR_H
#define ANDONPROCESSOR_H

#include <QObject>
#include <QDebug>

class AndonProcessor : public QObject
{
    Q_OBJECT
public:
    explicit AndonProcessor(QObject *parent = 0);

signals:

public slots:
    void started();
};

#endif // ANDONPROCESSOR_H
