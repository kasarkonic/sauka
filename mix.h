#ifndef MIX_H
#define MIX_H

#include "widgetdiagramelement.h"


class Mix : public WidgetDiagramElement
{
    Q_OBJECT
public:
    Mix(Global &global,QString name, QWidget *parent = nullptr);
    void updateSettings();

    // widDataStruct settings;

protected:
    void    paintEvent(QPaintEvent *event) override;
   // void    mousePressEvent(QMouseEvent *event) override;
   // void    mouseMoveEvent (QMouseEvent *event) override;
  //  void    mouseDoubleClickEvent(QMouseEvent *event) override;
  //  void setNewPosition(float koef) ;

private:
QImage *imgBackground;


};

#endif // MIX_H
