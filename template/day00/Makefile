CXX = clang++

CXX_FLAGS = -std=c++17
CXX_FLAGS += -pedantic
CXX_FLAGS += -Wall
CXX_FLAGS += -Wextra
CXX_FLAGS += -MMD
CXX_FLAGS += -MP
CXX_FLAGS += -stdlib=libstdc++
CXX_FLAGS += -Ofast
CXX_FLAGS += -march=native
CXX_FLAGS += -Wno-unknown-warning-option
CXX_FLAGS += -Qunused-arguments
CXX_FLAGS += -pipe
CXX_FLAGS += -I.. # look for headers in utils/

recwildcard=$(wildcard $1$2)\
			$(foreach d,$(wildcard $1*),$(call recwildcard,$d/,$2))

EXE = day00
BIN = bin/
OBJDIR = obj/
DOC = doc/
SRC = src/
ALL_SRC = $(sort $(dir $(call recwildcard,$(SRC)**/*/)))
VPATH = $(SRC):$(ALL_SRC)
OBJ = $(addprefix\
	  $(OBJDIR),$(notdir $(patsubst %.cpp,%.o,$(call recwildcard,src/,*.cpp))))
DEP = $(OBJ:.o=.d)

# Rules
.PHONY: all
all: $(OBJDIR) $(BIN) $(BIN)$(EXE)

-include $(DEP)

$(OBJDIR):
	mkdir $@

$(BIN):
	mkdir $@

$(BIN)$(EXE): $(OBJ)
	$(CXX) $(CXX_FLAGS) $^ $(MATH_LIBS) -o $@
	@echo "done ;-)"

$(OBJDIR)%.o: %.cpp
	$(CXX) $(CXX_FLAGS) -c $< -o $@

.PHONY: run
run: all
	@$(BIN)$(EXE)

.PHONY: mem-check
mem-check: all
	@valgrind $(BIN)$(EXE)

.PHONY: benchmark
benchmark: all
	@../benchmark.sh $(BIN)$(EXE)

.PHONY: format
format:
	@echo "Formatting the projects source code using clang-format ..."
	clang-format -style=file -i **/*.cpp

.PHONY: clean
clean:
	$(RM) -rf $(BIN)
	$(RM) -rf $(OBJDIR)
	$(RM) -rf $(DOC)
