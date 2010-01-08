PKGNAME = mingw-binutils
PKGVER  = 2.17

include ../mingw.mk
TOPDIR  = $(TOPDIR_)/..
include $(TOPDIR)/common.mk

WORKDIR = binutils-$(PKGVER)
SOURCE  = $(WORKDIR).tar.bz2
SRCURL  = http://ftp.gnu.org/gnu/binutils/$(SOURCE)

all: build

.fetch: .depend
	@echo && echo ===== fetch =====
	mkdir -p $(DISTDIR)
	if [ ! -f $(DISTDIR)/$(SOURCE) ]; then $(HTTPGET) $(SRCURL) && mv $(SOURCE) $(DISTDIR); fi
	touch $@

.extract: .fetch
	@echo && echo ===== extract =====
	pmgr-extract j $(DISTDIR)/$(SOURCE)
	touch $@

.patch: .extract
	@echo && echo ===== patch =====
	cp $(TOPDIR)/share/config.* $(WORKDIR)
	touch $@

.config: .patch
	@echo && echo ===== config =====
	cd $(WORKDIR) && CPPFLAGS=-D_ALL_SOURCE ./configure --prefix=$(PKGDEST) --target=$(ARCH_PREFIX)
	touch $@

.build: .config
	@echo && echo ===== build =====
	PATH="$(PKGDEST)/bin:$$PATH" CPPFLAGS=-D_ALL_SOURCE gmake -C $(WORKDIR)
	touch $@

.pkginst: .build
	@echo && echo ===== pkginst =====
	rm -rf dest
	gmake -C $(WORKDIR) prefix=`pwd`/dest install
	for exe in addr2line ar as c++filt dlltool dllwrap ld nm objcopy objdump ranlib readelf size strings strip windres; do strip dest/bin/$(ARCH_PREFIX)-$$exe; done
	for exe in ar as dlltool ld nm objdump ranlib strip; do strip dest/$(ARCH_PREFIX)/bin/$$exe; done
	touch $@

include $(TOPDIR)/pmgr.mk
