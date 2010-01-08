PKGNAME = libtool
PKGVER  = 2.2.6a

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-2.2.6
SOURCES = $(PKGNAME)-$(PKGVER).tar.gz
SRCURL  = ftp://ftp.gnu.org/gnu/$(PKGNAME)

do-fetch: std-fetch
do-extract: std-extract
do-patch:

do-config:
	cd $(WORKDIR) && ./configure --prefix=$(PKGDEST)

do-build:
	cd $(WORKDIR) && gmake

do-pkginst:
	cd $(WORKDIR) && gmake prefix=`pwd`/../dest install
	for lib in dest/lib/*.so.*; do if [ ! -L $$lib ]; then strip $$lib; chmod 755 $$lib; fi; done
