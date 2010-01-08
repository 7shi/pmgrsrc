PKGNAME = mingw-runtime
PKGVER  = 3.9

include ../cross.mk
TOPDIR  = $(TOPDIR_)/..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = 
SOURCES = $(PKGNAME)-$(PKGVER).tar.gz
SRCURL  = http://jaist.dl.sourceforge.net/sourceforge/mingw

do-fetch: std-fetch
do-extract:
do-patch:
do-config:
do-build:

do-pkginst:
	mkdir -p dest/$(ARCH_PREFIX)
	cd dest/$(ARCH_PREFIX) && pmgr-extract ../../$(DISTDIR)/$(SOURCES)
