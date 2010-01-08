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
	mkdir -p $(WORKDIR)
	cd $(WORKDIR) && pmgr-extract ../$(DISTDIR)/$(SOURCES)

do-patch:
	rm -rf $(WORKDIR)/x86_64-w64-mingw32/include/c++

do-config:
do-build:

do-pkginst:
	mkdir -p dest/$(ARCH_PREFIX)
	cd dest/$(ARCH_PREFIX) && (cd ../../$(WORKDIR)/x86_64-w64-mingw32 && tar cvf - include lib) | tar xf -
