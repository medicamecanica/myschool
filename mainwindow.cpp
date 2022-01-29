#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QFileDialog>
#include <QStandardPaths>
#include <QtQml>
#include <QxOrm_Impl.h>
#include <QtDebug>
#include <QMessageBox>
#include "dialogsync.h"
#include "importgroup.h"
#include "precompiled.h"
#include "setup.h"
#include "simat.h"
#include "student.h"
#include <QxOrm_Impl.h>
#include "qtcsv/stringdata.h"
#include "qtcsv/reader.h"
#include "qtcsv/writer.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    util->getSettings();







    /*  qx::QxCollectionIterator<long, simat_ptr> itr(list_of_simat);

    while (itr.next())
    {
        long code = itr.key();
        qDebug() << qPrintable(itr.value()->getDOC()) << " " << qPrintable(itr.value()->getNOMBRE1());
    }
    qDebug()<< qx::dao::count<simat>();*/
    /* iterate with 'for' keyword */
  /*  QSqlError daoError;
    list_of_simat list;
    daoError= qx::dao::fetch_all(list);
    qDebug()<< list.count();
    for (long l = 0; l < list.count(); ++l)
    {
        simat_ptr p = list.at(l);
       // long code = list.getKeyByIndex(l);
        // qDebug() << qPrintable(p->getNOMBRE1()) << " " << qPrintable(p->getDOC());
    }
    qx_query query;
    query.addJoinQuery("student","simat.DOC LIKE student.ref");
    daoError=qx::dao::fetch_by_query(query,list);
    qDebug() <<daoError.text();*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::importSUNAT()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image"),
                                                    QDir::homePath(),
                                                    tr("Archicos planos (*.txt *.csv)"));
   /* QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
        return ;
    }
    */
   //check if file exist if not show warning and return nothing
    if(fileName.isEmpty())
    {
        QMessageBox::warning(this,tr("Import"),tr("No file selected"));
        return;
    }
    QList<QStringList> simatCSV = QtCSV::Reader::readToList(fileName);

    QStringList wordList;
    int i=0;
    QList<QByteArray> header ;
     list_of_simat list;
    qx::QxSession session;
    //while (!file.atEnd()) {
    foreach (QStringList row, simatCSV) {
        //QByteArray line = file.readLine();
        if(i==0){
            //header = line.split(',');
            qx::dao::delete_all<simat>();
        }else{
            //QList<QByteArray> row=  line.split(',');
            qDebug()<<row.count();
            simat_ptr s; s.reset(new simat());
            s->setANO(row.at(0).toUInt());
            s->setESTADO(row.at(1));
            s->setCODIGO_JERARQUIA(row.at(2).toULong());
            s->setJERARQUIA(row.at(3));
            s->setINSTITUCION(row.at(4));
            s->setDANE(row.at(5).toLong());
            s->setCALENDARIO(row.at(6));
            s->setSECTOR(row.at(7));
            s->setSEDE(row.at(8));
            s->setCONSECUTIVO(row.at(9).toULong());
            s->setJORNADA(row.at(10));
            s->setGRADO(row.at(11));
            s->setGRADO_COD(row.at(12).toUInt());
            s->setGRUPO(row.at(13).toUInt());
            s->setMODELO(row.at(14));
           // s->setMOTIVO(row.at(15));
            s->setFECHAINI(row.at(16));
            //s->setFECHAFIN(row.at(17));
            s->setNUI(row.at(18));
            s->setESTRATO(row.at(19));
            s->setSISBEN_TRES(row.at(20).toInt());
            s->setDOC(row.at(21));
            s->setTIPODOC(row.at(22));
            s->setAPELLIDO1(row.at(23));
            s->setAPELLIDO2(row.at(24));
            s->setNOMBRE1(row.at(25));
            s->setNOMBRE2(row.at(26));
            s->setGENERO(row.at(27));
            s->setEDAD(row.at(28).toUInt());
            s->setMATRICULACONTRATADA(row.at(29));
            s->setFUENTE_RECURSOS(row.at(30));
            s->setINTERNADO(row.at(31));
            //list.push_back(s);
              session += qx::dao::insert(s, session.database());
        }

        i++;


    }
    //QSqlError daoError = qx::dao::insert(list);
    // If the session is not valid (so an error occured) => display first error
    if (! session.isValid()) { qDebug("[QxOrm] session error : '%s'", qPrintable(session.firstError().text())); }

}

void MainWindow::syncDialog(){
    DialogSync d(this);
    d.exec();
}
//create slot importGroups
void MainWindow::importGroups(){
    ImportGroup *ig = new ImportGroup(this);
    ig->exec();
}
//create solot setup
void MainWindow::setup(){
    Setup *s = new Setup(this);
    s->exec();
}




