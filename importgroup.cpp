#include "importgroup.h"
#include "ui_importgroup.h"

#include <QDataWidgetMapper>
#include <QSqlTableModel>
#include <QToolButton>
#define GROUUP_EXCLUDE_FILTER " AND year||'-'||grade_code ||'-'|| group_code NOT IN(\
SELECT year ||'-'|| gp.code||'-'|| gr.code FROM groups gr \
INNER JOIN c_grade gp ON gp.rowid=gr.fk_grade \
        WHERE year='%1')"
ImportGroup::ImportGroup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImportGroup)
{
    ui->setupUi(this);
    //year
    schoolModel= new QSqlTableModel(this,m_db);
    schoolModel->setTable("c_school");
    ui->cbSchool->setModel(schoolModel);
    ui->cbSchool->setModelColumn(1);
    schoolModel->select();
    //year
    simatYearsModel= new QSqlTableModel(this,m_db);
    simatYearsModel->setTable("view_simat_years");
    ui->cbYear->setModel(simatYearsModel);
    ui->cbYear->setModelColumn(0);
    simatYearsModel->select();
    //simat
    simatGroupsModel= new QSqlTableModel(this,m_db);
    simatGroupsModel->setTable("view_simat_groups");

    mapperSimatGroup = new QDataWidgetMapper(this);
    mapperSimatGroup->setOrientation(Qt::Horizontal);
    mapperSimatGroup->setModel(simatGroupsModel);

    mapperSimatGroup->addMapping(ui->label_num, simatGroupsModel->fieldIndex("num"),"text");

    ui->list_simat->setModel(simatGroupsModel);
    ui->list_simat->setModelColumn(simatGroupsModel->fieldIndex("label"));
    connect(ui->list_simat->selectionModel(),
            &QItemSelectionModel::currentRowChanged,
            mapperSimatGroup,
            &QDataWidgetMapper::setCurrentModelIndex
            );
    connect(ui->list_group_year->selectionModel(),
            &QItemSelectionModel::currentRowChanged,
            this,
            &ImportGroup::rechanged
            );

    //groups
    groupsYearModel= new QSqlTableModel(this,m_db);
    groupsYearModel->setTable("groups");
    //groupsYearModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->list_group_year->setModel(groupsYearModel);
    ui->list_group_year->setModelColumn(groupsYearModel->fieldIndex("label"));
    connect(ui->btnSelect,
            &QToolButton::clicked,
            this,
            &ImportGroup::import
            );
    connect(ui->btnRemove,
            &QToolButton::clicked,
            this,
            &ImportGroup::remove
            );
    connect(ui->cbSchool,
            &QComboBox::currentTextChanged,
            this,
            &ImportGroup::schoolChanged
            );
}

ImportGroup::~ImportGroup()
{
    delete ui;
}
void ImportGroup::import(bool press)
{
    QModelIndex index = ui->list_simat->selectionModel()->currentIndex();
    QSqlRecord simatr = simatGroupsModel->record(index.row());
    QSqlRecord r=groupsYearModel->record();

    r.setValue("year",ui->cbYear->currentText().toInt());
    r.setValue("school_code",ui->cbSchool->currentText());
    r.setValue("code",simatr.value("group_code").toString());
    r.setValue("label",simatr.value("label").toString());
    r.setValue("fk_grade",simatr.value("fk_grade").toInt());
    r.remove(r.indexOf("rowid"));

    if(groupsYearModel->insertRecord(-1, r)){
        qDebug()<<"successful insertion";
    }
    else{
        // db.rollback();
    }
    groupsYearModel->select();
    simatGroupsModel->select();
}
void ImportGroup::remove(bool press)
{
    QModelIndex index = ui->list_group_year->selectionModel()->currentIndex();
    groupsYearModel->removeRow(index.row());
    groupsYearModel->submitAll();
    qDebug()<<groupsYearModel->lastError().text();
    qDebug()<<groupsYearModel->query().lastQuery();
    groupsYearModel->select();
    simatGroupsModel->select();
}
void ImportGroup::yearChanged(QString year)
{
    QString school_code = ui->cbSchool->currentText();
    simatGroupsModel->setFilter("year='"+year+"' "+QString(GROUUP_EXCLUDE_FILTER).arg(year)+" AND school_code='"+school_code+"'");
    simatGroupsModel->select();
    groupsYearModel->setFilter("year='"+year+"'"+" AND school_code='"+school_code+"'");
    groupsYearModel->select();
    //debug query
    qDebug()<<simatGroupsModel->query().lastQuery();
    // mapperSimatGroup->toFirst();

}
void ImportGroup::schoolChanged(QString school_code)
{
    QString year = ui->cbYear->currentText();
    simatGroupsModel->setFilter("year='"+year+"' "+QString(GROUUP_EXCLUDE_FILTER).arg(year)+" AND school_code='"+school_code+"'");
    simatGroupsModel->select();
    groupsYearModel->setFilter("year='"+year+"'"+" AND school_code='"+school_code+"'");
    groupsYearModel->select();
    // mapperSimatGroup->toFirst();

}
void ImportGroup::simatChanged(QModelIndex index)
{
   // QSqlRecord r=groupsYearModel->record(index.row());
   // r.

}
void ImportGroup::rechanged(QModelIndex index)
{
    //mapperSimatGroup->setCurrentModelIndex(row);
    //simatGroupsModel->setFilter("year='"+year+"'");
    //simatGroupsModel->select();

    //qDebug()<<row.data();
}
//create new record slot

