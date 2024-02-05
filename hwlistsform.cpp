#include "hwlistsform.h"
#include "qlineedit.h"
#include "ui_hwlistsform.h"
#include <QFormLayout>
#include <QLabel>
#include <QGroupBox>
#include <QPushButton>


HWListsForm::HWListsForm(Global &global, QWidget *parent)
    : QMainWindow(parent)
    , global(global)
    , ui(new Ui::HWListsForm)

{

    ui->setupUi(this);

    sensorTabModel = new QStandardItemModel(1,1);   //row,col


    sensorTabModel->setColumnCount(6);
    sensorTabModel->setRowCount(30);
    sensorTabModel->horizontalHeaderItem(7);

    sensorTabModel->setHeaderData(0,Qt::Horizontal," Adrese");
    sensorTabModel->setHeaderData(1,Qt::Horizontal," Nosaukums");
    sensorTabModel->setHeaderData(2,Qt::Horizontal," Tips");
    sensorTabModel->setHeaderData(3,Qt::Horizontal," Vērtība DI");
    sensorTabModel->setHeaderData(4,Qt::Horizontal," Vērtība AI");
    sensorTabModel->setHeaderData(5,Qt::Horizontal," Mainīt DI");
    sensorTabModel->setHeaderData(7,Qt::Horizontal," Mainīt AI");

    ui->tableView->setModel(sensorTabModel);

    QLineEdit *lineEdit = new QLineEdit();
    QPushButton *butt = new QPushButton();

    ui->tableView->setIndexWidget(sensorTabModel->index(0,0),butt);
    ui->tableView->setIndexWidget(sensorTabModel->index(1,1),lineEdit);

   // ui->tableView->setModel(sensorTabModel);
    initUI();
}

HWListsForm::~HWListsForm()
{
    delete ui;
}




void HWListsForm::initUI()
{

//  for testing

    for(int row = 0; row < 4; row++)
    {
        for(int col = 0; col < 2; col++)
        {
            QModelIndex index = sensorTabModel->index(row,col,QModelIndex());
            // 0 for all data
            sensorTabModel->setData(index, col+1 + row+1);
        }
    }


}
