#ifndef MYTRIANGLE_H
#define MYTRIANGLE_H

#include <QObject>
#include <QWidget>



class MyTriangle : public QWidget
{
        Q_OBJECT
public:
    MyTriangle(QWidget *parent = nullptr);

    void    setColour(QColor col);
    void    setSize(int wSize,int orientation);      // 0,  90, 180, 270

protected:
    void    paintEvent(QPaintEvent *event);


private:
    QColor color = Qt::yellow;;
    int size = 120;
    int widgSize = 130;
    QPoint points[3];
    int orientation = 0;

};

#endif // MYTRIANGLE_H
