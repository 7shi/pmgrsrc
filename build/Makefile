PACKAGES = \
	arm-linux-gnueabi \
	autoconf \
	automake \
	cvs \
	distorm \
	file \
	ginstall \
	gmp \
	i686-mingw32 \
	mercurial \
	mkisofs \
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
