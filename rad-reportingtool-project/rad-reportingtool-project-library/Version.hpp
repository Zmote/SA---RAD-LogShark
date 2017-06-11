//  ***************************************************************************
//  COPYRIGHT 2013 TO THE PRESENT   RHEINMETALL AIR DEFENCE AG   CH-8050 ZURICH
//
//  SOFTWARE DEVELOPMENT DEPARTMENT
//  ***************************************************************************
/*!
//  \file    Version.hpp
//
//  \author  Philipp Maurer (file template author)
//
//  \brief   Defines the package version
*/
//  ***************************************************************************

#ifndef REP__VERSION_HPP_INCLUDED
#define REP__VERSION_HPP_INCLUDED

/*
 * This header defines the library version.
 *
 * Please note that this file is generated. All changes will get lost.
 */

#include "ModPrefix.hpp"

#define REP_PREFIX MOD__REPORTING_TOOL

#define REP_MAJOR_VERSION "2"
#define REP_INTER_VERSION "11"
#define REP_MINOR_VERSION "0"

#define REP_MAJOR_VERSION_NUM 2
#define REP_INTER_VERSION_NUM 11
#define REP_MINOR_VERSION_NUM 0

/*
 * Usage example for REP_MANGLE_VERSION and REP_MANGLED_VERSION:
 * #if REP_MANGLED_VERSION >= REP_MANGLE_VERSION(1, 2, 3)
 *   #define HAS_REP_123_FEATURES
 * #endif
 */

#define REP_MANGLE_VERSION(major, inter, minor) (((major) << 24) + ((inter) << 8) + (minor))

#define REP_MANGLED_VERSION REP_MANGLE_VERSION(REP_MAJOR_VERSION_NUM, REP_INTER_VERSION_NUM, REP_MINOR_VERSION_NUM)

/*
 * The application binary interface version of the REP library.
 */
#define REP_ABIVERSION REP_PREFIX "_" REP_MAJOR_VERSION "." REP_INTER_VERSION

/* 
* The software version of the REP library.
*/ 
#define REP_VERSION REP_PREFIX "_" REP_MAJOR_VERSION "." REP_INTER_VERSION "." REP_MINOR_VERSION

/*
 * The software version of the REP library for usage in RC files.
 */
#define REP_FILEVER 2,11,0,0
#define REP_PRODUCTVER 2,11,0,0
#define REP_STRFILEVER "2, 11, 0, 0"
#define REP_STRPRODUCTVER "2, 11, 0, 0"


#endif // REP__VERSION_HPP_INCLUDED
