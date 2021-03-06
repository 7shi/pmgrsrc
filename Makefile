include common.mk

help:
	@echo "[how to build]"
	@echo
	@echo "1. export PATH=\"$(PKGDEST)/bin:\$$PATH"\"
	@echo "2. cd base && make install"
	@echo "3. cd build[/PACKAGE] && make install"
	@echo
	@echo "[command usage]"
	@echo
	@echo "install:"
	@echo "% $(PKGCMDNAME)-add PACKAGE-VER.$(PKGSUFFIX)"
	@echo
	@echo "uninstall:"
	@echo "% $(PKGCMDNAME)-del PACKAGE"
	@echo
	@echo "list installed packages:"
	@echo "% $(PKGCMDNAME)-ls [package-name]"
	@echo
	@echo "Thank you!"

$(COMMANDS):
	cd base && $(MAKE) $@
	cd build && $(MAKE) $@
