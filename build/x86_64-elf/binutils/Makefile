PKGNAME = $(ARCH_PREFIX)-binutils
PKGVER  = 2.17

include ../cross.mk
TOPDIR  = $(TOPDIR_)/..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = binutils-$(PKGVER)
SOURCE  = $(WORKDIR).tar.bz2
SRCURL  = http://ftp.gnu.org/gnu/binutils/$(SOURCE)

do-fetch:
	if [ ! -f $(DISTDIR)/$(SOURCE) ]; then $(HTTPGET) $(SRCURL) && mv $(SOURCE) $(DISTDIR); fi

do-extract:
	pmgr-extract $(DISTDIR)/$(SOURCE)

do-patch:
	cp $(TOPDIR)/share/config.* $(WORKDIR)

do-config:
	cd $(WORKDIR) && CPPFLAGS=-D_ALL_SOURCE ./configure --prefix=$(PKGDEST) --target=$(ARCH_PREFIX) --enable-64-bit-bfd

do-build:
	CPPFLAGS=-D_ALL_SOURCE gmake -C $(WORKDIR)

do-pkginst:
	gmake -C $(WORKDIR) prefix=`pwd`/dest install
	strip dest/bin/* dest/$(ARCH_PREFIX)/bin/*
