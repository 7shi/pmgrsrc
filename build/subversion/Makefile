PKGNAME = subversion
PKGVER  = 1.4.3
DEPENDS = zlib libiconv

TOPDIR  = ../..
include $(TOPDIR)/common.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCE  = $(WORKDIR).tar.bz2 $(PKGNAME)-deps-$(PKGVER).tar.bz2
SRCURL  = http://subversion.tigris.org/downloads

all: build

fetch: .fetch
.fetch: .depend
	@echo && echo ===== $@ =====
	mkdir -p $(DESTDIR)
	for f in $(SOURCE); do if [ ! -f $(DESTDIR)/$$f ]; then $(HTTPGET) $(SRCURL)/$$f && mv $$f $(DESTDIR); fi; done
	touch $@

extract: .extract
.extract: .fetch
	@echo && echo ===== $@ =====
	for f in $(SOURCE); do pmgr-extract j $(DESTDIR)/$$f; done
	touch $@

patch: .patch
.patch: .extract
	@echo && echo ===== $@ =====
	for d in `find $(WORKDIR) -name config.guess`; do cp $(TOPDIR)/share/config.* `dirname $$d`; done
	touch $@

config: .config
.config: .patch
	@echo && echo ===== $@ =====
	cd $(WORKDIR) && CPPFLAGS="-I$(PKGDEST)/include -D_ALL_SOURCE" LDFLAGS=-L$(PKGDEST)/lib ./configure --prefix=$(PKGDEST)
	touch $@

post-config: .post-config
.post-config: .config
	@echo && echo ===== $@ =====
	touch $@

build: .build
.build: .post-config
	@echo && echo ===== $@ =====
	gmake -C $(WORKDIR)
	touch $@

pkginst: .pkginst
.pkginst: .build
	@echo && echo ===== $@ =====
	rm -rf dest
	gmake -C $(WORKDIR) prefix=`pwd`/dest install
	strip dest/bin/svn*
	touch $@

include $(TOPDIR)/pmgr.mk
