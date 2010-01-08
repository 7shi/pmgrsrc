PKGNAME = flex
PKGVER  = 2.5.35
BLDDEPS = bison

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCES = $(WORKDIR).tar.gz
SRCURL  = http://downloads.sourceforge.net/sourceforge/$(PKGNAME)
#SRCURL = ftp://ftp.gnu.org/non-gnu/$(PKGNAME)

do-fetch: std-fetch
do-extract: std-extract
do-patch: fix-configure

do-config:
	cd $(WORKDIR) && ./configure --prefix=$(PKGDEST) --disable-nls

do-build:
	cd $(WORKDIR) && gmake

do-pkginst:
	cd $(WORKDIR) && gmake prefix=`pwd`/../dest install
	strip dest/bin/flex
