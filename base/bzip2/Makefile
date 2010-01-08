PKGNAME = bzip2
PKGVER  = 1.0.4

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCES = $(WORKDIR).tar.gz
SRCURL  = http://www.bzip.org/$(PKGVER)

do-fetch: std-fetch
do-extract: std-extract
do-patch:
do-config:

do-build:
	cd $(WORKDIR) && gmake

do-pkginst:
	cd $(WORKDIR) && gmake PREFIX=`pwd`/../dest install
	cd dest/bin && rm bzcmp && ln -s bzdiff bzcmp
	cd dest/bin && rm bzegrep && ln -s bzgrep bzegrep
	cd dest/bin && rm bzfgrep && ln -s bzgrep bzfgrep
	cd dest/bin && rm bzless && ln -s bzmore bzless
	strip dest/bin/bzcat dest/bin/bzip2*
