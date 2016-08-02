#JULIA_HOME=/Users/joosep/Documents/julia
JULIA_INCLUDEDIR=$(JULIA_HOME)/usr/include/
#OS=Darwin
SRCDIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
builddir=$(SRCDIR)/usr/bin/

# shared library runtime paths
ifeq ($(OS), Darwin)
  CXX = c++
  RPATH := -Wl,-rpath,'$(JULIA_HOME)/usr/lib/'
  SHLIB_EXT := dylib
else
  CXX = c++
  RPATH := -Wl,-rpath,'$(JULIA_HOME)/usr/lib' -Wl,-rpath-link,'$(JULIA_HOME)/usr/lib' -Wl,-z,origin
  SHLIB_EXT := so
endif

override CFLAGS += $(JCFLAGS)
override CXXFLAGS += $(JCXXFLAGS)
override CPPFLAGS += $(JCPPFLAGS)

SRCS := repl

FLAGS := -I$(JULIA_HOME)/src -I$(JULIA_HOME)/src/support -I$(JULIA_INCLUDEDIR)
FLAGS += -Wall -Wno-strict-aliasing -fno-omit-frame-pointer -Wc++-compat

OBJS := $(SRCS:%=$(BUILDDIR)/%.o)
SHIPFLAGS += $(FLAGS)
JLDFLAGS += $(LDFLAGS) $(RPATH)

all: clean $(builddir)/julia

$(builddir)/julia: $(SRCDIR)/ui.cc
	$(CXX) $(FLAGS) $^ -o $@ `root-config --cflags --libs --ldflags` -DLIBJULIA=\"libjulia.$(SHLIB_EXT)\" $(JLDFLAGS)

clean:
	rm -rf $(builddir)/julia

.PHONY: clean all
