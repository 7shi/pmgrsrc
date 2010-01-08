PKGDEST     = /usr/pmgr
PKGDBDIR    = share/pmgr
PKGCMDNAME  = pmgr
PKGSUFFIX   = pmgr
FETCH       = wget
EXTRACT     = pmgr-extract
PKGCOMPRESS = xz
DISTDIR     = $(TOPDIR)/distfiles
PKGDIR      = $(TOPDIR)/packages
PKGCPPFLAGS = -I$(PKGDEST)/include -I/usr/local/include
PKGLDFLAGS  = -L$(PKGDEST)/lib -L/usr/local/lib/gcc -Wl,-R$(PKGDEST)/lib -Wl,-R/usr/local/lib/gcc
COMMANDS    = all fetch extract config build \
              package repackage install reinstall uninstall \
              clean distclean
