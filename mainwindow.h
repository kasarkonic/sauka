#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "valve.h"
#include "pipe.h"
#include "pump.h"
#include "dyno.h"
#include "tvertne.h"
#include "mix.h"
#include <QSettings>
#include <QMainWindow>
#include <QStringList>
#include "global.h"
#include "widgetdata.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Global &global, QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    // void openServiceForm();

    void on_pushButton_Stop_clicked();

    void on_comboBox_currentIndexChanged(int index);

protected:
    void    resizeEvent(QResizeEvent* event) override;
    void    mousePressEvent(QMouseEvent *event) override;
    void    mouseMoveEvent (QMouseEvent *event) override;
    void    timerEvent(QTimerEvent *event) override;

private:

    Global &global;

    Ui::MainWindow *ui;

    WidgetData widgetData;

    Valve valve;
    Valve valve1;

    Pipe pipe;
    Pipe pipe1;
    Pipe pipe2;
    Pipe pipe3;
    Pipe pipe4;
    Pipe pipe5;


    Pump pump;
    Pump pump1;

    Dyno dyno;
    Tvertne tvertne;
    Tvertne tvertne1;

    Mix mix;

    int valveStyleAngle;
    int valveWidgSize;
    int valveStatus;
    int areaY;
    int areaX;

    void openServiceFormValve();
    void openServiceFormPump();
    void openServiceFormPipe();

    void loadSettings();
    void saveSettings();
    QString settingsFile;
    void setShow1();
    void setShow2();
    void resizeAllKoef(float koef);
    void updateSettingForAll();
    void initUI();
    int  timerId = 0;
    int att = 0;

    QString currentTime; // HH:mm:ss

    void appendInfo(QString str, QColor col);

    QStringList  cmbList;
    void drawWidgets();
    bool initTimer;


};


#endif // MAINWINDOW_H
