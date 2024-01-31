#include "pump.h"

//#include <QPainter>
//#include<QMouseEvent>
//#include <QSettings>


Pump::Pump(Global &global,QString name, QWidget *parent)
    : WidgetDiagramElement(global, name,parent)
{
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::lightGray); //QColor(255, 0, 0, 127)
    pal.setColor(QPalette::Window, QColor(0, 0, 0, 20));
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    settings.startX = global.widData[settings.name].startX;
    settings.startY = global.widData[settings.name].startY;
    settings.startSize = global.widData[settings.name].startSize;

}
/*
void Pump::setNewPosition(float koef)
{
    settings.currX = int(settings.startX /koef);
    settings.currY = int(settings.startY / koef);
    settings.currSize = int (settings.startSize/koef);

    move(settings.currX,settings.currY);
    resize(settings.currSize,settings.currSize);
}
*/
/*
void Pump::updateSettings()
{

    qDebug() << "Pump updateSettings" << settings.options;
    settings.startX = global.widData[settings.name].startX;
    settings.startY = global.widData[settings.name].startY;
    settings.startSize = global.widData[settings.name].startSize;

    move(settings.currX,settings.currY);
    resize(settings.currSize,settings.currSize);

    if(settings.value == 0){        // 0 stop, 1 ->, 2<-)
        killTimer(timerId);
    }
    else{
        timerId = startTimer(150, Qt::CoarseTimer);
    }

}
*/
/*
void Pump::loadSettings()
{
    QString settingsFile = Global::settingsFileName;
    QSettings sett(settingsFile, QSettings::IniFormat);

    QString sText = settings.name;
    sett.beginGroup(sText);

    settings.name = sett.value("name","Pump").toString();
    settings.note = sett.value("note").toString();
    settings.startX = sett.value("startX","100").toInt();
    settings.startY = sett.value("startY","100").toInt();
    settings.startSize = sett.value("radiusStart","100").toInt();
    settings.speed = sett.value("speed","0").toInt();
    settings.rotate = sett.value("rotate","0").toInt();

    sett.endGroup();

    qDebug() << "Pump updateSettings() load settings in group "<< sText  << settingsFile << settings.startX << settings.startY;
    //    setNewPosition(1);
    //? updateSettings();
}

void Pump::saveSettings()
{
    QString settingsFile = global.settingsFileNameGlobal::settingsFileName;
    QSettings sett(settingsFile, QSettings::IniFormat);

    QString sText = settings.name;
    sett.beginGroup(sText);

    sett.setValue("name", settings.name);
    sett.setValue("note", settings.note);
    sett.setValue("startX", settings.startX);
    sett.setValue("startY", settings.startY);
    sett.setValue("radiusStart", settings.startSize);
    sett.setValue("speed", settings.speed);
    sett.setValue("rotate", settings.rotate);   // on off

    sett.endGroup();
    qDebug() << "Valve, save settings in group " << sText;
}
*/
void Pump::paintEvent(QPaintEvent *event)
{

    Q_UNUSED (event);
    qDebug() << "Pump::paintEvent" << settings.currX << settings.currY << settings.currSize;
    QPainter painter(this);
    QPen pen;
    pen.setWidth(4);    //draw pipe
    pen.setColor(Qt::green);
    //painter.setBrush(settings.triangColor);// (pipeColour);
    painter.setPen(pen);

    int rad = settings.currSize - 4;// minus pen
    painter.drawEllipse(2, 2, rad, rad);

    rad = (int)settings.currSize/2 ;

    float an = att * M_PI /180;
    QPoint points[3];
    points[0] = QPoint(rad * cos(an) + rad, rad * sin(an) + rad);
    points[1] = QPoint(rad * cos(an + 2*M_PI/3) + rad, rad * sin(an + 2*M_PI/3) + rad);
    points[2] = QPoint(rad * cos(an + 4*M_PI/3) + rad, rad * sin(an + 4*M_PI/3) + rad);

    pen.setWidth(2);
    pen.setColor(Qt::blue);
    painter.setBrush(triangColor);
    painter.setPen(pen);
    painter.drawPolygon(points,3);

  //  resize(settings.currSize,settings.currSize);
  //  move(settings.currX,settings.currY);
}

void Pump::timerEvent(QTimerEvent *event)
{
    Q_UNUSED (event);

    // qDebug() << "Pump timerEvent" <<settings.rotate << att;

    if(settings.value > 0){
        int step = settings.value/10; //360/72;
        att += step;
        if (att > 360)
            att = 0;
    }

    // qDebug() << "Pump::att " << att ;
    //update();
}
/*
void Pump::mouseMoveEvent(QMouseEvent *event)
{
    event->accept();

    // get the cursor position of this event
    const QPoint& pos = event->pos();

    int pointX = pos.x();
    int pointY = pos.y();

    settings.startX += pointX;
    settings.startY += pointY;
    //?   updateSettings();
    emit updateServiceUI();
    qDebug() << "Pump mouseMoveEvent dx:dy" << pointX - mouseStartPointX << pointY - mouseStartPointY ;


}

void Pump::mousePressEvent(QMouseEvent *event)
{
    const QPoint& pos = event->pos();
    mouseStartPointX = pos.x();
    mouseStartPointY = pos.y();
    qDebug() << " Pump mousePressEvent dx:dy" <<pos.x() << pos.y();
}

void Pump::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        qDebug() << "Pump mouseDoubleClickEvent" ;
        //emit openServicePump();
      //  WidgetService *serviceForm = new WidgetService();
      //  serviceForm->show();
    }
}

*/
