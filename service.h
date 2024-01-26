#ifndef SERVICE_H
#define SERVICE_H

#include <QMainWindow>
#include "valve.h"

namespace Ui {
class Service;
}

class Service : public QMainWindow
{
    Q_OBJECT

public:
    explicit Service(QWidget *parent = nullptr, QObject *obj = nullptr);
    ~Service();


private slots:
    void on_pushButton_Xposplus_clicked();

    void on_pushButton_Xposminus_clicked(bool checked);

    void on_pushButton_YposPlus_clicked();

    void on_pushButton__YposMinus_clicked();

    void on_pushButton_XsizePlus_clicked();

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

private:
    Ui::Service *ui;
  void  applaySettings();
  void  saveSettings();
  QObject *obj;
  QString tmpString;
  Valve valve;

};

#endif // SERVICE_H
