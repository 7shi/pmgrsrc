PACKAGES = \
	arm-linux-gnueabi \
	autoconf \
	automake \
	bash \
	bison \
	cvs \
	distorm \
	flex \
	gettext \
	ginstall \
	gmp \
	gsed \
	gtar \
	libiconv \
	libtool \
	libxml2 \
	lzma \
	m4 \
	mercurial \
	mingw \
	mkisofs \
	mpfr \
	nasm \
	openssh \
	openssl \
	php \
	python \
	readline \
	subversion \
	texinfo \
	x86_64-mingw32 \
	xz \
	yasm \
	zlib \
	zsh

TOPDIR = ..
include $(TOPDIR)/common.mk

$(COMMANDS):
	for pkg in $(PACKAGES); do (cd $$pkg && $(MAKE) $@) || exit; done
