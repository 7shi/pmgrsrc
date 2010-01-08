PKGNAME = automake
PKGVER  = 1.10
DEPENDS = autoconf

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCES = $(WORKDIR).tar.bz2
SRCURL  = ftp://ftp.gnu.org/gnu/$(PKGNAME)

do-fetch: std-fetch
do-extract: std-extract
do-patch:

do-config:
	cd $(WORKDIR) && ./configure --prefix=$(PKGDEST)

do-build:
	cd $(WORKDIR) && gmake

do-pkginst:
	cd $(WORKDIR) && gmake prefix=`pwd`/../dest install
