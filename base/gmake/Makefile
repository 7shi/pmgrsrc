PKGNAME = gmake
PKGVER  = 3.81

TOPDIR  = ../..
include $(TOPDIR)/common.mk

WORKDIR = make-$(PKGVER)
SOURCE  = $(WORKDIR).tar.gz
SRCURL  = http://ftp.gnu.org/gnu/make/$(SOURCE)

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
	cp $(TOPDIR)/share/config.* $(WORKDIR)/config
	touch $@

.config: .patch
	@echo && echo ===== config =====
	cd $(WORKDIR) && ./configure --prefix=$(PKGDEST) --program-prefix=g
	touch $@

.build: .config
	@echo && echo ===== build =====
	cd $(WORKDIR) && $(MAKE)
	touch $@

.pkginst: .build
	@echo && echo ===== pkginst =====
	rm -rf dest
	for mk in `find $(WORKDIR) -name Makefile`; do cp $$mk $$mk.orig && sed -e "s|^prefix *= */.*$$|prefix = `pwd`/dest|" $$mk.orig > $$mk; done
	cd $(WORKDIR) && $(MAKE) install
	strip dest/bin/*
	touch $@

include $(TOPDIR)/pmgr.mk
