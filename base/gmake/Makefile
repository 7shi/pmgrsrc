PKGNAME = gmake
PKGVER  = 3.81

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk
include ../base.mk

WORKDIR = make-$(PKGVER)
SOURCES = $(WORKDIR).tar.gz
SRCURL  = http://ftp.gnu.org/gnu/make

do-fetch: std-fetch
do-extract: std-extract
do-patch: fix-configure

do-config:
	cd $(WORKDIR) && ./configure --prefix=$(PKGDEST) --program-prefix=g --disable-nls

do-build:
	cd $(WORKDIR) && $(MAKE)

do-pkginst:
	cd $(WORKDIR) && ./make prefix=`pwd`/../dest install
	strip dest/bin/*
