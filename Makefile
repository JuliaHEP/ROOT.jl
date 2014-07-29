all: libs

objs: gen/tdirectory.o gen/tfile.o gen/tobject.o gen/ttree.o gen/th1.o gen/th1d.o gen/tlist.o gen/tcollection.o gen/tobjarray.o gen/tseqcollection.o gen/tkey.o gen/tbranch.o gen/tleaf.o gen/groot.o gen/th2.o gen/th2d.o gen/tarrayd.o gen/tarray.o gen/tchain.o gen/tlistiter.o
#gen/tunfold.o gen/tunfoldsys.o

CFLAGS=-Werror -fPIC `root-config --cflags` -Wno-error
LDFLAGS=-Werror -rdynamic -shared -fPIC `root-config --libs --glibs`

%.o: %.cc
	c++ $(CFLAGS) -c $< -o $@

lib-osx: objs
	c++ $(LDFLAGS) gen/*.o -o libroot.dylib

lib-linux: objs
	c++ $(LDFLAGS) gen/*.o -o libroot

libs: lib-osx lib-linux

.PHONY: clean

clean:
	rm -f gen/*.o
	rm -f libroot.*
	rm -f libroot
