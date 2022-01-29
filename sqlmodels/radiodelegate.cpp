#include "radiodelegate.h"

#include <QRadioButton>
#include <QApplication>
#include <QStyledItemDelegate>
RadioDelegate::RadioDelegate(QObject *parent,int radioCol)
    : QItemDelegate(parent)
{
    this->radioCol=radioCol;
    this->group=new QButtonGroup(this);
    this->group->setExclusive(true);
}

QWidget *RadioDelegate::createEditor(QWidget *parent,
                                        const QStyleOptionViewItem &option,
                                        const QModelIndex &index) const
{
    if(index.isValid() && index.column() == radioCol)
    {
        QRadioButton *editor = new QRadioButton(parent->parentWidget());
        editor->installEventFilter(const_cast<RadioDelegate*>(this));
        this->group->addButton(editor,index.row());
        return editor;
    }
    else
    {
        return QItemDelegate::createEditor(parent, option, index);
    }
}

void RadioDelegate::setEditorData(QWidget *editor,
                                     const QModelIndex &index) const
{
    if(index.isValid() && index.column() == radioCol)
    {
        QString value = index.model()->data(index, Qt::DisplayRole).toString();

        QRadioButton *radio = static_cast<QRadioButton*>(editor);


            radio->setChecked(value == 1);

    }
    else
    {
        QItemDelegate::setEditorData(editor, index);
    }
}

void RadioDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                    const QModelIndex &index) const
{
    if(index.isValid() && index.column() == radioCol)
    {
        QRadioButton *radio = static_cast<QRadioButton*>(editor);
        int value;
        if(radio->isChecked())
            value = 1;
        else
            value = 0;

        model->setData(index, value);
    }
    else
    {
        QItemDelegate::setModelData(editor, model, index);
    }
}

void RadioDelegate::updateEditorGeometry(QWidget *editor,
                                            const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.isValid() && index.column() == radioCol)
        editor->setGeometry(option.rect);
    else
        QItemDelegate::updateEditorGeometry(editor, option, index);

}
void RadioDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                             const QModelIndex &index) const
{
    //if (index.data().canConvert<QRadio>()) {
        // QRadio *radio = static_cast<QRadio*>(par->);
        QStyleOptionButton cbOpt;
        cbOpt.rect = option.rect;

        bool isChecked = index.data().toInt()==1;
        if (isChecked)
        {
            cbOpt.state |= QStyle::State_On;
        }
        else
        {
            cbOpt.state |= QStyle::State_Off;
        }

        QVariant enabled = index.data(Qt::ItemIsEnabled);
        if(enabled.isNull() || enabled.toBool() )
        {
            cbOpt.state |= QStyle::State_Enabled;
        }

        QApplication::style()->drawControl(QStyle::CE_RadioButton, &cbOpt, painter);

   // } else {
        //QItemDelegate ::paint(painter, option, index);
    //}

}
QRect RadioDelegate::GetRadioRect(const QStyleOptionViewItem &option)const
   {
       QStyleOptionButton opt_button;
       opt_button.QStyleOption::operator=(option);
       QRect sz = QApplication::style()->subElementRect(QStyle::SE_ViewItemCheckIndicator, &opt_button);
       QRect r = option.rect;
       // center 'sz' within 'r'
       int dx = (r.width() - sz.width())/2;
       int dy = (r.height()- sz.height())/2;
       r.setTopLeft(r.topLeft() + QPoint(dx,dy));
       r.setWidth(sz.width());
       r.setHeight(sz.height());

       return r;
   }
