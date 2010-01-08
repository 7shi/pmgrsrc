PKGNAME = yasm
PKGVER  = 0.6.0

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCE  = $(WORKDIR).tar.gz
SRCURL  = http://www.tortall.net/projects/$(PKGNAME)/releases/$(SOURCE)

do-fetch:
	if [ ! -f $(DISTDIR)/$(SOURCE) ]; then $(HTTPGET) $(SRCURL) && mv $(SOURCE) $(DISTDIR); fi

do-extract:
	pmgr-extract $(DISTDIR)/$(SOURCE)

do-patch:
	cp $(TOPDIR)/share/config.* $(WORKDIR)/config

do-config:
	cd $(WORKDIR) && ./configure --prefix=$(PKGDEST)

do-build:
	gmake -C $(WORKDIR)

do-pkginst:
	gmake -C $(WORKDIR) prefix=`pwd`/dest install
	strip dest/bin/*
