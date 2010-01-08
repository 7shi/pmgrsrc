PACKAGES = \
	zlib \
	perl python \
	ginstall gtar \
	m4 autoconf automake libtool \
	texinfo bison flex \
	libiconv gettext readline \
	openssl openssh \
	bash zsh \
	cvs subversion \
	mkisofs \
	nasm yasm distorm \
	mingw i386-elf x86_64-elf

TOPDIR = ..
include $(TOPDIR)/common.mk

$(COMMANDS):
	for pkg in $(PACKAGES); do (cd $$pkg && $(MAKE) $@) || exit; done
