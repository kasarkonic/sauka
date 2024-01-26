#ifndef WIDGETSERVICE_H
#define WIDGETSERVICE_H

#include <QWidget>

#include"global.h"
#include "pipe.h"


namespace Ui {
class WidgetService;
}

class WidgetService : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetService(QWidget *parent = nullptr);//, QObject *obj = nullptr);
    ~WidgetService();
    void openWidgetServiceForm();
protected:
    void    mousePressEvent(QMouseEvent *event) override;
    void    mouseMoveEvent (QMouseEvent *event) override;
private:
   // Global &global;
    QObject obj;
    Ui::WidgetService *ui;
    Pipe pipe;

    void updateUIvalue();
    int mouseStartPointX;
    int mouseStartPointY;
    //void openWidgetServiceForm();
};



#endif // WIDGETSERVICE_H
