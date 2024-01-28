#include "widgetdata.h"
#include "global.h"


WidgetData::WidgetData(Global &global):
    global(global)
{
    initData();
}


void WidgetData::initData()
{

    widName.append("Tvertne1"); //0
    widName.append("Tvertne1"); //1
    widName.append("Tvertne2"); //2
    widName.append("Tvertne3");//3
    widName.append("Tvertne4");//4

    widName.append("Pipe1");//5
    widName.append("Pipe2");//6
    widName.append("Pipe3");//7
    widName.append("Pipe4");//8

    widName.append("Valve1");//9
    widName.append("Valve2");//10
    widName.append("Valve3");//11
    widName.append("Valve4");//12

    widName.append("Pump1");//13
    widName.append("Pump2");//14
    widName.append("Pump3");//15
    widName.append("Pump4");//16

    widName.append("Dyno");//17
    widName.append("Mix");//18



    // type                      name         startX      startY  startSize  startSizeWi  options

    add(WidgetType::Mix,        widName[18],    100,        100,    50, 0,  0);
    add(WidgetType::Dyno,       widName[17],   200,         200,   50, 0,  0);
    add(WidgetType::Tvertne,     widName[0],  300,     300,   50, 0,  0);
    add(WidgetType::Pump,       widName[13],  100,        300,    50, 0,  0);

    add(WidgetType::Pipe,       widName[5],  350,         50,   0,  20,  0);
    add(WidgetType::Valve,      widName[9],  300,       100,   50, 0,  0);
    add(WidgetType::Pipe,     widName[6],    300,        50,    0,  20,  0);
    add(WidgetType::Pipe,     widName[7],    300,        70,    0,  20,  0);

    // qDebug() << "WidgetData widData [0] [1] " << global.widData.size();
}







void WidgetData::add(WidgetType::widgT ty, QString na,int X, int Y, int size, int sizeW, int options)
{
    dataStruct data;
    data.type = ty;
    data.name = na;
    data.startX = X;
    data.startY = Y;
    data.startsize = size;
    data.startSizeWi = sizeW;
    data.options = options;
    global.widData.append(data);

}
