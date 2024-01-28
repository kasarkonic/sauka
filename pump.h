#ifndef PUMP_H
#define PUMP_H


#include "widgetdiagramelement.h"
#include <QObject>
#include <QWidget>

class Pump : public WidgetDiagramElement
{
    Q_OBJECT
public:
    explicit Pump(QWidget *parent = nullptr);

    void setNewPosition(float koef) ;
    void updateSettings() ;
   // void saveSettings() ;
   // void loadSettings() ;
    // widDataStruct settings;
/*
    struct  {
        int type = 2; // pump
        QString name = "Pump";

        int startX = 100;
        int startY = 100;
        int startSize = 100;

        int currX;
        int currY;
        int currSize;



       // int radius ;
       // float speed  = 100;


        int rotate = 0;        // 0 stop, 1 -> run up
        QColor  triangColor = Qt::blue;    // pipe color
        QString note;
    } settings;
*/
        QColor  triangColor = Qt::blue;    // pipe color

signals:
    //void openServicePump();
    void updateServiceUI();
protected:
    void    paintEvent(QPaintEvent *event) override;
    void    timerEvent(QTimerEvent *event) override;
 //   void    mousePressEvent(QMouseEvent *event) override;
//    void    mouseMoveEvent (QMouseEvent *event) override;
//    void    mouseDoubleClickEvent(QMouseEvent *event) override;
private:

    int att = 360;
    int timerId = 0;
    int mouseStartPointX;
    int mouseStartPointY;

};

#endif // PUMP_H
