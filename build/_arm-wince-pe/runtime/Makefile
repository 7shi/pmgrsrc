PKGNAME = $(ARCH_PREFIX)-runtime
PKGVER  = 0.51.0-1

include ../cross.mk
TOPDIR  = $(TOPDIR_)/..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)
SOURCES = cygwin-cegcc-mingw32ce-$(PKGVER).tar.gz
SRCURL  = http://nchc.dl.sourceforge.net/sourceforge/cegcc

do-fetch: std-fetch

do-extract:
	mkdir -p $(WORKDIR)
	cd $(WORKDIR) && pmgr-extract ../$(DISTDIR)/$(SOURCES)

do-patch:
	rm -rf $(WORKDIR)/opt/mingw32ce/arm-wince-mingw32ce/include/c++
	rm -rf $(WORKDIR)/opt/mingw32ce/arm-wince-mingw32ce/lib/gcc

do-config:
do-build:

do-pkginst:
	mkdir -p dest/$(ARCH_PREFIX)
	(cd $(WORKDIR)/opt/mingw32ce/arm-wince-mingw32ce && gtar cvf - include lib) | gtar xf - -C dest/$(ARCH_PREFIX)
