PKGNAME = ginstall
PKGVER  = 4.1

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = fileutils-$(PKGVER)
SOURCES = $(WORKDIR).tar.gz
SRCURL  = ftp://ftp.gnu.org/gnu/fileutils

do-fetch: std-fetch
do-extract: std-extract

do-patch:
	cp $(PKGDEST)/share/libtool/config.* $(WORKDIR)

do-config:
	cd $(WORKDIR) && ./configure --prefix=$(PKGDEST)

do-build:
	cd $(WORKDIR)/lib && gmake
	cd $(WORKDIR)/intl && gmake
	cd $(WORKDIR)/src && gmake ginstall

do-pkginst:
	mkdir -p dest/bin dest/man/man1
	install -cs -m 0755 $(WORKDIR)/src/ginstall dest/bin
	install -c -m 0644 $(WORKDIR)/man/ginstall.1 dest/man/man1
