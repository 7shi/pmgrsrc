PKGNAME = mingw-binutils
PKGVER  = 2.17

TOPDIR  = ../../..
include $(TOPDIR)/common.mk
include ../mingw.mk

WORKDIR = binutils-$(PKGVER)
SOURCE  = $(WORKDIR).tar.bz2
SRCURL  = http://ftp.gnu.org/gnu/binutils/$(SOURCE)

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
	pmgr-extract j $(DESTDIR)/$(SOURCE)
	touch $@

patch: .patch
.patch: .extract
	@echo && echo ===== $@ =====
	cp $(TOPDIR)/share/config.* $(WORKDIR)
	touch $@

config: .config
.config: .patch
	@echo && echo ===== $@ =====
	cd $(WORKDIR) && CPPFLAGS=-D_ALL_SOURCE ./configure --prefix=$(PKGDEST) --target=$(ARCH_PREFIX)
	touch $@

post-config: .post-config
.post-config: .config
	@echo && echo ===== $@ =====
	touch $@

build: .build
.build: .post-config
	@echo && echo ===== $@ =====
	PATH="$(PKGDEST)/bin:$$PATH" CPPFLAGS=-D_ALL_SOURCE gmake -C $(WORKDIR)
	touch $@

pkginst: .pkginst
.pkginst: .build
	@echo && echo ===== $@ =====
	rm -rf dest
	gmake -C $(WORKDIR) prefix=`pwd`/dest install
	for exe in addr2line ar as c++filt dlltool dllwrap ld nm objcopy objdump ranlib readelf size strings strip windres; do strip dest/bin/$(ARCH_PREFIX)-$$exe; done
	for exe in ar as dlltool ld nm objdump ranlib strip; do strip dest/$(ARCH_PREFIX)/bin/$$exe; done
	touch $@

include $(TOPDIR)/pmgr.mk
