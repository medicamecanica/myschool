/************************************************************************************************
** File created by QxEntityEditor 1.2.6 (2021/12/19 18:00) : please, do NOT modify this file ! **
************************************************************************************************/

#ifndef _MYSCOOL_STUDENT_H_
#define _MYSCOOL_STUDENT_H_
#include <QString>
#include <QList>
#include "precompiled.h"
#include <QxRegister/QxRegister.h>
class ORM_MYSCHOOL_EXPORT student
{

   QX_REGISTER_FRIEND_CLASS(student)

protected:

   long m_rowid;
   QString m_ref;
   QString m_firstname;
   QString m_lastname;
   long m_age;

public:

   student();
   student(const long & id);
   virtual ~student();

   long getrowid() const;
   QString getref() const;
   QString getfirstname() const;
   QString getlastname() const;
   long getage() const;

   void setrowid(const long & val);
   void setref(const QString & val);
   void setfirstname(const QString & val);
   void setlastname(const QString & val);
   void setage(const long & val);

public:

   static QString column_rowid(bool key = false) { Q_UNUSED(key); return "rowid"; }
   static QString column_ref(bool key = false) { Q_UNUSED(key); return "ref"; }
   static QString column_firstname(bool key = false) { Q_UNUSED(key); return "firstname"; }
   static QString column_lastname(bool key = false) { Q_UNUSED(key); return "lastname"; }
   static QString column_age(bool key = false) { Q_UNUSED(key); return "age"; }

public:

   static QString table_name(bool key = false) { Q_UNUSED(key); return "student"; }

};

typedef std::shared_ptr<student> student_ptr;
typedef qx::QxCollection<long, student_ptr> list_of_student;
typedef std::shared_ptr<list_of_student> list_of_student_ptr;

QX_REGISTER_COMPLEX_CLASS_NAME_HPP_ORM_MYSCHOOL(student, qx::trait::no_base_class_defined, 0, student)


#endif // _MYSCOOL_STUDENT_H_
