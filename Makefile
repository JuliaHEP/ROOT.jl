all: libs

objs: gen/tdirectory.o gen/tfile.o gen/tobject.o gen/ttree.o gen/th1.o gen/th1d.o gen/tlist.o gen/tcollection.o gen/tobjarray.o gen/tseqcollection.o gen/tkey.o gen/tbranch.o gen/tleaf.o gen/groot.o

CFLAGS=-Werror -fPIC -lRIO `root-config --cflags --libs --glibs`
LDFLAGS=-Werror -rdynamic -shared -fPIC `root-config --libs --glibs`

%.o: %.cc
	c++ $(CFLAGS) -c $< -o $@

lib-osx: objs
	c++ $(LDFLAGS) gen/*.o -shared -fPIC -o libroot.dylib

lib-linux: objs
	c++ $(LDFLAGS) gen/*.o -o libroot

libs: lib-osx lib-linux

.PHONY: clean

clean:
	rm -f gen/*.o
	rm -f libroot.*
