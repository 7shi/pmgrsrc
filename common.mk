PKGDEST     = /opt/pmgr
PKGDBDIR    = share/pmgr
PKGCMDNAME  = pmgr
PKGSUFFIX   = pmgr
HTTPGET     = pmgr-httpget #-proxy proxy.somewhere:8080
DISTDIR     = $(TOPDIR)/distfiles
PKGDIR      = $(TOPDIR)/packages
COMMANDS    = all fetch extract config build \
              package repackage install reinstall uninstall \
              clean distclean
