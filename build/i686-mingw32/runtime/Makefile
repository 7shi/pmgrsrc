PKGNAME = $(ARCH_PREFIX)-runtime
PKGVER  = 3.18

include ../cross.mk
TOPDIR  = $(TOPDIR_)/..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = 
SOURCES = mingwrt-$(PKGVER)-mingw32-dev.tar.gz
SRCURL  = http://sourceforge.net/projects/mingw/files/MinGW/BaseSystem/RuntimeLibrary/MinGW-RT/mingwrt-$(PKGVER)

do-fetch: std-fetch
do-extract:
do-patch:
do-config:
do-build:

do-pkginst:
	mkdir -p dest/$(ARCH_PREFIX)
	cd dest/$(ARCH_PREFIX) && pmgr-extract ../../$(DISTDIR)/$(SOURCES)
	cd dest/$(ARCH_PREFIX) && rm -rf share
