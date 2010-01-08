PKGNAME = mingw-gcc
PKGVER  = 4.1.2
BLDDEPS = flex bison texinfo
DEPENDS = mingw/binutils mingw/runtime mingw/w32api

include ../mingw.mk
TOPDIR  = $(TOPDIR_)/..
include $(TOPDIR)/common.mk

WORKDIR = gcc-$(PKGVER)
SOURCE  = $(WORKDIR).tar.bz2
SRCURL  = http://ftp.gnu.org/gnu/gcc/$(WORKDIR)/$(SOURCE)

all: build

.fetch: .depend
	@echo && echo ===== fetch =====
	mkdir -p $(DISTDIR)
	if [ ! -f $(DISTDIR)/$(SOURCE) ]; then $(HTTPGET) $(SRCURL) && mv $(SOURCE) $(DISTDIR); fi
	touch $@

.extract: .fetch
	@echo && echo ===== extract =====
	pmgr-extract $(DISTDIR)/$(SOURCE)
	touch $@

.patch: .extract
	@echo && echo ===== patch =====
	cp $(TOPDIR)/share/config.* $(WORKDIR)
	cd $(WORKDIR)/libobjc && touch tconfig.h tm.h gthr-default.h
	touch $@

.config: .patch
	@echo && echo ===== config =====
	cd $(WORKDIR) && CPPFLAGS=-D_ALL_SOURCE ./configure --prefix=$(PKGDEST) --target=$(ARCH_PREFIX)
	cd $(WORKDIR) && cp Makefile Makefile.orig
	cd $(WORKDIR) && sed -e 's|^SHELL *=.*$$|SHELL = /bin/sh|' Makefile.orig > Makefile
	touch $@

.build: .config
	@echo && echo ===== build =====
	CPPFLAGS=-D_ALL_SOURCE gmake -C $(WORKDIR)
	touch $@

.pkginst: .build
	@echo && echo ===== pkginst =====
	rm -rf dest
	gmake -C $(WORKDIR) prefix=`pwd`/dest install
	for exe in c++ cpp fastjar g++ gcc gcc-4.1.2 gcj gcjh gcov gjnih grepjar jcf-dump jv-scan; do strip dest/bin/$(ARCH_PREFIX)-$$exe; done
	cd dest/libexec/gcc/i386-mingw32/4.1.2 && strip c* j*
	touch $@

include $(TOPDIR)/pmgr.mk
