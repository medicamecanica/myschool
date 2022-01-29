#ifndef CHECKBOXDELEGATE_H
#define CHECKBOXDELEGATE_H

#include <QItemDelegate>



class CheckBoxDelegate : public QItemDelegate
{
public:

    explicit CheckBoxDelegate(QObject *parent,int checkboxCol);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QRect GetCheckboxRect(const QStyleOptionViewItem &option) const;
private:
    int checkboxCol;
};

#endif // CHECKBOXDELEGATE_H
