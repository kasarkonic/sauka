#ifndef TVERTNE_H
#define TVERTNE_H

#include "widgetdiagramelement.h"
#include <QObject>
#include <QWidget>

class Tvertne : public WidgetDiagramElement
{
     Q_OBJECT
public:
    Tvertne(QWidget *parent = nullptr);
    void updateSettings();
    void setNewPosition(float koef);

    struct  {
        int type = 4; // Dyno
        QString name = "Tvertne";
        int startX = 100;
        int startY = 100;
        int startSize = 100;
        int currX;
        int currY;
        int currSize;
    } settings;

protected:
    void    paintEvent(QPaintEvent *event) override;
    void    mousePressEvent(QMouseEvent *event) override;
    void    mouseMoveEvent (QMouseEvent *event) override;
    void    mouseDoubleClickEvent(QMouseEvent *event) override;
private:
QImage *imgBackground;

};

#endif // TVERTNE_H
