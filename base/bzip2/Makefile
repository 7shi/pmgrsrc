PKGNAME = bzip2
PKGVER  = 1.0.4

TOPDIR  = ../..
include $(TOPDIR)/common.mk

PKGBZIP2 = $(PKGDEST)/bin/$(PKGCMDNAME)-bzip2
.install: $(PKGBZIP2)
$(PKGBZIP2): .build
	install -cs $(WORKDIR)/bzip2 $@

include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCE  = $(WORKDIR).tar.gz
SRCURL  = http://www.bzip.org/$(PKGVER)/$(SOURCE)

do-fetch:
	if [ ! -f $(DISTDIR)/$(SOURCE) ]; then $(HTTPGET) $(SRCURL) && mv $(SOURCE) $(DISTDIR); fi

do-extract:
	pmgr-extract $(DISTDIR)/$(SOURCE)

do-patch:
do-config:

do-build:
	cd $(WORKDIR) && $(MAKE)

do-pkginst:
	cd $(WORKDIR) && cp Makefile Makefile.orig
	sed -e "s|^PREFIX=.*$$|PREFIX=`pwd`/dest|" $(WORKDIR)/Makefile.orig > $(WORKDIR)/Makefile
	cd $(WORKDIR) && $(MAKE) install
	cd dest/bin && rm bzcmp && ln -s bzdiff bzcmp
	cd dest/bin && rm bzegrep && ln -s bzgrep bzegrep
	cd dest/bin && rm bzfgrep && ln -s bzgrep bzfgrep
	cd dest/bin && rm bzless && ln -s bzmore bzless
	strip dest/bin/bzcat dest/bin/bzip2*
