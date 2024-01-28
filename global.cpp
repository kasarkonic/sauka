#include "global.h"
#include <Qdebug>


Global::Global()
{
    appSwVers = "0.1";
    zoomKoef = 1.0;
    creatActList();

    //timer = new QTimer();
    //connect(timer, SIGNAL(timeout()),
    //      this, SLOT(MyTimerSlot()));

    //timer.start(100);
}

void Global::creatActName()
{    actName.append("Mix invertor"); //0
     actName.append("Dino invertor"); //1
     actName.append("Pump Tvertne2"); //2
     actName.append("Pump Tvertne3");//3
     actName.append("Pump Tvertne4");//4
}

void Global::creatActList()
{
addActList(ActuatorType::Invertor,0,1,0,0 );
addActList(ActuatorType::Invertor,1,1,0,0 );

}

void Global::addActList(ActuatorType::actT tp, int nr, int addres, int an, int di)
{
    act data;
    data.actNr = nr;
    data.adress = addres;
    data.analog = an;
    data.digital = di;
    if (nr < actList.size())
    data.name = actName[addres ];
    else{
        qDebug()  << "!!! Error unreal actuator addres > actList size";
    }
    data.type = tp;
}

void Global::MyTimerSlot()
{
    qDebug()  << "Global::MyTimerSlot()";
}

void Global::timerEvent(QTimerEvent *event)
{
qDebug()  << "Global::timerEvent()";
}

