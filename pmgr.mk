PACKAGE = $(PKGDIR)/$(PKGNAME)-$(PKGVER).$(PKGSUFFIX)
PKGFILE = dest/$(PKGDBDIR)/files/$(PKGNAME)
PKGVERF = dest/$(PKGDBDIR)/versions/$(PKGNAME)
PKGDEPF = dest/$(PKGDBDIR)/depends/$(PKGNAME)

all: build

depend: .depend
.depend:
	@echo && echo "===== depend: $(PKGNAME) ====="
	for dep in $(BLDDEPS) $(DEPENDS); do if [ ! -f $(PKGDEST)/$(PKGDBDIR)/files/`echo $$dep | sed -e 's|/|-|g'` ]; then (cd $(TOPDIR)/build/$$dep && $(MAKE) install) || exit; fi; done
	touch $@

fetch: .fetch
.fetch:
	@echo && echo "===== fetch: $(PKGNAME) ====="
	mkdir -p $(DISTDIR)
	@$(MAKE) do-fetch || exit
	for dep in $(BLDDEPS) $(DEPENDS); do if [ ! -f $(PKGDEST)/$(PKGDBDIR)/files/`echo $$dep | sed -e 's|/|-|g'` ]; then (cd $(TOPDIR)/build/$$dep && $(MAKE) fetch) || exit; fi; done
	touch $@

std-fetch:
	for src in $(SOURCES); do if [ ! -f $(DISTDIR)/$$src ]; then rm -f $$src && $(FETCH) $(SRCURL)/$$src && mv $$src $(DISTDIR); fi; done

extract: .extract
.extract: .depend .fetch
	@echo && echo "===== extract: $(PKGNAME) ====="
	@$(MAKE) do-extract || exit
	touch $@

std-extract:
	for src in $(SOURCES); do $(EXTRACT) $(DISTDIR)/$$src; done

patch: .patch
.patch: .extract
	@echo && echo "===== patch: $(PKGNAME) ====="
	if [ -f patch-00 ]; then cat patch-* | patch -p0 -d $(WORKDIR); fi
	@$(MAKE) do-patch || exit
	touch $@

fix-configure:
	for conf in `find $(WORKDIR) -name config.guess`; do cp $(PKGDEST)/share/libtool/[cl]*.* `dirname $$conf`; done
	for conf in `find $(WORKDIR) -name configure`; do cp $$conf $$conf.orig && sed -e "s/interix3\*/interix[3456]*/" $$conf.orig > $$conf; done

config: .config
.config: .patch
	@echo && echo "===== config: $(PKGNAME) ====="
	@$(MAKE) do-config || exit
	touch $@

reconfig:
	rm -f .config
	$(MAKE) config

build: .build
.build: .config
	@echo && echo "===== build: $(PKGNAME) ====="
	@$(MAKE) do-build || exit
	touch $@

rebuild:
	rm -f .build
	$(MAKE) build

pkginst: .pkginst
.pkginst: .build
	@echo && echo "===== pkginst: $(PKGNAME) ====="
	rm -rf dest
	@$(MAKE) do-pkginst || exit
	touch $@

package: $(PACKAGE)
$(PACKAGE): .pkginst
	@echo && echo "===== package: $(PKGNAME) ====="
	rm -rf dest/share/$(PKGCMDNAME)
	if [ -d dest/share ]; then if [ `ls -A dest/share | wc -l` -eq 0 ]; then rmdir dest/share; fi; fi
	(cd dest && find *) > files
	mkdir -p `dirname $(PKGFILE)`
	mv files $(PKGFILE)
	mkdir -p `dirname $(PKGVERF)`
	echo $(PKGVER) > $(PKGVERF)
	mkdir -p `dirname $(PKGDEPF)`
	echo `echo $(DEPENDS) | sed -e "s|/|-|g"` > $(PKGDEPF)
	mkdir -p $(PKGDIR)
	cd dest && tar cvf - * | $(PKGCMDNAME)-bzip2 > ../pkg
	mv pkg $@

repackage:
	rm -f .pkginst
	$(MAKE) package

install: .install
.install: $(PACKAGE)
	@echo && echo "===== install: $(PKGNAME) ====="
	$(PKGCMDNAME)-add $(PACKAGE)
	touch $@

reinstall:
	rm -f .install
	$(MAKE) install

uninstall:
	@echo && echo "===== uninstall: $(PKGNAME) ====="
	$(PKGCMDNAME)-del $(PKGNAME)
	rm -f .install

clean:
	rm -rf .depend .fetch .extract .patch .config .build .pkginst .install files pkg $(WORKDIR) $(SOURCES) dest

distclean: clean
	rm -f $(PACKAGE)
