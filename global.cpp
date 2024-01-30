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
    widData.insert(na, data);
}


void Global::creatActList()
{
    addActList("pump 1",ActuatorType::Relay,123);
    addActList("Mix invertor 1",ActuatorType::Invertor,124);
}

void Global::creatSensList()
{
    addSensList("1. sensors", SensorType::Digital, 1);
}

void Global::creatWidgList()
{
    // type                      name         startX      startY  startSize  startSizeWi  options

    addWidgList(WidgetType::Mix,        "Mix",    100,        100,    50, 0,  0);
    addWidgList(WidgetType::Dyno,       "Dyno",   200,         200,   51, 0,  0);
    addWidgList(WidgetType::Tvertne,     "Tvertne 1",  300,     300,   50, 0,  0);
    addWidgList(WidgetType::Pump,       "Pump 1",  100,        300,    50, 0,  0);

    addWidgList(WidgetType::Valve,      "Valve 1",  300,       100,   50, 0,  0);
    addWidgList(WidgetType::Pipe,       "Pipe 1",  35,         50,   100,  10,  30);
    addWidgList(WidgetType::Pipe,     "Pipe 2",    30,        250,    0,  20,  30 - 90);
    addWidgList(WidgetType::Pipe,    "Pipe 3",    30,        470,    0,  20,  0);
}

