#ifndef PUMP_H
#define PUMP_H


#include "widgetdiagramelement.h"
//#include <QObject>
//#include <QWidget>

class Pump : public WidgetDiagramElement
{
    Q_OBJECT
public:
    explicit Pump(Global &global,QString name, QWidget *parent = nullptr);

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
   // void setNewPosition(float koef) ;
    void updateSettings() ;
private:

    int att = 360;
    int timerId = 0;
    int mouseStartPointX;
    int mouseStartPointY;

};

#endif // PUMP_H
