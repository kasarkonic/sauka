#ifndef SERVICEPUMP_H
#define SERVICEPUMP_H

#include <QMainWindow>
#include "pump.h"

namespace Ui {
class Servicepump;
}

class Servicepump : public QMainWindow
{
    Q_OBJECT

public:
    explicit Servicepump(QWidget *parent = nullptr, QObject *obj = nullptr);
    ~Servicepump();
    //void updateUIvalue();

protected:
    void    mousePressEvent(QMouseEvent *event) override;
    void    mouseMoveEvent (QMouseEvent *event) override;

private slots:

    void on_lineEdit_Name_editingFinished();

    void on_pushButton_EMERG_STOP_clicked();

    void on_pushButton_ON_clicked();

    void on_pushButton_OFF_clicked();

    void on_lineEdit_note_editingFinished();

    void on_pushButton_SAVE_clicked();

    void on_pushButton_CANCEL_clicked();

    void on_lineEdit_Xpos_editingFinished();

    void on_pushButton_Xposplus_clicked();

    //void on_pushButton_Xposminus_clicked(bool checked);

    void on_lineEdit_Ypos_editingFinished();

    void on_pushButton_YposPlus_clicked();

    void on_pushButton__YposMinus_clicked();

    void on_lineEditSize_editingFinished();

    void on_pushButton_SizePlus_clicked();

    void on_pushButton_SizeMinus_clicked();

    void on_lineEdit_Speed_editingFinished();

    void on_pushButton_SpeedPlus_clicked();

    void on_pushButton_SpeedMinus_clicked();

    void on_pushButton_Xposminus_clicked();

private:

    Ui::Servicepump *ui;
    void  applaySettings();
    QObject *obj;
    QString tmpString;

    Pump *pump;
    Pump *pump1;
    void updateUIvalue();
    int mouseStartPointX;
    int mouseStartPointY;

};

#endif // SERVICEPUMP_H
