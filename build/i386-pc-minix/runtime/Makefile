PKGNAME = $(ARCH_PREFIX)-runtime
PKGVER  = 3.1.6

include ../cross.mk
TOPDIR  = $(TOPDIR_)/..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = 
SOURCES = minix-$(PKGVER)-dev-gcc.tar.xz
SRCURL  = http://cid-fb45e1f8ce8b532e.skydrive.live.com/self.aspx/.Public/MINIX

do-fetch:
	for src in $(SOURCES); \
	do \
	  if [ ! -f $(DISTDIR)/$$src ]; then \
	    wget -O $$src $(SRCURL)/$$src; \
	    wget -O $$src `cat $$src | sed 's|.*href="http|http|' | grep download | grep -v downloadUrl | sed -e 's|&#63;download".*||' -e 's|&#58;|:|g' -e 's|&#47;|/|g'`; \
	    mv $$src $(DISTDIR); \
	  fi; \
	done

do-extract:
do-patch:
do-config:
do-build:

do-pkginst:
	mkdir -p dest/$(ARCH_PREFIX)
	cd dest/$(ARCH_PREFIX) && (for src in $(SOURCES); do pmgr-extract ../../$(DISTDIR)/$$src; done)
