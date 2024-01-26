#include "dyno.h"
#include <QPainter>
#include<QMouseEvent>
#include <QPixmap>
#include <QFile>
#include "widgetservice.h"

Dyno::Dyno(QWidget *parent)
    : WidgetDiagramElement(parent)


{
    QPalette pal = QPalette();
    //pal.setColor(QPalette::Window, Qt::lightGray); //QColor(255, 0, 0, 127)
    pal.setColor(QPalette::Window, QColor(0, 0, 0, 50));
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    settings.currX = settings.startX;
    settings.currY = settings.startY;
    settings.currSize = settings.startSize;

}

void Dyno::updateSettings()
{
    settings.currX = settings.startX;
    settings.currY = settings.startY;
    settings.currSize = settings.startSize;
    move(settings.startX,settings.startY);

    resize( settings.currSize, settings.currSize);
    //   update();

}

void Dyno::setNewPosition(float koef)
{
    settings.currX = int(settings.startX /koef);
    settings.currY = int(settings.startY / koef);
    settings.currSize = int (settings.startSize/koef);

    move(settings.currX,settings.currY);
    resize(settings.currSize,settings.currSize);
}


void Dyno::paintEvent(QPaintEvent *event)
{
    Q_UNUSED (event);

    //   qDebug() << "Dyno::paintEvent";
    QPainter painter(this);
    QPen pen;
    pen.setWidth(4);    //draw pipe
    pen.setColor(Qt::red);
    painter.setBrush(Qt::red);
    painter.setPen(pen);

    QPoint points[4];

    points[0] = QPoint(0 + settings.currX,0 + settings.currY);
    points[1] = QPoint(settings.currSize + settings.currX,0 + settings.currY);
    points[2] = QPoint(settings.currSize + settings.currX,settings.currSize + settings.currY);
    points[3] = QPoint(0 + settings.currX,settings.currSize + settings.currY);

    //points[0] = QPoint(100,100);
    //points[1] = QPoint(100,100);
    // points[2] = QPoint(100,100);
    // points[3] = QPoint(100,100);

    painter.drawPolygon(points,4);

    imgBackground= new QImage();
    imgBackground->load(":/pictures/dino_mili.png"); // nepatīk krāsas png failam ???????????????????????????????

    *imgBackground = imgBackground->scaled(settings.currSize, settings.currSize, Qt::KeepAspectRatio);
    painter.drawImage(QPoint(), *imgBackground);

    resize(settings.currSize,settings.currSize);
    move(settings.startX,settings.startY);

}


void Dyno::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton) {
        // qDebug() << "dyno mousePressEvent" ;
        // updateSettings();
    }
}
void Dyno::mouseMoveEvent(QMouseEvent *event)
{
    event->accept();

    // get the cursor position of this event
    const QPoint& pos = event->pos();

    int pointX = pos.x();
    int pointY = pos.y();

    settings.startX += pointX;
    settings.startY += pointY;
    //?   updateSettings();
   // emit updateServiceUI();
//qDebug() << "Pump mouseMoveEvent dx:dy" << pointX - mouseStartPointX << pointY - mouseStartPointY ;
}

void Dyno::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        qDebug() << "Pipe mouseDoubleClickEvent" ;
        // emit openServicePump();
        //emit openServicePipe();

        WidgetService *serviceForm = new WidgetService();
        serviceForm->show();

    }

}
