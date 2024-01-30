#ifndef WIDGETSERVICE_H
#define WIDGETSERVICE_H

#include <QWidget>

//#include"global.h"

#include "widgetDiagramElement.h"
#include <QMainWindow>



namespace Ui {
class WidgetService;
}

class WidgetService :  public  QWidget
{
    Q_OBJECT

public:
   // explicit WidgetService(WidgetDiagramElement::widDataStruct &wsettings, QWidget *parent = nullptr);
    explicit WidgetService(WidgetDiagramElement *widgetElement, QWidget *parent = nullptr);

    ~WidgetService();
    void openWidgetServiceForm();
     Ui::WidgetService *ui;
     void updateSettings();

protected:
    void    mousePressEvent(QMouseEvent *event) override;
    void    mouseMoveEvent (QMouseEvent *event) override;
    void    mouseDoubleClickEvent(QMouseEvent *event) override;
private slots:
    void on_pushButton_Xplus_clicked();

    void on_pushButton_Xminus_clicked();

    void on_pushButton_Yplus_clicked();

    void on_pushButton_Yminus_clicked();

    void on_pushButton_sizeplus_clicked();

    void on_pushButton_sizeMinus_clicked();

private:
  // WidgetDiagramElement::widDataStruct &wsettings;
   WidgetDiagramElement *widgetElement;
    // Global &global;
    QObject obj;
    //Ui::WidgetService *ui;
   // Pipe pipe;

    void updateUIvalue();
    int mouseStartPointX;
    int mouseStartPointY;
    //void updateSettings();
    void updateFormData();

};



#endif // WIDGETSERVICE_H
