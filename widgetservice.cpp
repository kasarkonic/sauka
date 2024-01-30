#include "widgetservice.h"
#include "ui_widgetservice.h"
#include<QMouseEvent>
#include <QSettings>
//#include "widgetdiagramelement.h"



//WidgetService::WidgetService(WidgetDiagramElement::widDataStruct &wsettings ,  QWidget *parent)
WidgetService::WidgetService(WidgetDiagramElement *widgetElement, QWidget *parent)
    //: wsettings(wsettings)

    : QWidget(parent)
    , ui(new Ui::WidgetService)
    , widgetElement(widgetElement)
{
   // pipe = qobject_cast<Pipe*>(obj);
  //  qDebug() << "??? Name = " << valve->settings.name ;
    ui->setupUi(this);
 //  connect(
 //      &pipe, &Pipe::openServicePipe,
 //       this, &WidgetService::openWidgetServiceForm
 //        );
    updateFormData();
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

void WidgetService::updateFormData()
{

    ui->labelWtype->setText("Widget type: "+QString::number(widgetElement->settings.type));
    ui->labelWname->setText(widgetElement->settings.name);
    ui->lineEdit_Xpos->setText(QString::number(widgetElement->settings.startX));
    ui->lineEdit_Ypos->setText(QString::number(widgetElement->settings.startY));
    ui->lineEdit_startSize->setText(QString::number(widgetElement->settings.startSize));

}

void WidgetService::updateSettings()
{
  qDebug() << "WidgetService::updateSettings()";
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

    int pointX = pos.x();
    int pointY = pos.y();

    widgetElement->settings.startX = pointX;
    widgetElement->settings.startY = pointY;
    updateFormData();



   qDebug() << " WidgetService mouseMoveEvent dx:dy" << pos.x() << pos.y();


}

void WidgetService::mouseDoubleClickEvent(QMouseEvent *event)
{
 qDebug() << "WidgetService::mouseDoubleClickEvent" ;

}

void WidgetService::on_pushButton_Xplus_clicked()
{
    widgetElement->settings.startX +=1;
    updateSettings();
    updateFormData();
}


void WidgetService::on_pushButton_Xminus_clicked()
{
    if(widgetElement->settings.startX > 1)
        widgetElement->settings.startX -=1;

}


void WidgetService::on_pushButton_Yplus_clicked()
{
   widgetElement->settings.startY +=1;
}


void WidgetService::on_pushButton_Yminus_clicked()
{
    if(widgetElement->settings.startY > 1)
        widgetElement->settings.startY -=1;
}


void WidgetService::on_pushButton_sizeplus_clicked()
{
     widgetElement->settings.startSize +=1;
}


void WidgetService::on_pushButton_sizeMinus_clicked()
{
    if(widgetElement->settings.startSize > 1)
        widgetElement->settings.startSize -=1;
}

