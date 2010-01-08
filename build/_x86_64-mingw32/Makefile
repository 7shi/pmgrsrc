PACKAGES = binutils runtime gcc

include cross.mk
include $(TOPDIR_)/common.mk

$(COMMANDS):
	for pkg in $(PACKAGES); do (cd $$pkg && $(MAKE) $@) || exit; done
