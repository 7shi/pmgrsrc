FETCH = pmgr-httpget #-proxy proxy.somewhere:8080

subst-prefix:
	for mk in `find $(WORKDIR) -name Makefile`; do cp $$mk $$mk.orig && sed -e "s|^prefix *= */.*$$|prefix = `pwd`/dest|" $$mk.orig > $$mk; done
