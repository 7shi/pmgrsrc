PKGNAME = $(ARCH_PREFIX)-binutils
PKGVER  = 2.16.1

include ../cross.mk
TOPDIR  = $(TOPDIR_)/..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = binutils-$(PKGVER)
SOURCES = $(WORKDIR)-minix.tar.bz2
SRCURL  = http://www.minix3.org/software

do-fetch: #std-fetch
	if [ ! -f $(DISTDIR)/$(SOURCES) ]; then rm -f $(SOURCES) && $(FETCH) -O $(SOURCES) $(SRCURL)/$(WORKDIR).tar.bz2 && mv $(SOURCES) $(DISTDIR); fi

do-extract: std-extract

do-patch: #fix-configure
	cp a.out.h $(WORKDIR)/include

do-config:
	cd $(WORKDIR) && CPPFLAGS="-D_ALL_SOURCE -I$(PKGDEST)/include" LDFLAGS=-Wl,-R$(PKGDEST)/lib ./configure --prefix=$(PKGDEST) --target=$(ARCH_PREFIX)

do-build:
	cd $(WORKDIR) && CPPFLAGS="-D_ALL_SOURCE -I$(PKGDEST)/include" LDFLAGS=-Wl,-R$(PKGDEST)/lib make

do-pkginst:
	cd $(WORKDIR) && make prefix=`pwd`/../dest install
	strip dest/bin/* dest/$(ARCH_PREFIX)/bin/*
