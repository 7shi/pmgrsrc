PKGNAME = zlib
PKGVER  = 1.2.3

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCES = $(WORKDIR).tar.gz
SRCURL  = http://jaist.dl.sourceforge.net/sourceforge/libpng

do-fetch: std-fetch
do-extract: std-extract
do-patch:

do-config:
	#cd $(WORKDIR) && ./configure --prefix=$(PKGDEST) --shared
	cd $(WORKDIR) && CFLAGS=-g ./configure --prefix=$(PKGDEST) --shared

do-build:
	cd $(WORKDIR) && gmake all libz.a

do-pkginst:
	cd $(WORKDIR) && gmake prefix=`pwd`/../dest install
	cp $(WORKDIR)/libz.a dest/lib
