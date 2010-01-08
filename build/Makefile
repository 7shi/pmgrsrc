PACKAGES = \
	arm-linux-gnueabi \
	distorm \
	gtar \
	i386-elf \
	i686-mingw32 \
	mipsel-elf \
	x86_64-mingw32

TOPDIR = ..
include $(TOPDIR)/common.mk

$(COMMANDS):
	for pkg in $(PACKAGES); do (cd $$pkg && $(MAKE) $@) || exit; done
