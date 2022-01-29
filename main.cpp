#include "importgroup.h"
#include "mainwindow.h"
#include "setup.h"

#include <QApplication>
#include <QxOrm.h>
#include "student.h"
#include "simat.h"


int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   qx::QxSqlDatabase::getSingleton()->setDriverName("QSQLITE");
   qx::QxSqlDatabase::getSingleton()->setDatabaseName("/home/ander/Apps/QxEntityEditor_Linux_64b/app/dbs/simat.db");

    MainWindow w;
    w.show();
   /*list_of_simat list;
   qx_query query = qx_query().where("");
   query.freeText("DOC NOT IN(SELECT ref FROM student)");
   QSqlError daoError = qx::dao::fetch_by_query(query, list);
   for (long l = 0; l < list.count(); l++)

   qx::dump(list);
   */
    //Setup s;s.exec();
    //ImportGroup ig;ig.exec();
     // QCoreApplication::quit();
    return a.exec();


}
