PACKAGE = $(PKGDIR)/$(PKGNAME)-$(PKGVER).$(PKGSUFFIX)
PKGLIST = dest/$(PKGDBDIR)/$(PKGNAME)

depend: .depend
.depend:
	@echo && echo ===== depend =====
	for dep in $(DEPENDS); do if [ ! -f $(PKGDEST)/$(PKGDBDIR)/`echo $$dep | sed -e 's|/|-|g'` ]; then (cd $(TOPDIR)/build/$$dep && $(MAKE) install) || exit; fi; done
	touch $@

package: $(PACKAGE)
$(PACKAGE): .pkginst
	@echo && echo ===== package =====
	rm -rf dest/share/$(PKGCMDNAME)
	if [ -d dest/share ]; then if [ `ls -A dest/share | wc -l` -eq 0 ]; then rmdir dest/share; fi; fi
	(cd dest && find *) > list
	mkdir -p dest/$(PKGDBDIR)
	mv list $(PKGLIST)
	mkdir -p $(PKGDIR)
	cd dest && tar cvf - * | $(BZIP2) > ../pkg
	mv pkg $@

repackage:
	rm -f .pkginst
	$(MAKE) package

install: .install
.install: $(PACKAGE)
	@echo
	$(PKGCMDNAME)-add $(PACKAGE)
	touch $@

reinstall:
	rm -f .install
	$(MAKE) install

uninstall:
	@echo
	$(PKGCMDNAME)-del $(PKGNAME)
	rm -f .install

clean:
	rm -rf .depend .fetch .extract .patch .config .post-config .build .pkginst .install list pkg $(WORKDIR) $(SOURCE) dest

distclean: clean
	rm -f $(PACKAGE)
