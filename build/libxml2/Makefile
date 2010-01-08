PKGNAME = libxml2
PKGVER  = 2.7.6
BLDDEPS = libtool

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCES = $(WORKDIR).tar.gz
SRCURL  = ftp://ftp.xmlsoft.org/$(PKGNAME)

do-fetch: std-fetch
do-extract: std-extract
do-patch: #fix-configure

do-config:
	cd $(WORKDIR) && LDFLAGS=-Wl,-R$(PKGDEST)/lib ./configure --prefix=$(PKGDEST) --without-python

do-build:
	cd $(WORKDIR) && gmake

do-pkginst:
	cd $(WORKDIR) && gmake prefix=`pwd`/../dest install
	cd dest/bin && strip xmlcatalog xmllint
