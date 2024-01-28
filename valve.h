#ifndef VALVE_H
#define VALVE_H

#include <QObject>
#include <QWidget>
//#include "mytriangle.h"
#include "widgetdiagramelement.h"


namespace ValveStatus
{
enum{
    Close,  // 0
    OpenBA,
    OpenBC,
    OpenAC,
    Open_BA,
    Open_BC,
    Open_BB,
    OpenABC_B,
    OPENABC,
    Unknown,
};
}


class Valve : public WidgetDiagramElement
{
    Q_OBJECT
public:
    Valve(QWidget *parent = nullptr);
    // void saveSettings();
    // void loadSettings();

   // void setStartParam(QPoint dimA, QPoint dimC,QPoint pos);
   // MyTriangle myTriangle1;
   // MyTriangle myTriangle2;
   // MyTriangle myTriangle3;
   // MyTriangle myTriangle4;
    void updateWidget();

    void setNewPosition(float koef);
    void updateSettings();
    //widDataStruct settings;
    /*
    struct  {
        int type = 3; // valve
        QString name = "Valve";
        int startX = 120;
        int startY = 120;
        int startSize = 130;

        int currX;
        int currY;
        int currSize;

       // int triangStartSize = 250;     // widget size
       // int triangSize = 150;     // widget size
        int status = 0;
        int style = 0;


    } settings;
*/

signals:
    // void openServiceValve();

protected:
    void    paintEvent(QPaintEvent *event) override;
    void    timerEvent(QTimerEvent *event) override;


private:
    int angle;

    void updateStatus();
    int  timerId = 0;
    int att = 0;

    QPoint points[4];
    void calcPoints(int angle);
   // QColor color = Qt::yellow;;

};

#endif // VALVE_H
