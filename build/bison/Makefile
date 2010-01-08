PKGNAME = bison
PKGVER  = 2.3
DEPENDS = m4 gettext

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCES = $(WORKDIR).tar.gz
SRCURL  = ftp://ftp.gnu.org/gnu/$(PKGNAME)

do-fetch: std-fetch

do-extract: std-extract
	chmod 666 $(WORKDIR)/build-aux/config.*

do-patch: fix-configure

do-config:
	cd $(WORKDIR) && ./configure --prefix=$(PKGDEST) LDFLAGS="-Wl,-R$(PKGDEST)/lib"

do-build:
	cd $(WORKDIR) && gmake

do-pkginst:
	cd $(WORKDIR) && gmake prefix=`pwd`/../dest install
	strip dest/bin/bison
