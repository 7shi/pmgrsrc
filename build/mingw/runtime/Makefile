PKGNAME = mingw-runtime
PKGVER  = 3.9

TOPDIR  = ../../..
include $(TOPDIR)/common.mk
include ../mingw.mk

WORKDIR = 
SOURCE  = $(PKGNAME)-$(PKGVER).tar.gz
SRCURL  = http://jaist.dl.sourceforge.net/sourceforge/mingw/$(SOURCE)

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
	touch $@

patch: .patch
.patch: .extract
	@echo && echo ===== $@ =====
	touch $@

config: .config
.config: .patch
	@echo && echo ===== $@ =====
	touch $@

post-config: .post-config
.post-config: .config
	@echo && echo ===== $@ =====
	touch $@

build: .build
.build: .post-config
	@echo && echo ===== $@ =====
	touch $@

pkginst: .pkginst
.pkginst: .build
	@echo && echo ===== $@ =====
	mkdir -p dest/$(ARCH_PREFIX)
	pmgr-extract z $(DESTDIR)/$(SOURCE) -C dest/$(ARCH_PREFIX)
	touch $@

include $(TOPDIR)/pmgr.mk
