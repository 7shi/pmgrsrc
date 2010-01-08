PKGNAME = subversion
PKGVER  = 1.4.3
DEPENDS = zlib libiconv

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCE  = $(WORKDIR).tar.bz2 $(PKGNAME)-deps-$(PKGVER).tar.bz2
SRCURL  = http://subversion.tigris.org/downloads

do-fetch:
	for f in $(SOURCE); do if [ ! -f $(DISTDIR)/$$f ]; then $(HTTPGET) $(SRCURL)/$$f && mv $$f $(DISTDIR); fi; done

do-extract:
	for f in $(SOURCE); do pmgr-extract $(DISTDIR)/$$f; done

do-patch:
	for d in `find $(WORKDIR) -name config.guess`; do cp $(TOPDIR)/share/config.* `dirname $$d`; done

do-config:
	cd $(WORKDIR) && CPPFLAGS="-I$(PKGDEST)/include -D_ALL_SOURCE" LDFLAGS=-L$(PKGDEST)/lib ./configure --prefix=$(PKGDEST)

do-build:
	gmake -C $(WORKDIR)

do-pkginst:
	gmake -C $(WORKDIR) prefix=`pwd`/dest install
	strip dest/bin/svn*
