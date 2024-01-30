#include "widgetdiagramelement.h"
#include<QMouseEvent>
#include "widgetservice.h"
#include "global.h"

WidgetDiagramElement::WidgetDiagramElement(Global &global,QString name, QWidget *parent)
   : QWidget{parent}
    , global(global)

{
    settings.name = name;
}

void WidgetDiagramElement::setNewPosition(float koef)
{
   // qDebug() << "WidgetDiagramElement 1::setNewPosition()" <<settings.name << global.zoomKoef<<settings.startX<<settings.startY<<
   // settings.currX<<settings.currY  ;
    settings.currX = int((float)settings.startX /koef);
    settings.currY = int((float)settings.startY / koef);
    settings.currSize = int ((float)settings.startSize/koef);
    //qDebug() << "WidgetDiagramElement 2::setNewPosition()" <<settings.name << global.zoomKoef<<settings.startX<<settings.startY<<
    //    settings.currX<<settings.currY  ;
}

void WidgetDiagramElement::mouseDoubleClickEvent(QMouseEvent *event)
{
Q_UNUSED (event)
    qDebug() << "WidgetDiagramElement::mouseDoubleClickEvent ws:" << settings.name << settings.type ;


    qDebug() << "this" << this;


    //WidgetService *serviceForm = new WidgetService(settings);

     WidgetService *serviceForm = new WidgetService( this );
    serviceForm->show();
}

void WidgetDiagramElement::timerEvent(QTimerEvent *event)
{
    Q_UNUSED (event);
}

void WidgetDiagramElement::resizeEvent(QResizeEvent *event)
{
 // qDebug() << "WidgetDiagramElement::resizeEvent";
  Q_UNUSED (event);

  float koefx = 1.0;
  float koefy = 1.0;
  float koef = 1.0;

  if(size().width() > 0 && size().height() > 0){
      koefx =  (float)global.UIXsize/global.UIXresizeSize;
      koefy = (float)global.UIYsize/global.UIYresizeSize;
  }

  if(koefx >= koefy){
      koef = koefy;
  }
  else{
      koef = koefx;
  }

  if(koef == 0){
      koef = 1;
  }
 // qDebug() << "resizeEvent UIsize"  << global.UIXsize << global.UIYsize <<size().width()<<size().height()<<koefx <<koefy<<koef;
  global.zoomKoef = koef;
  setNewPosition(koef);
}

