PACKAGES = \
	zlib \
	libiconv gettext \
	wget \
	bash zsh \
	cvs subversion \
	texinfo m4 bison flex \
	mingw

TOPDIR = ..
include $(TOPDIR)/common.mk

$(COMMANDS):
	for pkg in $(PACKAGES); do (cd $$pkg && $(MAKE) $@) || exit; done
