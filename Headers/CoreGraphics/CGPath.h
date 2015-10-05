/** 
   Mica: Implementation of CoreGraphics on top of AppKit
   CGPath.h

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

#ifndef CGPATH_H_
#define CGPATH_H_

#ifdef __OBJC__

@class CGPath;
typedef const CGPath  *CGPathRef;
typedef CGPath  *CGMutablePathRef;

#else /* standard C */

typedef const struct CGPath  *CGPathRef;
typedef struct CGPath  *CGMutablePathRef;

#endif /* OBJC */

#include <CoreGraphics/CGAffineTransform.h>

enum CGPathDrawingMode
{
  kCGPathFill,
  kCGPathEOFill,
  kCGPathStroke,
  kCGPathFillStroke,
  kCGPathEOFillStroke
};
typedef enum CGPathDrawingMode CGPathDrawingMode;

enum CGPathElementType
{
  kCGPathElementMoveToPoint,
  kCGPathElementAddLineToPoint,
  kCGPathElementAddQuadCurveToPoint,
  kCGPathElementAddCurveToPoint,
  kCGPathElementCloseSubpath
};
typedef enum CGPathElementType CGPathElementType;

enum CGLineCap
{
  kCGLineCapButt,
  kCGLineCapRound,
  kCGLineCapSquare
};
typedef enum CGLineCap CGLineCap; 

enum CGLineJoin
{
  kCGLineJoinMiter,
  kCGLineJoinRound,
  kCGLineJoinBevel
};
typedef enum CGLineJoin CGLineJoin;

/* creation and management */

void CGPathRelease
(
 CGPathRef path
 );

CGPathRef CGPathRetain
(
 CGPathRef path
 );


/* modifying */

void CGPathAddArcToPoint
(
 CGMutablePathRef path,
 const CGAffineTransform *m,
 CGFloat x1, CGFloat y1,
 CGFloat x2, CGFloat y2,
 CGFloat radius
 ); 

void CGPathAddLineToPoint
( CGMutablePathRef path,
  const CGAffineTransform *m,
  CGFloat x, CGFloat y
  ); 

void CGPathAddPath
(
 CGMutablePathRef path1,
 const CGAffineTransform *m,
 CGPathRef path2
 );

void CGPathMoveToPoint
(
 CGMutablePathRef path1,
 const CGAffineTransform *m,
 CGFloat x, CGFloat y
 );

void CGPathCloseSubpath
(
 CGMutablePathRef path
 ); 

#endif /* CGPATH_H_ */
