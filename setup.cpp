#include "setup.h"
#include "ui_setup.h"
#include <QSqlRelationalDelegate>
#include <QSqlTableModel>
#include <QCloseEvent>
#include <sqlmodels/areamodel.h>
#include <sqlmodels/checkboxdelegate.h>
#include <sqlmodels/radiodelegate.h>
#include <QMessageBox>
#include <QMessageBox>
#include <QVBoxLayout>
#include "userconnection.h"
Setup::Setup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setup)
{
    ui->setupUi(this);
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(new UserConnection(this));
    ui->tab_6->setLayout(mainLayout);
    //school
    schoolModel= new   QSqlRelationalTableModel(this,m_db);
    schoolModel->setTable("c_school");
    schoolModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
     schoolModel->setJoinMode(QSqlRelationalTableModel::LeftJoin);
    schoolModel->setRelation(4, QSqlRelation("c_school", "rowid", "name"));

    ui->tableSchool->setModel(schoolModel);
    ui->tableSchool->setItemDelegateForColumn(4,new QSqlRelationalDelegate(this));
    //ui->tableSchool->setItemDelegateForColumn(5, new CheckBoxDelegate(ui->tableSchool,5));
    ui->tableSchool->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableSchool->setAlternatingRowColors(true);
    ui->tableSchool->hideColumn(0);
    schoolModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Codigo"));
    schoolModel->setHeaderData(2, Qt::Horizontal, QObject::tr("DANE"));
    schoolModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Nombre"));
    schoolModel->setHeaderData(4, Qt::Horizontal, QObject::tr("Sede Principal"));
   // schoolModel->setHeaderData(5, Qt::Horizontal, QObject::tr("Activa"));
    ui->tableSchool->show();

    schoolModel->select();
     qDebug()<<schoolModel->query().lastQuery();
     qDebug()<<schoolModel->query().lastError();
    qDebug()<<schoolModel->lastError().text();
    //area
    areaModel= new  QSqlTableModel(this,m_db);
    areaModel->setTable("c_area");

    ui->tableArea->setModel(areaModel);
    ui->tableArea->setItemDelegateForColumn(3, new CheckBoxDelegate(ui->tableArea,3));
    ui->tableArea->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableArea->setAlternatingRowColors(true);
    ui->tableArea->hideColumn(0);
    areaModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    areaModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Codigo"));
    areaModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Nombre"));
    areaModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Activa"));
    ui->tableArea->show();
    areaModel->select();
    //subject
    subjectModel= new   QSqlRelationalTableModel(this,m_db);
    subjectModel->setTable("c_subject");
    subjectModel->setRelation(4, QSqlRelation("c_area", "rowid", "label"));

    ui->tableSubject->setModel(subjectModel);
    ui->tableSubject->setItemDelegate(new QSqlRelationalDelegate(this));
    ui->tableSubject->setItemDelegateForColumn(5, new CheckBoxDelegate(ui->tableSubject,5));
    ui->tableSubject->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableSubject->setAlternatingRowColors(true);
    ui->tableSubject->hideColumn(0);
    subjectModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Codigo"));
    subjectModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Nombre"));
    subjectModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Horas"));
    subjectModel->setHeaderData(4, Qt::Horizontal, QObject::tr("Area"));
    subjectModel->setHeaderData(5, Qt::Horizontal, QObject::tr("Activa"));
    ui->tableSubject->show();
    subjectModel->select();

    //schema and schema range
    schemaRangeModel= new   QSqlRelationalTableModel(this,m_db);
    schemaRangeModel->setTable("c_schema_range");
    schemaRangeModel->setRelation(1, QSqlRelation("c_schema", "rowid", "code"));

    ui->tableSchemaRange ->setModel(schemaRangeModel);
    ui->tableSchemaRange->setItemDelegate(new QSqlRelationalDelegate(this));
    //ui->tableSchemaRange->setItemDelegateForColumn(5, new CheckBoxDelegate(ui->tableSchemaRange,5));
    ui->tableSchemaRange->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableSchemaRange->setAlternatingRowColors(true);
    ui->tableSchemaRange->hideColumn(0);
     ui->tableSchemaRange->hideColumn(1);
     schemaRangeModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    schemaRangeModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Esquema"));
    schemaRangeModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Min"));
    schemaRangeModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Max"));
    schemaRangeModel->setHeaderData(4, Qt::Horizontal, QObject::tr("Etiqueta"));
    //schemaRangeModel->setHeaderData(5, Qt::Horizontal, QObject::tr("Activo"));
    ui->tableSchemaRange->show();
    schemaRangeModel->setFilter("fk_schema=0");
    schemaRangeModel->select();


    //schema range
    schemaModel=schemaRangeModel->relationModel(1);
    //schemaModel= new  QSqlTableModel(this,m_db);
    //schemaModel->setTable("c_schema");

    ui->tableSchema->setModel(schemaModel);
    ui->tableSchema->setItemDelegateForColumn(5, new CheckBoxDelegate(ui->tableSchema,5));
    ui->tableSchema->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableSchema->setAlternatingRowColors(true);
    ui->tableSchema->hideColumn(0);

    schemaModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    schemaModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Codigo"));
    schemaModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Min"));
    schemaModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Max"));
    schemaModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Dscripción"));
    schemaModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Activo"));
    connect(ui->tableSchema->selectionModel(), SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)),
            SLOT(schemaSelectionChange(const QItemSelection &, const QItemSelection &))
            );
    connect(ui->tableSchemaRange->selectionModel(), SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)),
            SLOT(schemaRangSelectionChange(const QItemSelection &, const QItemSelection &))
            );
    ui->tableSchema->show();
    //schemaModel->setFilter("active=1");
    schemaModel->select();
    ui->btnSchema_new->setEnabled(false);
    ui->btnSchema_del->setEnabled(false);

    userModel= new  QSqlTableModel(this,m_db);
    userModel->setTable("user");

    ui->tableUser->setModel(userModel);
    ui->tableUser->setItemDelegateForColumn(6, new RadioDelegate(ui->tableUser,6));
    ui->tableUser->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableUser->setAlternatingRowColors(true);
    ui->tableUser->hideColumn(0);
    userModel->select();

}
void Setup::schemaSelectionChange(const QItemSelection &selection, const QItemSelection &)
{
    int id=0;
    if(selection.size()>0){
        const  QModelIndex item=selection.indexes().first();
        id=item.sibling(item.row(),0).data().toInt();
    }
    schemaRangeModel->setFilter("fk_schema="+QString::number(id));
    schemaRangeModel->select();
    ui->btnSchema_new->setEnabled(id>0);
    ui->btnSchema_del->setEnabled(id>0);
}
void Setup::schemaRangSelectionChange(const QItemSelection &selection, const QItemSelection &)
{
    int id=0;
    if(selection.size()>0){
        const  QModelIndex item=selection.indexes().first();
        id=item.sibling(item.row(),0).data().toInt();
    }
    //schemaRangeModel->setFilter("fk_schema="+QString::number(id));
    //schemaRangeModel->select();
    ui->btnSchema_new_2->setEnabled(id!=0);
    ui->btnSchema_del_2->setEnabled(id!=0);
}
void Setup::saveSchool()
{
    schoolModel->submitAll();
     qDebug()<<schoolModel->lastError().text();
    schoolModel->select();
}
void Setup::refreshSchool()
{
    schoolModel->revertAll();
    schoolModel->select();
}
void Setup::newSchool()
{
    int row = schoolModel->rowCount();
    schoolModel->insertRow(row);
    qDebug()<<schoolModel->lastError().text();
     qDebug()<<"new";
}
void Setup::deleteSchool()
{
    QModelIndexList indices = ui->tableSchool->selectionModel()->selectedRows();

    for (int i=indices.count()-1; i>=0; --i)
    {
        QModelIndex index = indices.at(i);
        schoolModel->removeRow(index.row());
        ui->tableSchool->model()->setData(index,QBrush( QColor().blue()), Qt::DisplayRole);
    }
}
void Setup::saveArea()
{
    areaModel->submitAll();
    areaModel->select();
}
void Setup::refreshArea()
{
    areaModel->revertAll();
    areaModel->select();
}
void Setup::newArea()
{
    int row = areaModel->rowCount();
    areaModel->insertRow(row);
    areaModel->setData(areaModel->index(row, 3), true);
}
void Setup::deleteArea()
{
    QModelIndexList indices = ui->tableArea->selectionModel()->selectedRows();

    for (int i=indices.count()-1; i>=0; --i)
    {
        QModelIndex index = indices.at(i);
        areaModel->removeRow(index.row());
        ui->tableArea->model()->setData(index,QBrush( QColor().blue()), Qt::DisplayRole);
    }
}
void Setup::saveSubject()
{
    subjectModel->submitAll();
    if(subjectModel->lastError().isValid())
        QMessageBox::critical(this,"Error",subjectModel->lastError().text());
    subjectModel->select();
}
void Setup::refreshSubject()
{
    subjectModel->revertAll();
    subjectModel->select();
}
void Setup::newSubject()
{
    int row = subjectModel->rowCount();
    subjectModel->insertRow(row);
    //subjectModel->()
    subjectModel->setData(subjectModel->index(row, 5), true);
    subjectModel->setData(subjectModel->index(row, 1), "",Qt::EditRole);
    QSqlRecord rec = subjectModel->record(row);
    //rec.setGenerated("rowid", false);
    rec.setValue("active",true);
    ui->tableSubject->setCurrentIndex(subjectModel->index(row,1));

    subjectModel->insertRecord(row,rec);

}
void Setup::deleteSubject()
{
    QModelIndexList indices = ui->tableSubject->selectionModel()->selectedRows();

    for (int i=indices.count()-1; i>=0; --i)
    {
        QModelIndex index = indices.at(i);

        subjectModel->removeRow(index.row());
    }
}
void Setup::refreshSchema()
{
    schemaModel->revertAll();
    schemaModel->select();
    schemaRangeModel->revertAll();
       schemaRangeModel->setFilter("fk_schema=0");
    schemaRangeModel->select();
}
void Setup::newSchema()
{
    int row = schemaModel->rowCount();
    schemaModel->insertRow(-1);
    //subjectModel->()
    //schemaModel->setData(schemaModel->index(row, 5), true);
    //schemaModel->setData(schemaModel->index(row, 1), "",Qt::EditRole);
    QSqlRecord rec = schemaModel->record(row);
    //rec.setGenerated("rowid", false);
    rec.setValue("active",true);
    ui->tableSchema->setCurrentIndex(schemaModel->index(row,1));

    schemaModel->insertRecord(row,rec);

}
void Setup::deleteSchema()
{
    QModelIndexList indices = ui->tableSchema->selectionModel()->selectedRows();

    for (int i=indices.count()-1; i>=0; --i)
    {
        QModelIndex index = indices.at(i);
        schemaModel->removeRow(index.row());
    }
}
void Setup::newSchemaRange()
{
    const QModelIndex item = ui->tableSchema->selectionModel()->selectedRows().first();
    int id=item.sibling(item.row(),0).data().toInt();
    int row = schemaRangeModel->rowCount();
    schemaRangeModel->insertRow(row);

    schemaRangeModel->setData(schemaRangeModel->index(row, 1),id,Qt::EditRole);
    QSqlRecord rec = schemaRangeModel->record(row);

    rec.setValue("fk_schema",id);
    ui->tableSchemaRange->setCurrentIndex(schemaRangeModel->index(row,1));
}
void Setup::deleteSchemaRange()
{
    QModelIndexList indices = ui->tableSchemaRange->selectionModel()->selectedRows();

    for (int i=indices.count()-1; i>=0; --i)
    {
        QModelIndex index = indices.at(i);
        schemaRangeModel->removeRow(index.row());
    }
}
void Setup::saveSchema()
{
  QModelIndexList indices = ui->tableSchema->selectionModel()->selectedRows();


    schemaRangeModel->submitAll();
    //QMessageBox::critical(this,"Error",schemaRangeModel->lastError().text());
    if(schemaRangeModel->lastError().isValid())
        QMessageBox::critical(this,"Error",schemaRangeModel->lastError().text());
    else{
        schemaModel->submitAll();
        if(schemaModel->lastError().isValid())
            QMessageBox::critical(this,"Error",schemaModel->lastError().text());
        else {
             schemaRangeModel->setFilter("fk_schema=0");
            schemaRangeModel->select();
             schemaModel->select();
              if(indices.count()>0 && schemaModel->rowCount()>indices.first().row())
              ui->tableSchema->selectRow(indices.first().row());
        }

    }


}
void Setup::saveUser()
{
    userModel->submitAll();
    if(userModel->lastError().isValid())
        QMessageBox::critical(this,"Error",userModel->lastError().text());
    userModel->select();
}
void Setup::refreshUser()
{
    userModel->revertAll();
    userModel->select();
}
void Setup::newUser()
{
    int row = userModel->rowCount();
    userModel->insertRow(row);
    QSqlRecord rec = userModel->record(row);
    rec.setValue("active",true);
    ui->tableUser->setCurrentIndex(userModel->index(row,1));

    userModel->insertRecord(row,rec);

}
void Setup::deleteUser()
{
    QModelIndexList indices = ui->tableUser->selectionModel()->selectedRows();

    for (int i=indices.count()-1; i>=0; --i)
    {
        QModelIndex index = indices.at(i);
        userModel->removeRow(index.row());
    }
}
Setup::~Setup()
{
    delete ui;
    QCoreApplication::exit();
}
