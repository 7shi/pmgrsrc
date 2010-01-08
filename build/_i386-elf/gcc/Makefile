# cf. http://www.osdev.org/osfaq2/index.php/GCC%20Cross-Compiler

PKGNAME = $(ARCH_PREFIX)-gcc
PKGVER  = 4.1.2
BLDDEPS = flex bison texinfo gtar
DEPENDS = $(ARCH_PREFIX)/binutils

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

do-config:
	cd $(WORKDIR) && ./configure --prefix=$(PKGDEST) --target=$(ARCH_PREFIX)

do-build:
	cd $(WORKDIR) && gmake CPPFLAGS=-D_ALL_SOURCE LDFLAGS=-Wl,-R$(PKGDEST)/lib SHELL=/bin/sh all-gcc

do-pkginst:
	cd $(WORKDIR) && gmake prefix=`pwd`/../dest install-gcc
	for exe in c++ cpp g++ gcc gcc-$(PKGVER) gcj gcjh gcov gjnih jcf-dump jv-scan; do strip dest/bin/$(ARCH_PREFIX)-$$exe; done
	strip dest/libexec/gcc/$(ARCH_PREFIX)/$(PKGVER)/[cj]*
