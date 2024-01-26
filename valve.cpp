#include "valve.h"
#include<QMouseEvent>
#include <QSettings>
#include "widgetservice.h"




Valve::Valve(QWidget *parent)
    : WidgetDiagramElement(parent)
  , myTriangle1(this)
  , myTriangle2(this)
  , myTriangle3(this)
  , myTriangle4(this)
{

    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    settings.currX = settings.startX;
    settings.currY = settings.startY;
    settings.currSize = settings.startSize;
    qDebug() << "Valve::Valve" << settings.currX << settings.currY << settings.currSize;

   // drawTriangle();

   // move(settings.currX,settings.currY);
   // resize(settings.currSize,settings.currSize);

    timerId = startTimer(2000, Qt::CoarseTimer);

}


void Valve::setMySize(int val)
{
    mySize = val;
}

void Valve::setMyStyle()
{
    switch (settings.style) {
    case 0:
        myTriangle1.show();
        myTriangle2.hide();
        myTriangle3.show();
        myTriangle4.hide();
        break;
    case 90:
        myTriangle1.hide();
        myTriangle2.show();
        myTriangle3.hide();
        myTriangle4.show();

        break;
    case 180:
        myTriangle1.show();
        myTriangle2.hide();
        myTriangle3.show();
        myTriangle4.show();

        break;
    case 270:
        myTriangle1.show();
        myTriangle2.show();
        myTriangle3.hide();
        myTriangle4.show();

        break;
    default:
        myTriangle1.show();
        myTriangle2.show();
        myTriangle3.show();
        myTriangle4.show();
        break;
    }
}

void Valve::updateStatus()
{
    //qDebug() << "Valve::updateStatus()" << settings.status ;
    switch (settings.status) {
    case ValveStatus::Close:
        myTriangle1.setColour(Qt::red); // A
        myTriangle2.setColour(Qt::red); // B
        myTriangle3.setColour(Qt::red); // C
        myTriangle4.setColour(Qt::red); // _B
        break;
    case ValveStatus::OpenBA:
        myTriangle1.setColour(Qt::green);
        myTriangle2.setColour(Qt::green);
        myTriangle3.setColour(Qt::red);
        myTriangle4.setColour(Qt::red);
        break;
    case ValveStatus::OpenBC:
        myTriangle1.setColour(Qt::red);
        myTriangle2.setColour(Qt::green);
        myTriangle3.setColour(Qt::green);
        myTriangle4.setColour(Qt::red);
        break;
    case ValveStatus::OpenAC:
        myTriangle1.setColour(Qt::green);
        myTriangle2.setColour(Qt::red);
        myTriangle3.setColour(Qt::green);
        myTriangle4.setColour(Qt::red);
        break;
    case ValveStatus::OPENABC:
        myTriangle1.setColour(Qt::green);
        myTriangle2.setColour(Qt::green);
        myTriangle3.setColour(Qt::green);
        myTriangle4.setColour(Qt::red);
        break;

    case ValveStatus::Open_BA:
        myTriangle1.setColour(Qt::green);
        myTriangle2.setColour(Qt::red);
        myTriangle3.setColour(Qt::red);
        myTriangle4.setColour(Qt::green);
        break;
    case ValveStatus::Open_BC:
        myTriangle1.setColour(Qt::red);
        myTriangle2.setColour(Qt::red);
        myTriangle3.setColour(Qt::green);
        myTriangle4.setColour(Qt::green);
        break;
    case ValveStatus::Open_BB:
        myTriangle1.setColour(Qt::red);
        myTriangle2.setColour(Qt::green);
        myTriangle3.setColour(Qt::red);
        myTriangle4.setColour(Qt::green);
        break;
    case ValveStatus::OpenABC_B:
        myTriangle1.setColour(Qt::green);
        myTriangle2.setColour(Qt::green);
        myTriangle3.setColour(Qt::green);
        myTriangle4.setColour(Qt::green);
        break;

    case ValveStatus::Unknown:
        myTriangle1.setColour(Qt::yellow);
        myTriangle2.setColour(Qt::yellow);
        myTriangle3.setColour(Qt::yellow);
        myTriangle4.setColour(Qt::yellow);
        break;
    default:
        myTriangle1.setColour(Qt::yellow);
        myTriangle2.setColour(Qt::yellow);
        myTriangle3.setColour(Qt::yellow);
        myTriangle4.setColour(Qt::yellow);
        break;
    }

 //   updateWidget();
}
/*
void Valve::loadSettings()
{
    QString settingsFile = Global::settingsFileName;
    QSettings sett(settingsFile, QSettings::IniFormat);

    QString sText = settings.name;
    sett.beginGroup(sText);

    settings.startX = sett.value("startX","100").toInt();
    settings.startY = sett.value("startY","100").toInt();;
    settings.startsize = sett.value("startsize","100").toInt();;
    settings.triangStartSize = sett.value("triangStartSize","100").toInt();;
    settings.status = sett.value("status","0").toInt();;
    settings.style = sett.value("style","0").toInt();;

    sett.endGroup();

    qDebug() << "Valve,  load settings in group "<< sText  << settingsFile << settings.startX << settings.startY;
    //    setNewPosition(1);
    updateSettings();
}

void Valve::saveSettings()
{
    QString settingsFile = global.settingsFileName;;
    QSettings sett(settingsFile, QSettings::IniFormat);

    QString sText = settings.name;
    sett.beginGroup(sText);

    sett.setValue("startX", settings.startX);
    sett.setValue("startY", settings.startY);
    sett.setValue("startsize", settings.startsize);
    sett.setValue("triangStartSize",settings.triangStartSize);
    sett.setValue("status", settings.status);
    sett.setValue("style", settings.style);
    sett.endGroup();

    qDebug() << "Valve, save settings in group " << sText;

}
*/
void Valve::updateWidget()
{
    //?    drawTriangle();
    //?     myTriangle1.update();
    //?     myTriangle2.update();
    //?     myTriangle3.update();
    //?     myTriangle4.update();
}



void Valve::setNewPosition(float koef)
{
    settings.currX = int(settings.startX /koef);
    settings.currY = int(settings.startY / koef);
    settings.currSize = int (settings.startSize/koef);
    qDebug() << "Valve::setNewPosition" << koef;
   // move(settings.currX,settings.currY);
    //resize(settings.currSize,settings.currSize);
    drawTriangle();

    move(settings.currX,settings.currY);
    resize(settings.currSize,settings.currSize);

}

void Valve::updateSettings()
{
    qDebug() << "Valve updateSettings";
    settings.currX = settings.startX;
    settings.currY = settings.startY;
    settings.currSize = settings.currSize;

   // drawTriangle();
    move(settings.currX,settings.currY);
    resize(settings.currSize, settings.currSize );

   // killTimer(timerId);

    if(settings.status == 0){        // 0 stop, 1 ->, 2<-)
        killTimer(timerId);
    }
    else{
        //timerId = startTimer(2000, Qt::CoarseTimer);
    }
    //settings.status = ValveStatus::OpenAC;

   // drawTriangle();
   // setMyStyle();
   //  //update();
}

void Valve::drawTriangle()
{
    qDebug() << "3ang::drawTriangle()" << settings.currX << settings.currY << settings.currSize;

    int mySize = settings.currSize;
    qDebug() << "Valve    triangSize" << mySize;
    myTriangle1.setGeometry(0,0,mySize,mySize); // triangle A
    myTriangle1.setSize(mySize,90);   // size and orientation
    //myTriangle1.update();

    myTriangle2.setGeometry(0,0,mySize,mySize); // triangle B
    myTriangle2.setSize(mySize,180);   // size and orientation
   // myTriangle2.update();

    myTriangle3.setGeometry(0,0,mySize,mySize); // triangle C
    myTriangle3.setSize(mySize,270);   // size and orientation
   // myTriangle3.update();

    myTriangle4.setGeometry(0,0,mySize,mySize); // triangle B inverse
    myTriangle4.setSize(mySize,0);   // size and orientation
   // myTriangle4.update();

  //  resize(settings.currSize,settings.currSize);  //Strādā
  //  move(settings.currX,settings.currY);  //Strādā, bet ciklā
}

void Valve::timerEvent(QTimerEvent *event){

    Q_UNUSED (event);
    qDebug() << "timerEvent(QTimerEvent " << att;
    att +=1;
    if (att%2){
        settings.status = ValveStatus::OpenAC;
    }
    else{
        settings.status = ValveStatus::Close;
    }



    killTimer(timerId);
    update();



    //qDebug() << "Valve::timerEvent " << att;
    // updateSettings();
    // update();
    //setMyStyle();

   // drawTriangle();

   // update();
  //  updateStatus();
  //  resize(settings.currSize,settings.currSize);
  //  move(settings.currX,settings.currY);

}


void Valve::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton) {
        //qDebug() << "Valve::mousePressEvent" ;
        emit openServiceValve();
    }
}

void Valve::mouseMoveEvent(QMouseEvent *event)
{
    event->accept();

    // get the cursor position of this event
    const QPoint& pos = event->pos();

    int pointX = pos.x();
    int pointY = pos.y();

    settings.startX += pointX;
    settings.startY += pointY;
    //?   updateSettings();
    //emit updateServiceUI();
//qDebug() << "Pump mouseMoveEvent dx:dy" << pointX - mouseStartPointX << pointY - mouseStartPointY ;
}

void Valve::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        qDebug() << "Pipe mouseDoubleClickEvent" ;
        // emit openServicePump();
        //emit openServicePipe();

        WidgetService *serviceForm = new WidgetService();
        serviceForm->show();

    }

}
