/************************************************************************

  MxCamera

  Copyright (C) 1998 Michael Garland.  See "COPYING.txt" for details.
  
  $Id: MxCamera.cxx,v 1.1.1.1 2006/09/20 01:42:05 marc Exp $

 ************************************************************************/

#include "stdmix.h"
#include "MxCamera.h"



void MxCamera::look_at(const MxBounds& bounds, double ratio)
{
    double d = 3*bounds.radius / tan(60*M_PI/180.0);

    at = bounds.center;
    from = at;

    from[Z] += d;

    up[X] = 0; up[Y] = 1; up[Z] = 0;

    fovy = 60.0;
    aspect = ratio;

    znear = d/20;
    zfar = 10*d;
}

void MxCamera::apply()
{
    gluPerspective(fovy, aspect, znear, zfar);
    gluLookAt(from[X], from[Y], from[Z],
              at[X], at[Y], at[Z],
              up[X], up[Y], up[Z]);
}

void MxCamera::apply(GLenum mode)
{
    GLint last_mode; glGetIntegerv(GL_MATRIX_MODE, &last_mode);
      glMatrixMode(mode);
      apply();
    glMatrixMode((GLenum)last_mode);
}
