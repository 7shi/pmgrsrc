PKGNAME = gmake
PKGVER  = 3.81

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = make-$(PKGVER)
SOURCE  = $(WORKDIR).tar.gz
SRCURL  = http://ftp.gnu.org/gnu/make/$(SOURCE)

do-fetch:
	if [ ! -f $(DISTDIR)/$(SOURCE) ]; then $(HTTPGET) $(SRCURL) && mv $(SOURCE) $(DISTDIR); fi

do-extract:
	pmgr-extract $(DISTDIR)/$(SOURCE)

do-patch:
	cp $(TOPDIR)/share/config.* $(WORKDIR)/config

do-config:
	cd $(WORKDIR) && ./configure --prefix=$(PKGDEST) --program-prefix=g

do-build:
	cd $(WORKDIR) && make

do-pkginst:
	for mk in `find $(WORKDIR) -name Makefile`; do cp $$mk $$mk.orig && sed -e "s|^prefix *= */.*$$|prefix = `pwd`/dest|" $$mk.orig > $$mk; done
	cd $(WORKDIR) && make install
	strip dest/bin/*
