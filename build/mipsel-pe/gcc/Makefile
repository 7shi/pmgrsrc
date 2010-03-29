PKGNAME = $(ARCH_PREFIX)-gcc
PKGVER  = 4.3.4
DEPENDS = $(ARCH_PREFIX)/binutils

include ../cross.mk
TOPDIR  = $(TOPDIR_)/..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = gcc-$(PKGVER)
SOURCES = gcc-core-$(PKGVER).tar.bz2 gcc-g++-$(PKGVER).tar.bz2 gcc-objc-$(PKGVER).tar.bz2
SRCURL  = ftp://ftp.gnu.org/gnu/gcc/$(WORKDIR)

do-fetch: std-fetch
do-extract: std-extract
do-patch: #fix-configure

do-config:
	mkdir -p $(WORKDIR)/build
	cd $(WORKDIR)/build && CPPFLAGS="-D_ALL_SOURCE -I$(PKGDEST)/include" LDFLAGS="-L$(PKGDEST)/lib -Wl,-R$(PKGDEST)/lib" ../configure --prefix=$(PKGDEST) --target=$(ARCH_PREFIX)

do-build:
	cd $(WORKDIR)/build && make CPPFLAGS="-D_ALL_SOURCE -I$(PKGDEST)/include" LDFLAGS="-L$(PKGDEST)/lib -Wl,-R$(PKGDEST)/lib" all-gcc

do-pkginst:
	cd $(WORKDIR)/build && make prefix=`pwd`/../../dest install-gcc
	for exe in c++ cpp g++ gcc gcc-$(PKGVER) gcov; do strip dest/bin/$(ARCH_PREFIX)-$$exe; done
	strip dest/libexec/gcc/$(ARCH_PREFIX)/$(PKGVER)/[cj]*
