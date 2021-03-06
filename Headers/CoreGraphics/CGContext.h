/** 
   Mica: Implementation of CoreGraphics on top of AppKit
   CGContext.h

   Copyright (C) 2015 Free Software Foundation, Inc.

   Written by:  Riccardo Mottola <rm@gnu.org>

   This file is part of the Mica Framework.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the Free
   Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02111 USA.
   */

#ifndef CGCONTEXT_H_
#define CGCONTEXT_H_

#include <CoreGraphics/CGColorSpace.h>
#include <CoreGraphics/CGImage.h>
#include <CoreGraphics/CGPath.h>

#ifdef __OBJC__

@class CGContext;
typedef CGContext *CGContextRef;

#else /* standard C */

typedef struct CGContext *CGContextRef;

#endif


/* managing */

void CGContextRelease( CGContextRef c);
CGContextRef CGContextRetain( CGContextRef c);

/* saving and restoring */


/* graphic state parameters */

void CGContextSetLineWidth ( CGContextRef c, CGFloat width );

/* constructing paths */

void CGContextAddPath ( CGContextRef c, CGPathRef path );

/* painting paths */

void CGContextDrawPath ( CGContextRef c, CGPathDrawingMode mode );
void CGContextFillPath ( CGContextRef c );

#endif /* CGCONTEXT_H_ */
