PKGNAME = bzip2
PKGVER  = 1.0.4

TOPDIR  = ../..
include $(TOPDIR)/common.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCE  = $(WORKDIR).tar.gz
SRCURL  = http://www.bzip.org/$(PKGVER)/$(SOURCE)

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
	touch $@

post-config: .post-config
.post-config: .config
	@echo && echo ===== $@ =====
	touch $@

build: .build
.build: .post-config
	@echo && echo ===== $@ =====
	cd $(WORKDIR) && $(MAKE)
	touch $@

pkginst: .pkginst
.pkginst: .build
	@echo && echo ===== $@ =====
	rm -rf dest
	cd $(WORKDIR) && cp Makefile Makefile.orig
	sed -e "s|^PREFIX=.*$$|PREFIX=`pwd`/dest|" $(WORKDIR)/Makefile.orig > $(WORKDIR)/Makefile
	cd $(WORKDIR) && $(MAKE) install
	cd dest/bin && rm bzcmp && ln -s bzdiff bzcmp
	cd dest/bin && rm bzegrep && ln -s bzgrep bzegrep
	cd dest/bin && rm bzfgrep && ln -s bzgrep bzfgrep
	cd dest/bin && rm bzless && ln -s bzmore bzless
	strip dest/bin/bzcat dest/bin/bzip2*
	touch $@

BZIP2 = ../$(WORKDIR)/bzip2
PKGCMDNAME = PATH="`pwd`/dest/bin:$$PATH" pmgr

include $(TOPDIR)/pmgr.mk
