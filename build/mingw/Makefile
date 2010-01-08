PACKAGES = binutils runtime w32api gcc

all fetch extract config build package install uninstall clean distclean:
	for pkg in $(PACKAGES); do (cd $$pkg && $(MAKE) $@) || exit; done
