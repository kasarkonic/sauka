#ifndef WIDGETS_LIST_H
#define WIDGETS_LIST_H


#include <QMainWindow>
#include <QObject>
#include <QVector>



class widgets_list
{
public:

    enum{
        valve,  // 0
        pipe,
        pipe1,
        pipe2,
        pipe3,
        pipe4,
        pipe5,
        pipe6,
        pump1,
        pump2,
        dyno,
        tvertne1,
        tvertne2,
        tvertne3,
        tvertne4,
        mix,

    };


    widgets_list();
    QVector<int> widgetArray = {};
private:
    void add( int npk ,QString name);
};

#endif // WIDGETS_LIST_H
