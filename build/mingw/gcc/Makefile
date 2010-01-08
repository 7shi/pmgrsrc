PKGNAME = mingw-gcc
PKGVER  = 4.1.2
BLDDEPS = flex bison texinfo gtar
DEPENDS = mingw/binutils mingw/runtime mingw/w32api

include ../cross.mk
TOPDIR  = $(TOPDIR_)/..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = gcc-$(PKGVER)
SOURCES = gcc-core-$(PKGVER).tar.bz2 gcc-g++-$(PKGVER).tar.bz2 gcc-java-$(PKGVER).tar.bz2 gcc-objc-$(PKGVER).tar.bz2
SRCURL  = ftp://ftp.gnu.org/gnu/gcc/$(WORKDIR)
EXTRACT = pmgr-extract -gtar

do-fetch: std-fetch
do-extract: std-extract

do-patch:
	cp $(PKGDEST)/share/libtool/config.* $(WORKDIR)
	cd $(WORKDIR)/libobjc && touch tconfig.h tm.h gthr-default.h

do-config:
	cd $(WORKDIR) && ./configure --prefix=$(PKGDEST) --target=$(ARCH_PREFIX)

do-build:
	cd $(WORKDIR) && gmake CPPFLAGS=-D_ALL_SOURCE LDFLAGS=-Wl,-R$(PKGDEST)/lib SHELL=/bin/sh

do-pkginst:
	cd $(WORKDIR) && gmake prefix=`pwd`/../dest install
	for exe in c++ cpp fastjar g++ gcc gcc-$(PKGVER) gcj gcjh gcov gjnih grepjar jcf-dump jv-scan; do strip dest/bin/$(ARCH_PREFIX)-$$exe; done
	strip dest/libexec/gcc/$(ARCH_PREFIX)/$(PKGVER)/[cj]*
