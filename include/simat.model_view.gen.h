/************************************************************************************************
** File created by QxEntityEditor 1.2.6 (2021/12/19 21:16) : please, do NOT modify this file ! **
************************************************************************************************/

#ifndef _ORM_MYSCHOOL_SIMAT_MODEL_VIEW_H_
#define _ORM_MYSCHOOL_SIMAT_MODEL_VIEW_H_

#ifdef _QX_NO_PRECOMPILED_HEADER
#ifndef Q_MOC_RUN
#include "../include/orm_myschool_precompiled_header.model_view.gen.h" // Need to include precompiled header for the generated moc file
#endif // Q_MOC_RUN
#endif // _QX_NO_PRECOMPILED_HEADER

#include "../orm/include/simat.gen.h"

namespace model_view {

typedef qx::QxModel<simat> simat_model_base_class;

class ORM_MYSCHOOL_MODEL_VIEW_EXPORT simat_model : public simat_model_base_class
{

   Q_OBJECT

public:

   simat_model(QObject * parent = 0);
   simat_model(qx::IxModel * other, QObject * parent);
   virtual ~simat_model();

   /* List of properties exposed by the model (33) :
      - rowid
      - ANO
      - ESTADO
      - CODIGO_JERARQUIA
      - JERARQUIA
      - INSTITUCION
      - DANE
      - CALENDARIO
      - SECTOR
      - SEDE
      - CONSECUTIVO
      - JORNADA
      - GRADO
      - GRADO_COD
      - GRUPO
      - MODELO
      - MOTIVO
      - FECHAINI
      - FECHAFIN
      - NUI
      - ESTRATO
      - SISBEN_TRES
      - DOC
      - TIPODOC
      - APELLIDO1
      - APELLIDO2
      - NOMBRE1
      - NOMBRE2
      - GENERO
      - EDAD
      - MATRICULACONTRATADA
      - FUENTE_RECURSOS
      - INTERNADO
   */

};

} // namespace model_view

#endif // _ORM_MYSCHOOL_SIMAT_MODEL_VIEW_H_
