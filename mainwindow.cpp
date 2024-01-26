#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <Qdebug>

#include <QFile>
#include "servicevalve.h"
#include "servicepump.h"
#include "widgetService.h"
#include <QMouseEvent>
#include "global.h"
#include <QDateTime>



MainWindow::MainWindow(Global &global,  QWidget *parent)
    : QMainWindow(parent)
    , global(global)
    , ui(new Ui::MainWindow)
    ,  widgetData(global)


{ 
    ui->setupUi(this);


    QString settingsFile = QApplication::applicationDirPath() + "/settings.ini";
    global.settingsFileName =  settingsFile;

    QSettings settings(settingsFile, QSettings::IniFormat);
    qDebug() << "settingsFile" << settingsFile << global.settingsFileName;

    //IntegerSetting = settings.value("SettingName", default).toInt();
    // BooleanSetting = settings.value("SettingName", default).toBool();


    areaY = size().height();
    areaX = size().width();
    qDebug() << "area Width" << areaX <<":" << areaY;

   // initUI();
    drawWidgets();

    initTimer = true;
   // timerId = startTimer(100);


    // connect(&valve,SIGNAL(openService()),this,SLOT(openServiceFormValve()));  old style
    connect(
                &valve, &Valve::openServiceValve,
                this, &MainWindow::openServiceFormValve
                );
    connect(
                &pump, &Pump::openServicePump,
                this, &MainWindow::openServiceFormPump
                );


   // connect(
    //    &pipe, &Pipe::openServicePipe,
   //     &widgetService, &WidgetService::openWidgetServiceForm
   //     );


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

    float koefx = 1.0;
    float koefy = 1.0;
    float koef = 1.0;

    // qDebug() << "resizeEvent"  << size().height() << size().width();

    if(size().width() > 0 && size().height() > 0)
    {
        koefx =  ((float)areaX/size().width());
        koefy = ((float)areaY/size().height());
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
    qDebug() << "resizeEvent X=" << size().width() << "Y=" <<  size().height() << "koef= " << koef;

    if(areaY/20 >= areaX/30){
        minWidgSize = areaX/30;   // minWidth
    }
    {
        minWidgSize = areaY/20; // minHeight
    }

    if(minWidgSize < 15)
        minWidgSize = 15;

    global.zoomKoef = koef;
    resizeAllKoef(koef);
    //int data;
    // pipe.get( &data );
    // qDebug() << "pipe.get( &data );" << data  ;
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
    qDebug() << "Main att" << att ;
    if(att%10 == 0){
        //setShow1();
        // pump.settings.rotate = 0;//1
        // pump.updateSettings();
    }
    if(att%10 == 5){
       // setShow2();
        // pump.settings.rotate =1;//1
        // pump.updateSettings();
    }
}
}


void MainWindow::openServiceFormValve()
{

    Servicevalve *servicevalve = new Servicevalve(this,sender());
    qDebug() << "Main !! Open service form !!!" ;
    Valve* valve = qobject_cast<Valve*>(sender());
    qDebug() << "Open service : " << valve->settings.name ;
    servicevalve->show();
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

void MainWindow::setShow1()
{
qDebug() << "setShow1\n" ;


    updateSettingForAll();

    QString str = currentTime;
    str.append("Maisītājs tiek pieslēgts 1. tvertnei\n");
    appendInfo(str,Qt::black);

    //float koef = 0.771094;
    //resizeAllKoef(int koef)

}

void MainWindow::setShow2()
{

qDebug() << "setShow2\n" ;
    valve.settings.status = ValveStatus::Close;//ValveStatus::OpenAC;
    valve1.settings.status = ValveStatus::OpenAC;//ValveStatus::Close;

    updateSettingForAll();

    QString str = currentTime;
    str.append(" Maisītājs tiek pieslēgts 2. tvertnei\n");
    appendInfo(str,Qt::black);

    // float koef = 0.771094;
    resizeAllKoef(global.zoomKoef);
}

void MainWindow::resizeAllKoef(float koef)
{

    tvertne.setNewPosition(koef);
    tvertne1.setNewPosition(koef);

    mix.setNewPosition(koef);

}

void MainWindow::updateSettingForAll()
{


  //  ServiceWidget* serviceWidget2 = &pump1;
  //  serviceWidget2->updateSettings();

 //   serviceWidget2->setNewPosition(1.1);

    //serviceWidget2->loadSettings();
    //serviceWidget2->loadSettings();






    dyno.updateSettings();

    tvertne.updateSettings();
    tvertne1.updateSettings();

    mix.updateSettings();

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





   ui->horizontalLayout_ProcessFlow->addWidget(&valve);
   ui->horizontalLayout_ProcessFlow->addWidget(&valve1);
   ui->horizontalLayout_ProcessFlow->addWidget(&pipe);
   ui->horizontalLayout_ProcessFlow->addWidget(&pipe1);
   ui->horizontalLayout_ProcessFlow->addWidget(&pipe2);
   ui->horizontalLayout_ProcessFlow->addWidget(&pipe3);
   ui->horizontalLayout_ProcessFlow->addWidget(&pipe4);
   ui->horizontalLayout_ProcessFlow->addWidget(&pipe5);
   ui->horizontalLayout_ProcessFlow->addWidget(&pump);
   ui->horizontalLayout_ProcessFlow->addWidget(&pump1);
   ui->horizontalLayout_ProcessFlow->addWidget(&dyno);
   ui->horizontalLayout_ProcessFlow->addWidget(&tvertne);
   ui->horizontalLayout_ProcessFlow->addWidget(&tvertne1);
   ui->horizontalLayout_ProcessFlow->addWidget(&mix);

    loadSettings();
    resizeAllKoef(1.0);
    updateSettingForAll();



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
    qDebug() << "widData draw  " << global.widData.size() << "elements";

//    << global.widData[0].type<< global.widData[1].type;

        foreach (WidgetData::dataStruct widData, global.widData){

            qDebug() << "widData Draw: " << widData.type;
            switch (widData.type) {
            case WidgetType::widgT::Dyno:
            {
                Dyno *dynoA = new Dyno(this);
                dynoA->settings.startX = widData.startX;
                dynoA->settings.startY = widData.startY;
                dynoA->settings.startSize = widData.startsize;
                ui->horizontalLayout_ProcessFlow->addWidget(dynoA);
               // dynoA->setNewPosition(global.zoomKoef);

            }
                break;

            case WidgetType::widgT::Mix:
            {
                Mix *mixA = new Mix(this);
                mixA->settings.startX = widData.startX;
                mixA->settings.startY = widData.startY;
                mixA->settings.startSize = widData.startsize;
                ui->horizontalLayout_ProcessFlow->addWidget(mixA);
               // mixA->setNewPosition(global.zoomKoef);
            }
                break;

            case WidgetType::widgT::Pipe:

                {
                Pipe *pipeA = new Pipe(this);


                pipeA->settings.startX = widData.startX;
                pipeA->settings.startY = widData.startY;
                pipeA->settings.angle = widData.startsize;
                ui->horizontalLayout_ProcessFlow->addWidget(pipeA);
               // pipeA->setNewPosition(global.zoomKoef);

            }
                break;

            case WidgetType::Pump:
            {
                Pump *pumpA = new Pump(this);
                pumpA->settings.startX = widData.startX;
                pumpA->settings.startY = widData.startY;
                pumpA->settings.startSize = widData.startsize;
                ui->horizontalLayout_ProcessFlow->addWidget(pumpA);
                pumpA->setNewPosition(global.zoomKoef);
            }
                break;

            case WidgetType::Tvertne:
            {
                Tvertne *tvertneA = new Tvertne(this);
                tvertneA->settings.startX = widData.startX;
                tvertneA->settings.startY = widData.startY;
                tvertneA->settings.startSize = widData.startsize;
                ui->horizontalLayout_ProcessFlow->addWidget(tvertneA);
               // tvertneA->setNewPosition(global.zoomKoef);
            }
                break;

            case WidgetType::Valve:
            {
                Valve *valveA = new Valve(this);
                valveA->settings.startX = widData.startX;
                valveA->settings.startY = widData.startY;
                valveA->settings.startSize = widData.startsize;
                ui->horizontalLayout_ProcessFlow->addWidget(valveA);
                valveA->setNewPosition(global.zoomKoef);
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

