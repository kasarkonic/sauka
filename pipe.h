#ifndef PIPE_H
#define PIPE_H


#include "widgetdiagramelement.h"

class Pipe : public WidgetDiagramElement
{
    Q_OBJECT
public:
    Pipe(QWidget *parent = nullptr);

    void get(int *pnt);
    void setNewPosition(float koef);
    void updateSettings();
    //void saveSettings();
    //void loadSettings();
  // widDataStruct settings;
/*
    struct  {
        int type = 1; // pipe
        QString name = "Pipe";
        QString note = "";
        int startX = 100;
        int startY = 100;
        int starwi = 50;
        int starhi = 200;

        int wi = 0;          // pipe width
        int hi = 0;          // pipe hight
        int currX = 0;
        int currY = 0;

        float angle = 0; // 0 vertical, ccw

        int flow = 0;        // 0 stop, 1 -> run up
        QColor  pipeColor = Qt::white;   // pipe color
        QColor  arrowColor = Qt::white;    // pipe color

        // for internal use
        //____________________________
        // float an = angle * M_PI /180;


    } settings;


    */



    //int starwi = 50;    //int options = 0;
    //int starhi = 200;   //startSize

    int currWi = 0;          //     pipe width
    int currHi = 0;          //     pipe hi

    float angle = 0; // 0 options = 0;   vertical, ccw
    int flow = 0;        // int value 0 stop, 1 -> run up

    QColor  pipeColor = Qt::white;   // pipe color
    QColor  arrowColor = Qt::white;    // pipe color




signals:
   // void openServicePipe();
    void updateServiceUI();
protected:
    void    paintEvent(QPaintEvent *event) override;
    void    timerEvent(QTimerEvent *event) override;
  //  void    mousePressEvent(QMouseEvent *event) override;
 //   void    mouseMoveEvent (QMouseEvent *event) override;
//    void    mouseDoubleClickEvent(QMouseEvent *event) override;
private:

    int timerId = 0;
    int att = 100;


    QPoint position;

    QPoint pipePoints[4];
    QPoint arrowPoints[40];
    QPoint pipemiddle[2];
    int arrTop = 20;
    int mouseStartPointX;
    int mouseStartPointY;


};

#endif // PIPE_H
