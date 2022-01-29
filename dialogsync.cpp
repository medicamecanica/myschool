#include "dialogsync.h"
#include "ui_dialogsync.h"
#include <QxOrm.h>
#include <QxOrm_Impl.h>
#include "simat.h"
#include "student.h"
DialogSync::DialogSync(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSync)
{
    ui->setupUi(this);
}

DialogSync::~DialogSync()
{
    delete ui;
}
void DialogSync::sync()
{
    list_of_simat listSimat;

    qx_query query = qx_query().where("");
    query.freeText("DOC NOT IN(SELECT ref FROM student)");
    QSqlError daoError = qx::dao::fetch_by_query(query, listSimat);
    qDebug()<< listSimat.count();
    //list_of_student studentList;
    //typedef std::vector<student_ptr> list_students;
    qx::QxSession session;
    for (long l = 0; l < listSimat.count(); ++l)
    {

        simat_ptr p = listSimat.at(l);
        //long code = list.getKeyByIndex(l);
        student_ptr st; st.reset(new student());
        st->setage(p->getEDAD());
        st->setref(p->getDOC());
        if(p->getNOMBRE2().isNull() || p->getNOMBRE2().isEmpty()){
            st->setfirstname(p->getNOMBRE1());
        }else{
            st->setfirstname(p->getNOMBRE1()+" "+p->getNOMBRE2());
        }
        if(p->getAPELLIDO2().isNull() || p->getAPELLIDO2().isEmpty()){
            st->setlastname(p->getAPELLIDO1());
        }else{
            st->setlastname(p->getAPELLIDO1()+" "+p->getAPELLIDO2());
        }
        /*qx::dao::insert(st);
        // Create a session, open automatically a transaction and throw an exception when an error occured
        qx::QxSession session;

        // Fetch the database version with a lock to protect the database

        session.fetchByQuery(qx_query("WHERE ref='"+p->getDOC()+"'"), st);
        qDebug()<<st->getrowid();

        // When unlocked for other users, verify that the database must be updated or not
        // if (st.version >= domainVersion) { return; }
        // qDebug() << qPrintable(p->getNOMBRE1()) << " " << qPrintable(p->getDOC());
        */
        // list_student->push_back(st);
        session += qx::dao::insert(st, session.database());
    }
    // If the session is not valid (so an error occured) => display first error
    if (! session.isValid()) { qDebug("[QxOrm] session error : '%s'", qPrintable(session.firstError().text())); }

}
