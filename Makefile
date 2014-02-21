all: gen/tdirectory.o gen/tfile.o gen/tobject.o gen/ttree.o gen/th1.o gen/th1d.o


CFLAGS=`root-config --cflags --libs` -shared -fPIC

gen/tdirectory.o: gen/tdirectory.cc
	c++ $(CFLAGS) $< -o $@

gen/tobject.o: gen/tobject.cc
	c++ $(CFLAGS) $< -o $@

gen/tfile.o: gen/tfile.cc
	c++ $(CFLAGS) $< -o $@

gen/ttree.o: gen/ttree.cc
	c++ $(CFLAGS) $< -o $@

gen/th1.o: gen/th1.cc
	c++ $(CFLAGS) $< -o $@

gen/th1d.o: gen/th1d.cc
	c++ $(CFLAGS) $< -o $@

lib-osx:
	c++ `root-config --libs` -shared -fPIC gen/*.o -o libroot.dylib

lib-linux:
	c++ `root-config --libs` -shared -fPIC gen/*.o -o libroot.so

.PHONY: clean

clean:
	rm -f gen/*.o
	rm -f libroot.*