PKGNAME = git
PKGVER  = 1.6.5.7
BLDDEPS = ginstall

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCES = $(WORKDIR).tar.bz2
SRCURL  = http://kernel.org/pub/software/scm/$(PKGNAME)

do-fetch: std-fetch
do-extract: std-extract
do-patch: #fix-configure

do-config:
	cd $(WORKDIR) && CC=gcc ./configure --prefix=$(PKGDEST)

do-build:
	cd $(WORKDIR) && make

do-pkginst:
	rm -rf $(WORKDIR)/dest
	cd $(WORKDIR) && make DESTDIR=`pwd`/dest INSTALL=ginstall install
	mkdir -p dest
	mv $(WORKDIR)/dest$(PKGDEST)/* dest
	cd dest/bin && strip git git-receive-pack git-shell git-upload-archive git-upload-pack
