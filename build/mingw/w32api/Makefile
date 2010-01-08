PKGNAME = mingw-w32api
PKGVER  = 3.6

include ../cross.mk
TOPDIR  = $(TOPDIR_)/..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = 
SOURCE  = w32api-$(PKGVER).tar.gz
SRCURL  = http://jaist.dl.sourceforge.net/sourceforge/mingw/$(SOURCE)

do-fetch:
	if [ ! -f $(DISTDIR)/$(SOURCE) ]; then $(HTTPGET) $(SRCURL) && mv $(SOURCE) $(DISTDIR); fi

do-extract:
do-patch:
do-config:
do-build:

do-pkginst:
	mkdir -p dest/$(ARCH_PREFIX)
	pmgr-extract $(DISTDIR)/$(SOURCE) -C dest/$(ARCH_PREFIX)
