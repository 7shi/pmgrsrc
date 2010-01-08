PKGNAME = flex
PKGVER  = 2.5.4a

TOPDIR  = ../..
include $(TOPDIR)/common.mk

WORKDIR = $(PKGNAME)-2.5.4
SOURCE  = $(PKGNAME)-$(PKGVER).tar.gz
SRCURL  = http://ftp.gnu.org/non-gnu/$(PKGNAME)/$(SOURCE)

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
	strip dest/bin/flex
	rm dest/bin/flex++
	touch $@

include $(TOPDIR)/pmgr.mk
