PKGNAME = bison
PKGVER  = 2.3
DEPENDS = m4

TOPDIR  = ../..
include $(TOPDIR)/common.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCE  = $(WORKDIR).tar.gz
SRCURL  = http://ftp.gnu.org/gnu/$(PKGNAME)/$(SOURCE)

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
	chmod 666 $(WORKDIR)/build-aux/config.*
	cp $(TOPDIR)/share/config.* $(WORKDIR)/build-aux
	touch $@

config: .config
.config: .patch
	@echo && echo ===== $@ =====
	cd $(WORKDIR) && PATH="$(PKGDEST)/bin:$$PATH" ./configure --prefix=$(PKGDEST)
	touch $@

post-config: .post-config
.post-config: .config
	@echo && echo ===== $@ =====
	touch $@

build: .build
.build: .post-config
	@echo && echo ===== $@ =====
	PATH="$(PKGDEST)/bin:$$PATH" gmake -C $(WORKDIR)
	touch $@

pkginst: .pkginst
.pkginst: .build
	@echo && echo ===== $@ =====
	rm -rf dest
	gmake -C $(WORKDIR) prefix=`pwd`/dest install
	strip dest/bin/bison
	touch $@

include $(TOPDIR)/pmgr.mk
