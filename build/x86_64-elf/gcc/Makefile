# cf. http://www.osdev.org/osfaq2/index.php/GCC%20Cross-Compiler

PKGNAME = $(ARCH_PREFIX)-gcc
PKGVER  = 4.1.2
BLDDEPS = flex bison texinfo
DEPENDS = $(ARCH_PREFIX)/binutils

include ../cross.mk
TOPDIR  = $(TOPDIR_)/..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = gcc-$(PKGVER)
SOURCE  = gcc-core-$(PKGVER).tar.bz2 gcc-g++-$(PKGVER).tar.bz2 gcc-java-$(PKGVER).tar.bz2 gcc-objc-$(PKGVER).tar.bz2
SRCURL  = http://ftp.gnu.org/gnu/gcc/$(WORKDIR)

do-fetch:
	for src in $(SOURCE); do if [ ! -f $(DISTDIR)/$$src ]; then $(HTTPGET) $(SRCURL)/$$src && mv $$src $(DISTDIR); fi; done

do-extract:
	for src in $(SOURCE); do pmgr-extract $(DISTDIR)/$$src; done

do-patch:
	cp $(TOPDIR)/share/config.* $(WORKDIR)
	cat patch-* | patch -p0 -d $(WORKDIR)

do-config:
	cd $(WORKDIR) && CPPFLAGS=-D_ALL_SOURCE ./configure --prefix=$(PKGDEST) --target=$(ARCH_PREFIX)
	cd $(WORKDIR) && cp Makefile Makefile.orig
	cd $(WORKDIR) && sed -e 's|^SHELL *=.*$$|SHELL = /bin/sh|' Makefile.orig > Makefile

do-build:
	CPPFLAGS=-D_ALL_SOURCE gmake -C $(WORKDIR) all-gcc

do-pkginst:
	gmake -C $(WORKDIR) prefix=`pwd`/dest install-gcc
	for exe in c++ cpp g++ gcc gcc-$(PKGVER) gcj gcjh gcov gjnih jcf-dump jv-scan; do strip dest/bin/$(ARCH_PREFIX)-$$exe; done
	strip dest/libexec/gcc/$(ARCH_PREFIX)/$(PKGVER)/[cj]*
