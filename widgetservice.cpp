#include "widgetservice.h"
#include "ui_widgetservice.h"
#include<QMouseEvent>
#include <QSettings>
#include "pipe.h"



WidgetService::WidgetService( QWidget *parent)//, QObject *obj)
   : QWidget(parent)

   , ui(new Ui::WidgetService)
{
   // pipe = qobject_cast<Pipe*>(obj);
  //  qDebug() << "??? Name = " << valve->settings.name ;
    ui->setupUi(this);
   connect(
       &pipe, &Pipe::openServicePipe,
        this, &WidgetService::openWidgetServiceForm
        );
}
    void WidgetService::openWidgetServiceForm()
    {
        qDebug() << "WidgetSrv Open service pipe ??? : " ;

        this->show();
    }

  //  qDebug() << "Open service pipe ??? : " ;
  //  WidgetService *widgetService = new WidgetService (this,global,sender());
  //  Pipe* pipe = qobject_cast<Pipe*>(sender());
  //  qDebug() << "Open service : " << pipe->settings.name ;
  //  widgetService->show();





WidgetService::~WidgetService()
{
    delete ui;
}

void WidgetService::updateUIvalue()
{

}
void WidgetService::mousePressEvent(QMouseEvent *event)
{
    const QPoint& pos = event->pos();
    mouseStartPointX = pos.x();
    mouseStartPointY = pos.y();
     qDebug() << " WidgetService mousePressEvent dx:dy" <<pos.x() << pos.y();
}
void WidgetService::mouseMoveEvent(QMouseEvent *event)
{
    event->accept();

    // get the cursor position of this event
    const QPoint& pos = event->pos();

  //  int pointX = pos.x();
  //  int pointY = pos.y();

   // pump->settings.startX += pointX;
  //  pump->settings.startY += pointY;
  //  pump->updateSettings();

   qDebug() << " WidgetService mouseMoveEvent dx:dy" << pos.x() << pos.y();


}
