#include "widgetdata.h"
#include "global.h"

WidgetData::WidgetData(Global &global):
    global(global)
{
    initData();
}


/*

namespace WidgetName
{
enum widg{
    Tvertne1,
    Tvertne2,
    Tvertne3,
    Tvertne4,

    Pipe1,
    Pipe2,
    Pipe3,
    Pipe4,
    Valve1,
    Valve2,
    Valve3,
    Valve4,
    Pump1,
    Pump2,
    Pump3,
    Pump4,
    Dyno,
    Mix,
};
}



namespace WidgetType
{
enum {
    Dyno,
    Mix,
    Pipe,
    Pump,
    Tvertne,
    Valve,
};
}
*/
void WidgetData::initData()
{
    add(WidgetType::Mix,        WidgetName::Mix,  100,     100    ,50);
    add(WidgetType::Dyno,       WidgetName::Dyno,  200,     200    ,50);
    add(WidgetType::Tvertne,     WidgetName::Tvertne3,  300,     300    ,50);
    add(WidgetType::Pump,       WidgetName::Pump1,  100,     300    ,50);

    add(WidgetType::Pipe,       WidgetName::Pipe1,  300,     100    ,0);
    add(WidgetType::Valve,      WidgetName::Valve1,  300,     300    ,50);
    //add(WidgetType::Pipe,     WidgetName::Pipe3,  100,     300    ,0);
    // add(WidgetType::Pipe,     WidgetName::Pipe4,  300,     300    ,0);

   // qDebug() << "WidgetData widData [0] [1] " << global.widData.size();
}







void WidgetData::add(WidgetType::widgT ty, WidgetName::widgN na,int X, int Y, int size)
{
    dataStruct data;
    data.type = ty;
    data.name = na;
    data.startX = X;
    data.startY = Y;
    data.startsize = size;

    global.widData.append(data);

}
