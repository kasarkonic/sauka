#ifndef GLOBAL_H
#define GLOBAL_H

#include <QObject>
#include "widgetdata.h"

class Global
{
public:
    Global();

    QString settingsFileName;
    QString appSwVers;
    float zoomKoef;
    QVector <WidgetData::dataStruct> widData;

};

#endif // GLOBAL_H
