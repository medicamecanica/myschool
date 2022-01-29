#ifndef USERMODEL_H
#define USERMODEL_H

#include <QAbstractTableModel>
#include <QSqlTableModel>


const int COLS= 3;
const int ROWS= 2;
class UserModel : public QSqlTableModel
{
    Q_OBJECT
public:
     explicit UserModel(QObject * parent=0,QSqlDatabase db=QSqlDatabase()): QSqlTableModel(parent,db){
        this->setEditStrategy(QSqlTableModel::OnFieldChange);
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex & index) const ;
private:
    QString m_gridData[ROWS][COLS];  //holds text entered into QTableView
signals:
    void editCompleted(const QString &);
};

#endif // USERMODEL_H
