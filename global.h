#ifndef GLOBAL_H
#define GLOBAL_H

#include <QObject>
#include "widgetdata.h"
 //#include <QTimer>

namespace ActuatorType
{
enum actT{
    Invertor,
    Relay,
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






    QString settingsFileName;
    QString appSwVers;
    float zoomKoef;

    QVector <WidgetData::dataStruct> widData;

    QList <ActuatorType::actT> actList;



    void creatActName();
    void creatActList();
    void addActList( ActuatorType::actT tp, int nr, int addres, int an, int di);
    QList<QString> actName;
    QList<QString> sensName;

     void    timerEvent(QTimerEvent *event) ;

public slots:
    void MyTimerSlot();


private:

    //QList<QString> actName;
    int timerId;
};

#endif // GLOBAL_H
