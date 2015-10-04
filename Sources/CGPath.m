/** 
   Mica: Implementation of CoreGraphics on top of AppKit
   CGPath.m

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

#import <CoreGraphics/CGPath.h>

#import <AppKit/NSAffineTransform.h>
#import <AppKit/NSBezierPath.h>

@interface CGPath : NSBezierPath
@end


void CGPathRelease
(
 CGPathRef path
 )
{
  const NSBezierPath *nsPath;

  nsPath = path;
  if (nsPath)
    [nsPath release];
}

CGPathRef CGPathRetain
(
 CGPathRef path
 )
{
  const NSBezierPath *nsPath;

  nsPath = path;
  if (nsPath)
    [nsPath retain];

  return (CGPathRef)nsPath;
}


/* modifying */

void CGPathAddPath
(
 CGMutablePathRef path1,
 const CGAffineTransform *m,
 CGPathRef path2
 )
{
  NSBezierPath *nsPath1;
  NSBezierPath *nsPath2;
  NSAffineTransform *nsAt;
 
  nsPath1 = path1;
  nsPath2 = (NSBezierPath *)path2;  // discard const qualifier
  nsAt = [NSAffineTransform transform];
  [nsAt setTransformStruct: *(NSAffineTransformStruct *)m];

  [nsPath2 transformUsingAffineTransform: nsAt];
  [nsPath1 appendBezierPath:nsPath2];
}

void CGPathMoveToPoint
(
 CGMutablePathRef path,
 const CGAffineTransform *m,
 CGFloat x, CGFloat y
 )
{
  const NSBezierPath *nsPath;
  NSAffineTransform *nsAt;
  
  nsPath = path;
  nsAt = [NSAffineTransform transform];
  [nsAt setTransformStruct: *(NSAffineTransformStruct *)m];

  [nsPath transformUsingAffineTransform: nsAt];
  [nsPath moveToPoint: NSMakePoint(x, y)];
}
