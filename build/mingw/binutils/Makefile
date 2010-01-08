PKGNAME = mingw-binutils
PKGVER  = 2.17

include ../cross.mk
TOPDIR  = $(TOPDIR_)/..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = binutils-$(PKGVER)
SOURCES = $(WORKDIR).tar.bz2
SRCURL  = ftp://ftp.gnu.org/gnu/binutils

do-fetch: std-fetch
do-extract: std-extract

do-patch:
	cp $(PKGDEST)/share/libtool/config.* $(WORKDIR)

do-config:
	cd $(WORKDIR) && CPPFLAGS=-D_ALL_SOURCE LDFLAGS=-Wl,-R$(PKGDEST)/lib ./configure --prefix=$(PKGDEST) --target=$(ARCH_PREFIX)

do-build:
	cd $(WORKDIR) && CPPFLAGS=-D_ALL_SOURCE LDFLAGS=-Wl,-R$(PKGDEST)/lib gmake

do-pkginst:
	cd $(WORKDIR) && gmake prefix=`pwd`/../dest install
	for exe in addr2line ar as c++filt dlltool dllwrap ld nm objcopy objdump ranlib readelf size strings strip windres; do strip dest/bin/$(ARCH_PREFIX)-$$exe; done
	for exe in ar as dlltool ld nm objdump ranlib strip; do strip dest/$(ARCH_PREFIX)/bin/$$exe; done
