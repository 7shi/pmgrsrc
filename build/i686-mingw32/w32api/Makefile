PKGNAME = $(ARCH_PREFIX)-w32api
PKGVER  = 3.14

include ../cross.mk
TOPDIR  = $(TOPDIR_)/..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = 
SOURCES = w32api-$(PKGVER)-mingw32-dev.tar.gz
SRCURL  = http://sourceforge.net/projects/mingw/files/MinGW/BaseSystem/RuntimeLibrary/Win32-API/w32api-$(PKGVER)

do-fetch: std-fetch
do-extract:
do-patch:
do-config:
do-build:

do-pkginst:
	mkdir -p dest/$(ARCH_PREFIX)
	cd dest/$(ARCH_PREFIX) && pmgr-extract ../../$(DISTDIR)/$(SOURCES)
