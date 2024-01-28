#include "mytriangle.h"
#include <QPainter>
#include <qmath.h>

#define SIN30   1/2
#define COS60   1/2


MyTriangle::MyTriangle(QWidget *parent): QWidget(parent) {

    QPalette pal = QPalette();
    //pal.setColor(QPalette::Window, Qt::lightGray); //QColor(255, 0, 0, 127)
    pal.setColor(QPalette::Window, QColor(0, 0, 0, 50));
    this->setAutoFillBackground(true);
    this->setPalette(pal);


   // color = Qt::yellow;
   // widgSize = 100;
   // size = widgSize - 3;
   // orientation = 0;
   // resize(widgSize,widgSize);        // widget izmērs
}

void MyTriangle::paintEvent(QPaintEvent *event)
{
    qDebug() << "Triangle::draw" << widgSize <<points[0]<<points[1]<<points[2];
    Q_UNUSED (event);
  //  qDebug() << "MyTriangle::paintEvent";
    QPainter painter(this);
    QPen pen;
    pen.setWidth(4);
    pen.setColor(Qt::black);
    painter.setBrush(color);
    painter.setPen(pen);
    painter.drawPolygon(points,3);

}

void MyTriangle::setColour(QColor col)
{
    color = col;
}

void MyTriangle::setSize(int wSize, int orientation)
{

   // widgSize = wSize;
    size = wSize - 3;  // line width
    switch (orientation) {
    case 0:
        points[0] = QPoint(size/4,size);
        points[1] = QPoint(static_cast<uint16_t>(size * SIN30),static_cast<uint16_t>(size * COS60));
        points[2] = QPoint(3*size/4,size);
        break;
    case 90:
        points[0] = QPoint(0,size/4);
        points[1] = QPoint(static_cast<uint16_t>(size * SIN30),static_cast<uint16_t>(size * COS60));
        points[2] = QPoint(0,3*size/4);
        break;
    case 180:
        points[0] = QPoint(size/4,0);
        points[1] = QPoint(static_cast<uint16_t>(size * SIN30),static_cast<uint16_t>(size * COS60));
        points[2] = QPoint(3*size/4,0);
        break;
    case 270:
        points[0] = QPoint(size,size/4);
        points[1] = QPoint(static_cast<uint16_t>(size * SIN30),static_cast<uint16_t>(size * COS60));
        points[2] = QPoint(size,3*size/4);
        break;
    default:
        points[0] = QPoint(size/4,size);
        points[1] = QPoint(static_cast<uint16_t>(size * SIN30),static_cast<uint16_t>(size * COS60));
        points[2] = QPoint(3*size/4,size);
        break;
    }
}


