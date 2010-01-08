PKGNAME = distorm
PKGVER  = 1.6.20

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)
SOURCES = $(PKGNAME)-pkg$(PKGVER).tar.bz2
SRCURL  = http://www.ragestorm.net/$(PKGNAME)

do-fetch: std-fetch
do-extract: std-extract

do-patch:
	cp sysexits.h $(WORKDIR)/linuxproj
	if [ ! -f /usr/include/stdint.h ]; then cp stdint.h $(WORKDIR)/build/linux; fi

do-config:

do-build:
	cd $(WORKDIR)/build/linux && make CFLAGS="-O2 -Wall -D_ALL_SOURCE -I." clib
	cd $(WORKDIR) && gcc -O2 -I.. -I$(PKGDEST)/include -D_ALL_SOURCE -o $(PKGNAME) linuxproj/main.c $(PKGDEST)/include/strtoull.c -Lbuild/linux -Wl,-R$(PKGDEST)/lib -ldistorm64

do-pkginst:
	mkdir dest && cd dest && mkdir bin include lib
	install -sc $(WORKDIR)/$(PKGNAME) dest/bin
	install -sc $(WORKDIR)/build/linux/libdistorm64.so dest/lib/libdistorm64.so.$(PKGVER)
	cd dest/lib && ln -s libdistorm64.so.$(PKGVER) libdistorm64.so
	install -c $(WORKDIR)/distorm.h dest/include
