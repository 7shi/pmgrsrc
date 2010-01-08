PKGNAME = zsh
PKGVER  = 4.2.6
DEPENDS = bash

TOPDIR  = ../..
include $(TOPDIR)/common.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCE  = $(WORKDIR).tar.gz
SRCURL  = http://jaist.dl.sourceforge.net/sourceforge/$(PKGNAME)/$(SOURCE)

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
	pmgr-extract z $(DESTDIR)/$(SOURCE)
	touch $@

patch: .patch
.patch: .extract
	@echo && echo ===== $@ =====
	cp $(TOPDIR)/share/config.* $(WORKDIR)
	patch -p0 -d $(WORKDIR) < patch-ab
	touch $@

config: .config
.config: .patch
	@echo && echo ===== $@ =====
	cd $(WORKDIR) && bash configure --prefix=$(PKGDEST)
	touch $@

post-config: .post-config
.post-config: .config
	@echo && echo ===== $@ =====
	cat config.h.interix >> $(WORKDIR)/config.h
	touch $@

build: .build
.build: .post-config
	@echo && echo ===== $@ =====
	gmake -C $(WORKDIR)
	touch $@

pkginst: .pkginst
.pkginst: .build
	@echo && echo ===== $@ =====
	rm -rf dest
	gmake -C $(WORKDIR) prefix=`pwd`/dest install
	rm dest/bin/zsh-*
	strip dest/bin/zsh
	touch $@

include $(TOPDIR)/pmgr.mk
