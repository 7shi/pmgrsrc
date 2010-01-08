# cf. http://www.hakusan.tsg.ne.jp/tjkawa/lib/interix/simplymake.jsp

PKGNAME = openssl
PKGVER  = 0.9.7m
BLDDEPS = perl

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCE  = $(WORKDIR).tar.gz
SRCURL  = http://www.openssl.org/source/$(SOURCE)

do-fetch:
	if [ ! -f $(DISTDIR)/$(SOURCE) ]; then $(HTTPGET) $(SRCURL) && mv $(SOURCE) $(DISTDIR); fi

do-extract:
	pmgr-extract $(DISTDIR)/$(SOURCE)

do-patch:
	cat patch-* | patch -p0 -d $(WORKDIR)

do-config:
	cd $(WORKDIR) && ./Configure --prefix=$(PKGDEST) threads Interix-gcc

do-build:
	gmake -C $(WORKDIR)

do-pkginst:
	gmake -C $(WORKDIR) INSTALL_PREFIX=`pwd`/dest install
	mv dest$(PKGDEST)/* dest
	rm -rf dest/`echo $(PKGDEST) | sed -e "s|^/||" | sed -e "s|/.*$$||" | sed -e "s|^|/|"`
	strip dest/bin/openssl
