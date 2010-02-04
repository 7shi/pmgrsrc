PKGNAME = $(ARCH_PREFIX)-gcc
PKGVER  = 4.1.1
DEPENDS = $(ARCH_PREFIX)/binutils $(ARCH_PREFIX)/runtime

include ../cross.mk
TOPDIR  = $(TOPDIR_)/..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = gcc-$(PKGVER)
SOURCES = $(WORKDIR)-minix.tar.bz2
SRCURL  = http://www.minix3.org/software

do-fetch: #std-fetch
	if [ ! -f $(DISTDIR)/$(SOURCES) ]; then rm -f $(SOURCES) && $(FETCH) -O $(SOURCES) $(SRCURL)/$(WORKDIR).tar.bz2 && mv $(SOURCES) $(DISTDIR); fi

do-extract: std-extract

do-patch:
	cp $(PKGDEST)/share/libtool/config.* $(WORKDIR)

do-config:
	mkdir -p $(WORKDIR)/build
	cd $(WORKDIR)/build && CPPFLAGS="-D_ALL_SOURCE -I$(PKGDEST)/include" LDFLAGS="-L$(PKGDEST)/lib -Wl,-R$(PKGDEST)/lib" ../configure --prefix=$(PKGDEST) --target=$(ARCH_PREFIX)

do-build:
	cd $(WORKDIR)/build && make CPPFLAGS="-D_ALL_SOURCE -I$(PKGDEST)/include" LDFLAGS="-L$(PKGDEST)/lib -Wl,-R$(PKGDEST)/lib" SHELL=/bin/sh

do-pkginst:
	cd $(WORKDIR)/build && make -i prefix=`pwd`/../../dest install
	for exe in c++ cpp g++ gcc gcc-$(PKGVER) gcov; do strip dest/bin/$(ARCH_PREFIX)-$$exe; done
	strip dest/libexec/gcc/$(ARCH_PREFIX)/$(PKGVER)/[cj]*
