#ifndef GLOBAL_H
#define GLOBAL_H


#include <QObject>
#include <QHash>
 //#include <QTimer>


namespace ActuatorType
{
enum actT{
    Invertor,
    Relay,
};
}
namespace SensorType
{
enum sensT{
    Digital,
    Analog,
};
}


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

class Global
{

public:
    Global();

    //QTimer *timer;

    struct  act{
        ActuatorType::actT type = ActuatorType::actT::Relay;  // Dyno
        QString name = "Dyno";
        int actNr = 0;
        int adress = 0;
        int analog = 0;
        int digital = 0;
    } ;

    struct  sens{
        SensorType::sensT type = SensorType::sensT::Digital;  //
        QString name = "Valve 1";
        int adress = 0;
        int analog = 7; //VALUE
        int digital = 2; //VALUE
    } ;

    struct wdataStruct {
        WidgetType::widgT type; // valve
        QString name ;
        int startX = 100;
        int startY = 100;
        int startSize = 50;
        int startSizeWi = 10;
        int options = 0;   //valve |- and pipe angle
        int actAdr = 0;
        int analogSensAdr = 0;
        int digitaSensAdr = 0;

    };
    QHash<QString,act> actHash;
    QHash<QString,sens> sensHash;
    QHash<QString,wdataStruct> widData;

    QString settingsFileName;
    QString appSwVers;
    float zoomKoef;
    int UIXsize;
    int UIYsize;
    int UIXresizeSize;
    int UIYresizeSize;



private:


    void creatWidgList();

    void addWidgList(WidgetType::widgT ty, QString na,int X, int Y, int size, int sizeW, int options);

    void creatActList();
    void addActList(QString name, ActuatorType::actT tp, int addres);

    void creatSensList();
    void addSensList(QString name, SensorType::sensT tp, int addres);

};

#endif // GLOBAL_H
