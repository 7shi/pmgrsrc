PKGNAME = xz
PKGVER  = 4.999.9beta

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCES = $(WORKDIR).tar.bz2
SRCURL  = http://tukaani.org/$(PKGNAME)

do-fetch: std-fetch
do-extract: std-extract
do-patch: #fix-configure

do-config:
	cd $(WORKDIR) && ./configure --prefix=$(PKGDEST) --disable-assembler

do-build:
	cd $(WORKDIR) && gmake

do-pkginst:
	cd $(WORKDIR) && gmake prefix=`pwd`/../dest install
	cd dest/bin && strip lzmadec lzmainfo xz xzdec
