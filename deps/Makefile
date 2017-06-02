SRCDIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
builddir=$(SRCDIR)/usr/bin/

# shared library runtime paths
ifeq ($(OS), Darwin)
  CXX = c++
  RPATH := -Wl,-rpath,'$(ROOT_LIBDIR)' -Wl,-rpath,'$(JULIA_LIBDIR)'
else
  CXX = c++
  RPATH := -Wl,-rpath,'$(ROOT_LIBDIR)' -Wl,-rpath,'$(JULIA_LIBDIR)'
endif

override CFLAGS += $(JCFLAGS)
override CXXFLAGS += $(JCXXFLAGS)
override CPPFLAGS += $(JCPPFLAGS)

FLAGS := -I$(INCDIR_JULIA_H) -I$(INCDIR_UV_H) -I$(INCDIR_SUPPORT_H)
FLAGS += -Wall -Wno-strict-aliasing -fno-omit-frame-pointer -Wc++-compat

SHIPFLAGS += $(FLAGS)
JLDFLAGS += $(LDFLAGS) $(RPATH)

all: clean $(builddir)/julia

$(builddir)/julia: $(SRCDIR)/ui.cc
	$(CXX) $(FLAGS) $^ -o $@ `root-config --cflags --libs --ldflags` -DLIBJULIA=\"$(LIBJULIA_PATH)\" $(JLDFLAGS)

clean:
	rm -rf $(builddir)/julia

.PHONY: clean all
