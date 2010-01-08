PKGNAME = gmake
PKGVER  = 3.81

TOPDIR  = ../..
include $(TOPDIR)/common.mk

WORKDIR = make-$(PKGVER)
SOURCE  = $(WORKDIR).tar.gz
SRCURL  = http://ftp.gnu.org/gnu/make/$(SOURCE)

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
	cp $(TOPDIR)/share/config.* $(WORKDIR)/config
	touch $@

config: .config
.config: .patch
	@echo && echo ===== $@ =====
	cd $(WORKDIR) && ./configure --prefix=$(PKGDEST) --program-prefix=g
	touch $@

post-config: .post-config
.post-config: .config
	@echo && echo ===== $@ =====
	touch $@

build: .build
.build: .post-config
	@echo && echo ===== $@ =====
	cd $(WORKDIR) && $(MAKE)
	touch $@

pkginst: .pkginst
.pkginst: .build
	@echo && echo ===== $@ =====
	rm -rf dest
	for mk in `find $(WORKDIR) -name Makefile`; do cp $$mk $$mk.orig && sed -e "s|^prefix *= */.*$$|prefix = `pwd`/dest|" $$mk.orig > $$mk; done
	cd $(WORKDIR) && $(MAKE) install
	strip dest/bin/*
	touch $@

include $(TOPDIR)/pmgr.mk
