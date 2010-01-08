PKGNAME = python
PKGVER  = 2.5

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = Python-$(PKGVER)
SOURCE  = $(WORKDIR).tar.bz2
SRCURL  = http://www.python.org/ftp/$(PKGNAME)/$(PKGVER)/$(SOURCE)

do-fetch:
	if [ ! -f $(DISTDIR)/$(SOURCE) ]; then $(HTTPGET) $(SRCURL) && mv $(SOURCE) $(DISTDIR); fi

do-extract:
	pmgr-extract $(DISTDIR)/$(SOURCE)

do-patch:
	-patch -p0 -d $(WORKDIR) < patch-al
	cd $(WORKDIR) && cp Makefile.pre.in Makefile.pre.in.orig && cat Makefile.pre.in.orig | sed -e "s/@BUILDEXEEXT@/.exe/" > Makefile.pre.in

do-config:
	cd $(WORKDIR) && CC="gcc -D_ALL_SOURCE" ./configure --prefix=$(PKGDEST)

do-build:
	gmake -C $(WORKDIR)

do-pkginst:
	-gmake -k -C $(WORKDIR) prefix=`pwd`/dest install
	cd dest/bin && rm python *-config
	strip dest/bin/*
	cd dest/bin && ln -s $(PKGNAME)$(PKGVER) $(PKGNAME)
