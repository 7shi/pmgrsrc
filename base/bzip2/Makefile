PKGNAME = bzip2
PKGVER  = 1.0.4

TOPDIR  = ../..
include $(TOPDIR)/common.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCE  = $(WORKDIR).tar.gz
SRCURL  = http://www.bzip.org/$(PKGVER)/$(SOURCE)

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
	touch $@

.build: .config
	@echo && echo ===== build =====
	cd $(WORKDIR) && $(MAKE)
	touch $@

.pkginst: .build
	@echo && echo ===== pkginst =====
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

PKGBZIP2 = $(PKGDEST)/bin/$(PKGCMDNAME)-bzip2
.install: $(PKGBZIP2)
$(PKGBZIP2): build
	install -cs $(WORKDIR)/bzip2 $@

include $(TOPDIR)/pmgr.mk
