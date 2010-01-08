PKGNAME = cvs
PKGVER  = 1.11.22

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCES = $(WORKDIR).tar.gz
SRCURL  = ftp://ftp.gnu.org/non-gnu/$(PKGNAME)/source/stable/$(PKGVER)

do-fetch: std-fetch
do-extract: std-extract
do-patch:

do-config:
	cd $(WORKDIR) && ./configure --prefix=$(PKGDEST)

do-build:
	cd $(WORKDIR) && make

do-pkginst:
	cd $(WORKDIR) && make prefix=`pwd`/../dest install
	strip dest/bin/cvs
	rm dest/bin/rcs2log
