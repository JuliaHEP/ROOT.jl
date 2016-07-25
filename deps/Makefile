include Make.inc

ROOTFLAGS = `root-config --libs --cflags`
JLFLAGS = -L/Users/joosep/Documents/julia/usr/lib -I/Users/joosep/Documents/julia/usr/include -I/Users/joosep/Documents/julia/src -I/Users/joosep/Documents/julia/src/support

../julia: ../src/ui.cc
	$(CXX) $(ROOTFLAGS) $(JLFLAGS) -DLIBJULIA=\"libjulia.$(SHLIB_EXT)\" -luv ../src/ui.cc -o $@

.PHONY: clean

clean:
	rm -f ../julia
