PKGNAME = lzma
PKGVER  = 4.32.7

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCES = $(WORKDIR).tar.bz2
SRCURL  = http://tukaani.org/$(PKGNAME)

do-fetch: std-fetch
do-extract: std-extract

do-patch: #fix-configure
	cp inttypes.h $(WORKDIR)

do-config:
	cd $(WORKDIR) && CPPFLAGS=-D_ALL_SOURCE ./configure --prefix=$(PKGDEST)

do-build:
	cd $(WORKDIR) && gmake

do-pkginst:
	cd $(WORKDIR) && gmake prefix=`pwd`/../dest install
	strip dest/bin/$(PKGNAME)*
