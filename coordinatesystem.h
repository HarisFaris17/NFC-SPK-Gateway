#ifndef COORDINATESYSTEM_H
#define COORDINATESYSTEM_H

#include "constants.h"
#include "devicedatacontainer.h"
#include "file.h"
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
    void updateLocatorCoordinate(QString x0, QString y0, QString z0,
                                 QString x1, QString y1, QString z1,
                                 QString x2, QString y2, QString z2,
                                 QString x3, QString y3, QString z3,
                                 QString x4, QString y4, QString z4,
                                 QString x5, QString y5, QString z5,
                                 QString x6, QString y6, QString z6,
                                 QString x7, QString y7, QString z7);

public:
    void paintEvent(QPaintEvent *event) override;
    void receiveCoordinate(QMap<QString, DeviceDataContainer> *devices);

private:
    void paintBeacon(QPainter *painter, QString beaconAddress, QPointF coord);
    void paintLocator(QPainter *painter, QPointF locator, int locator_idx);
    void paintGrid(QPainter *painter);
    void paintCoordinateCartesian(QPainter *painter);

    QMap<QString, DeviceDataContainer> *pDevices;
    QMap<int, QList<int>> locatorCoordinates;

};

#endif // COORDINATESYSTEM_H
