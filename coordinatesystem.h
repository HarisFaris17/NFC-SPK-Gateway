#ifndef COORDINATESYSTEM_H
#define COORDINATESYSTEM_H

#include "constants.h"
#include "devicedatacontainer.h"
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QGuiApplication>
#include <QScreen>
#include <QRect>
#include <QResizeEvent>
#include <QFont>
#include <QFontMetrics>
#include <QPointF>
#include <QPoint>
#include <QBrush>
#include <QMap>
#include <QDebug>

class CoordinateSystem : public QWidget
{
    Q_OBJECT
public:
    explicit CoordinateSystem(QWidget *parent = 0);

signals:

public slots:
    void updateCoord();

public:
    void paintEvent(QPaintEvent *event) override;
    void receiveCoordinate(QMap<QString, DeviceDataContainer> *devices);

private:
    void paintBeacon(QPainter *painter, QString beaconAddress, QPointF coord);
    void paintGrid(QPainter *painter);
    void paintCoordinateCartesian(QPainter *painter);

    QMap<QString, DeviceDataContainer> *pDevices;

};

#endif // COORDINATESYSTEM_H
