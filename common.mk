PKGDEST     = /opt/pmgr
PKGDBDIR    = share/pmgr
PKGCMDNAME  = pmgr
PKGSUFFIX   = pmgr
FETCH       = wget
EXTRACT     = pmgr-extract
DISTDIR     = $(TOPDIR)/distfiles
PKGDIR      = $(TOPDIR)/packages
COMMANDS    = all fetch extract config build \
              package repackage install reinstall uninstall \
              clean distclean
