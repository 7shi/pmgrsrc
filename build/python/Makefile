PKGNAME = python
PKGVER  = 2.6.4
BLDDEPS = ginstall
#DEPENDS = readline zlib openssl

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = Python-$(PKGVER)
SOURCES = $(WORKDIR).tar.bz2
SRCURL  = http://www.python.org/ftp/$(PKGNAME)/$(PKGVER)

do-fetch: std-fetch
do-extract: std-extract

do-patch:
	cp $(PKGDEST)/share/libtool/config.* $(WORKDIR)/Modules/_ctypes/libffi

do-config:
	cd $(WORKDIR) && CC="gcc -D_ALL_SOURCE" CPPFLAGS="-I$(PKGDEST)/include" LDFLAGS="-L$(PKGDEST)/lib -Wl,-R$(PKGDEST)/lib" ./configure --prefix=$(PKGDEST)

do-build:
	cd $(WORKDIR) && make

do-pkginst:
	cd $(WORKDIR) && make prefix=`pwd`/../dest install
	cd dest/bin && rm python *-config
	strip dest/bin/$(PKGNAME)2.6
	cd dest/bin && ln -s $(PKGNAME)2.6 $(PKGNAME)
