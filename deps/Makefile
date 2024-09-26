# This makefile is meant to be called from the companion build.jl Julia script.
# and requires the CXXWRAP_PREFIX and JL_SHARE to be set.
#
# make CXXWRAP_PREFIX=... JL_SHARE=...
#
BUILD_DIR = build
ROOT_CONFIG = root-config
UNAME=$(shell uname)

ROOT_LIBS = $(shell $(ROOT_CONFIG) --libs) -lGeom
ROOT_INC_DIR = $(shell $(ROOT_CONFIG) --incdir)

CPPFLAGS = -MMD -I. -I $(CXXWRAP_PREFIX)/include
CXXFLAGS = $(patsubst -std=gnu%,,$(shell $(JL_SHARE)/julia-config.jl --cflags))
CXXFLAGS += $(shell $(ROOT_CONFIG) --cflags)
CXXFLAGS += -O2
CXXFLAGS += -Wno-c++20-extensions
#CXXFLAGS += -DVERBOSE_IMPORT #To enable the verbose mode of the libray loading
#CXXFLAGS += -Wall -O0 -g     #To compile with debugger infomation
LDFLAGS = $(shell $(JL_SHARE)/julia-config.jl --ldflags)
LDLIBS = $(shell $(JL_SHARE)/julia-config.jl --ldlibs) -L$(CXXWRAP_PREFIX)/lib -lcxxwrap_julia -lcxxwrap_julia_stl
JULIA = julia

CXX_IS_CLANG = $(shell $(CXX) -dM -E - < /dev/null | grep -c __clang__)

VERBOSE = no #use -DVERBOSE to enable verbosity
# Verbose output
ifeq ($(VERBOSE), no)
    Q =
else
    Q = @
endif

ifeq ($(UNAME),Darwin)
  SO_SUFFIX = .dylib
else
  SO_SUFFIX = .so
endif

ifneq ($(CXX_IS_CLANG), 0)
	CXXFLAGS += -ferror-limit=3
else #assuming gcc
	CXXFLAGS += -fmax-errors=3
endif


LINK.o = $(CXX) $(LDFLAGS) $(TARGET_ARCH)

.PHONY: all clean distclean run_demo run_demo2 check_root make_lib_from_objs

PRODUCTS = $(BUILD_DIR)/libroot_julia$(SO_SUFFIX)

#Define WRAPPER_CXX
#WRAPPER_CXX: = $(file < src/generated_cxx) Extra.cxx #does not work on MacOS
include generated_cxx.make

OBJS = $(addprefix $(BUILD_DIR)/, $(patsubst %.cxx,%.o, $(WRAPPER_CXX)))
DEPS = $(patsubst %.o,%.d, $(OBJS))

all: $(PRODUCTS)

clean:
	-$(RM) -r $(BUILD_DIR)

distclean:
	-$(RM) -r $(BUILD_DIR) build build.log
	-$(RM) $(PRODUCTS)

#$(BUILD_DIR):
#	@[ -d $(BUILD_DIR) ] && mkdir -p $(BUILD_DIR)
#	@echo 'all:\n\n%:\n\t$$(MAKE) -C .. $$@\nclean:\n\t$$(MAKE) -C .. clean build\n' > $(BUILD_DIR)/Makefile

$(BUILD_DIR)/ROOT-generated.wit: ROOT.wit #$(BUILD_DIR)
	@echo "Build $(notdir $@)"
	$(Q) $(MAKE) -DVERBOSE=$(VERBOSE) check_root
	$(Q) [ -d $(BUILD_DIR)/libROOT/build ] || mkdir -p $(BUILD_DIR)/libROOT/build
	$(Q) $(shell echo "#\n# Warning: file generated automatically from $<\n#" > $@)
	$(Q) $(shell sed "s@%ROOT_INC_DIR%@$(ROOT_INC_DIR)@" $< >> $@ || rm $@)

check_root:
ifeq ($(ROOT_LIBS),)
	$(error ERROR: "Command root-config not found. ROOT (http:://root.cern.ch) environment needs to be set")
endif

run_demo: all
	LD_LIBRARY_PATH=$(shell $(ROOT_CONFIG) --libdir) JULIA_LOAD_PATH=.:@:@v#.#:@stdlib "$(JULIA)" -i demo_ROOT.jl

run_demo2: all
	LD_LIBRARY_PATH=$(shell $(ROOT_CONFIG) --libdir) JULIA_LOAD_PATH=.:@:@v#.#:@stdlib "$(JULIA)" -i demo_TGraph.jl

test: all
	LD_LIBRARY_PATH=$(shell $(ROOT_CONFIG) --libdir) \
JULIA_LOAD_PATH=`pwd`/build/ROOT/src:$(JULIA_LOAD_PATH): "$(JULIA)" --project=.. demo_ROOT.jl
	cmp demo_ROOT.png demo_ROOT-ref.png
	LD_LIBRARY_PATH=$(shell $(ROOT_CONFIG) --libdir) \
JULIA_LOAD_PATH=`pwd`/build/ROOT/src:$(JULIA_LOAD_PATH): "$(JULIA)" --project=.. demo_TGraph.jl
	cmp demo_TGraph.png demo_TGraph-ref.png
	LD_LIBRARY_PATH=$(shell $(ROOT_CONFIG) --libdir) \
JULIA_LOAD_PATH=`pwd`/build/ROOT/src:$(JULIA_LOAD_PATH): "$(JULIA)" --project=.. TTree_examples/write_tree1.jl \
&& JULIA_LOAD_PATH=`pwd`/build/ROOT/src:$(JULIA_LOAD_PATH): "$(JULIA)" --project=.. TTree_examples/read_tree1.jl
	LD_LIBRARY_PATH=$(shell $(ROOT_CONFIG) --libdir) \
JULIA_LOAD_PATH=`pwd`/build/ROOT/src:$(JULIA_LOAD_PATH): "$(JULIA)" --project=.. TTree_examples/write_tree2.jl \
&& JULIA_LOAD_PATH=`pwd`/build/ROOT/src:$(JULIA_LOAD_PATH): "$(JULIA)" --project=.. -e 'import Pkg; Pkg.activate(;temp=true); Pkg.add("UnROOT"); include("TTree_examples/read_tree2.jl")'
	LD_LIBRARY_PATH=$(shell $(ROOT_CONFIG) --libdir) \
JULIA_LOAD_PATH=`pwd`/build/ROOT/src:$(JULIA_LOAD_PATH): "$(JULIA)" --project=.. TTree_examples/write_tree3.jl \
&& JULIA_LOAD_PATH=`pwd`/build/ROOT/src:$(JULIA_LOAD_PATH): "$(JULIA)" --project=.. TTree_examples/read_tree3.jl

$(BUILD_DIR)/%.o: src/%.cxx #$(BUILD_DIR)
	@echo "Make $(notdir $@)"
	$(Q) [ -d $(BUILD_DIR)/libROOT/build ] || mkdir -p $(BUILD_DIR)/libROOT/build
	$(Q) $(COMPILE.cc) $(CPPFLAGS) -o $@ $<

$(BUILD_DIR)/libroot_julia$(SO_SUFFIX): $(OBJS)
	@echo "Make $(notdir $@)"
	$(Q) $(MAKE) check_root
	$(Q) $(LINK.o) -o $@ --shared -fPIC $(OBJS) $(ROOT_LIBS) $(LDLIBS)


echo_%:
	@echo "$* = $(subst ",\",$($*))"

-include $(DEPS)
