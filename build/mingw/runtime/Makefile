PKGNAME = mingw-runtime
PKGVER  = 3.9

include ../mingw.mk
TOPDIR  = $(TOPDIR_)/..
include $(TOPDIR)/common.mk

WORKDIR = 
SOURCE  = $(PKGNAME)-$(PKGVER).tar.gz
SRCURL  = http://jaist.dl.sourceforge.net/sourceforge/mingw/$(SOURCE)

all: build

.fetch: .depend
	@echo && echo ===== fetch =====
	mkdir -p $(DISTDIR)
	if [ ! -f $(DISTDIR)/$(SOURCE) ]; then $(HTTPGET) $(SRCURL) && mv $(SOURCE) $(DISTDIR); fi
	touch $@

.extract: .fetch
	@echo && echo ===== extract =====
	touch $@

.patch: .extract
	@echo && echo ===== patch =====
	touch $@

.config: .patch
	@echo && echo ===== config =====
	touch $@

.build: .config
	@echo && echo ===== build =====
	touch $@

.pkginst: .build
	@echo && echo ===== pkginst =====
	mkdir -p dest/$(ARCH_PREFIX)
	pmgr-extract z $(DISTDIR)/$(SOURCE) -C dest/$(ARCH_PREFIX)
	touch $@

include $(TOPDIR)/pmgr.mk
