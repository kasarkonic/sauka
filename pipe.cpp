#include "pipe.h"

//#include <QPainter>
//#include <QtMath>
//#include<QMouseEvent>
//#include <QSettings>

Pipe::Pipe(Global &global,QString name, QWidget *parent)
    : WidgetDiagramElement(global,name, parent)

{
    /*
    qDebug() << "Pipe::Pipe";
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::lightGray);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
*/
    settings.startX = global.widHash[settings.name].startX;
    settings.startY = global.widHash[settings.name].startY;
    settings.startSize = global.widHash[settings.name].startSize;
    settings.startSizeWi = global.widHash[settings.name].startSizeWi;
    settings.options = global.widHash[settings.name].options;
    angle = settings.options;
    settings.currSize = settings.startSize;        //Hi
    settings.currSizeWi = settings.startSizeWi;

}

void Pipe::get(int *pnt)
{
    int po = 123;
    *pnt = po;
}


void Pipe::setNewPosition(float koef)
{
    WidgetDiagramElement::setNewPosition(koef); // call base class
    settings.currSize = int(settings.startSize /koef);        //Hi
    settings.currSizeWi = int(settings.startSizeWi /koef);
    //   qDebug() << "Pipe::setNewPosition";
}

void Pipe::updateSettings()
{
    qDebug() << "Pipe updateSettings" << settings.options;
    WidgetDiagramElement::updateSettings();
    update();


    // settings.wi = settings.starwi;
    // settings.hi = settings.starhi;

    //settings.currX = settings.startX;
    //settings.currY = settings.startY;

    // move(settings.startX,settings.startY);

    // if(settings.flow == 0){        // 0 stop, 1 ->, 2<-)
    //     killTimer(timerId);
    // }
    // else{
    //      timerId = startTimer(200, Qt::CoarseTimer);
    // }
}


/*
void Pipe::loadSettings()
{
    QString settingsFile = Global::settingsFileName;
    QSettings sett(settingsFile, QSettings::IniFormat);

    QString sText = settings.name;
    sett.beginGroup(sText);

    settings.name = sett.value("name","Pipe").toString();
    settings.note = sett.value("note").toString();
    settings.startX = sett.value("startX","100").toInt();
    settings.startY = sett.value("startY","100").toInt();
    settings.starwi = sett.value("starwi","10").toInt();
    settings.starhi = sett.value("starhi","100").toInt();

    sett.endGroup();

    qDebug() << "Pump updateSettings() load settings in group "<< sText  << settingsFile << settings.startX << settings.startY;
    //    setNewPosition(1);
    //? updateSettings();
}

void Pipe::saveSettings()
{
    QString settingsFile = global.settingsFileName;
    QSettings sett(settingsFile, QSettings::IniFormat);

    QString sText = settings.name;
    sett.beginGroup(sText);

    sett.setValue("name", settings.name);
    sett.setValue("note", settings.note);
    sett.setValue("startX", settings.startX);
    sett.setValue("startY", settings.startY);

    sett.setValue("starwi", settings.starwi);
    sett.setValue("starhi", settings.starhi);

    sett.endGroup();
    qDebug() << "Pipe, save settings in group " << sText;
}
*/





void Pipe::paintEvent(QPaintEvent *event)
{
    Q_UNUSED (event);
    //qDebug() << "Pipe::paintEvent" << settings.currX << settings.currY;
    QPainter painter(this);
    QPen pen;
    pen.setWidth(2);    //draw pipe
    pen.setColor(Qt::black);
    painter.setBrush(pipeColor);// (pipeColour);
    painter.setPen(pen);

    pen.setWidth(2);    //draw pipe
    pen.setColor(Qt::red);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(pen);

    // arrow points

    int stX ;
    int stY ;

    int hi = settings.currSize;        //Hi
    int wi = settings.currSizeWi;



    settings.options %=360;
    float an = settings.options * M_PI /180;




    // int diog = sqrt(wi*wi + hi*hi);
    // float diogAngle = atan((double)wi/hi);


    if (settings.options >= 0 && settings.options <= 90){
        stY = wi * sin(an);
        stX = 0;
        // resize(wi * cos(an) + hi * sin(an),hi * cos(an)  + wi * sin(an));
    }
    if (settings.options > 90  && settings.options <= 180){
        stX  = wi * sin(an-M_PI/2);
        stY = hi * cos(M_PI - an) + wi * cos(an - M_PI/2);
        // resize(wi * sin(an-M_PI/2) + hi * cos(an-M_PI/2),stY);
    }
    if (settings.options > 180 && settings.options <= 270){
        stX  = hi * sin(an-M_PI) + wi * cos(an-M_PI) ;
        stY = settings.startY = hi * cos(an - M_PI)  ;
        // resize(stX ,hi * cos(an - M_PI) + wi * sin(an-M_PI));
    }
    if (settings.options > 270 && settings.options <= 360){
        stX  = hi * cos( an - 3*M_PI/2) ;
        stY = 0;
        // resize(stX +  wi * sin( an - 3*M_PI/2) , diog * cos( 2* M_PI - (an + diogAngle) ));
    }

    pipePoints[0].setX(stX);        //left upper corner
    pipePoints[0].setY(stY);

    pipePoints[1].setX(stX + wi * cos(an)); // right upper corner
    pipePoints[1].setY(stY - wi * sin(an));

    pipePoints[2].setX(stX  + hi * sin(an) + wi * cos(an));
    pipePoints[2].setY(stY + hi * cos(an)- wi * sin(an)) ;

    pipePoints[3].setX(stX  + hi * sin(an) );
    pipePoints[3].setY(stY  + hi * cos(an));

    painter.drawPolygon(pipePoints,4);


    //pipe virtual middle line

    pipemiddle[0].setX(stX + wi * cos(an)/2);
    pipemiddle[0].setY(stY - wi * sin(an)/2);

    pipemiddle[1].setX(stX + hi * sin(an) + wi * cos(an)/2 );
    pipemiddle[1].setY(stY + hi * cos(an) - wi * sin(an)/2 );

    pen.setWidth(1);    //draw pipe
    pen.setColor(Qt::black);
    painter.setPen(pen);
    painter.drawLines(pipemiddle,1);

    if(settings.value != 0)
    {
        //draw arrow

        pipemiddle[0].setX(stX + wi * cos(an)/2);
        pipemiddle[0].setY(stY - wi * sin(an)/2);


        arrowPoints[0].setX(pipePoints[0].x() + att * sin(an)  );
        arrowPoints[0].setY(pipePoints[0].y() + att * cos(an)  );

        arrowPoints[1].setX(pipemiddle[0].x() + (att + arrTop) * sin(an)  );
        arrowPoints[1].setY(pipemiddle[0].y() + (att + arrTop) * cos(an)  );

        arrowPoints[2] = arrowPoints[1];
        arrowPoints[2] = arrowPoints[1];

        arrowPoints[3].setX(pipePoints[1].x() + att * sin(an)  );
        arrowPoints[3].setY(pipePoints[1].y() + att * cos(an)  );


        pen.setWidth(6);    //draw arrow
        pen.setColor(Qt::green);
        pen.setCapStyle(Qt::RoundCap);  //Qt::FlatCap   Qt::RoundCap
        painter.setPen(pen);
        painter.drawLines(arrowPoints,2);
    }


    //painter.drawText(10,10,"hello");

    //    resize(settings.currSize,settings.currSize);
    //    move(settings.currX,settings.currY);
    //painter.drawText(10,10,"hello");

}
void Pipe::timerEvent(QTimerEvent *event){

    Q_UNUSED (event);
    int step = 3;
    //qDebug() << "timerEvent" << att;

    att = att + step;
    //  if (att > currHi - arrTop)
    //      att = 0;

    qDebug() << "Pipe::att "<< att ;
}
/*
void Pipe::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton) {
         qDebug() << "mousePressEvent" ;
    }
}

void Pipe::mouseMoveEvent(QMouseEvent *event)
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

void Pipe::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        qDebug() << "Pipe mouseDoubleClickEvent" ;
       // emit openServicePump();
        //emit openServicePipe();

    //    WidgetService *serviceForm = new WidgetService();
     //   serviceForm->show();

    }

}
*/
