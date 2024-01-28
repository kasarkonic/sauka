#ifndef CREATESENSORLIST_H
#define CREATESENSORLIST_H

#include <QObject>
#include "global.h"

namespace SensorType
{
enum sensT{
    Digital,
    Analog,
};
}

class CreateSensorList  : public Global
{
public:
    CreateSensorList();

    struct  sens{
        SensorType::sensT type = SensorType::sensT::Digital;  //
        QString name = "Valve1";
        int actNr = 0;
        int adress = 0;
        int analog = 0;
        int digital = 0;
    } ;

    void creatSensorName();
    void creatSensList();
    void addSensList(SensorType::sensT tp, int nr, int addres);


};

#endif // CREATESENSORLIST_H
