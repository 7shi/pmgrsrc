PKGNAME = python
PKGVER  = 2.5

TOPDIR  = ../..
include $(TOPDIR)/common.mk

WORKDIR = Python-$(PKGVER)
SOURCE  = $(WORKDIR).tar.bz2
SRCURL  = http://www.python.org/ftp/$(PKGNAME)/$(PKGVER)/$(SOURCE)

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
	-patch -p0 -d $(WORKDIR) < patch-al
	cd $(WORKDIR) && cp Makefile.pre.in Makefile.pre.in.orig && cat Makefile.pre.in.orig | sed -e "s/@BUILDEXEEXT@/.exe/" > Makefile.pre.in
	touch $@

.config: .patch
	@echo && echo ===== config =====
	cd $(WORKDIR) && CC="gcc -D_ALL_SOURCE" ./configure --prefix=$(PKGDEST)
	touch $@

.build: .config
	@echo && echo ===== build =====
	gmake -C $(WORKDIR)
	touch $@

.pkginst: .build
	@echo && echo ===== pkginst =====
	rm -rf dest
	-gmake -k -C $(WORKDIR) prefix=`pwd`/dest install
	cd dest/bin && rm python *-config
	strip dest/bin/*
	cd dest/bin && ln -s $(PKGNAME)$(PKGVER) $(PKGNAME)
	touch $@

include $(TOPDIR)/pmgr.mk
