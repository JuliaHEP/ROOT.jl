objs: gen/tdirectory.o gen/tfile.o gen/tobject.o gen/ttree.o gen/th1.o gen/th1d.o gen/tlist.o gen/tcollection.o gen/tobjarray.o gen/tseqcollection.o gen/th3.o gen/tkey.o gen/tbranch.o gen/tleaf.o gen/th2.o gen/th2d.o gen/tarrayd.o gen/tarray.o gen/tchain.o gen/tlistiter.o gen/groot.o gen/tsvdunfold.o

CFLAGS=-Werror -fPIC `root-config --cflags` -Wno-error
LDFLAGS=-Werror -rdynamic -shared -fPIC `root-config --libs --glibs`

%.o: %.cc
	c++ $(CFLAGS) -c $< -o $@

lib-osx: objs
	c++ $(LDFLAGS) gen/*.o -o libroot.dylib

lib-linux: objs
	c++ $(LDFLAGS) gen/*.o -o libroot.so

INCDIRS=-I$(INCDIR_UV) -I$(INCDIR_JULIA) -I$(INCDIR_SUPPORT)
LIBDIRS=-L$(LIBDIR_JULIA)
#compile getopts to an object file
#link getopts and repl to a dynamic library
#compile ui.cc, which dlopens the repl after initializing ROOT
ui-osx:
	c++ -w src/getopt.c src/repl.c $(LIBDIRS) $(INCDIRS) -lc -ljulia -shared -o librepl.dylib
	c++ src/ui.cc `root-config --cflags --libs --ldflags` -o julia

ui-linux:
	c++ -fPIC -w src/getopt.c src/repl.c $(LIBDIRS) $(INCDIRS) -lc -ljulia -shared -o librepl.so
	c++ src/ui.cc -fPIC `root-config --cflags --libs --ldflags` -o julia

.PHONY: ui-osx ui-linux lib-osx lib-linux clean

perf: test/perf.cc
	c++  `root-config --libs --cflags` test/perf.cc -o perf
clean:
	rm -rf gen/*.o
	rm -rf libroot*
	rm -rf librepl*
	rm -rf julia
