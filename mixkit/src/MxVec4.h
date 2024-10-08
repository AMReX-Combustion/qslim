#ifndef MXVEC4_INCLUDED // -*- C++ -*-
#define MXVEC4_INCLUDED
#if !defined(__GNUC__)
#  pragma once
#endif

/************************************************************************

  4D Vector class

  Copyright (C) 1998 Michael Garland.  See "COPYING.txt" for details.
  
  $Id: MxVec4.h,v 1.1.1.1 2006/09/20 01:42:05 marc Exp $

 ************************************************************************/

#include <gfx/vec4.h>

#ifdef MXGL_INCLUDED
inline void glV(const Vec4& v) { glVertex4d(v[X], v[Y], v[Z], v[W]); }
inline void glC(const Vec4& v) { glColor4d(v[X], v[Y], v[Z], v[W]); }
#endif

// MXVEC4_INCLUDED
#endif
