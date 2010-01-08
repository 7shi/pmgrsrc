PKGNAME = zsh
PKGVER  = 4.2.6
BLDDEPS = bash

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCES = $(WORKDIR).tar.gz
SRCURL  = http://jaist.dl.sourceforge.net/sourceforge/$(PKGNAME)

do-fetch: std-fetch
do-extract: std-extract
do-patch: fix-configure

do-config:
	cd $(WORKDIR) && bash configure --prefix=$(PKGDEST)
	cat config.h.interix >> $(WORKDIR)/config.h

do-build:
	cd $(WORKDIR) && gmake

do-pkginst:
	cd $(WORKDIR) && gmake prefix=`pwd`/../dest install
	rm dest/bin/zsh-*
	strip dest/bin/zsh
