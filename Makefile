all: libs

objs: gen/tdirectory.o gen/tfile.o gen/tobject.o gen/ttree.o gen/th1.o gen/th1d.o gen/tlist.o gen/tcollection.o gen/tobjarray.o gen/tseqcollection.o gen/th3.o gen/tkey.o gen/tbranch.o gen/tleaf.o gen/th2.o gen/th2d.o gen/tarrayd.o gen/tarray.o gen/tchain.o gen/tlistiter.o gen/groot.o

CFLAGS=-Werror -fPIC `root-config --cflags` -Wno-error -I/Users/joosep/Documents/root-6.03.04//core/meta/src/
LDFLAGS=-Werror -rdynamic -shared -fPIC `root-config --libs --glibs`

%.o: %.cc
	c++ $(CFLAGS) -c $< -o $@

lib-osx: objs ui-osx
	c++ $(LDFLAGS) gen/*.o -o libroot.dylib

lib-linux: objs
	c++ $(LDFLAGS) gen/*.o -o libroot

libs: lib-osx lib-linux

#compile getopts to an object file
#link getopts and repl to a dynamic library
#compile ui.cc, which dlopens the repl after initializing ROOT
ui-osx:
	c++ -w -c $(JULIA_HOME)/../../ui/getopt.c -O
	ld -macosx_version_min 10.10 -dylib getopt.o $(JULIA_HOME)/../../ui/repl.o -L$(JULIA_HOME) -ljulia -lc -lcrt1.o -o librepl
	c++ src/ui.cc `root-config --cflags --libs --ldflags` -o rjulia

ui-linux:
	c++ -w -c $(JULIA_HOME)/../../ui/getopt.c -O -fPIC
	ld -fPIC -shared getopt.o $(JULIA_HOME)/../../ui/repl.o -L$(JULIA_HOME) -ljulia -o librepl
	c++ src/ui.cc -fPIC `root-config --cflags --libs --ldflags` -o rjulia

.PHONY: clean

clean:
	rm -f gen/*.o
	rm -f libroot*
	rm -f librepl*
