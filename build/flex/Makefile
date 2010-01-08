PKGNAME = flex
PKGVER  = 2.5.4a
BLDDEPS = bison

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-2.5.4
SOURCES = $(PKGNAME)-$(PKGVER).tar.gz
SRCURL  = ftp://ftp.gnu.org/non-gnu/$(PKGNAME)

do-fetch: std-fetch
do-extract: std-extract
do-patch:

do-config:
	cd $(WORKDIR) && ./configure --prefix=$(PKGDEST)

do-build:
	cd $(WORKDIR) && gmake

do-pkginst:
	cd $(WORKDIR) && gmake prefix=`pwd`/../dest install
	strip dest/bin/flex
	rm dest/bin/flex++
