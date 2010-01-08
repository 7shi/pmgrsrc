PKGNAME = zsh
PKGVER  = 4.2.6
BLDDEPS = bash

TOPDIR  = ../..
include $(TOPDIR)/common.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCE  = $(WORKDIR).tar.gz
SRCURL  = http://jaist.dl.sourceforge.net/sourceforge/$(PKGNAME)/$(SOURCE)

all: build

.fetch: .depend
	@echo && echo ===== fetch =====
	mkdir -p $(DISTDIR)
	if [ ! -f $(DISTDIR)/$(SOURCE) ]; then $(HTTPGET) $(SRCURL) && mv $(SOURCE) $(DISTDIR); fi
	touch $@

.extract: .fetch
	@echo && echo ===== extract =====
	pmgr-extract z $(DISTDIR)/$(SOURCE)
	touch $@

.patch: .extract
	@echo && echo ===== patch =====
	cp $(TOPDIR)/share/config.* $(WORKDIR)
	patch -p0 -d $(WORKDIR) < patch-ab
	touch $@

.config: .patch
	@echo && echo ===== config =====
	cd $(WORKDIR) && bash configure --prefix=$(PKGDEST)
	cat config.h.interix >> $(WORKDIR)/config.h
	touch $@

.build: .config
	@echo && echo ===== build =====
	gmake -C $(WORKDIR)
	touch $@

.pkginst: .build
	@echo && echo ===== pkginst =====
	rm -rf dest
	gmake -C $(WORKDIR) prefix=`pwd`/dest install
	rm dest/bin/zsh-*
	strip dest/bin/zsh
	touch $@

include $(TOPDIR)/pmgr.mk
