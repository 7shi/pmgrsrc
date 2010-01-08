PKGNAME = libiconv
PKGVER  = 1.11

TOPDIR  = ../..
include $(TOPDIR)/common.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCE  = $(WORKDIR).tar.gz
SRCURL  = http://ftp.gnu.org/gnu/$(PKGNAME)/$(SOURCE)

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
	cp $(WORKDIR)/build-aux/config.guess $(WORKDIR)/libcharset/build-aux/config.guess
	touch $@

.config: .patch
	@echo && echo ===== config =====
	cd $(WORKDIR) && ./configure --prefix=$(PKGDEST)
	touch $@

.build: .config
	@echo && echo ===== build =====
	gmake -C $(WORKDIR)
	touch $@

.pkginst: .build
	@echo && echo ===== pkginst =====
	rm -rf dest
	gmake -C $(WORKDIR) prefix=`pwd`/dest install
	strip dest/bin/*
	touch $@

include $(TOPDIR)/pmgr.mk
