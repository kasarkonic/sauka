#ifndef SERVICEWIDGET_H
#define SERVICEWIDGET_H

#include <QObject>
#include <QWidget>

class ServiceWidget : public QWidget
{
    Q_OBJECT
public:
    ServiceWidget(QWidget *parent = nullptr);
    virtual void updateSettings();
    //virtual void setNewPosition(float koef);
   // virtual void loadSettings();
   // virtual void saveSettings();
};

#endif // SERVICEWIDGET_H
