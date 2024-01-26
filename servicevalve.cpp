
#include "servicevalve.h"
#include "ui_servicevalve.h"





Servicevalve::Servicevalve(QWidget *parent, QObject *obj)
    : QMainWindow(parent)
    , ui(new Ui::Servicevalve)

{
    ui->setupUi(this);

    valve = qobject_cast<Valve*>(obj);
    qDebug() << "??? Name = " << valve->settings.name ;
    tmpString = valve->settings.name;
    applaySettings();

    // display settings:
    //QString s = QString::number(i);
    //QString str = "10";
    // int n = str.toInt();

    QColor col = QColor(Qt::red);
    QString qss = QString("background-color: %1").arg(col.name());
    ui->pushButton_STOP->setStyleSheet(qss);





}

Servicevalve::~Servicevalve()
{
    qDebug() << "~Servicevalve()" ;
    delete ui;
}

void Servicevalve::applaySettings()
{
    ui->label_Name->setText(tmpString);
    QString str = QString::number(valve->settings.startX);
    ui->lineEdit_Xpos->setText(str);
    ui->lineEdit_Ypos->setText(QString::number(valve->settings.startY));

    ui->label_Digital_val->setText(QString::number(valve->settings.status));
    ui->label_Analog_val->setText("Not Used");


    valve->updateSettings();
}

void Servicevalve::on_pushButton_Xposplus_clicked()
{
    if(valve->settings.startX < 4000){
        valve->settings.startX +=1;
    }

    valve->updateSettings();
}


void Servicevalve::on_pushButton_Xposminus_clicked()
{
    if(valve->settings.startX > 1){
        valve->settings.startX -=1;
    }
    valve->updateSettings();
}


void Servicevalve::on_pushButton_YposPlus_clicked()
{
    if(valve->settings.startY < 2000){
        valve->settings.startY +=5;
    }
    valve->updateSettings();
}


void Servicevalve::on_pushButton__YposMinus_clicked()
{
    if(valve->settings.startY > 1){
        valve->settings.startY -=5;
    }
    valve->updateSettings();
}


//void Servicevalve::on_pushButton_XsizePlus_clicked()
//{

//}


void Servicevalve::on_lineEdit_Xpos_editingFinished()
{
    qDebug() << "lineEdit_Xpos_editingFinished()";
    QString str = ui->lineEdit_Xpos->text();
    valve->settings.startX = str.toInt();
    applaySettings();
}


void Servicevalve::on_lineEdit_Ypos_editingFinished()
{
    qDebug() << "lineEdit_Ypos_editingFinished()";
    QString str = ui->lineEdit_Ypos->text();
    valve->settings.startY = str.toInt();
    applaySettings();
}


void Servicevalve::on_lineEdit_Xsize_editingFinished()
{

}


void Servicevalve::on_lineEdit_Ysize_editingFinished()
{

}


void Servicevalve::on_pushButton_STOP_clicked()
{
    qDebug() << "on_pushButton_STOP_clicked()";

}


void Servicevalve::on_pushButton_SAVE_clicked()
{
    //valve->saveSettings();

}


void Servicevalve::on_pushButton_CANCEL_clicked()
{

}


void Servicevalve::on_pushButton_ON_clicked()
{
    qDebug() << "on_pushButton_ON_clicked()";

    QColor col = QColor(Qt::green);

    QString qss = QString("background-color: %1").arg(col.name());
    ui->pushButton_ON->setStyleSheet(qss);

    col = QColor(Qt::white);
    qss = QString("background-color: %1").arg(col.name());
    ui->pushButton_OFF->setStyleSheet(qss);

    valve->settings.status = 3;
    applaySettings();

}


void Servicevalve::on_pushButton_OFF_clicked()
{
    qDebug() << "on_pushButton_OFF_clicked()";

    QColor col = QColor(Qt::red);

    QString qss = QString("background-color: %1").arg(col.name());
    ui->pushButton_OFF->setStyleSheet(qss);

    col = QColor(Qt::white);
    qss = QString("background-color: %1").arg(col.name());
    ui->pushButton_ON->setStyleSheet(qss);
    valve->settings.status = 0;
    applaySettings();
}


void Servicevalve::on_lineEdit_Name_editingFinished()
{
    QString str = ui->lineEdit_Name->text();
    //qDebug() << str;
    valve->settings.name = str;
    //qDebug() << valve->settings.name;
}

