#include "global.h"
#include <Qdebug>


//using namespace inputWidg;
//using namespace inputAct;
//using namespace inputSens;

Global::Global()
{
    appSwVers = "0.1 01.02";
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

void Global::addWidgList(WidgetType::widgT ty, QString na,int X, int Y, int size, int sizeW, int options, int page)
{
    wdataStruct data;
    data.type = ty;
    data.name = na;
    data.startX = X;
    data.startY = Y;
    data.startSize = size;
    data.startSizeWi = sizeW;
    data.options = options;
    data.page = page;
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
startSizeWi  not used



page = 0   draw on "Mix" page
page = 1   draw on "Dyno" page
page = 3   draw on all pages

    */
void Global::creatWidgList()
{
    // type                      name         startX      startY  startSize  startSizeWi  options      page
    addWidgList(WidgetType::Mix,        "Mix",    415,        443,    100, 0,  0,0);

    addWidgList(WidgetType::Dyno,       "Dyno1",   751,         50,   70, 0,  0,3);

    addWidgList(WidgetType::Tvertne,     "Tvertne 1",  225,     50,   50, 0,  0,0);
    addWidgList(WidgetType::Tvertne,     "Tvertne 2",  375,     50,   50, 0,  0,0);
    addWidgList(WidgetType::Tvertne,     "Tvertne 3",  525,     50,   50, 0,  0,0);
    addWidgList(WidgetType::Tvertne,     "Tvertne 4",  650,     50,   50, 0,  0,0);

    addWidgList(WidgetType::Pump,       "Pump1",  255,        255,    35, 0,  0,0);
    addWidgList(WidgetType::Pump,       "Pump2",  378,        255,    35, 0,  0,0);
    addWidgList(WidgetType::Pump,       "Pump3",  526,        255,    35, 0,  0,0);
    addWidgList(WidgetType::Pump,       "Pump4",  652,        255,    35, 0,  0,0);

    addWidgList(WidgetType::Valve,      "Valve 1",  231,       165,   25, 0,  45,0);
    addWidgList(WidgetType::Valve,      "Valve 2",  386,      165,   25,  10,  45,0);
    addWidgList(WidgetType::Valve,      "Valve 3",  534,       165,   25, 0,  45,0);
    addWidgList(WidgetType::Valve,      "Valve 4",  658,      165,   25,  10,  45,0);

    addWidgList(WidgetType::Pipe,     "Pipe 1",   240,        105,    60,  10,  0,0);
    addWidgList(WidgetType::Pipe,    "Pipe 2",    392,        105,    60,  10,  0,0);
    addWidgList(WidgetType::Pipe,     "Pipe 3",   540,        105,    60,  10,  0,0);
    addWidgList(WidgetType::Pipe,    "Pipe 4",    665,        105,    60,  10,  0,0);

    addWidgList(WidgetType::Pipe,     "Pipe 5",    240,        190,    60,  10,  0,0);
    addWidgList(WidgetType::Pipe,    "Pipe 6",    392,        190,    60,  10,  0,0);
    addWidgList(WidgetType::Pipe,     "Pipe 7",    540,        190,    60,  10,  0,0);
    addWidgList(WidgetType::Pipe,    "Pipe 8",    665,        190,    60,  10,  0,0);

    addWidgList(WidgetType::Pipe,     "Pipe 9",    269,        297,    176,  10,  40,0);
    addWidgList(WidgetType::Pipe,    "Pipe 10",    391,        298,    137,  10,  21,0);
    addWidgList(WidgetType::Pipe,     "Pipe 11",    492,        295,    133,  10,  160,0);
    addWidgList(WidgetType::Pipe,    "Pipe 12",    526,        295,    189,  10,  135,0);

    qDebug() << "create " << widHash.size() << "widgets";
}

