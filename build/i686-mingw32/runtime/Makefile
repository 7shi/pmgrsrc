PKGNAME = $(ARCH_PREFIX)-runtime
PKGVER  = 3.16

include ../cross.mk
TOPDIR  = $(TOPDIR_)/..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = 
SOURCES = mingwrt-$(PKGVER)-mingw32-dev.tar.gz
SRCURL  = http://jaist.dl.sourceforge.net/project/mingw/MinGW%20Runtime/mingwrt-$(PKGVER)

do-fetch: std-fetch
do-extract:
do-patch:
do-config:
do-build:

do-pkginst:
	mkdir -p dest/$(ARCH_PREFIX)
	cd dest/$(ARCH_PREFIX) && pmgr-extract ../../$(DISTDIR)/$(SOURCES)
	cd dest/$(ARCH_PREFIX) && rm -rf share
