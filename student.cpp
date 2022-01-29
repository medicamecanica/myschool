/************************************************************************************************
** File created by QxEntityEditor 1.2.6 (2021/12/19 18:00) : please, do NOT modify this file ! **
************************************************************************************************/

#include "precompiled.h"

#include <QxOrm_Impl.h>
#include "student.h"


QX_REGISTER_COMPLEX_CLASS_NAME_CPP_ORM_MYSCHOOL(student, student)

namespace qx {

template <>
void register_class(QxClass<student> & t)
{
   qx::IxDataMember * pData = NULL; Q_UNUSED(pData);
   qx::IxSqlRelation * pRelation = NULL; Q_UNUSED(pRelation);
   qx::IxFunction * pFct = NULL; Q_UNUSED(pFct);
   qx::IxValidator * pValidator = NULL; Q_UNUSED(pValidator);

   t.setName("student");
   t.setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");

   pData = t.id(& student::m_rowid, "rowid", 0);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");

   pData = t.data(& student::m_ref, "ref", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");
   pData = t.data(& student::m_firstname, "firstname", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");
   pData = t.data(& student::m_lastname, "lastname", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");
   pData = t.data(& student::m_age, "age", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");

   qx::QxValidatorX<student> * pAllValidator = t.getAllValidator(); Q_UNUSED(pAllValidator);
}

} // namespace qx

student::student() : m_rowid(0), m_age(0) { ; }

student::student(const long & id) : m_rowid(id), m_age(0) { ; }

student::~student() { ; }

long student::getrowid() const { return m_rowid; }

QString student::getref() const { return m_ref; }

QString student::getfirstname() const { return m_firstname; }

QString student::getlastname() const { return m_lastname; }

long student::getage() const { return m_age; }

void student::setrowid(const long & val) { m_rowid = val; }

void student::setref(const QString & val) { m_ref = val; }

void student::setfirstname(const QString & val) { m_firstname = val; }

void student::setlastname(const QString & val) { m_lastname = val; }

void student::setage(const long & val) { m_age = val; }

