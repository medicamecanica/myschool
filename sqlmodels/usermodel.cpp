#include "usermodel.h"




//-----------------------------------------------------------------
int UserModel::rowCount(const QModelIndex & /*parent*/) const
{
    return ROWS;
}

//-----------------------------------------------------------------
int UserModel::columnCount(const QModelIndex & /*parent*/) const
{
    return COLS;
}

//-----------------------------------------------------------------
QVariant UserModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        return m_gridData[index.row()][index.column()];
    }
    return QVariant();
}

//-----------------------------------------------------------------
//! [quoting mymodel_e]
bool UserModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
    if (role == Qt::EditRole)
    {
        //save value from editor to member m_gridData
        m_gridData[index.row()][index.column()] = value.toString();
    //for presentation purposes only: build and emit a joined string
    QString result;
    for(int row= 0; row < ROWS; row++)
    {
            for(int col= 0; col < COLS; col++)
        {
            result += m_gridData[row][col] + " ";
        }
        }
        emit editCompleted( result );
    }
    return true;
}
//! [quoting mymodel_e]

//-----------------------------------------------------------------
//! [quoting mymodel_f]
Qt::ItemFlags UserModel::flags(const QModelIndex & /*index*/) const
{
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled ;
}
