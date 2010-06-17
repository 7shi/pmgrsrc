PKGNAME = mpc
PKGVER  = 0.8.2
DEPENDS = gmp mpfr

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCES = $(WORKDIR).tar.gz
SRCURL  = http://www.multiprecision.org/mpc/download

do-fetch: std-fetch
do-extract: std-extract
do-patch:

do-config:
	cd $(WORKDIR) && CPPFLAGS=-I$(PKGDEST)/include LDFLAGS="-L$(PKGDEST)/lib -Wl,-R$(PKGDEST)/lib" ./configure --prefix=$(PKGDEST)

do-build:
	cd $(WORKDIR) && make

do-pkginst:
	cd $(WORKDIR) && make prefix=`pwd`/../dest install
	for lib in dest/lib/*.so.*; do if [ ! -L $$lib ]; then strip $$lib; chmod 755 $$lib; fi; done
