/************************************************************************************************
** File created by QxEntityEditor 1.2.6 (2021/12/19 19:21) : please, do NOT modify this file ! **
************************************************************************************************/

#include "precompiled.h"

#include "simat.h"



QX_REGISTER_COMPLEX_CLASS_NAME_CPP_ORM_MYSCHOOL(simat, simat)

namespace qx {

template <>
void register_class(QxClass<simat> & t)
{
   qx::IxDataMember * pData = NULL; Q_UNUSED(pData);
   qx::IxSqlRelation * pRelation = NULL; Q_UNUSED(pRelation);
   qx::IxFunction * pFct = NULL; Q_UNUSED(pFct);
   qx::IxValidator * pValidator = NULL; Q_UNUSED(pValidator);

   t.setName("simat");
   t.setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");

   pData = t.id(& simat::m_rowid, "rowid", 0);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");

   pData = t.data(& simat::m_ANO, "ANO", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");
   pData = t.data(& simat::m_ESTADO, "ESTADO", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");
   pData = t.data(& simat::m_CODIGO_JERARQUIA, "CODIGO_JERARQUIA", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");
   pData = t.data(& simat::m_JERARQUIA, "JERARQUIA", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");
   pData = t.data(& simat::m_INSTITUCION, "INSTITUCION", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");
   pData = t.data(& simat::m_DANE, "DANE", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");
   pData = t.data(& simat::m_CALENDARIO, "CALENDARIO", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");
   pData = t.data(& simat::m_SECTOR, "SECTOR", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");
   pData = t.data(& simat::m_SEDE, "SEDE", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");
   pData = t.data(& simat::m_CONSECUTIVO, "CONSECUTIVO", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");
   pData = t.data(& simat::m_JORNADA, "JORNADA", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");
   pData = t.data(& simat::m_GRADO, "GRADO", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");
   pData = t.data(& simat::m_GRADO_COD, "GRADO_COD", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");
   pData = t.data(& simat::m_GRUPO, "GRUPO", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");
   pData = t.data(& simat::m_MODELO, "MODELO", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");
   pData = t.data(& simat::m_MOTIVO, "MOTIVO", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");
   pData = t.data(& simat::m_FECHAINI, "FECHAINI", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");
   pData = t.data(& simat::m_FECHAFIN, "FECHAFIN", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");
   pData = t.data(& simat::m_NUI, "NUI", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");
   pData = t.data(& simat::m_ESTRATO, "ESTRATO", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");
   pData = t.data(& simat::m_SISBEN_TRES, "SISBEN_TRES", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");
   pData = t.data(& simat::m_DOC, "DOC", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");
   pData = t.data(& simat::m_TIPODOC, "TIPODOC", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");
   pData = t.data(& simat::m_APELLIDO1, "APELLIDO1", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");
   pData = t.data(& simat::m_APELLIDO2, "APELLIDO2", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");
   pData = t.data(& simat::m_NOMBRE1, "NOMBRE1", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");
   pData = t.data(& simat::m_NOMBRE2, "NOMBRE2", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");
   pData = t.data(& simat::m_GENERO, "GENERO", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");
   pData = t.data(& simat::m_EDAD, "EDAD", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");
   pData = t.data(& simat::m_MATRICULACONTRATADA, "MATRICULACONTRATADA", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");
   pData = t.data(& simat::m_FUENTE_RECURSOS, "FUENTE_RECURSOS", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");
   pData = t.data(& simat::m_INTERNADO, "INTERNADO", 0, true, true);
   pData->setPropertyBag("QX_EE_GENERATED_BY_SQLITE_IMPORT_PLUGIN", "1");

   qx::QxValidatorX<simat> * pAllValidator = t.getAllValidator(); Q_UNUSED(pAllValidator);
    //t.relationManyToOne(& simat::m_student, "DOC","");
}

} // namespace qx

simat::simat() : m_rowid(0), m_ANO(0), m_CODIGO_JERARQUIA(0), m_DANE(0), m_CONSECUTIVO(0), m_GRADO_COD(0), m_GRUPO(0), m_MOTIVO(0), m_FECHAFIN(0), m_SISBEN_TRES(0), m_EDAD(0) { ; }

simat::simat(const long & id) : m_rowid(id), m_ANO(0), m_CODIGO_JERARQUIA(0), m_DANE(0), m_CONSECUTIVO(0), m_GRADO_COD(0), m_GRUPO(0), m_MOTIVO(0), m_FECHAFIN(0), m_SISBEN_TRES(0), m_EDAD(0) { ; }

simat::~simat() { ; }

long simat::getrowid() const { return m_rowid; }

long simat::getANO() const { return m_ANO; }

QString simat::getESTADO() const { return m_ESTADO; }

long simat::getCODIGO_JERARQUIA() const { return m_CODIGO_JERARQUIA; }

QString simat::getJERARQUIA() const { return m_JERARQUIA; }

QString simat::getINSTITUCION() const { return m_INSTITUCION; }

long simat::getDANE() const { return m_DANE; }

QString simat::getCALENDARIO() const { return m_CALENDARIO; }

QString simat::getSECTOR() const { return m_SECTOR; }

QString simat::getSEDE() const { return m_SEDE; }

long simat::getCONSECUTIVO() const { return m_CONSECUTIVO; }

QString simat::getJORNADA() const { return m_JORNADA; }

QString simat::getGRADO() const { return m_GRADO; }

long simat::getGRADO_COD() const { return m_GRADO_COD; }

long simat::getGRUPO() const { return m_GRUPO; }

QString simat::getMODELO() const { return m_MODELO; }

long simat::getMOTIVO() const { return m_MOTIVO; }

QString simat::getFECHAINI() const { return m_FECHAINI; }

long simat::getFECHAFIN() const { return m_FECHAFIN; }

QString simat::getNUI() const { return m_NUI; }

QString simat::getESTRATO() const { return m_ESTRATO; }

long simat::getSISBEN_TRES() const { return m_SISBEN_TRES; }

QString simat::getDOC() const { return m_DOC; }

QString simat::getTIPODOC() const { return m_TIPODOC; }

QString simat::getAPELLIDO1() const { return m_APELLIDO1; }

QString simat::getAPELLIDO2() const { return m_APELLIDO2; }

QString simat::getNOMBRE1() const { return m_NOMBRE1; }

QString simat::getNOMBRE2() const { return m_NOMBRE2; }

QString simat::getGENERO() const { return m_GENERO; }

long simat::getEDAD() const { return m_EDAD; }

QString simat::getMATRICULACONTRATADA() const { return m_MATRICULACONTRATADA; }

QString simat::getFUENTE_RECURSOS() const { return m_FUENTE_RECURSOS; }

QString simat::getINTERNADO() const { return m_INTERNADO; }

void simat::setrowid(const long & val) { m_rowid = val; }

void simat::setANO(const long & val) { m_ANO = val; }

void simat::setESTADO(const QString & val) { m_ESTADO = val; }

void simat::setCODIGO_JERARQUIA(const long & val) { m_CODIGO_JERARQUIA = val; }

void simat::setJERARQUIA(const QString & val) { m_JERARQUIA = val; }

void simat::setINSTITUCION(const QString & val) { m_INSTITUCION = val; }

void simat::setDANE(const long & val) { m_DANE = val; }

void simat::setCALENDARIO(const QString & val) { m_CALENDARIO = val; }

void simat::setSECTOR(const QString & val) { m_SECTOR = val; }

void simat::setSEDE(const QString & val) { m_SEDE = val; }

void simat::setCONSECUTIVO(const long & val) { m_CONSECUTIVO = val; }

void simat::setJORNADA(const QString & val) { m_JORNADA = val; }

void simat::setGRADO(const QString & val) { m_GRADO = val; }

void simat::setGRADO_COD(const long & val) { m_GRADO_COD = val; }

void simat::setGRUPO(const long & val) { m_GRUPO = val; }

void simat::setMODELO(const QString & val) { m_MODELO = val; }

void simat::setMOTIVO(const long & val) { m_MOTIVO = val; }

void simat::setFECHAINI(const QString & val) { m_FECHAINI = val; }

void simat::setFECHAFIN(const long & val) { m_FECHAFIN = val; }

void simat::setNUI(const QString & val) { m_NUI = val; }

void simat::setESTRATO(const QString & val) { m_ESTRATO = val; }

void simat::setSISBEN_TRES(const long & val) { m_SISBEN_TRES = val; }

void simat::setDOC(const QString & val) { m_DOC = val; }

void simat::setTIPODOC(const QString & val) { m_TIPODOC = val; }

void simat::setAPELLIDO1(const QString & val) { m_APELLIDO1 = val; }

void simat::setAPELLIDO2(const QString & val) { m_APELLIDO2 = val; }

void simat::setNOMBRE1(const QString & val) { m_NOMBRE1 = val; }

void simat::setNOMBRE2(const QString & val) { m_NOMBRE2 = val; }

void simat::setGENERO(const QString & val) { m_GENERO = val; }

void simat::setEDAD(const long & val) { m_EDAD = val; }

void simat::setMATRICULACONTRATADA(const QString & val) { m_MATRICULACONTRATADA = val; }

void simat::setFUENTE_RECURSOS(const QString & val) { m_FUENTE_RECURSOS = val; }

void simat::setINTERNADO(const QString & val) { m_INTERNADO = val; }

