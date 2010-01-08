PKGNAME = bison
PKGVER  = 2.3
DEPENDS = m4

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
	chmod 666 $(WORKDIR)/build-aux/config.*
	cp $(TOPDIR)/share/config.* $(WORKDIR)/build-aux

do-config:
	cd $(WORKDIR) && ./configure --prefix=$(PKGDEST)

do-build:
	gmake -C $(WORKDIR)

do-pkginst:
	gmake -C $(WORKDIR) prefix=`pwd`/dest install
	strip dest/bin/bison
