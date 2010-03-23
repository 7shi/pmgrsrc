PKGNAME = $(ARCH_PREFIX)-sdl
PKGVER  = 1.2.14
DEPENDS = $(ARCH_PREFIX)/gcc

include ../cross.mk
TOPDIR  = $(TOPDIR_)/..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = SDL-$(PKGVER)
SOURCES = $(WORKDIR).tar.gz
SRCURL  = http://www.libsdl.org/release

do-fetch: std-fetch
do-extract: std-extract
do-patch: #fix-configure

do-config:
	cd $(WORKDIR) && ./configure --prefix=$(PKGDEST)/$(ARCH_PREFIX) --host=$(ARCH_PREFIX)

do-build:
	cd $(WORKDIR) && make

do-pkginst:
	cd $(WORKDIR) && make prefix=`pwd`/../dest/$(ARCH_PREFIX) install
