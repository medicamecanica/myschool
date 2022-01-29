#ifndef IMPORTGROUP_H
#define IMPORTGROUP_H

#include <QDataWidgetMapper>
#include <QDialog>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QxOrm.h>
namespace Ui {
class ImportGroup;
}

class ImportGroup : public QDialog
{
    Q_OBJECT

public:
    explicit ImportGroup(QWidget *parent = nullptr);
    ~ImportGroup();

private slots:
    void yearChanged(QString year);
    void simatChanged(QModelIndex row);
    void rechanged(QModelIndex row);
    void import(bool press);
    void remove(bool press);
    void schoolChanged(QString school_code);
private:
    Ui::ImportGroup *ui;
    QSqlDatabase m_db=qx::QxSqlDatabase::getSingleton()->getDatabase();
    QSqlTableModel *simatYearsModel;
    QSqlTableModel *schoolModel;
    QSqlTableModel *simatGroupsModel;
    QSqlTableModel *groupsYearModel;
    QDataWidgetMapper *mapperSimatGroup;
};

#endif // IMPORTGROUP_H
