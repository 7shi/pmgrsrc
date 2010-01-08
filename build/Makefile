PACKAGES = \
	arm-linux-gnueabi \
	autoconf \
	automake \
	bash \
	bison \
	cvs \
	distorm \
	file \
	flex \
	gettext \
	ginstall \
	gmp \
	gsed \
	gtar \
	i686-mingw32 \
	libiconv \
	libtool \
	libxml2 \
	m4 \
	mercurial \
	mkisofs \
	mpfr \
	nasm \
	openssh \
	openssl \
	python \
	readline \
	subversion \
	texinfo \
	which \
	x86_64-mingw32 \
	yasm \
	zlib \
	zsh

TOPDIR = ..
include $(TOPDIR)/common.mk

$(COMMANDS):
	for pkg in $(PACKAGES); do (cd $$pkg && $(MAKE) $@) || exit; done
