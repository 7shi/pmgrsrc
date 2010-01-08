PACKAGES = \
	zlib \
	libiconv gettext \
	wget openssl openssh \
	bash zsh \
	cvs subversion \
	mkisofs \
	texinfo m4 bison flex autoconf automake \
	perl \
	nasm yasm distorm \
	mingw x86_64-elf

TOPDIR = ..
include $(TOPDIR)/common.mk

$(COMMANDS):
	for pkg in $(PACKAGES); do (cd $$pkg && $(MAKE) $@) || exit; done
