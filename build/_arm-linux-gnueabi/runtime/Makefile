PKGNAME = $(ARCH_PREFIX)-runtime
PKGVER  = 20091125

include ../cross.mk
TOPDIR  = $(TOPDIR_)/..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = 
SOURCES = ubuntu-jaunty-araneo-armel-dev.tar.xz
SRCURL  = http://cid-fb45e1f8ce8b532e.skydrive.live.com/self.aspx/.Public/Others

do-fetch:
	if [ ! -f $(DISTDIR)/$(SOURCES) ]; then \
	  wget -O $(SOURCES) $(SRCURL)/$(SOURCES); \
	  wget -O $(SOURCES) `cat $(SOURCES) | sed 's|.*href="http|http|' | grep download | grep -v downloadUrl | sed -e 's|&#63;download".*||' -e 's|&#58;|:|g' -e 's|&#47;|/|g'`; \
	  mv $(SOURCES) $(DISTDIR); \
	fi

do-extract:
do-patch:
do-config:
do-build:

do-pkginst:
	mkdir -p dest/$(ARCH_PREFIX)
	cd dest/$(ARCH_PREFIX) && pmgr-extract ../../$(DISTDIR)/$(SOURCES)
	rm -rf dest/$(ARCH_PREFIX)/lib/gcc
