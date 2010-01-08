PKGNAME = subversion
PKGVER  = 1.4.3
DEPENDS = zlib libiconv

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCES = $(WORKDIR).tar.bz2 $(PKGNAME)-deps-$(PKGVER).tar.bz2
SRCURL  = http://subversion.tigris.org/downloads

do-fetch: std-fetch
do-extract: std-extract
do-patch: fix-configure

do-config:
	cd $(WORKDIR) && CPPFLAGS="-I$(PKGDEST)/include -D_ALL_SOURCE" LDFLAGS=-L$(PKGDEST)/lib ./configure --prefix=$(PKGDEST)

do-build:
	cd $(WORKDIR) && gmake

do-pkginst:
	cd $(WORKDIR) && gmake prefix=`pwd`/../dest install
	strip dest/bin/svn*
