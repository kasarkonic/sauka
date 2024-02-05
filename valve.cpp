#include "valve.h"
//#include<QMouseEvent>
//#include <QSettings>

//#include <QPainter>



Valve::Valve(Global &global, QString name, QWidget *parent)
    : WidgetDiagramElement(global,name,parent)

{
    /*
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
 */
    settings.startX = global.widHash[settings.name].startX;
    settings.startY = global.widHash[settings.name].startY;
    settings.startSize = global.widHash[settings.name].startSize;
    settings.options = global.widHash[settings.name].options;
    //  timerId = startTimer(100, Qt::CoarseTimer);
}

void Valve::updateSettings()
{
    qDebug() << "Valve updateSettings" << settings.options;
    WidgetDiagramElement::updateSettings();

    int dSensAdr1 = global.widHash[widName].sensAddres1;
    int dSensAdr2 = global.widHash[widName].sensAddres2;

   // options Angle fron vertical CCW  options
   // startSizeWi  not used
   // sensAdr1.digital     end switch open
   // sensAdr2.digital     end switch close

    // default   close angle
    settings.options = global.widHash[settings.name].options;
    int opSW = global.sensList[dSensAdr1].digital;       // open SW
    int clSW = global.sensList[dSensAdr2].digital;       // close sw

    if(clSW == 1 && opSW == 0){  //close
       settings.options = global.widHash[settings.name].options;
       settings.status = 0 ;    // closw
       settings.options = global.widHash[settings.name].options;
    }
    if(clSW == 0 && opSW == 1){  //open
       settings.options = global.widHash[settings.name].options;
       settings.status = 1 ;    // open
       settings.options = global.widHash[settings.name].options + 90;
    }
    if(clSW == 0 && opSW == 0){  //process
       settings.options = global.widHash[settings.name].options;
       settings.status = 2 ;    // process
       settings.options = global.widHash[settings.name].options + 45;
    }

    if(clSW == 1 && opSW == 1){  //error
       settings.options = global.widHash[settings.name].options;
       settings.status = 2 ;    // error
       settings.options = global.widHash[settings.name].options + 45;
    }

    update();
}

void Valve::calcPoints(int angle)
{
    float an = M_PI/180 * (35 + angle);
    float an1 = M_PI/180 * (180 -35 + angle);
    float size = settings.currSize;

    points[0] = QPoint(size/2 + size/2 * cos(an),size/2 - size/2 * sin(an));//0
    points[1] = QPoint(size/2 - size/2 * cos(an),size/2 + size/2 * sin(an));//3
    points[2] = QPoint(size/2 + size/2 * cos(an1),size/2 - size/2 * sin(an1));//1
    points[3] = QPoint(size/2 - size/2 * cos(an1),size/2 + size/2 * sin(an1));//2
}

void Valve::updateWidget()
{
    move(settings.currX,settings.currY);
    resize(settings.currSize,settings.currSize);
}
/*
void Valve::setNewPosition(float koef)
{
    settings.currX = int(settings.startX /koef);
    settings.currY = int(settings.startY / koef);
    settings.currSize = int (settings.startSize/koef);
    qDebug() << "Valve::setNewPosition" << koef;

    move(settings.currX,settings.currY);
    resize(settings.currSize,settings.currSize);
}

*/
void Valve::paintEvent(QPaintEvent *event)
{
    Q_UNUSED (event);

    //qDebug() << "Valve::paintEvent";
    // qDebug() << "Valve paintEvent"<<settings.name <<settings.currX << settings.currY << settings.currSize<<"\n" ;

    calcPoints(settings.options);

    QPainter painter(this);
    QPen pen;
    pen.setWidth(1);
    pen.setColor(Qt::black);

    QColor  color = Qt::yellow;

    if(settings.status == 0){
        color = Qt::red;
    }
    if(settings.status == 1){
        color = Qt::green;
    }
    if(settings.status == 2){
        color = Qt::yellow;
    }

    painter.setBrush(color);
    painter.setPen(pen);
    painter.drawPolygon(points,4,Qt::WindingFill);

    //  resize(settings.currSize,settings.currSize);
    //  move(settings.currX,settings.currY);
}


void Valve::timerEvent(QTimerEvent *event){
    Q_UNUSED (event);
    settings.options -= 5;
    att +=1;
    // qDebug()<< "att" << att << settings.status;
    if (att > 100)
    {
        att = 0;
        settings.status +=1;
        if(settings.status > 2){
            settings.status = 0;
        }
    }

    update();
}
