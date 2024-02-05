#ifndef HWLISTSFORM_H
#define HWLISTSFORM_H

#include <QMainWindow>
#include <QDialog>
#include <QTableView>
#include <QItemDelegate>
#include <QStandardItemModel>
#include "global.h"

namespace Ui {
class HWListsForm;
}

class HWListsForm : public QMainWindow//, public QDialog
{
    Q_OBJECT

public:
    explicit HWListsForm(Global &global, QWidget *parent = nullptr);

    Global &global;
    ~HWListsForm();


private:
    Ui::HWListsForm *ui;
    void initUI();
    QStandardItemModel *sensorTabModel;
};

#endif // HWLISTSFORM_H
