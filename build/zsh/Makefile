PKGNAME = zsh
PKGVER  = 4.2.6
BLDDEPS = bash

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCE  = $(WORKDIR).tar.gz
SRCURL  = http://jaist.dl.sourceforge.net/sourceforge/$(PKGNAME)/$(SOURCE)

do-fetch:
	if [ ! -f $(DISTDIR)/$(SOURCE) ]; then $(HTTPGET) $(SRCURL) && mv $(SOURCE) $(DISTDIR); fi

do-extract:
	pmgr-extract $(DISTDIR)/$(SOURCE)

do-patch:
	cp $(TOPDIR)/share/config.* $(WORKDIR)
	cat patch-* | patch -p0 -d $(WORKDIR)

do-config:
	cd $(WORKDIR) && bash configure --prefix=$(PKGDEST)
	cat config.h.interix >> $(WORKDIR)/config.h

do-build:
	gmake -C $(WORKDIR)

do-pkginst:
	gmake -C $(WORKDIR) prefix=`pwd`/dest install
	rm dest/bin/zsh-*
	strip dest/bin/zsh
