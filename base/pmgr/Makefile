TOPDIR = ../..
include $(TOPDIR)/common.mk

SCRIPTS = $(PKGCMDNAME)-add $(PKGCMDNAME)-del $(PKGCMDNAME)-ls $(PKGCMDNAME)-extract
TARGETS = $(PKGCMDNAME)-sizecat $(SCRIPTS)

all: build
fetch extract:
build: $(TARGETS)
patch config package repackage:

install reinstall: $(TARGETS)
	mkdir -p $(PKGDEST)/bin
	install -c -m 0755 $(TARGETS) $(PKGDEST)/bin
	mkdir -p $(PKGDEST)/include
	cp include/* $(PKGDEST)/include
	mkdir -p $(PKGDEST)/share/libtool
	cp config.* ltmain.sh $(PKGDEST)/share/libtool

uninstall:
	cd $(PKGDEST)/bin && rm -f $(TARGETS)
	cd include && for src in *.h *.c; do rm -f $(PKGDEST)/include/$$src; done

$(PKGCMDNAME)-add: $(PKGCMDNAME)-add.in $(TOPDIR)/common.mk
$(PKGCMDNAME)-del: $(PKGCMDNAME)-del.in $(TOPDIR)/common.mk
$(PKGCMDNAME)-ls: $(PKGCMDNAME)-ls.in $(TOPDIR)/common.mk
$(PKGCMDNAME)-extract: $(PKGCMDNAME)-extract.in $(TOPDIR)/common.mk

$(SCRIPTS):
	sed -e 's|@PKGDEST@|$(PKGDEST)|' -e 's|@PKGDBDIR@|$(PKGDBDIR)|' $@.in > $@
	chmod 755 $@

$(PKGCMDNAME)-sizecat: sizecat.c
	gcc -o $@ sizecat.c
	strip $@

clean distclean:
	rm -f $(TARGETS)
