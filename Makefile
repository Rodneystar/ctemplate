SRC_DIR := src
OBJ_DIR := obj
TST_DIR := test
BIN_DIR := bin
TST_BIN_DIR := $(TST_DIR)/bin
EXE := $(BIN_DIR)/pts
TST_EXE := $(TST_BIN_DIR)/test

SRC := $(wildcard $(SRC_DIR)/*.c)
TST := $(wildcard $(TST_DIR)/*.cpp)

# make manual 6.3.1 - substitution references
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_NOMAIN = $(filter-out $(OBJ_DIR)/main%, $(OBJ))

CPPFLAGS := -g -Iinclude
CXXFLAGS := -include CppUTest/MemoryLeakDetectorNewMacros.h
CFLAGS := -Wall  -include CppUTest/MemoryLeakDetectorMallocMacros.h
LDFLAGS := 
LDLIBS := 
TST_LDLIBS := -lCppUTest -lCppUTestExt

.PHONY: all clean list
all: $(EXE) $(TST_EXE)
	./$(TST_EXE)

$(EXE): $(OBJ) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

list:
	echo $(OBJ)
	echo $(OBJ_NOMAIN)

$(TST_EXE): $(OBJ_NOMAIN) $(TST) | $(TST_BIN_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ $(TST_LDLIBS) -o $(TST_EXE)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_DIR) $(BIN_DIR) $(TST_BIN_DIR):
	mkdir -p $@

clean:
	rm -r $(OBJ_DIR) $(BIN_DIR) $(TST_DIR)/bin