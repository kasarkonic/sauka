#ifndef SERVICEVALVE_H
#define SERVICEVALVE_H

#include <QMainWindow>
#include "valve.h"

namespace Ui {
class Servicevalve;
}

class Servicevalve : public QMainWindow
{
    Q_OBJECT

public:
    explicit Servicevalve(QWidget *parent = nullptr, QObject *obj = nullptr);
    ~Servicevalve();


private slots:
    void on_pushButton_Xposplus_clicked();

    void on_pushButton_YposPlus_clicked();

    void on_pushButton__YposMinus_clicked();

    //void on_pushButton_XsizePlus_clicked();

    void on_lineEdit_Xpos_editingFinished();

    void on_lineEdit_Ypos_editingFinished();

    void on_lineEdit_Xsize_editingFinished();

    void on_lineEdit_Ysize_editingFinished();

    void on_pushButton_STOP_clicked();

    void on_pushButton_SAVE_clicked();

    void on_pushButton_CANCEL_clicked();

    void on_pushButton_ON_clicked();

    void on_pushButton_OFF_clicked();

    void on_lineEdit_Name_editingFinished();

    void on_pushButton_Xposminus_clicked();

private:
  Ui::Servicevalve *ui;
  void  applaySettings();
  QObject *obj;
  QString tmpString;

  Valve *valve;

};

#endif // SERVICEVALVE_H
