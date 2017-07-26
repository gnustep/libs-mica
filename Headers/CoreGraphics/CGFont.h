/** 
   Mica: Implementation of CoreGraphics on top of AppKit
   CGFont.h

   Copyright (C) 2017 Free Software Foundation, Inc.

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

#ifndef FONT_H_
#define FONT_H_

#ifdef __OBJC__
@class CGFont;
typedef const CGFont *CGFontRef;
#else
typedef struct CGFont *CGFontRef;
#endif

/* creation and management */


void CGFontRelease
(
 CGFontRef path
 );

CGFontRef CGFontRetain
(
 CGFontRef path
 );


#endif /* FONT_H_ */