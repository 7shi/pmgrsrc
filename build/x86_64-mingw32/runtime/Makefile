PKGNAME = $(ARCH_PREFIX)-runtime
PKGVER  = 4.4.1a

include ../cross.mk
TOPDIR  = $(TOPDIR_)/..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)
SOURCES = mingw-w64-bin_i686-cygwin-1.5.25-15_$(PKGVER).tar.bz2
SRCURL  = http://downloads.sourceforge.net/sourceforge/mingw-w64/

do-fetch: std-fetch
do-extract:
do-patch:
do-config:
do-build:

do-pkginst:
	mkdir -p dest/$(ARCH_PREFIX)
	mkdir -p dest/tmp
	cd dest/tmp && pmgr-extract ../../$(DISTDIR)/$(SOURCES)
	cd dest/tmp && patch -p0 < ../../_patch-00
	rm -rf dest/tmp/x86_64-w64-mingw32/include/c++
	cd dest/tmp/x86_64-w64-mingw32/lib && rm libobjc.a libstdc++.a
	cd dest/tmp/x86_64-w64-mingw32 && mv include lib ../../$(ARCH_PREFIX)
	rm -rf dest/tmp
