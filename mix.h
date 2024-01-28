#ifndef MIX_H
#define MIX_H

#include "widgetdiagramelement.h"
#include <QObject>
#include <QWidget>
//#include "widgetservice.h"

class Mix : public WidgetDiagramElement
{
    Q_OBJECT
public:
    Mix(QWidget *parent = nullptr);
    void updateSettings();
    void setNewPosition(float koef);
    // widDataStruct settings;
/*
    struct  {
        int type = 4; // Mix
        QString name = "Mix";
        int startX = 100;
        int startY = 100;
        int startSize = 100;
        int currX;
        int currY;
        int currSize;
    } settings;
*/
protected:
    void    paintEvent(QPaintEvent *event) override;
   // void    mousePressEvent(QMouseEvent *event) override;
   // void    mouseMoveEvent (QMouseEvent *event) override;
  //  void    mouseDoubleClickEvent(QMouseEvent *event) override;
private:
QImage *imgBackground;


};

#endif // MIX_H
