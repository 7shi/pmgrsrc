PKGNAME = cvs
PKGVER  = 1.11.22

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCE  = $(WORKDIR).tar.gz
SRCURL  = http://ftp.gnu.org/non-gnu/$(PKGNAME)/source/stable/$(PKGVER)/$(SOURCE)

do-fetch:
	if [ ! -f $(DISTDIR)/$(SOURCE) ]; then $(HTTPGET) $(SRCURL) && mv $(SOURCE) $(DISTDIR); fi

do-extract:
	pmgr-extract $(DISTDIR)/$(SOURCE)

do-patch:

do-config:
	cd $(WORKDIR) && ./configure --prefix=$(PKGDEST)

do-build:
	gmake -C $(WORKDIR)

do-pkginst:
	gmake -C $(WORKDIR) prefix=`pwd`/dest install
	strip dest/bin/cvs
	rm dest/bin/rcs2log
