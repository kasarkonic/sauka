#include "widgetservice.h"
#include "ui_widgetservice.h"
#include<QMouseEvent>
#include <QSettings>
//#include "widgetdiagramelement.h"


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




    currentWid =  widgetElement->settings.name;
    qDebug() << "currentWid" << currentWid  ;


    //QString str =  widgetElement->global.widData[currentWid].name;
    qDebug() << "???" << widgetElement->global.widData[currentWid].startX << widgetElement->global.widData[currentWid].startY  ;
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
    ui->labelWname->setText(widgetElement->global.widData[currentWid].name);
    ui->lineEdit_Xpos->setText(QString::number(widgetElement->global.widData[currentWid].startX));
    ui->lineEdit_Ypos->setText(QString::number(widgetElement->global.widData[currentWid].startY));
    ui->lineEdit_startSize->setText(QString::number(widgetElement->global.widData[currentWid].startSize));
    ui->lineEdit_options->setText(QString::number(widgetElement->global.widData[currentWid].options));
    widgetElement->updateSettings();
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
    // event->accept();

    // get the cursor position of this event
    const QPoint& pos = event->pos();

    int pointX = pos.x();
    int pointY = pos.y();

    widgetElement->global.widData[currentWid].startX = pointX;
    widgetElement->global.widData[currentWid].startY = pointY;
    updateFormData();

    qDebug() << " WidgetService mouseMoveEvent dx:dy" << pos.x() << pos.y();


}

void WidgetService::mouseDoubleClickEvent(QMouseEvent *event)
{
    qDebug() << "WidgetService::mouseDoubleClickEvent" ;

}

void WidgetService::on_pushButton_Xplus_clicked()
{
    widgetElement->global.widData[currentWid].startX +=1;
    // updateSettings();
    // updateFormData();
    updateFormData();
}


void WidgetService::on_pushButton_Xminus_clicked()
{
    if(widgetElement->global.widData[currentWid].startX > 1)
        widgetElement->global.widData[currentWid].startX -=1;
    updateFormData();
}


void WidgetService::on_pushButton_Yplus_clicked()
{
    widgetElement->global.widData[currentWid].startY +=1;
    updateFormData();
}


void WidgetService::on_pushButton_Yminus_clicked()
{
    if(widgetElement->global.widData[currentWid].startY > 1)
        widgetElement->global.widData[currentWid].startY -=1;
    updateFormData();
}


void WidgetService::on_pushButton_sizeplus_clicked()
{
    widgetElement->global.widData[currentWid].startSize +=1;
    updateFormData();
}


void WidgetService::on_pushButton_sizeMinus_clicked()
{
    if(widgetElement->global.widData[currentWid].startSize > 1)
        widgetElement->global.widData[currentWid].startSize -=1;
    updateFormData();
}


void WidgetService::on_pushButton_OptionsMinus_clicked()
{
    if(widgetElement->global.widData[currentWid].options > 0)
        widgetElement->global.widData[currentWid].options -=1;
    updateFormData();
}


void WidgetService::on_pushButton_OptionsPlus_clicked()
{
    widgetElement->global.widData[currentWid].options +=1;
    updateFormData();
}


void WidgetService::on_lineEdit_Xpos_editingFinished()
{
    int val = ui->lineEdit_Xpos->text().toInt();
    widgetElement->global.widData[currentWid].startX = val;
    updateFormData();
}


void WidgetService::on_lineEdit_Ypos_editingFinished()
{
    int val = ui->lineEdit_Ypos->text().toInt();
    widgetElement->global.widData[currentWid].startY = val;
    updateFormData();
}


void WidgetService::on_lineEdit_startSize_editingFinished()
{
    int val = ui->lineEdit_startSize->text().toInt();
    widgetElement->global.widData[currentWid].startSize = val;
    updateFormData();
}


void WidgetService::on_lineEdit_options_editingFinished()
{
    int val = ui->lineEdit_options->text().toInt();
    widgetElement->global.widData[currentWid].options = val;
    updateFormData();
}

