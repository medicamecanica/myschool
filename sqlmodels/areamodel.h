#ifndef MODELAREA_H
#define MODELAREA_H

#include <QSqlTableModel>
#include <QDebug>
#define AREA_COLUMN_ACTIVE 3
class AreaModel : public QSqlTableModel
{
    Q_OBJECT
public:
    //explicit AreaModel(QObject *parent = 0);
    explicit AreaModel(QObject * parent=0,QSqlDatabase db=QSqlDatabase()): QSqlTableModel(parent,db){
        this->setEditStrategy(QSqlTableModel::OnFieldChange);
    };


private:
    Qt::ItemFlags flags(const QModelIndex& idx) const
    {
        Qt::ItemFlags result = QSqlTableModel::flags(idx);
           if (idx.column() == AREA_COLUMN_ACTIVE) {
               result |= Qt::ItemIsUserCheckable;
           }
           return result;
    }

    bool setData(const QModelIndex& idx,const QVariant& value,int role)
    {
        if (idx.column() == AREA_COLUMN_ACTIVE)
            {
                QVariant data = value.toInt() == 2? QVariant(true) : QVariant(false);
                return QSqlQueryModel::setData(idx, data, Qt::EditRole);
            }
        qDebug()<< role;
        if(idx.row() < 0 || idx.row() >= rowCount() || idx.column() < 0 || idx.column() >= columnCount())
            return false;
        QVariant v;
        if(role == Qt::CheckStateRole && idx.column() == AREA_COLUMN_ACTIVE){
            qDebug()<< value;
            v = (value== Qt::Checked ? 1 : 0);
        }else
            v=value;
        bool r= QSqlTableModel::setData(idx,0,Qt::EditRole);
        // qDebug() << (r ? "Y":"N"); //Always returns "false" for checkbox column. Why? How do I fix this?
        return r;
    }
    QVariant data(const QModelIndex &index, int role) const
    {
        if( index.column() == AREA_COLUMN_ACTIVE && role == Qt::CheckStateRole )
            {
                if (role == Qt::CheckStateRole)
                {
                    return index.data(Qt::EditRole).toBool() ? QVariant(Qt::Checked) : QVariant(Qt::Unchecked);
                }
            }
            return QSqlQueryModel::data(index, role);
    }
};

#endif // MODELAREA_H
