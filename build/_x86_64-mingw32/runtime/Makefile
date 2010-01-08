PKGNAME = $(ARCH_PREFIX)-runtime
PKGVER  = 20080608

include ../cross.mk
TOPDIR  = $(TOPDIR_)/..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)
SOURCES = mingw-w64-bin_i686-cygwin-1.5.25-14_$(PKGVER).tar.bz2
SRCURL  = http://nchc.dl.sourceforge.net/sourceforge/mingw-w64

do-fetch: std-fetch

do-extract:
	mkdir -p $(WORKDIR)
	cd $(WORKDIR) && pmgr-extract ../$(DISTDIR)/$(SOURCES)

do-patch:
	rm -rf $(WORKDIR)/x86_64-pc-mingw32/include/c++

do-config:
do-build:

do-pkginst:
	mkdir -p dest/$(ARCH_PREFIX)
	(cd $(WORKDIR)/x86_64-pc-mingw32 && gtar cvf - include lib) | gtar xf - -C dest/$(ARCH_PREFIX)
