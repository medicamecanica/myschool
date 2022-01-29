/************************************************************************************************
** File created by QxEntityEditor 1.2.6 (2021/12/19 21:16) : please, do NOT modify this file ! **
************************************************************************************************/

#ifndef _ORM_MYSCHOOL_ENRROLL_MODEL_VIEW_H_
#define _ORM_MYSCHOOL_ENRROLL_MODEL_VIEW_H_

#ifdef _QX_NO_PRECOMPILED_HEADER
#ifndef Q_MOC_RUN
#include "../include/orm_myschool_precompiled_header.model_view.gen.h" // Need to include precompiled header for the generated moc file
#endif // Q_MOC_RUN
#endif // _QX_NO_PRECOMPILED_HEADER

#include "../orm/include/enrroll.gen.h"

namespace model_view {

typedef qx::QxModel<enrroll> enrroll_model_base_class;

class ORM_MYSCHOOL_MODEL_VIEW_EXPORT enrroll_model : public enrroll_model_base_class
{

   Q_OBJECT

public:

   enrroll_model(QObject * parent = 0);
   enrroll_model(qx::IxModel * other, QObject * parent);
   virtual ~enrroll_model();

   /* List of properties exposed by the model (6) :
      - rowid
      - ref
      - code_student
      - grade
      - group
      - year
   */

};

} // namespace model_view

#endif // _ORM_MYSCHOOL_ENRROLL_MODEL_VIEW_H_
