PKGNAME = perl
PKGVER  = 5.8.8

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCES = $(WORKDIR).tar.bz2
SRCURL  = ftp://ftp.funet.fi/pub/CPAN/src

do-fetch: std-fetch
do-extract: std-extract
do-patch:

do-config:
	cd $(WORKDIR) && sh Configure -sde -Dprefix=$(PKGDEST) -Uinstallusrbinperl

do-build:
	cd $(WORKDIR) && gmake

do-pkginst:
	cd $(WORKDIR) && gmake DESTDIR="`pwd`/../dest" INSTALLFLAGS="--man1dir=`pwd`/../dest$(PKGDEST)/lib/perl5/man/man1 --man1ext=1 --man3dir=`pwd`/../dest$(PKGDEST)/lib/perl5/man/man3 --man3ext=3" install
	mv dest$(PKGDEST)/* dest
	rm -rf dest/`echo $(PKGDEST) | sed -e "s|^/||" | sed -e "s|/.*$$||" | sed -e "s|^|/|"`
	cd dest/bin && strip perl perl$(PKGVER)
