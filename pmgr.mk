PACKAGE = $(PKGDIR)/$(PKGNAME)-$(PKGVER).$(PKGSUFFIX)
PKGFILE = dest/$(PKGDBDIR)/files/$(PKGNAME)
PKGVERF = dest/$(PKGDBDIR)/versions/$(PKGNAME)
PKGDEPF = dest/$(PKGDBDIR)/depends/$(PKGNAME)

all: build

depend: .depend
.depend:
	@echo && echo ===== depend =====
	for dep in $(BLDDEPS) $(DEPENDS); do if [ ! -f $(PKGDEST)/$(PKGDBDIR)/files/`echo $$dep | sed -e 's|/|-|g'` ]; then (cd $(TOPDIR)/build/$$dep && $(MAKE) install) || exit; fi; done
	touch $@

fetch: .fetch
.fetch:
	@echo && echo ===== fetch =====
	mkdir -p $(DISTDIR)
	for dep in $(BLDDEPS) $(DEPENDS); do if [ ! -f $(PKGDEST)/$(PKGDBDIR)/files/`echo $$dep | sed -e 's|/|-|g'` ]; then (cd $(TOPDIR)/build/$$dep && $(MAKE) do-fetch) || exit; fi; done
	@$(MAKE) do-fetch || exit
	touch $@

extract: .extract
.extract: .depend .fetch
	@echo && echo ===== extract =====
	@$(MAKE) do-extract || exit
	touch $@

patch: .patch
.patch: .extract
	@echo && echo ===== patch =====
	@$(MAKE) do-patch || exit
	touch $@

config: .config
.config: .patch
	@echo && echo ===== config =====
	@$(MAKE) do-config || exit
	touch $@

build: .build
.build: .config
	@echo && echo ===== build =====
	@$(MAKE) do-build || exit
	touch $@

pkginst: .pkginst
.pkginst: .build
	@echo && echo ===== pkginst =====
	rm -rf dest
	@$(MAKE) do-pkginst || exit
	touch $@

package: $(PACKAGE)
$(PACKAGE): .pkginst
	@echo && echo ===== package =====
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
	@echo && echo ===== install =====
	$(PKGCMDNAME)-add $(PACKAGE)
	touch $@

reinstall:
	rm -f .install
	$(MAKE) install

uninstall:
	@echo && echo ===== uninstall =====
	$(PKGCMDNAME)-del $(PKGNAME)
	rm -f .install

clean:
	rm -rf .depend .fetch .extract .patch .config .post-config .build .pkginst .install files pkg $(WORKDIR) $(SOURCE) dest

distclean: clean
	rm -f $(PACKAGE)
