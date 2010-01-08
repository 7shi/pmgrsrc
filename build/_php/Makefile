PKGNAME = php
PKGVER  = 5.2.6
DEPENDS = libxml2
BLDDEPS = libtool

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCES = $(WORKDIR).tar.gz
SRCURL  = http://jp.php.net/distributions

do-fetch: std-fetch
do-extract: std-extract
do-patch: fix-configure

do-config:
	cd $(WORKDIR) && CFLAGS=-D_ALL_SOURCE ./configure --prefix=$(PKGDEST) --with-libxml-dir=$(PKGDEST)

do-build:
	cd $(WORKDIR) && gmake

do-pkginst:
	cd $(WORKDIR) && gmake prefix=`pwd`/../dest install
	cd dest/bin && strip php php-cgi
