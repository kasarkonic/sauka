#ifndef WIDGETDIAGRAMELEMENT_H
#define WIDGETDIAGRAMELEMENT_H

#include <QWidget>


class WidgetDiagramElement : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetDiagramElement( QWidget *parent = nullptr);

    void setNewPosition(float koef);


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
private:

    int timerId = 0;
    int att = 100;

};


#endif // WIDGETDIAGRAMELEMENT_H
