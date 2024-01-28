#include "createsensorlist.h"
#include <Qdebug>

CreateSensorList::CreateSensorList()

{
}

void CreateSensorList::creatSensorName()
{
    sensName.append("Valve1 On");
    sensName.append("Valve1 OFF");
}

void CreateSensorList::creatSensList()
{
addSensList(SensorType::Digital, 1, 123);
}

void CreateSensorList::addSensList(SensorType::sensT tp, int nr, int addres)
{
    sens data;

    data.type = SensorType::sensT::Digital;  //
    data.actNr = 0;
    data.adress = 0;
   // data.analog = 0; VALUE
   // data.digital = 0;
    if (nr < sensName.size())
    data.name = actName[addres];
    else{
        qDebug()  << "!!! Error unreal sensor addres > actList size";
    }
}
