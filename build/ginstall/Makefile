PKGNAME = ginstall
PKGVER  = 6.9

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = coreutils-$(PKGVER)
SOURCES = $(WORKDIR).tar.gz
SRCURL  = ftp://ftp.gnu.org/gnu/coreutils

do-fetch: std-fetch
do-extract: std-extract

do-patch:
	cp $(PKGDEST)/share/libtool/config.* $(WORKDIR)

do-config:
	cd $(WORKDIR) && ./configure --prefix=$(PKGDEST)

do-build:
	cd $(WORKDIR)/lib && make
	cd $(WORKDIR)/src && make ginstall

do-pkginst:
	mkdir -p dest/bin dest/man/man1
	install -cs -m 0755 $(WORKDIR)/src/ginstall dest/bin
	install -c -m 0644 $(WORKDIR)/man/install.1 dest/man/man1/ginstall.1
