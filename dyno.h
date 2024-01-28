#ifndef DYNO_H
#define DYNO_H

#include "widgetdiagramelement.h"
#include <QObject>
#include <QWidget>


class Dyno : public WidgetDiagramElement
{
    Q_OBJECT
public:
    Dyno(QWidget *parent = nullptr);
    //void updateSettings();
    void setNewPosition(float koef);

    void updateSettings() ;


  //      widDataStruct settings;
/*
    struct  {
        int type = 4; // Dyno
        QString name = "Dyno";

        int startX = 100;
        int startY = 100;
        int startSize = 100;

        //valve |-
        // pipe WI
        int opcijas = 0;

        // līmenis, ātrums
        int value = 0;

        // tvertne gala slēdzis
        //pārējie on/off/??
        int status = 0;

        int currX;
        int currY;
        int currSize;

    } settings;
*/
protected:
    void    paintEvent(QPaintEvent *event) override;
 //   void    mousePressEvent(QMouseEvent *event) override;
 //   void    mouseMoveEvent (QMouseEvent *event) override;
//    void    mouseDoubleClickEvent(QMouseEvent *event) override;

  //  void updateSettings() ;
private:
QImage *imgBackground;


};

#endif // DYNO_H
