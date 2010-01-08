PKGNAME = distorm
PKGVER  = 1.6.20

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)
SOURCE  = $(PKGNAME)-pkg$(PKGVER).tar.bz2
SRCURL  = http://www.ragestorm.net/$(PKGNAME)/$(SOURCE)

do-fetch:
	if [ ! -f $(DISTDIR)/$(SOURCE) ]; then $(HTTPGET) $(SRCURL) && mv $(SOURCE) $(DISTDIR); fi

do-extract:
	pmgr-extract $(DISTDIR)/$(SOURCE)

do-patch:
	cp sysexits.h $(WORKDIR)/linuxproj

do-config:

do-build:
	gmake -C $(WORKDIR)/build/linux clib
	cd $(WORKDIR) && gcc -O2 -I.. -I$(PKGDEST)/include -D_ALL_SOURCE -o $(PKGNAME) linuxproj/main.c ../strtoull.c -Lbuild/linux -Wl,-R$(PKGDEST)/lib -ldistorm64

do-pkginst:
	mkdir dest && cd dest && mkdir bin include lib
	install -sc $(WORKDIR)/$(PKGNAME) dest/bin
	install -sc $(WORKDIR)/build/linux/libdistorm64.so dest/lib/libdistorm64.so.$(PKGVER)
	cd dest/lib && ln -s libdistorm64.so.$(PKGVER) libdistorm64.so
	install -c $(WORKDIR)/distorm.h dest/include
