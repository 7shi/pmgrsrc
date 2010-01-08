PACKAGES = pmgr bzip2 gmake wget

TOPDIR = ..
include $(TOPDIR)/common.mk

$(COMMANDS):
	for pkg in $(PACKAGES); do (cd $$pkg && $(MAKE) $@) || exit; done
