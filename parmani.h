#ifndef PARMANI_H
#define PARMANI_H

#include "dyno.h"
#include <QMainWindow>

namespace Ui {
class ParMani;
}

class ParMani : public QMainWindow
{
    Q_OBJECT

public:
    explicit ParMani(Global &global, QWidget *parent = nullptr);
    Global &global;
    ~ParMani();

private slots:
    void on_pushButtonExit_clicked();
protected:
    void    timerEvent(QTimerEvent *event) override;
private:
    Ui::ParMani *ui;
    Dyno *dynoA;
    int timerId;
    int att;
    int attX = 1;
    int attY = 1;
    int currX = 0;
    int currY = 0;
};

#endif // PARMANI_H
