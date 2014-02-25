all: libs

objs: gen/tdirectory.o gen/tfile.o gen/tobject.o gen/ttree.o gen/th1.o gen/th1d.o gen/tlist.o gen/tcollection.o gen/tobjarray.o gen/tseqcollection.o

CFLAGS=`root-config --cflags` -fPIC
LDFLAGS=`root-config --libs` -shared -fPIC

%.o: %.cc
	c++ $(CFLAGS) -c $< -o $@

lib-osx: objs
	c++ $(LDFLAGS) gen/*.o -shared -fPIC -o libroot.dylib

lib-linux: objs
	c++ $(LDFLAGS) -shared -fPIC gen/*.o -o libroot.so

libs: lib-osx lib-linux

.PHONY: clean

clean:
	rm -f gen/*.o
	rm -f libroot.*