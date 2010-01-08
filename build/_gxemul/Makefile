PKGNAME = gxemul
PKGVER  = 0.4.7.2

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCES = $(WORKDIR).tar.gz
SRCURL  = http://gxemul.sourceforge.net/src

do-fetch: std-fetch
do-extract: std-extract

do-patch:
	cp inttypes.h $(WORKDIR)
	cp inttypes.h $(WORKDIR)/src/include

do-config:
	cd $(WORKDIR) && CFLAGS=-I. ./configure --disable-x

do-build:
	cd $(WORKDIR) && make

do-pkginst:
	mkdir -p dest/bin
	mkdir -p dest/man/man1
	mkdir -p dest/share/doc/$(PKGNAME)
	cp $(WORKDIR)/$(PKGNAME) dest/bin
	cp $(WORKDIR)/man/$(PKGNAME).1 dest/man/man1
	cp $(WORKDIR)/doc/* dest/share/doc/$(PKGNAME)
	strip dest/bin/*
