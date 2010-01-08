PKGNAME = nasm
PKGVER  = 0.98.39

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCES = $(WORKDIR).tar.bz2
SRCURL  = http://jaist.dl.sourceforge.net/sourceforge/$(PKGNAME)

do-fetch: std-fetch
do-extract: std-extract
do-patch:

do-config:
	cd $(WORKDIR) && ./configure --prefix=$(PKGDEST)

do-build:
	cd $(WORKDIR) && gmake

do-pkginst:
	mkdir -p dest/bin dest/man/man1
	cd $(WORKDIR) && gmake prefix=`pwd`/../dest install
	strip dest/bin/*
