PKGNAME = mkisofs
PKGVER  = 2.01

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = cdrtools-$(PKGVER)
SOURCES = $(WORKDIR).tar.bz2
SRCURL  = http://gd.tuwien.ac.at/utils/schilling/cdrtools

do-fetch: std-fetch
do-extract: std-extract

do-patch:
	echo "MANSTYLE=bsd" > $(WORKDIR)/RULES/os-interix.def
	echo "O_ARCH=interix" > $(WORKDIR)/RULES/os-interix.id
	echo "-O_ARCH=-\$$(O_ARCH)" >> $(WORKDIR)/RULES/os-interix.id
	cd $(WORKDIR)/RULES && ln -s i586-linux-gcc.rul x86-interix-gcc.rul
	cd $(WORKDIR)/DEFAULTS && sed -e "s/	cc/	gcc/" Defaults.linux > Defaults.interix

do-config:
	cd $(WORKDIR) && make config

do-build:
	cd $(WORKDIR) && make

do-pkginst:
	cd $(WORKDIR)/mkisofs && make INS_BASE=`pwd`/../../dest install
	strip dest/bin/*
