PKGNAME = $(ARCH_PREFIX)-zlib
PKGVER  = 1.2.4
DEPENDS = $(ARCH_PREFIX)/gcc

include ../cross.mk
TOPDIR  = $(TOPDIR_)/..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = zlib-$(PKGVER)
SOURCES = $(WORKDIR).tar.bz2
SRCURL  = http://downloads.sourceforge.net/project/libpng/zlib/$(PKGVER)

do-fetch: std-fetch
do-extract: std-extract
do-patch: #fix-configure

do-config:
	cd $(WORKDIR) && CC=$(ARCH_PREFIX)-gcc AR=$(ARCH_PREFIX)-ar RANLIB=$(ARCH_PREFIX)-ranlib ./configure --prefix=$(PKGDEST)/$(ARCH_PREFIX) --static

do-build:
	cd $(WORKDIR) && make

do-pkginst:
	cd $(WORKDIR) && make prefix=`pwd`/../dest/$(ARCH_PREFIX) install
