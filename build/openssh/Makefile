PKGNAME = openssh
PKGVER  = 5.3p1

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCES = $(WORKDIR).tar.gz
SRCURL  = http://ftp.jaist.ac.jp/pub/OpenBSD/OpenSSH/portable

do-fetch: std-fetch
do-extract: std-extract

do-patch: fix-configure
	cd $(WORKDIR) && cp log.h log.h.orig && sed -e "s/__dead//" log.h.orig > log.h
	cd $(WORKDIR) && cp Makefile.in Makefile.in.orig && sed -e "s/-lopenbsd-compat/-lopenbsd-compat -lcrypt -lbind -ldb/" -e "s/-m 4711/-m 0755/" Makefile.in.orig > Makefile.in
	cp port-interix.c $(WORKDIR)/openbsd-compat
	cp pwd.h $(WORKDIR)

do-config:
	cd $(WORKDIR) && ./configure --prefix=$(PKGDEST) --with-privsep-path=$(PKGDEST)/var/empty CPPFLAGS="-I$(PKGDEST)/include -I/usr/local/include/bind -I/usr/local/bind/include -D_ALL_SOURCE" LDFLAGS="-L$(PKGDEST)/lib -L/usr/local/lib/bind  -Wl,-R$(PKGDEST)/lib"
	echo "#define HAVE_STRUCT_TIMESPEC" >> $(WORKDIR)/config.h
	echo "#define MISSING_HOWMANY" >> $(WORKDIR)/config.h
	echo "#define DISABLE_LOGIN" >> $(WORKDIR)/config.h

do-build:
	cd $(WORKDIR) && make

do-pkginst:
	cd $(WORKDIR) && make DESTDIR=`pwd`/../dest install
	mv dest$(PKGDEST)/* dest
	rm -rf dest/`echo $(PKGDEST) | sed -e "s|^/||" | sed -e "s|/.*$$||" | sed -e "s|^|/|"`
	strip dest/bin/* dest/libexec/*
