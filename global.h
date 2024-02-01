#ifndef GLOBAL_H
#define GLOBAL_H



#include <QObject>
#include <QHash>
#include <QList>
 //#include <QTimer>


 class WidgetService;
 class WidgetDiagramElement;
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
        int adress = 0;
        int analog = 0;
        int digital = 0;
    } ;

    struct  sens{
        SensorType::sensT type = SensorType::sensT::Digital;  //
        QString name = "Sens";
       // int adress = 0;
        int analog = 7; //VALUE
        int digital = 2; //VALUE
    };

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
        int windowNr = 0;
        bool formExist = false;
        WidgetDiagramElement * ptrCurrWidget = nullptr;
        WidgetService * ptrCurrWidgetService = nullptr;
        int page = 0;
        int actAddres = 0;
        int sensAddres1 = 0;
        int sensAddres2 = 0;

    };

    QList<act> actList;
    QList<sens> sensList;
    QHash<QString,wdataStruct> widHash;

    QString settingsFileName;
    QString appSwVers;
    float zoomKoef;
    int UIXsize;
    int UIYsize;
    int UIXresizeSize;
    int UIYresizeSize;

private:


    void creatWidgList();
    void addWidgList(WidgetType::widgT ty, QString na,int X, int Y, int size, int sizeW, int options, int page, int actAdr, int sensAdr1, int sensAdr2);

    void creatActList();
    void addActList(QString name, ActuatorType::actT tp, int addres);

    void creatSensList();
    void addSensList(QString name, SensorType::sensT tp, int addres);


};

#endif // GLOBAL_H
