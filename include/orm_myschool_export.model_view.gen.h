/************************************************************************************************
** File created by QxEntityEditor 1.2.6 (2021/12/19 21:16) : please, do NOT modify this file ! **
************************************************************************************************/

#ifndef _ORM_MYSCHOOL_MODEL_VIEW_EXPORT_H_
#define _ORM_MYSCHOOL_MODEL_VIEW_EXPORT_H_

#ifdef _MSC_VER
#pragma once
#endif

#include "../orm/include/orm_myschool_export.gen.h"

#ifdef _BUILDING_MODEL_VIEW_ORM_MYSCHOOL
#define ORM_MYSCHOOL_MODEL_VIEW_EXPORT QX_DLL_EXPORT_HELPER
#else // _BUILDING_MODEL_VIEW_ORM_MYSCHOOL
#define ORM_MYSCHOOL_MODEL_VIEW_EXPORT QX_DLL_IMPORT_HELPER
#endif // _BUILDING_MODEL_VIEW_ORM_MYSCHOOL

#ifdef _BUILDING_MODEL_VIEW_ORM_MYSCHOOL
#define QX_REGISTER_HPP_ORM_MYSCHOOL_MODEL_VIEW QX_REGISTER_HPP_EXPORT_DLL
#define QX_REGISTER_CPP_ORM_MYSCHOOL_MODEL_VIEW QX_REGISTER_CPP_EXPORT_DLL
#define QX_REGISTER_COMPLEX_CLASS_NAME_HPP_ORM_MYSCHOOL_MODEL_VIEW QX_REGISTER_COMPLEX_CLASS_NAME_HPP_EXPORT_DLL
#define QX_REGISTER_COMPLEX_CLASS_NAME_CPP_ORM_MYSCHOOL_MODEL_VIEW QX_REGISTER_COMPLEX_CLASS_NAME_CPP_EXPORT_DLL
#else // _BUILDING_MODEL_VIEW_ORM_MYSCHOOL
#define QX_REGISTER_HPP_ORM_MYSCHOOL_MODEL_VIEW QX_REGISTER_HPP_IMPORT_DLL
#define QX_REGISTER_CPP_ORM_MYSCHOOL_MODEL_VIEW QX_REGISTER_CPP_IMPORT_DLL
#define QX_REGISTER_COMPLEX_CLASS_NAME_HPP_ORM_MYSCHOOL_MODEL_VIEW QX_REGISTER_COMPLEX_CLASS_NAME_HPP_IMPORT_DLL
#define QX_REGISTER_COMPLEX_CLASS_NAME_CPP_ORM_MYSCHOOL_MODEL_VIEW QX_REGISTER_COMPLEX_CLASS_NAME_CPP_IMPORT_DLL
#endif // _BUILDING_MODEL_VIEW_ORM_MYSCHOOL

#ifndef QX_DLL_EXPORT_ORM_MYSCHOOL_MODEL_VIEW_SINGLETON_HPP
#ifdef _BUILDING_MODEL_VIEW_ORM_MYSCHOOL
#define QX_DLL_EXPORT_ORM_MYSCHOOL_MODEL_VIEW_SINGLETON_HPP(x) /* Nothing */
#else // _BUILDING_MODEL_VIEW_ORM_MYSCHOOL
#define QX_DLL_EXPORT_ORM_MYSCHOOL_MODEL_VIEW_SINGLETON_HPP(x) QX_DLL_EXPORT_TEMPLATE_HPP(class, qx::QxSingleton< x >)
#endif // _BUILDING_MODEL_VIEW_ORM_MYSCHOOL
#endif // QX_DLL_EXPORT_ORM_MYSCHOOL_MODEL_VIEW_SINGLETON_HPP

#ifndef QX_DLL_EXPORT_ORM_MYSCHOOL_MODEL_VIEW_SINGLETON_CPP
#ifdef _BUILDING_MODEL_VIEW_ORM_MYSCHOOL
#define QX_DLL_EXPORT_ORM_MYSCHOOL_MODEL_VIEW_SINGLETON_CPP(x) QX_DLL_EXPORT_TEMPLATE_CPP(class, qx::QxSingleton< x >)
#else // _BUILDING_MODEL_VIEW_ORM_MYSCHOOL
#define QX_DLL_EXPORT_ORM_MYSCHOOL_MODEL_VIEW_SINGLETON_CPP(x) /* Nothing */
#endif // _BUILDING_MODEL_VIEW_ORM_MYSCHOOL
#endif // QX_DLL_EXPORT_ORM_MYSCHOOL_MODEL_VIEW_SINGLETON_CPP

#endif // _ORM_MYSCHOOL_MODEL_VIEW_EXPORT_H_
