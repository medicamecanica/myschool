#include "checkboxdelegate.h"

#include <QCheckBox>
#include <QApplication>
#include <QStyledItemDelegate>
#include <QButtonGroup>
CheckBoxDelegate::CheckBoxDelegate(QObject *parent,int checkboxCol)
    : QItemDelegate(parent)
{
    this->checkboxCol=checkboxCol;
}

QWidget *CheckBoxDelegate::createEditor(QWidget *parent,
                                        const QStyleOptionViewItem &option,
                                        const QModelIndex &index) const
{
    if(index.isValid() && index.column() == checkboxCol)
    {
        QCheckBox *editor = new QCheckBox(parent);
        editor->installEventFilter(const_cast<CheckBoxDelegate*>(this));
        return editor;
    }
    else
    {
        return QItemDelegate::createEditor(parent, option, index);
    }
}

void CheckBoxDelegate::setEditorData(QWidget *editor,
                                     const QModelIndex &index) const
{
    if(index.isValid() && index.column() == checkboxCol)
    {
        QString value = index.model()->data(index, Qt::DisplayRole).toString();

        QCheckBox *checkBox = static_cast<QCheckBox*>(editor);
        if(value == 1)
            checkBox->setCheckState(Qt::Checked);
        else
            checkBox->setCheckState(Qt::Unchecked);
    }
    else
    {
        QItemDelegate::setEditorData(editor, index);
    }
}

void CheckBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                    const QModelIndex &index) const
{
    if(index.isValid() && index.column() == checkboxCol)
    {
        QCheckBox *checkBox = static_cast<QCheckBox*>(editor);
        int value;
        if(checkBox->checkState() == Qt::Checked)
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

void CheckBoxDelegate::updateEditorGeometry(QWidget *editor,
                                            const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.isValid() && index.column() == checkboxCol)
        editor->setGeometry(option.rect);
    else
        QItemDelegate::updateEditorGeometry(editor, option, index);

}
void CheckBoxDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                             const QModelIndex &index) const
{
    //if (index.data().canConvert<QCheckBox>()) {
        // QCheckBox *checkBox = static_cast<QCheckBox*>(par->);
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

        QApplication::style()->drawControl(QStyle::CE_CheckBox, &cbOpt, painter);

   // } else {
        //QItemDelegate ::paint(painter, option, index);
    //}

}
QRect CheckBoxDelegate::GetCheckboxRect(const QStyleOptionViewItem &option)const
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
