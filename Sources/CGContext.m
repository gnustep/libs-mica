/** 
   Mica: Implementation of CoreGraphics on top of AppKit
   CGContext.m 

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

#import <CoreGraphics/CGContext.h>

#import <AppKit/NSGraphicsContext.h>
#import <AppKit/NSBezierPath.h>

@interface CGContext : NSGraphicsContext
{
  NSBezierPath *_path;
}

- (void)setPath:(NSBezierPath *)p;
- (NSBezierPath *)path;

@end

@implementation CGContext

- (void)dealloc
{
  [_path release];
}

- (void)setPath:(NSBezierPath *)p
{
  if (_path != p)
    {
      [_path release];
      _path = p;
      [_path retain];
    }
}

- (NSBezierPath *)path
{
  return _path;
}

@end

/* managing */

void CGContextRelease
(
 CGContextRef c
)
{
  NSGraphicsContext *nsGc;

  nsGc = c;
  if (nsGc)
    [nsGc release];
}

CGContextRef CGContextRetain
(
 CGContextRef c
)
{
  NSGraphicsContext *nsGc;

  nsGc = c;
  if (nsGc)
    [nsGc retain];

  return (CGContextRef)nsGc;
}


void CGContextAddPath
(
 CGContextRef c, CGPathRef path
)
{
  NSGraphicsContext *nsGc;

  nsGc = c;
}


void CGContextDrawPath
(
 CGContextRef c, CGPathDrawingMode mode
)
{
  NSGraphicsContext *nsGc;
  NSBezierPath *p;
  
  nsGc = c;
  p = [c path];
  
  switch (mode)
    {
    kCGPathFill:
      [p setWindingRule:NSNonZeroWindingRule];
      [p fill];
      break;
    kCGPathEOFFill:
      [p setWindingRule:NSEvenOddWindingRule];
      [p fill];
      break;
    kCGPathStroke:
      [p stroke];
      break;
    kCGPathFillStroke:
      [p setWindingRule:NSNonZeroWindingRule];
      [p fill];
      [p stroke];
      break;
    kCGPathEOFFillStroke:
      [p setWindingRule:NSEvenOddWindingRule];
      [p fill];
      [p stroke];
      break;
    default:
      NSLog(@"CGContextDrawPath: unexpected CGPathDrawingMode");
    }
}

void CGContextFillPath
(
 CGContextRef c
 )
{
  CGContextDrawPath (c, kCGPathFill);
}
