PKGNAME = gettext
PKGVER  = 0.16.1
DEPENDS = libiconv

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
	touch $@

config: .config
.config: .patch
	@echo && echo ===== $@ =====
	cd $(WORKDIR) && ./configure --prefix=$(PKGDEST) CPPFLAGS=-D_ALL_SOURCE
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
	rm -rf dest/share/doc/gettext/examples/
	strip dest/bin/msg*
	touch $@

include $(TOPDIR)/pmgr.mk
