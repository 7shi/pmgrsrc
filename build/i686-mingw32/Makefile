PACKAGES = binutils runtime w32api gcc zlib sdl

include cross.mk
include $(TOPDIR_)/common.mk

$(COMMANDS):
	for pkg in $(PACKAGES); do (cd $$pkg && $(MAKE) $@) || exit; done
