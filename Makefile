include common.mk

all:
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

clean:
	cd base && $(MAKE) clean
	cd build && $(MAKE) clean
