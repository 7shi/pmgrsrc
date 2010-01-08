PKGNAME = perl
PKGVER  = 5.8.8

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCE  = $(WORKDIR).tar.bz2
SRCURL  = http://ftp.funet.fi/pub/CPAN/src/$(SOURCE)

do-fetch:
	if [ ! -f $(DISTDIR)/$(SOURCE) ]; then $(HTTPGET) $(SRCURL) && mv $(SOURCE) $(DISTDIR); fi

do-extract:
	pmgr-extract $(DISTDIR)/$(SOURCE)

do-patch:

do-config:
	cd $(WORKDIR) && sh Configure -sde -Dprefix=$(PKGDEST) -Uinstallusrbinperl

do-build:
	gmake -C $(WORKDIR)

do-pkginst:
	gmake -C $(WORKDIR) DESTDIR="`pwd`/dest" INSTALLFLAGS="--man1dir=`pwd`/dest$(PKGDEST)/lib/perl5/man/man1 --man1ext=1 --man3dir=`pwd`/dest$(PKGDEST)/lib/perl5/man/man3 --man3ext=3" install
	mv dest$(PKGDEST)/* dest
	rm -rf dest/`echo $(PKGDEST) | sed -e "s|^/||" | sed -e "s|/.*$$||" | sed -e "s|^|/|"`
	cd dest/bin && strip perl perl$(PKGVER)
