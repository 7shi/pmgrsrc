PACKAGES = \
	arm-linux-gnueabi \
	autoconf \
	automake \
	cvs \
	distorm \
	file \
	ginstall \
	git \
	gtar \
	gxemul \
	i386-elf \
	i686-mingw32 \
	mercurial \
	mipsel-elf \
	mkisofs \
	openssh \
	python \
	subversion \
	which \
	x86_64-mingw32

TOPDIR = ..
include $(TOPDIR)/common.mk

$(COMMANDS):
	for pkg in $(PACKAGES); do (cd $$pkg && $(MAKE) $@) || exit; done
