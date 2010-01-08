PKGNAME = mingw-gcc
PKGVER  = 4.1.2
DEPENDS = bzip2 texinfo mingw/binutils mingw/runtime mingw/w32api

TOPDIR  = ../../..
include $(TOPDIR)/common.mk
include ../mingw.mk

WORKDIR = gcc-$(PKGVER)
SOURCE  = $(WORKDIR).tar.bz2
SRCURL  = http://ftp.gnu.org/gnu/gcc/$(WORKDIR)/$(SOURCE)

all: build

fetch: .fetch
.fetch: .depend
	@echo && echo ===== $@ =====
	mkdir -p $(DESTDIR)
	if [ ! -f $(DESTDIR)/$(SOURCE) ]; then $(HTTPGET) $(SRCURL) && mv $(SOURCE) $(DESTDIR); fi
	touch $@

extract: .extract
.extract: .fetch
	@echo && echo ===== $@ =====
	pmgr-extract j $(DESTDIR)/$(SOURCE)
	touch $@

patch: .patch
.patch: .extract
	@echo && echo ===== $@ =====
	cp $(TOPDIR)/share/config.* $(WORKDIR)
	cd $(WORKDIR)/libobjc && touch tconfig.h tm.h gthr-default.h
	touch $@

config: .config
.config: .patch
	@echo && echo ===== $@ =====
	cd $(WORKDIR) && CPPFLAGS=-D_ALL_SOURCE ./configure --prefix=$(PKGDEST) --target=$(ARCH_PREFIX)
	touch $@

post-config: .post-config
.post-config: .config
	@echo && echo ===== $@ =====
	cd $(WORKDIR) && cp Makefile Makefile.orig
	cd $(WORKDIR) && sed -e 's|^SHELL *=.*$$|SHELL = /bin/sh|' Makefile.orig > Makefile
	touch $@

build: .build
.build: .post-config
	@echo && echo ===== $@ =====
	CPPFLAGS=-D_ALL_SOURCE gmake -C $(WORKDIR)
	touch $@

pkginst: .pkginst
.pkginst: .build
	@echo && echo ===== $@ =====
	rm -rf dest
	gmake -C $(WORKDIR) prefix=`pwd`/dest install
	for exe in c++ cpp fastjar g++ gcc gcc-4.1.2 gcj gcjh gcov gjnih grepjar jcf-dump jv-scan; do strip dest/bin/$(ARCH_PREFIX)-$$exe; done
	cd dest/libexec/gcc/i386-mingw32/4.1.2 && strip c* j*
	touch $@

include $(TOPDIR)/pmgr.mk
