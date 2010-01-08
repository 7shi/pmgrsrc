PKGNAME = $(ARCH_PREFIX)-gcc
PKGVER  = 4.3.4
BLDDEPS = flex bison texinfo gtar
DEPENDS = gmp mpfr $(ARCH_PREFIX)/binutils $(ARCH_PREFIX)/runtime

include ../cross.mk
TOPDIR  = $(TOPDIR_)/..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = gcc-$(PKGVER)
SOURCES = gcc-core-$(PKGVER).tar.bz2 gcc-g++-$(PKGVER).tar.bz2 gcc-java-$(PKGVER).tar.bz2 gcc-objc-$(PKGVER).tar.bz2
SRCURL  = ftp://ftp.gnu.org/gnu/gcc/$(WORKDIR)
EXTRACT = pmgr-extract -gtar

do-fetch: std-fetch
	#if [ ! -f $(DISTDIR)/ecj-latest.jar ]; then rm -f ecj-latest.jar && $(FETCH) ftp://sourceware.org/pub/java/ecj-latest.jar && mv ecj-latest.jar $(DISTDIR); fi

do-extract: std-extract
	#cp $(DISTDIR)/ecj-latest.jar $(WORKDIR)/ecj.jar

do-patch:
	cp $(PKGDEST)/share/libtool/config.* $(WORKDIR)

do-config:
	mkdir -p $(WORKDIR)/build
	cd $(WORKDIR)/build && CPPFLAGS="-D_ALL_SOURCE -I$(PKGDEST)/include" LDFLAGS="-L$(PKGDEST)/lib -Wl,-R$(PKGDEST)/lib" ../configure --prefix=$(PKGDEST) --target=$(ARCH_PREFIX)

do-build:
	cd $(WORKDIR)/build && gmake CPPFLAGS="-D_ALL_SOURCE -I$(PKGDEST)/include" LDFLAGS="-L$(PKGDEST)/lib -Wl,-R$(PKGDEST)/lib"

do-pkginst:
	cd $(WORKDIR)/build && gmake prefix=`pwd`/../../dest install
	for exe in c++ cpp g++ gcc gcc-$(PKGVER) gcj gcov jcf-dump; do strip dest/bin/$(ARCH_PREFIX)-$$exe; done
	strip dest/libexec/gcc/$(ARCH_PREFIX)/$(PKGVER)/[cj]*
