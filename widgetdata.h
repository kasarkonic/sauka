#ifndef WIDGETDATA_H
#define WIDGETDATA_H

#include <QObject>


class Global;


namespace WidgetType
{
enum widgT{
    Dyno,
    Mix,
    Pipe,
    Pump,
    Tvertne,
    Valve,
};
}


class WidgetData
{
public:

    struct dataStruct {
        WidgetType::widgT type; // valve
        QString name ;
        int startX = 100;
        int startY = 100;
        int startsize = 50;
        int startSizeWi = 10;
        int options = 0;   //valve |- and pipe angle
        int actAdr = 0;
        int analogSensAdr = 0;
        int digitaSensAdr = 0;

    };

   // QVector <dataStruct> widData;


    WidgetData(Global &global);
private:

    Global &global;
    QList<QString> widName;
    void initData();
    void add(WidgetType::widgT ty, QString na,int X, int Y, int size, int sizeW, int options);
};

#endif // WIDGETDATA_H
