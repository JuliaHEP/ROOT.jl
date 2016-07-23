include Make.inc

ROOTFLAGS = `root-config --libs --cflags`

../julia: ../src/ui.cc
	$(CXX) $(ROOTFLAGS) -DLIBJULIAREPL=\"librepl.$(SHLIB_EXT)\" ../src/ui.cc -o $@

.PHONY: clean

clean:
	rm -f ../julia
