PKGNAME = libiconv
PKGVER  = 1.11

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCE  = $(WORKDIR).tar.gz
SRCURL  = http://ftp.gnu.org/gnu/$(PKGNAME)/$(SOURCE)

do-fetch:
	if [ ! -f $(DISTDIR)/$(SOURCE) ]; then $(HTTPGET) $(SRCURL) && mv $(SOURCE) $(DISTDIR); fi

do-extract:
	pmgr-extract $(DISTDIR)/$(SOURCE)

do-patch:
	cp $(WORKDIR)/build-aux/config.guess $(WORKDIR)/libcharset/build-aux/config.guess

do-config:
	cd $(WORKDIR) && ./configure --prefix=$(PKGDEST)

do-build:
	gmake -C $(WORKDIR)

do-pkginst:
	gmake -C $(WORKDIR) prefix=`pwd`/dest install
	strip dest/bin/*
