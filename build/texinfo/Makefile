PKGNAME = texinfo
PKGVER  = 4.8a

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-4.8
SOURCES = $(PKGNAME)-$(PKGVER).tar.gz
SRCURL  = ftp://ftp.gnu.org/gnu/$(PKGNAME)

do-fetch: std-fetch
do-extract: std-extract
do-patch: fix-configure

do-config:
	cd $(WORKDIR) && ./configure --prefix=$(PKGDEST) LDFLAGS=-Wl,-R$(PKGDEST)/lib

do-build:
	cd $(WORKDIR) && gmake

do-pkginst:
	cd $(WORKDIR) && gmake prefix=`pwd`/../dest install
	cd dest/bin && strip *info* texindex
