PKGNAME = file
PKGVER  = 5.03

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCES = $(WORKDIR).tar.gz
SRCURL  = ftp://ftp.astron.com/pub/$(PKGNAME)

do-fetch: std-fetch
do-extract: std-extract
do-patch: #fix-configure

do-config:
	cd $(WORKDIR) && ./configure --prefix=$(PKGDEST) CPPFLAGS="-I$(PKGDEST)/include -D_ALL_SOURCE"

do-build:
	cd $(WORKDIR) && make

do-pkginst:
	cd $(WORKDIR) && make prefix=`dirname \`pwd\``/dest install
	strip dest/bin/*
