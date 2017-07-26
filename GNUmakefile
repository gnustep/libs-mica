#
# Mica makefiles
#
# Copyright 2015 Free Software Foundation, Inc
# Written by:  Riccardo Mottola <rm@gnu.org>
#

ifeq ($(GNUSTEP_MAKEFILES),)
 GNUSTEP_MAKEFILES := $(shell gnustep-config --variable=GNUSTEP_MAKEFILES 2>/dev/null)
  ifeq ($(GNUSTEP_MAKEFILES),)
    $(warning )
    $(warning Unable to obtain GNUSTEP_MAKEFILES setting from gnustep-config!)
    $(warning Perhaps gnustep-make is not properly installed,)
    $(warning so gnustep-config is not in your PATH.)
    $(warning )
    $(warning Your PATH is currently $(PATH))
    $(warning )
  endif
endif

ifeq ($(GNUSTEP_MAKEFILES),)
  $(error You need to set GNUSTEP_MAKEFILES before compiling!)
endif

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
CoreGraphics/CGAffineTransform.h \
CoreGraphics/CGBitmapContext.h \
CoreGraphics/CGContext.h \
CoreGraphics/CGGeometry.h \
CoreGraphics/CGColorSpace.h \
CoreGraphics/CGBitmapContext.h \
CoreGraphics/CGImage.h \
CoreGraphics/CGFont.h \
CoreGraphics/CGPath.h \
CoreGraphics/CoreGraphics.h \


#
# Class files
#
Mica_OBJC_FILES = \
Sources/CGContext.m \
Sources/CGColorSpace.m \
Sources/CGBitmapContext.m \
Sources/CGPath.m \
Sources/CGFont.m \

#
# Makefiles
#
-include GNUmakefile.preamble
-include $(GNUSTEP_MAKEFILES)/aggregate.make
include $(GNUSTEP_MAKEFILES)/framework.make
-include GNUmakefile.postamble
