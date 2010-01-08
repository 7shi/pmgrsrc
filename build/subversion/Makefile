PKGNAME = subversion
PKGVER  = 1.5.7

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCES = $(WORKDIR).tar.bz2 $(PKGNAME)-deps-$(PKGVER).tar.bz2
SRCURL  = http://subversion.tigris.org/downloads

do-fetch: std-fetch
do-extract: std-extract
do-patch: #fix-configure

do-config:
	cd $(WORKDIR) && CPPFLAGS="-I$(PKGDEST)/include -D_ALL_SOURCE" LDFLAGS=-L$(PKGDEST)/lib ./configure --prefix=$(PKGDEST)

do-build:
	cd $(WORKDIR) && make

do-pkginst:
	rm -rf $(WORKDIR)/dest
	cd $(WORKDIR) && make DESTDIR=`pwd`/dest install
	mkdir -p dest
	mv $(WORKDIR)/dest$(PKGDEST)/* dest
	strip dest/bin/svn*
	chmod 755 dest/lib/libserf-0.so.0.0.0
