PKGNAME = bison
PKGVER  = 2.3
DEPENDS = m4

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
	pmgr-extract z $(DISTDIR)/$(SOURCE)
	touch $@

.patch: .extract
	@echo && echo ===== patch =====
	chmod 666 $(WORKDIR)/build-aux/config.*
	cp $(TOPDIR)/share/config.* $(WORKDIR)/build-aux
	touch $@

.config: .patch
	@echo && echo ===== config =====
	cd $(WORKDIR) && PATH="$(PKGDEST)/bin:$$PATH" ./configure --prefix=$(PKGDEST)
	touch $@

.build: .config
	@echo && echo ===== build =====
	PATH="$(PKGDEST)/bin:$$PATH" gmake -C $(WORKDIR)
	touch $@

.pkginst: .build
	@echo && echo ===== pkginst =====
	rm -rf dest
	gmake -C $(WORKDIR) prefix=`pwd`/dest install
	strip dest/bin/bison
	touch $@

include $(TOPDIR)/pmgr.mk
