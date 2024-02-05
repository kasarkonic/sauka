#ifndef SENSORTABLEMODEL_H
#define SENSORTABLEMODEL_H

//#include <QAbstractItemModel>



//#include "qabstractitemmodel.h"
//#include "QAbstractTableModel.h"



#include <QObject>

class SensorTableModel // : public QAbstractTableModel
{
 //   Q_OBJECT
public:
    explicit SensorTableModel(QObject* parent = nullptr);

 //   int rowCount(const QModelIndex& parent = QModelIndex()) const;
 //   int columnCount(const QModelIndex& parent = QModelIndex()) const;
 //   QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
protected:

};

#endif // SENSORTABLEMODEL_H
