#ifndef SETUP_H
#define SETUP_H

#include <QDialog>
#include <QItemSelection>
#include <QSqlDatabase>
#include <QSqlRelationalTableModel>
#include <QSqlTableModel>
#include <QxOrm.h>
namespace Ui {
class Setup;
}

class Setup : public QDialog
{
    Q_OBJECT

public:
    explicit Setup(QWidget *parent = nullptr);
    ~Setup();


private slots:
    void saveArea();
    void newArea();
    void refreshArea();
    void deleteArea();
    void deleteSubject();
    void newSubject();
    void refreshSubject();
    void saveSubject();
    void saveSchema();
    void newSchema();
    void refreshSchema();
    void deleteSchema();
    void schemaSelectionChange(const QItemSelection &selection, const QItemSelection &);
    void newSchemaRange();
    void deleteSchemaRange();
    void schemaRangSelectionChange(const QItemSelection &selection, const QItemSelection &);
    void saveSchool();
    void deleteSchool();
    void refreshSchool();
    void newSchool();
    void saveUser();
    void deleteUser();
    void refreshUser();
    void newUser();
private:
    Ui::Setup *ui;
    QSqlDatabase m_db=qx::QxSqlDatabase::getSingleton()->getDatabase();
    QSqlRelationalTableModel *schoolModel;
    QSqlTableModel *areaModel;
    QSqlRelationalTableModel *subjectModel;
    QSqlTableModel *schemaModel;
    QSqlRelationalTableModel *schemaRangeModel;
     QSqlTableModel *userModel;

};

#endif // SETUP_H
