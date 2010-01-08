PKGNAME = gtar
PKGVER  = 1.22
DEPENDS = xz

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = tar-$(PKGVER)
SOURCES = $(WORKDIR).tar.bz2
SRCURL  = http://ftp.gnu.org/gnu/tar

do-fetch: std-fetch
do-extract: std-extract
do-patch:

do-config:
	cd $(WORKDIR) && ./configure --prefix=$(PKGDEST) --program-prefix=g CPPFLAGS=-D_ALL_SOURCE

do-build:
	cd $(WORKDIR) && gmake HAVE_STDINT_H=0

do-pkginst:
	cd $(WORKDIR) && gmake prefix=`pwd`/../dest install
	strip dest/bin/*
