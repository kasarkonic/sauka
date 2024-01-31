#include "mainwindow.h"
#include "dyno.h"
#include "qforeach.h"
#include "ui_mainwindow.h"
#include <Qdebug>

#include <QFile>


#include <QMouseEvent>
#include "global.h"
#include <QDateTime>



MainWindow::MainWindow(Global &global,  QWidget *parent)
    : QMainWindow(parent)
    , global(global)
    , ui(new Ui::MainWindow)
    //,  widgetData(global)


{ 
    ui->setupUi(this);


    QString settingsFile = QApplication::applicationDirPath() + "/settings.ini";
    global.settingsFileName =  settingsFile;

    QSettings settings(settingsFile, QSettings::IniFormat);
    qDebug() << "settingsFile" << settingsFile << global.settingsFileName;

    //IntegerSetting = settings.value("SettingName", default).toInt();
    // BooleanSetting = settings.value("SettingName", default).toBool();


    //areaY = size().height();
    //areaX = size().width();
    global.UIXsize = size().width();
    global.UIYsize = size().height();
    qDebug() << "UI size" << global.UIXsize <<":" << global.UIYsize;

    // initUI();
    drawWidgets();

    initTimer = true;
    // timerId = startTimer(100);


    // connect(&valve,SIGNAL(openService()),this,SLOT(openServiceFormValve()));  old style
    //    connect(
    //               &valve, &Valve::openServiceValve,
    //               this, &MainWindow::openServiceFormValve
    //               );
    //   connect(
    //                &pump, &Pump::openServicePump,
    //                this, &MainWindow::openServiceFormPump
    //                );



    // sender, &Sender::valueChanged,
    //     receiver, &Receiver::updateValue;



}

MainWindow::~MainWindow()
{
    saveSettings();
    delete ui;
}


void MainWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED (event);
    //qDebug() << "MainWindow::resizeEvent"  << size().height() << size().width();
    global.UIXresizeSize = size().width();
    global.UIYresizeSize = size().height() ;
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton) {
        qDebug() << "Main mousePressEvent MainWind" ;
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    event->accept();

    // get the cursor position of this event
    const QPoint& pos = event->pos();

    int dx =pos.x();
    int dy = pos.y();

    qDebug() << " Main mouseMoveEventdx:dy"<< dx <<dy ;
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event)

    if(initTimer){
        initTimer = false;
        // timerId = startTimer(1000);
        killTimer(timerId);
        //  timerId = startTimer(1000);

        // setShow2();
        // updateSettingForAll();
    }
    else{
        currentTime = QTime::currentTime().toString("hh:mm:ss");
        setWindowTitle(currentTime);
        // qDebug() << currentTime ;
        att += 1;

    }
}


void MainWindow::openServiceFormValve()
{

    //  Servicevalve *servicevalve = new Servicevalve(this,sender());
    //  qDebug() << "Main !! Open service form !!!" ;
    // Valve* valve = qobject_cast<Valve*>(sender());
    //  qDebug() << "Open service : " << valve->settings.name ;
    //  servicevalve->show();
}

void MainWindow::openServiceFormPump()
{
    //  qDebug() << "Main !! Open service form !!!" ;
    //  Servicepump *servicepump = new Servicepump(this,sender());

    //  Pump* pump = qobject_cast<Pump*>(sender());
    //  qDebug() << "Open service : " << pump->settings.name ;
    //  servicepump->show();

}

void MainWindow::openServiceFormPipe()
{

    qDebug() << "Main Open service pipe ??? : " ;
    //  WidgetService *widgetService = new WidgetService (this,global,sender());
    //  Pipe* pipe = qobject_cast<Pipe*>(sender());
    //  qDebug() << "Open service : " << pipe->settings.name ;
    //  widgetService->show();



}

void MainWindow::loadSettings()
{

    // QString settingsFile = global.settingsFileName;
    //  QSettings settings(settingsFile, QSettings::NativeFormat);
    // QString sText = settings.value("last_save", "").toString();
    //  qDebug() << "last_save " << sText ;

    // valve.loadSettings();
    // pump.loadSettings();


}

void MainWindow::saveSettings()
{

    QString settingsFile = global.settingsFileName;
    QSettings settings(settingsFile, QSettings::IniFormat);
    QString sText = settingsFile;



    settings.beginGroup("mainwindow");
    settings.setValue("settingsFile", global.appSwVers);
    settings.setValue("settingsFile", sText);

    QDateTime date = QDateTime::currentDateTime();
    sText = date.toString("dd.MM.yyyy hh:mm:ss");


    // sText = QTime::currentTime().toString("YY:MM:DD:hh:mm:ss");
    qDebug() << "QTime::currentTime:" << sText ;
    settings.setValue("last_save", sText);




    settings.setValue("UI_width", size().width());
    settings.setValue("UI_height", size().height());
    settings.endGroup();


}


void MainWindow::resizeAllKoef(float koef)
{

    // tvertne.setNewPosition(koef);
    // tvertne1.setNewPosition(koef);

    // mix.setNewPosition(koef);
    //
}

void MainWindow::updateSettingForAll()
{



}

void MainWindow::initUI()
{
    qDebug() << "start UI settings";
    this->move(1000,1000);
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::lightGray); //QColor(255, 0, 0, 127)
    //pal.setColor(QPalette::Window, QColor(242, 219, 238, 0.251));
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    QColor col = QColor(Qt::green);
    QString qss = QString("background-color: %1").arg(col.name());
    ui->pushButton_Stop->setStyleSheet(qss);

    pal.setColor(QPalette::Base,Qt::yellow);
    ui->textEdit_Field->setPalette(pal);

    // strādā   ui->label_logo->setStyleSheet("background-image: url(:/pictures/logo2.png)");
    QPixmap pixmap(":/pictures/logo2.png");
    ui->label_logo->setPixmap(pixmap);
    ui->label_logo->setMask(pixmap.mask());

    QString str = "Šaja laukā tiek attēloti tekošie notikumi un avārias situāciju apraksti.\n Piemēram:\n\n\n";
    str.append("10.01:23 Sistēma ieslēgta\n");
    str.append("10.02:25 ieslēdzās sapropeļa padeves vārsts V1\n");
    str.append("10.05:33 ieslēdzās sapropeļa padeves motors\n");
    str.append("10.07:43 ERROR ! vārsts V2 nav aizvēries\n");
    str.append("10.11:53 BRĪDINĀJUMS ! vārsta V4 aizversanas laiks 20s morma 12s\n");
    ui->textEdit_Field->setText(str);

    cmbList << "Iestatijumi" << "Receptes" << "Atskaites" << "Serviss"  << "Par_mani";
    ui->comboBox->addItems(cmbList);



}






void MainWindow::appendInfo(QString str, QColor col)
{
    ui->textEdit_Field->setTextColor(col);
    ui->textEdit_Field->append(str);
    ui->textEdit_Field->setTextColor(Qt::black);

    QTextCursor cursor = ui->textEdit_Field->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->textEdit_Field->setTextCursor(cursor);


}

void MainWindow::drawWidgets()
{
    qDebug() << "widData draw  " << global.widHash.size() << "elements";

    foreach (Global::wdataStruct widData, global.widHash){

        qDebug() << "drawWidgets Draw: " << widData.type << widData.name;
        switch (widData.type) {
            case WidgetType::widgT::Dyno:
             {
                Dyno *dynoA = new Dyno(global,widData.name,this);
                ui->horizontalLayout_ProcessFlow->addWidget(dynoA);
            }
        break;

        case WidgetType::widgT::Mix:
        {
            Mix *mixA = new Mix(global,widData.name,this);
            ui->horizontalLayout_ProcessFlow->addWidget(mixA);
        }
        break;

        case WidgetType::widgT::Pipe:
            {
                Pipe *pipeA = new Pipe(global,widData.name,this);
                ui->horizontalLayout_ProcessFlow->addWidget(pipeA);
            }
            break;

        case WidgetType::Pump:
        {
            Pump *pumpA = new Pump(global,widData.name,this);
            ui->horizontalLayout_ProcessFlow->addWidget(pumpA);

        }
        break;

        case WidgetType::Tvertne:
        {
            Tvertne *tvertneA = new Tvertne(global,widData.name,this);
            ui->horizontalLayout_ProcessFlow->addWidget(tvertneA);

        }
        break;

        case WidgetType::Valve:
        {
            Valve *valveA = new Valve(global,widData.name,this);
            ui->horizontalLayout_ProcessFlow->addWidget(valveA);

        }
        break;


        default:
            qDebug() << "Wrong widget type !!! "  <<widData.type;
            break;
        }


    }


}



void MainWindow::on_pushButton_Stop_clicked()
{
    qDebug() << "pushButton_EMERG_STOP_clicked() ????????????????????????????????????";
    QColor col = QColor(Qt::red);
    QString qss = QString("background-color: %1").arg(col.name());
    ui->pushButton_Stop->setStyleSheet(qss);


    qss = currentTime;
    qss.append("  PUSH EMERGENCY STOP !!!");
    appendInfo(qss,Qt::red);

}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    qDebug() << " Combo box index" << index << cmbList[index];
    // cmbList << "Iestatijumi" << "Receptes" << "Atskaites" << "Serviss"  << "Par_mani";

    switch (index) {
    case 0:

        break;
    case 1:

        break;
    case 2:

        break;
    case 3:

        break;
    case 4:

        break;
    default:
        break;
    }


}

