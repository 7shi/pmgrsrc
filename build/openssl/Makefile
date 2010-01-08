# cf. http://www.hakusan.tsg.ne.jp/tjkawa/lib/interix/simplymake.jsp

PKGNAME = openssl
PKGVER  = 0.9.8l
#BLDDEPS = perl

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCES = $(WORKDIR).tar.gz
SRCURL  = ftp://ftp.infoscience.co.jp/pub/Crypto/SSL/openssl/source
#SRCURL  = http://www.openssl.org/source

do-fetch: std-fetch
do-extract: std-extract
do-patch:

do-config:
	cd $(WORKDIR) && ./Configure --prefix=$(PKGDEST) threads Interix-gcc

do-build:
	cd $(WORKDIR) && gmake

do-pkginst:
	cd $(WORKDIR) && gmake INSTALL_PREFIX=`pwd`/../dest install
	mv dest$(PKGDEST)/* dest
	rm -rf dest/`echo $(PKGDEST) | sed -e "s|^/||" | sed -e "s|/.*$$||" | sed -e "s|^|/|"`
	strip dest/bin/openssl
