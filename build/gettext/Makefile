PKGNAME = gettext
PKGVER  = 0.17
DEPENDS = libiconv

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCES = $(WORKDIR).tar.gz
SRCURL  = ftp://ftp.gnu.org/gnu/$(PKGNAME)

do-fetch: std-fetch
do-extract: std-extract
do-patch: fix-configure

do-config:
	cd $(WORKDIR) && ./configure --prefix=$(PKGDEST) CPPFLAGS=-D_ALL_SOURCE
	echo "all install:" > $(WORKDIR)/gettext-tools/examples/Makefile

do-build:
	cd $(WORKDIR) && gmake

do-pkginst:
	cd $(WORKDIR) && gmake prefix=`pwd`/../dest install
	strip dest/bin/msg*
	for lib in dest/lib/*.so.*; do if [ ! -L $$lib ]; then strip $$lib; chmod 755 $$lib; fi; done
