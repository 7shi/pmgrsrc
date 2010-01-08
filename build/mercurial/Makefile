PKGNAME = mercurial
PKGVER  = 1.3.1
DEPENDS = python

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCES = $(WORKDIR).tar.gz
SRCURL  = http://mercurial.selenic.com/release

do-fetch: std-fetch
do-extract: std-extract

do-patch:
	echo "typedef unsigned long long uint64_t;" > $(WORKDIR)/$(PKGNAME)/inttypes.h
	for src in $(WORKDIR)/$(PKGNAME)/*.c; do cp $$src $$src.orig && sed -e 's/<inttypes\.h>/"inttypes.h"/' $$src.orig > $$src; done

do-config:

do-build:
	cd $(WORKDIR) && make PREFIX=$(PKGDEST) all

do-pkginst:
	cd $(WORKDIR) && make PREFIX=`pwd`/../dest install
