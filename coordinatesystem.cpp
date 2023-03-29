#include "coordinatesystem.h"

CoordinateSystem::CoordinateSystem(QWidget *parent) : QWidget(parent)
{
    setAttribute(Qt::WA_DeleteOnClose);

    setWindowTitle(tr("Coordinate System"));
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();

    setMinimumSize(MINIMUM_WIDTH_WINDOW_COORDINATE * screenGeometry.width(), MINIMUM_HEIGHT_WINDOW_COORDINATE * screenGeometry.height());
//    setMinimumSize();
    resize(DEFAULT_WIDTH_WINDOW_COORDINATE * screenGeometry.width(), DEFAULT_HEIGHT_WINDOW_COORDINATE * screenGeometry.height());
//    QPainter *painter = new QPainter(this);
    setStyleSheet(tr("background-color: white"));
}

void CoordinateSystem::updateCoord(){
    update();
}

QPoint origin(0,0);
QSize  originSize(5,5);
QColor originColor(100, 192, 44);

QColor beaconColor(234,182,118);
QColor beaconOutlineColor(135,62,35);

QColor gridColor(21,127,179,150);
QBrush gridBrush(gridColor);
QPen gridPen(gridBrush, 1, Qt::DashLine );

QColor cartesianColor(21,127,179,255);
QPen cartesianPen(cartesianColor);

void CoordinateSystem::paintEvent(QPaintEvent *event){
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.translate(width()/2, height()/2);
    painter.save();
    float defaultWidth = DEFAULT_WIDTH_WINDOW_COORDINATE * screenGeometry.width();
    float defaultHeight = DEFAULT_HEIGHT_WINDOW_COORDINATE * screenGeometry.height();

//    QPen pen = QPen(gridBrush, 3, Qt::DashLine, )
    painter.setPen(gridPen);
    paintGrid(&painter);

    painter.setPen(cartesianPen);
    paintCoordinateCartesian(&painter);

    painter.setBrush(originColor);
    painter.setPen(Qt::NoPen);
    painter.drawEllipse(origin, originSize.width(), originSize.height());

    painter.setBrush(beaconColor);
    painter.setPen(beaconOutlineColor);

    QMap<QString, DeviceDataContainer> devices = QMap<QString, DeviceDataContainer>(*pDevices);

    for (auto device = devices.begin(); device != devices.end(); ++device){
        paintBeacon(&painter, device.key(), QPointF(device.value().x, device.value().y));
    }
//    paintBeacon(&painter, "F1A5", QPointF(-1.25,10));
//    paintBeacon(&painter, "F2MM", QPoint(10,10));
//    paintBeacon(&painter, "F1A5", QPointF(2.25,6.25));





//    painter.scale(width()/(defaultWidth), height()/(defaultHeight));

//! [15] //! [16]



//    auto minScaler = qMin(defaultWidth, defaultHeight);

//    if (minScaler == )



    painter.restore();
}

void CoordinateSystem::receiveCoordinate(QMap<QString, DeviceDataContainer> *devices){
    qDebug()<<"Coordinates buffer received";
    pDevices = devices;
}

void CoordinateSystem::paintBeacon(QPainter *painter, QString beaconAddress, QPointF coord){
    float x = width()/2 * coord.x() / (WIDTH_FIELD/2);
    float y = (-1) * height()/2 * coord.y() / (HEIGHT_FIELD/2);

    painter->drawEllipse(QPoint(x, y), BEACON_POINT_RADIUS, BEACON_POINT_RADIUS);

    QFont font = painter->font();
    QFontMetrics fontMetrics = QFontMetrics(font);
    QSize size = fontMetrics.size(Qt::TextSingleLine, beaconAddress);
    QRect rect = QRect(x - size.width()/2, y - size.height() * 1.2 - BEACON_POINT_RADIUS, size.width(), size.height());
    painter->drawText(rect, Qt::AlignCenter, beaconAddress);

//    painter->setPen(Qt::DashLine);
//    painter->setBrush(Qt::NoBrush);
//    painter->drawRect(rect);
    QString coordinate = tr("(%1, %2)").arg(coord.x()).arg(coord.y());
    size = fontMetrics.size(Qt::TextSingleLine, coordinate);
    rect = QRect(x - size.width()/2, y + size.height() * 0.2, size.width(), size.height());
    painter->drawText(rect, Qt::AlignCenter, coordinate);
}

void CoordinateSystem::paintGrid(QPainter *painter){
    for (double i = 0.0; i < GRID_Y_SIZE/2; i++){
        QPointF point1 = QPointF((-1) * width()/2, ((i + 1)/(GRID_Y_SIZE/2)) * height()/2);
        QPointF point2 = QPointF((1) * width()/2, ((i+ 1)/(GRID_Y_SIZE/2)) * height()/2);
        painter->drawLine(point1, point2);

        point1 = QPointF((-1) * width()/2, (-1) * ((i+1)/(GRID_Y_SIZE/2)) * height()/2);
        point2 = QPointF((1) * width()/2, (-1) * ((i+1)/(GRID_Y_SIZE/2)) * height()/2);
        painter->drawLine(point1, point2);
    }


    for (double i = 0.0; i < GRID_X_SIZE/2; i++){
        QPointF point1 = QPointF(((i + 1)/(GRID_X_SIZE/2)) * width()/2, (-1) * height()/2);
        QPointF point2 = QPointF(((i + 1)/(GRID_X_SIZE/2)) * width()/2, (1) * height()/2);
        painter->drawLine(point1, point2);

        point1 = QPointF((-1) * ((i+1)/(GRID_X_SIZE/2)) * width()/2, (-1) * height()/2);
        point2 = QPointF((-1) * ((i+1)/(GRID_X_SIZE/2)) * width()/2, (1) * height()/2);
        painter->drawLine(point1, point2);
    }
}

void CoordinateSystem::paintCoordinateCartesian(QPainter *painter){
    QFont font = painter->font();
    QFontMetrics fontMetrics = QFontMetrics(font);

    QPointF yAxis0 = QPointF((-1) * width()/2, 0);
    QPointF yAxis1 = QPointF((1) * width()/2, 0);
    painter->drawLine(yAxis0, yAxis1);

    for (double i = 0.0; i < GRID_Y_SIZE/2; i++){
        int value = int(i + 1) * (HEIGHT_FIELD/2) / (GRID_Y_SIZE/2);

        QSize plusTextSize = fontMetrics.size(Qt::TextSingleLine, tr("%1").arg((1) * value));
        QSize minusTextSize = fontMetrics.size(Qt::TextSingleLine, tr("%1").arg((-1) * value));

        QPointF pointPlus = QPointF(-plusTextSize.width(), ((-1) * (i + 1)/(GRID_Y_SIZE/2)) * height()/2);
        QPointF pointMinus = QPointF(-minusTextSize.width(), ((1) * (i + 1)/(GRID_Y_SIZE/2)) * height()/2);

        painter->drawText(pointPlus, tr("%1").arg((1) * value));
        painter->drawText(pointMinus, tr("%1").arg((-1) * value));
    }

    QPointF xAxis0 = QPointF(0, (-1) * width()/2);
    QPointF xAxis1 = QPointF(0, (1) * width()/2);

    for (double i = 0.0; i < GRID_X_SIZE/2; i++){
        int value = int(i + 1) * (WIDTH_FIELD/2) / (GRID_X_SIZE/2);

        QSize plusTextSize = fontMetrics.size(Qt::TextSingleLine, tr("%1").arg((1) * value));
        QSize minusTextSize = fontMetrics.size(Qt::TextSingleLine, tr("%1").arg((-1) * value));

        QPointF pointPlus = QPointF(((1) * (i + 1)/(GRID_X_SIZE/2)) * width()/2, 0);
        QPointF pointMinus = QPointF(((-1) * (i + 1)/(GRID_X_SIZE/2)) * width()/2, 0);

        painter->drawText(pointPlus, tr("%1").arg((1) * value));
        painter->drawText(pointMinus, tr("%1").arg((-1) * value));
    }

    painter->drawLine(xAxis0, xAxis1);
}
