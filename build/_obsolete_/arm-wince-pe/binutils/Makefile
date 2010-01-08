PKGNAME = $(ARCH_PREFIX)-binutils
PKGVER  = 2.18

include ../cross.mk
TOPDIR  = $(TOPDIR_)/..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = binutils-$(PKGVER)
SOURCES = $(WORKDIR).tar.bz2
SRCURL  = ftp://ftp.gnu.org/gnu/binutils

do-fetch: std-fetch
do-extract: std-extract

do-patch:
	cp $(PKGDEST)/share/libtool/config.* $(WORKDIR)

do-config:
	cd $(WORKDIR) && CPPFLAGS="-D_ALL_SOURCE -I$(PKGDEST)/include" LDFLAGS=-Wl,-R$(PKGDEST)/lib ./configure --prefix=$(PKGDEST) --target=$(ARCH_PREFIX)

do-build:
	cd $(WORKDIR) && CPPFLAGS="-D_ALL_SOURCE -I$(PKGDEST)/include" LDFLAGS=-Wl,-R$(PKGDEST)/lib gmake

do-pkginst:
	cd $(WORKDIR) && gmake prefix=`pwd`/../dest install
	strip dest/bin/* dest/$(ARCH_PREFIX)/bin/*
