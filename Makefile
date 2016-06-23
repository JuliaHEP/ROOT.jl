objs: gen/tdirectory.o gen/tfile.o gen/tobject.o gen/ttree.o gen/th1.o gen/th1d.o gen/tlist.o gen/tcollection.o gen/tobjarray.o gen/tseqcollection.o gen/th3.o gen/tkey.o gen/tbranch.o gen/tleaf.o gen/th2.o gen/th2d.o gen/tarrayd.o gen/tarray.o gen/tchain.o gen/tlistiter.o gen/groot.o gen/tsvdunfold.o

CFLAGS=-Werror -fPIC `root-config --cflags` -Wno-error
LDFLAGS=-Werror -rdynamic -shared -fPIC `root-config --libs --glibs`

%.o: %.cc
	c++ $(CFLAGS) -c $< -o $@

lib-osx: objs
	c++ $(LDFLAGS) gen/*.o -o libroot.dylib

lib-linux: objs
	c++ -Wl,--no-as-needed $(LDFLAGS) gen/*.o -o libroot.so

.PHONY: ui-osx ui-linux lib-osx lib-linux clean

perf: test/perf.cc
	c++  `root-config --libs --cflags` test/perf.cc -o perf
clean:
	rm -rf gen/*.o
	rm -rf libroot*
	rm -rf julia
