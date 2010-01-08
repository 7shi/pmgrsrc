PKGDEST     = /opt/pmgr
PKGDBDIR    = share/pmgr
PKGCMDNAME  = pmgr
PKGSUFFIX   = pmgr
FETCH       = wget
EXTRACT     = pmgr-extract
PKGCOMPRESS = xz
DISTDIR     = $(TOPDIR)/distfiles
PKGDIR      = $(TOPDIR)/packages
PKGCPPFLAGS = -I$(PKGDEST)/include -I/usr/pkg/include
PKGLDFLAGS  = -L$(PKGDEST)/lib -L/usr/pkg/lib -Wl,-R$(PKGDEST)/lib -Wl,-R/usr/pkg/lib
COMMANDS    = all fetch extract config build \
              package repackage install reinstall uninstall \
              clean distclean
