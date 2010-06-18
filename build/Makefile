PACKAGES = \
	alpha-elf \
	arm-linux-gnueabi \
	arm-pe \
	autoconf \
	automake \
	cvs \
	distorm \
	file \
	gawk \
	ginstall \
	git \
	gmp \
	gtar \
	gxemul \
	i386-elf \
	i386-pc-minix \
	i686-mingw32 \
	m4 \
	mercurial \
	mipsel-elf \
	mipsel-pe \
	mkisofs \
	mpc \
	mpfr \
	openssh \
	python \
	subversion \
	which \
	x86_64-mingw32

TOPDIR = ..
include $(TOPDIR)/common.mk

$(COMMANDS):
	for pkg in $(PACKAGES); do (cd $$pkg && $(MAKE) $@) || exit; done
