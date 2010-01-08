PKGNAME = subversion
PKGVER  = 1.4.3
DEPENDS = zlib libiconv

TOPDIR  = ../..
include $(TOPDIR)/common.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCE  = $(WORKDIR).tar.bz2 $(PKGNAME)-deps-$(PKGVER).tar.bz2
SRCURL  = http://subversion.tigris.org/downloads

all: build

.fetch: .depend
	@echo && echo ===== fetch =====
	mkdir -p $(DISTDIR)
	for f in $(SOURCE); do if [ ! -f $(DISTDIR)/$$f ]; then $(HTTPGET) $(SRCURL)/$$f && mv $$f $(DISTDIR); fi; done
	touch $@

.extract: .fetch
	@echo && echo ===== extract =====
	for f in $(SOURCE); do pmgr-extract $(DISTDIR)/$$f; done
	touch $@

.patch: .extract
	@echo && echo ===== patch =====
	for d in `find $(WORKDIR) -name config.guess`; do cp $(TOPDIR)/share/config.* `dirname $$d`; done
	touch $@

.config: .patch
	@echo && echo ===== config =====
	cd $(WORKDIR) && CPPFLAGS="-I$(PKGDEST)/include -D_ALL_SOURCE" LDFLAGS=-L$(PKGDEST)/lib ./configure --prefix=$(PKGDEST)
	touch $@

.build: .config
	@echo && echo ===== build =====
	gmake -C $(WORKDIR)
	touch $@

.pkginst: .build
	@echo && echo ===== pkginst =====
	rm -rf dest
	gmake -C $(WORKDIR) prefix=`pwd`/dest install
	strip dest/bin/svn*
	touch $@

include $(TOPDIR)/pmgr.mk
