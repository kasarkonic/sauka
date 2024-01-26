#include "service.h"
#include "ui_service.h"





Service::Service(QWidget *parent, QObject *obj)
    : QMainWindow(parent)
    , ui(new Ui::Service)

{
    ui->setupUi(this);
    applaySettings();
    Valve* valve = qobject_cast<Valve*>(obj);
    qDebug() << "??? Name = " << valve->settings.name ;
    tmpString = valve->settings.name;
    applaySettings();
}

Service::~Service()
{
    qDebug() << "~Service()" ;
    delete ui;
}

void Service::applaySettings()
{
    ui->label_Name->setText(tmpString);

}

void Service::saveSettings()
{

}

void Service::on_pushButton_Xposplus_clicked()
{

}


void Service::on_pushButton_Xposminus_clicked(bool checked)
{
Q_UNUSED (checked);
}


void Service::on_pushButton_YposPlus_clicked()
{

}


void Service::on_pushButton__YposMinus_clicked()
{

}


void Service::on_pushButton_XsizePlus_clicked()
{

}


void Service::on_lineEdit_Xpos_editingFinished()
{

}


void Service::on_lineEdit_Ypos_editingFinished()
{

}


void Service::on_lineEdit_Xsize_editingFinished()
{

}


void Service::on_lineEdit_Ysize_editingFinished()
{

}


void Service::on_pushButton_STOP_clicked()
{

}


void Service::on_pushButton_SAVE_clicked()
{

}


void Service::on_pushButton_CANCEL_clicked()
{

}


void Service::on_pushButton_ON_clicked()
{

}


void Service::on_pushButton_OFF_clicked()
{

}


void Service::on_lineEdit_Name_editingFinished()
{
    QString str = ui->lineEdit_Name->text();
    qDebug() << str;
 //   valve->settings.name = str;
}

