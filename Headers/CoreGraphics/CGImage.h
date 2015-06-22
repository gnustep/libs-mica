/** 
   Mica: Implementation of CoreGraphics on top of AppKit
   CGImage.h

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

#ifndef CGIMAGE_H_
#define CGIMAGE_H_

typedef struct CGImage *CGImageRef;

enum CGImageAlphaInfo {
  kCGImageAlphaNone,
  kCGImageAlphaPremultipliedLast,
  kCGImageAlphaPremultipliedFirst,
  kCGImageAlphaLast,
  kCGImageAlphaFirst,
  kCGImageAlphaNoneSkipLast,
  kCGImageAlphaNoneSkipFirst,
  kCGImageAlphaOnly
};
typedef enum CGImageAlphaInfo CGImageAlphaInfo;

enum {
  kCGBitmapAlphaInfoMask = 0x1F,
  kCGBitmapFloatComponents = (1 << 8),

  kCGBitmapByteOrderMask = 0x7000,
  kCGBitmapByteOrderDefault = (0 << 12),
  kCGBitmapByteOrder16Little = (1 << 12),
  kCGBitmapByteOrder32Little = (2 << 12),
  kCGBitmapByteOrder16Big = (3 << 12),
  kCGBitmapByteOrder32Big = (4 << 12)
};
typedef uint32_t CGBitmapInfo;

#endif /* CGIMAGE_H_ */
