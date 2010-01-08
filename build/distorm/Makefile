PKGNAME = distorm
PKGVER  = 1.6.20

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)
SOURCES = $(PKGNAME)-pkg$(PKGVER).tar.bz2
SRCURL  = http://www.ragestorm.net/$(PKGNAME)

do-fetch: std-fetch
do-extract: std-extract
do-patch: #fix-configure
do-config:

do-build:
	cd $(WORKDIR)/build/linux && make clib
	cd $(WORKDIR)/linuxproj && make

do-pkginst:
	mkdir dest && cd dest && mkdir bin include lib
	install -sc $(WORKDIR)/linuxproj/disasm dest/bin/$(PKGNAME)
	install -sc $(WORKDIR)/build/linux/libdistorm64.so dest/lib/libdistorm64.so.$(PKGVER)
	cd dest/lib && ln -s libdistorm64.so.$(PKGVER) libdistorm64.so
	install -c $(WORKDIR)/distorm.h dest/include
