PKGNAME = openssh
PKGVER  = 4.5p1
BLDDEPS = wget
DEPENDS = zlib openssl libresolv libcrypt

TOPDIR  = ../..
include $(TOPDIR)/common.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCE  = $(WORKDIR).tar.gz
SRCURL  = ftp://ftp.iij.ad.jp/pub/OpenBSD/OpenSSH/portable/$(SOURCE)

all: build

.fetch: .depend
	@echo && echo ===== fetch =====
	mkdir -p $(DISTDIR)
	if [ ! -f $(DISTDIR)/$(SOURCE) ]; then wget $(SRCURL) && mv $(SOURCE) $(DISTDIR); fi
	touch $@

.extract: .fetch
	@echo && echo ===== extract =====
	pmgr-extract $(DISTDIR)/$(SOURCE)
	touch $@

.patch: .extract
	@echo && echo ===== patch =====
	cp $(TOPDIR)/share/config.* $(WORKDIR)
	cat patch-* | patch -p0 -d $(WORKDIR)
	cd $(WORKDIR) && cp log.h log.h.orig && sed -e "s/__dead//" log.h.orig > log.h
	cd $(WORKDIR) && cp Makefile.in Makefile.in.orig && sed -e "s/-lopenbsd-compat/-lopenbsd-compat -lresolv -lcrypt/" -e "s/-m 4711/-m 0755/" Makefile.in.orig > Makefile.in
	cp port-interix.c $(WORKDIR)/openbsd-compat
	touch $@

.config: .patch
	@echo && echo ===== config =====
	cd $(WORKDIR) && ./configure --prefix=$(PKGDEST) --with-privsep-path=$(PKGDEST)/var/empty CPPFLAGS="-I$(PKGDEST)/include -D_ALL_SOURCE" LDFLAGS=-L$(PKGDEST)/lib
	echo "#define HAVE_STRUCT_TIMESPEC" >> $(WORKDIR)/config.h
	echo "#define MISSING_HOWMANY" >> $(WORKDIR)/config.h
	echo "#define DISABLE_LOGIN" >> $(WORKDIR)/config.h
	touch $@

.build: .config
	@echo && echo ===== build =====
	gmake -C $(WORKDIR)
	touch $@

.pkginst: .build
	@echo && echo ===== pkginst =====
	rm -rf dest
	gmake -C $(WORKDIR) DESTDIR=`pwd`/dest install
	mv dest$(PKGDEST)/* dest
	rm -rf dest/`echo $(PKGDEST) | sed -e "s|^/||" | sed -e "s|/.*$$||" | sed -e "s|^|/|"`
	strip dest/bin/* dest/libexec/*
	touch $@

include $(TOPDIR)/pmgr.mk
