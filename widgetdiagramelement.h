#ifndef WIDGETDIAGRAMELEMENT_H
#define WIDGETDIAGRAMELEMENT_H

#include <QWidget>
#include"global.h"
#include<QMouseEvent>

#include <QPainter>
#include <QPixmap>

class WidgetDiagramElement : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetDiagramElement( Global &global,QString name, QWidget *parent = nullptr);




    struct  widDataStruct{
        int type = 4; // Dyno
        QString name = "";

        int startX = 100;
        int startY = 100;
        int startSize = 100;
        int startSizeWi = 10;

        //valve |- angle
        // pipe angle
        int options = 0;

        // līmenis, ātrums
        int value = 0;

        // tvertne gala slēdzis
        //pārējie on/off/??
        int status = 0;

        int currX;
        int currY;
        int currSize;
        int currSizeWi;
    } settings;

protected:
   // void    mousePressEvent(QMouseEvent *event) override;
    //void    mouseMoveEvent (QMouseEvent *event) override;
    void    mouseDoubleClickEvent(QMouseEvent *event) override;
    void    timerEvent(QTimerEvent *event) override;
    void    resizeEvent(QResizeEvent* event) override ;
    Global &global;
    void setNewPosition(float koef);


private:

    int timerId = 0;
    int att = 100;
    QString widName;

};


#endif // WIDGETDIAGRAMELEMENT_H
