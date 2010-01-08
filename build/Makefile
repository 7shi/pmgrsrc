PACKAGES = \
	distorm \
	gmp \
	i386-elf \
	i686-mingw32 \
	libtool \
	mipsel-elf \
	mkisofs \
	mpfr \
	nasm \
	x86_64-mingw32 \
	yasm

TOPDIR = ..
include $(TOPDIR)/common.mk

$(COMMANDS):
	for pkg in $(PACKAGES); do (cd $$pkg && $(MAKE) $@) || exit; done
