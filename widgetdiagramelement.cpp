#include "widgetdiagramelement.h"
#include<QMouseEvent>
#include "widgetservice.h"

WidgetDiagramElement::WidgetDiagramElement( QWidget *parent)
    : QWidget{parent}

{

}

void WidgetDiagramElement::setNewPosition(float koef)
{
    qDebug() << "WidgetDiagramElement::setNewPosition(koef)" << koef ;

}

void WidgetDiagramElement::mouseDoubleClickEvent(QMouseEvent *event)
{
Q_UNUSED (event)
    qDebug() << "WidgetDiagramElement::mouseDoubleClickEvent ws:" << settings.name << settings.type ;


    qDebug() << "this" << this;


    WidgetService *serviceForm = new WidgetService(settings);

    // WidgetService *serviceForm = new WidgetService( &this );
    serviceForm->show();
}

void WidgetDiagramElement::timerEvent(QTimerEvent *event)
{
    Q_UNUSED (event);
     qDebug() << "WidgetDiagramElement::timerEvent" << settings.startX;
}
