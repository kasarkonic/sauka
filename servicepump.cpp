#include "servicepump.h"
#include "ui_servicepump.h"

#include<QMouseEvent>
#include <QSettings>



Servicepump::Servicepump(QWidget *parent, QObject *obj)
    : QMainWindow(parent)
    , ui(new Ui::Servicepump)

{
    ui->setupUi(this);

    pump = qobject_cast<Pump*>(obj);
    qDebug() << "??? Name = " << pump->settings.name ;
    tmpString = pump->settings.name;
    applaySettings();


    // display settings:
    //QString s = QString::number(i);
    //QString str = "10";
    // int n = str.toInt();

    QColor col = QColor(Qt::red);
    QString qss = QString("background-color: %1").arg(col.name());
  //  ui->pushButton_->setStyleSheet(qss);

    updateUIvalue();

//    connect(
//        &pump, &Pump::openServicePump,
//        this, &MainWindow::openServiceFormPump
//        );


connect(
        pump, &Pump::updateServiceUI,
            this, &Servicepump::updateUIvalue
            );
//}
//connect(
//        pipe, &Pipe::updateServiceUI,
//            this, &Servicepump::updateUIvalue   ////  ?? &ServicePipe::updateUIvalue
 //           );
}


void Servicepump::updateUIvalue()
{

    ui->lineEdit_Name->setText(pump->settings.name);

    if(pump->settings.rotate == 0)
    {
  //      on_pushButton_OFF_clicked();
    }
    else{
     //?   on_pushButton_ON_clicked();
    }

     ui->label_Digital_val->setText(QString::number(pump->settings.rotate));
     //ui->label_Analog_val->setText(QString::number(pump->settings.speed));


       ui->lineEdit_Xpos->setText(QString::number(pump->settings.startX));
       ui->lineEdit_Ypos->setText(QString::number(pump->settings.startY));
       ui->lineEditSize->setText(QString::number(pump->settings.startSize));

       QColor col = QColor(Qt::green);
       QString qss = QString("background-color: %1").arg(col.name());
       ui->pushButton_EMERG_STOP->setStyleSheet(qss);

   // QString qss = QString("background-color: %1").arg(col.name());

}


Servicepump::~Servicepump()
{
    qDebug() << "~Servicepump()" ;
    delete ui;
}

void Servicepump::mousePressEvent(QMouseEvent *event)
{
    const QPoint& pos = event->pos();
    mouseStartPointX = pos.x();
    mouseStartPointY = pos.y();
     qDebug() << " Servicepump mousePressEvent dx:dy" <<pos.x() << pos.y();
}

void Servicepump::mouseMoveEvent(QMouseEvent *event)
{
    event->accept();

    // get the cursor position of this event
    const QPoint& pos = event->pos();

    int pointX = pos.x();
    int pointY = pos.y();

    pump->settings.startX += pointX;
    pump->settings.startY += pointY;
    pump->updateSettings();

   qDebug() << " Servicepump mouseMoveEvent dx:dy" << pos.x() << pos.y();


}

void Servicepump::applaySettings()
{
  /*  ui->label_Name->setText(tmpString);
    QString str = QString::number(pump->settings.startX);
    ui->lineEdit_Xpos->setText(str);
    ui->lineEdit_Ypos->setText(QString::number(pump->settings.startY));

    ui->label_Digital_val->setText(QString::number(pump->settings.rotate));
    ui->label_Analog_val->setText("Not Used");

    */
    pump->updateSettings();
}



void Servicepump::on_lineEdit_Name_editingFinished()
{
    QString str = ui->lineEdit_Name->text();
    pump->settings.name = str;

   // pump->updateSettings();
}


void Servicepump::on_pushButton_EMERG_STOP_clicked()
{
  qDebug() << "pushButton_EMERG_STOP_clicked() ????????????????????????????????????";
  QColor col = QColor(Qt::red);
  QString qss = QString("background-color: %1").arg(col.name());
  ui->pushButton_EMERG_STOP->setStyleSheet(qss);
}


void Servicepump::on_pushButton_ON_clicked()
{
    qDebug() << "on_pushButton_ON_clicked()";

    QColor col = QColor(Qt::green);

    QString qss = QString("background-color: %1").arg(col.name());
    ui->pushButton_ON->setStyleSheet(qss);

    col = QColor(Qt::white);
    qss = QString("background-color: %1").arg(col.name());
    ui->pushButton_OFF->setStyleSheet(qss);

    pump->settings.rotate = 3;
    pump->updateSettings();
}


void Servicepump::on_pushButton_OFF_clicked()
{
    qDebug() << "on_pushButton_OFF_clicked()";

    QColor col = QColor(Qt::red);

    QString qss = QString("background-color: %1").arg(col.name());
    ui->pushButton_OFF->setStyleSheet(qss);

    col = QColor(Qt::white);
    qss = QString("background-color: %1").arg(col.name());
    ui->pushButton_ON->setStyleSheet(qss);
    pump->settings.rotate = 0;
    pump->updateSettings();
}


void Servicepump::on_lineEdit_note_editingFinished()
{
    QString str = ui->lineEdit_note->text();
    pump->settings.note = str;

    pump->updateSettings();
}


void Servicepump::on_pushButton_SAVE_clicked()
{
    //pump->saveSettings();
}


void Servicepump::on_pushButton_CANCEL_clicked()
{
  close();
}


void Servicepump::on_lineEdit_Xpos_editingFinished()
{
    qDebug() << "on_lineEdit_Xpos_editingFinished()";
    QString str = ui->lineEdit_Xpos->text();
    pump->settings.startX = str.toInt();
    pump->updateSettings();
}


void Servicepump::on_pushButton_Xposplus_clicked()
{
    if(pump->settings.startX < 4000){
        pump->settings.startX +=1;
    }
    ui->lineEdit_Xpos->setText(QString::number(pump->settings.startX));
    pump->updateSettings();
}

/*
void Servicepump::on_pushButton_Xposminus_clicked(bool checked)
{
    {
        if(pump->settings.startX > 0){
            pump->settings.startX -=1;
        }
         ui->lineEdit_Xpos->setText(QString::number(pump->settings.startX));
        pump->updateSettings();
    }
}
*/

void Servicepump::on_lineEdit_Ypos_editingFinished()
{
    qDebug() << "on_lineEdit_Ypos_editingFinished()";
    QString str = ui->lineEdit_Ypos->text();
    pump->settings.startY = str.toInt();
    pump->updateSettings();
}


void Servicepump::on_pushButton_YposPlus_clicked()
{
    if(pump->settings.startY < 4000){
        pump->settings.startY +=1;
    }
     ui->lineEdit_Ypos->setText(QString::number(pump->settings.startY));
    pump->updateSettings();
}


void Servicepump::on_pushButton__YposMinus_clicked()
{
    if(pump->settings.startY > 0){
        pump->settings.startY -=1;
    }
    ui->lineEdit_Ypos->setText(QString::number(pump->settings.startY));
    pump->updateSettings();
}


void Servicepump::on_lineEditSize_editingFinished()
{
    qDebug() << "on_lineEditSize_editingFinished()";
    QString str = ui->lineEditSize->text();
    pump->settings.startSize = str.toInt();
    pump->updateSettings();
}


void Servicepump::on_pushButton_SizePlus_clicked()
{
    if(pump->settings.startSize < 4000){
        pump->settings.startSize +=1;
    }
    ui->lineEditSize->setText(QString::number(pump->settings.startSize));
    pump->updateSettings();
}


void Servicepump::on_pushButton_SizeMinus_clicked()
{
    if(pump->settings.startSize > 0){
        pump->settings.startSize -=1;
    }
    ui->lineEditSize->setText(QString::number(pump->settings.startSize));
    pump->updateSettings();
}


void Servicepump::on_lineEdit_Speed_editingFinished()
{
    qDebug() << "on_lineEdit_Speed_editingFinished()";
    QString str = ui->lineEdit_Speed->text();
   // pump->settings.speed = str.toInt();
    pump->updateSettings();
}


void Servicepump::on_pushButton_SpeedPlus_clicked()
{
    //if(pump->settings.speed < 4000){
    //    pump->settings.speed +=1;
   // }
   // ui->lineEdit_Speed->setText(QString::number(pump->settings.speed));
   // pump->updateSettings();
}


void Servicepump::on_pushButton_SpeedMinus_clicked()
{
    //if(pump->settings.speed > 0){
   //     pump->settings.speed -=1;
   // }
   // ui->lineEdit_Speed->setText(QString::number(pump->settings.speed));
   // pump->updateSettings();
}


void Servicepump::on_pushButton_Xposminus_clicked()
{
    {
        if(pump->settings.startX > 0){
            pump->settings.startX -=1;
        }
         ui->lineEdit_Xpos->setText(QString::number(pump->settings.startX));
        pump->updateSettings();
    }
}

