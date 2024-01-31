#include "global.h"
#include <Qdebug>


//using namespace inputWidg;
//using namespace inputAct;
//using namespace inputSens;

Global::Global()
{
    appSwVers = "0.1";
    zoomKoef = 1.0;
    UIXsize = 1000;
    UIYsize = 1000;
    UIXresizeSize = 1000;
    UIYresizeSize = 1000;

    creatWidgList();
    creatActList();
    creatSensList();
}


void Global::addActList(QString name, ActuatorType::actT tp, int addres)
{

    act data;

    data.type = tp;  //
    data.adress = addres;
    // data.analog = 0; VALUE
    // data.digital = 0; VALUE

    actHash.insert(name,data);

    qDebug()  << "!!! test actuator name ";
}

void Global::addSensList(QString name, SensorType::sensT tp, int addres)
{
    sens data;

    data.type = tp;  //
    data.adress = addres;
    // data.analog = 0; VALUE
    // data.digital = 0; VALUE

    sensHash.insert(name,data);

    qDebug()  << "!!! test sensor name ";

}

void Global::addWidgList(WidgetType::widgT ty, QString na,int X, int Y, int size, int sizeW, int options)
{
    wdataStruct data;
    data.type = ty;
    data.name = na;
    data.startX = X;
    data.startY = Y;
    data.startSize = size;
    data.startSizeWi = sizeW;
    data.options = options;
    widHash.insert(na, data);
}


void Global::creatActList()
{
    addActList("pump 1",ActuatorType::Relay,123);
    addActList("Mix invertor 1",ActuatorType::Invertor,124);
    qDebug() << "create " << actHash.size() << "actuators";
}

void Global::creatSensList()
{
    addSensList("1. sensors", SensorType::Digital, 1);
    qDebug() << "create " << sensHash.size() << "sensors";
}




/*

Left upper corner coordinates:
startX
startY

Widget size
startSize


for  Pipe :
Hight startSize
Width  startSizeWi
Angle > 0 fron vertical CCW  options

for  Valve :
options Angle fron vertical CCW  options

    */
void Global::creatWidgList()
{
    // type                      name         startX      startY  startSize  startSizeWi  options
    addWidgList(WidgetType::Mix,        "Mix",    600,        600,    50, 0,  0);

    addWidgList(WidgetType::Dyno,       "Dyno1",   202,         203,   51, 0,  0);

    addWidgList(WidgetType::Tvertne,     "Tvertne 1",  225,     50,   50, 0,  0);
    addWidgList(WidgetType::Tvertne,     "Tvertne 2",  375,     50,   50, 0,  0);
    addWidgList(WidgetType::Tvertne,     "Tvertne 3",  525,     50,   50, 0,  0);
    addWidgList(WidgetType::Tvertne,     "Tvertne 4",  650,     50,   50, 0,  0);

    addWidgList(WidgetType::Pump,       "Pump1",  100,        300,    50, 0,  0);
    addWidgList(WidgetType::Pump,       "Pump2",  100,        300,    50, 0,  0);
    addWidgList(WidgetType::Pump,       "Pump3",  100,        300,    50, 0,  0);
    addWidgList(WidgetType::Pump,       "Pump4",  100,        300,    50, 0,  0);

    addWidgList(WidgetType::Valve,      "Valve 1",  135,       150,   50, 0,  0);
    addWidgList(WidgetType::Valve,      "Valve 2",  350,      50,   50,  10,  30);
    addWidgList(WidgetType::Valve,      "Valve 3",  300,       100,   50, 0,  0);
    addWidgList(WidgetType::Valve,      "Valve 4",  350,      350,   50,  10,  30);

    addWidgList(WidgetType::Pipe,     "Pipe 1",   154,        64,    100,  10,  0);
    addWidgList(WidgetType::Pipe,    "Pipe 2",    154,        186,    100,  10,  0);
    addWidgList(WidgetType::Pipe,     "Pipe 3",    30,        250,    100,  10,  0);
    addWidgList(WidgetType::Pipe,    "Pipe 4",    330,        470,    100,  10,  0);
    addWidgList(WidgetType::Pipe,     "Pipe 5",    30,        250,    100,  10,  0);
    addWidgList(WidgetType::Pipe,    "Pipe 6",    330,        470,    100,  10,  0);

    qDebug() << "create " << widHash.size() << "widgets";
}

