PKGNAME = python
PKGVER  = 2.5
BLDDEPS = ginstall
DEPENDS = readline

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
	cd $(WORKDIR) && gmake

do-pkginst:
	cd $(WORKDIR) && gmake prefix=`pwd`/../dest install
	cd dest/bin && rm python *-config
	strip dest/bin/$(PKGNAME)$(PKGVER)
	cd dest/bin && ln -s $(PKGNAME)$(PKGVER) $(PKGNAME)
