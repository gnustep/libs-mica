#
# Mica makefiles
#
# Copyright 2015 Free Software Foundation, Inc
# Written by:  Riccardo Mottola <rm@gnu.org>
#

include $(GNUSTEP_MAKEFILES)/common.make

#
# Framework
#
VERSION = 0.1
FRAMEWORK_NAME = Mica
Mica_CURRENT_VERSION_NAME = 0.1
Mica_DEPLOY_WITH_CURRENT_VERSION = yes

#
# Libraries
#
Mica_LIBRARIES_DEPEND_UPON += -lgnustep-base -lgnustep-gui

Mica_HEADER_FILES_DIR = Headers
#
# Public headers (will be installed)
#
Mica_HEADER_FILES = \
CoreGraphics/CGBitmapContext.h \
CoreGraphics/CGContext.h \
CoreGraphics/CGGeometry.h \
CoreGraphics/CGColorSpace.h \
CoreGraphics/CGImage.h \
CoreGraphics/CGPath.h \
CoreGraphics/CoreGraphics.h \


#
# Class files
#
Mica_OBJC_FILES = \


#
# Makefiles
#
-include GNUmakefile.preamble
-include $(GNUSTEP_MAKEFILES)/aggregate.make
include $(GNUSTEP_MAKEFILES)/framework.make
-include GNUmakefile.postamble
