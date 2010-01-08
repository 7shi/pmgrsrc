PKGNAME = perl
PKGVER  = 5.8.8

TOPDIR  = ../..
include $(TOPDIR)/common.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCE  = $(WORKDIR).tar.bz2
SRCURL  = http://ftp.funet.fi/pub/CPAN/src/$(SOURCE)

all: build

.fetch: .depend
	@echo && echo ===== fetch =====
	mkdir -p $(DISTDIR)
	if [ ! -f $(DISTDIR)/$(SOURCE) ]; then $(HTTPGET) $(SRCURL) && mv $(SOURCE) $(DISTDIR); fi
	touch $@

.extract: .fetch
	@echo && echo ===== extract =====
	pmgr-extract $(DISTDIR)/$(SOURCE)
	touch $@

.patch: .extract
	@echo && echo ===== patch =====
	touch $@

.config: .patch
	@echo && echo ===== config =====
	cd $(WORKDIR) && sh Configure -sde -Dprefix=$(PKGDEST) -Uinstallusrbinperl
	touch $@

.build: .config
	@echo && echo ===== build =====
	gmake -C $(WORKDIR)
	touch $@

.pkginst: .build
	@echo && echo ===== pkginst =====
	rm -rf dest
	gmake -C $(WORKDIR) DISTDIR="`pwd`/dest" INSTALLFLAGS="--man1dir=`pwd`/dest$(PKGDEST)/lib/perl5/man/man1 --man1ext=1 --man3dir=`pwd`/dest$(PKGDEST)/lib/perl5/man/man3 --man3ext=3" install
	mv dest$(PKGDEST)/* dest
	rm -rf dest/`echo $(PKGDEST) | sed -e "s|^/||" | sed -e "s|/.*$$||" | sed -e "s|^|/|"`
	cd dest/bin && strip perl perl$(PKGVER)
	touch $@

include $(TOPDIR)/pmgr.mk
