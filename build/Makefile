PACKAGES = \
	arm-linux-gnueabi \
	distorm \
	gtar \
	gxemul \
	i686-mingw32 \
	mercurial \
	openssh \
	python \
	subversion \
	x86_64-mingw32

TOPDIR = ..
include $(TOPDIR)/common.mk

$(COMMANDS):
	for pkg in $(PACKAGES); do (cd $$pkg && $(MAKE) $@) || exit; done
