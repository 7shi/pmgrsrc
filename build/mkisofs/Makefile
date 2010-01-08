PKGNAME = mkisofs
PKGVER  = 2.01
BLDDEPS = wget

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = cdrtools-$(PKGVER)
SOURCE  = $(WORKDIR).tar.bz2
SRCURL  = ftp://ftp.berlios.de/pub/cdrecord/$(SOURCE)

do-fetch:
	if [ ! -f $(DISTDIR)/$(SOURCE) ]; then wget $(SRCURL) && mv $(SOURCE) $(DISTDIR); fi

do-extract:
	pmgr-extract $(DISTDIR)/$(SOURCE)

do-patch:
	cat patch-* | patch -p0 -d $(WORKDIR)
	echo "MANSTYLE=bsd" > $(WORKDIR)/RULES/os-interix.def
	echo "O_ARCH=interix\n-O_ARCH=-\$$(O_ARCH)" > $(WORKDIR)/RULES/os-interix.id
	cd $(WORKDIR)/RULES && ln -s i586-linux-gcc.rul x86-interix-gcc.rul
	cd $(WORKDIR)/DEFAULTS && sed -e "s/	cc/	gcc/" Defaults.linux > Defaults.interix

do-config:
	gmake -C $(WORKDIR) config

do-build:
	gmake -C $(WORKDIR)

do-pkginst:
	gmake -C $(WORKDIR)/mkisofs INS_BASE=`pwd`/dest install
	strip dest/bin/*
