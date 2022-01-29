#ifndef RADIODELEGATE_H
#define RADIODELEGATE_H

#include <QButtonGroup>
#include <QItemDelegate>



class RadioDelegate : public QItemDelegate
{
public:

    explicit RadioDelegate(QObject *parent,int radioCol);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QRect GetRadioRect(const QStyleOptionViewItem &option) const;
private:
    int radioCol;
    QButtonGroup *group;
};

#endif // RADIODELEGATE_H
