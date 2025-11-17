# Compiler and flags
CC = gcc
CFLAGS = -Wall
DEBUG_FLAGS = -g -DDEBUG

#dirs
OUTPUT_DIR = outputs
BIN_DIR = bin

# Source and object files
SRC = trie.c
READABLE_OBJ = $(BIN_DIR)/trie.o
OBJ = $(BIN_DIR)/main.o $(BIN_DIR)/parser.o $(BIN_DIR)/util.o
EXEC = $(BIN_DIR)/second_trie
REFERENCE_EXEC = trie_ref

#default target doesnt do anything
default: 
	echo "oops read the makefile!"

# generates the executable and the bin dir. PLEASE PLEASE PLEASE DO NOT DELETE BIN
snow: $(BIN_DIR) $(READABLE_OBJ)
	$(CC) $(OBJ) $(READABLE_OBJ) -o $(EXEC)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Pattern rule for compiling .c files into .o files
$(BIN_DIR)/%.o: %.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Debug target (compiles with debug flags)
doc: CFLAGS += $(DEBUG_FLAGS)
doc: snow

# Checks all outputs for all test cases
dopey: snow
	@for testfile in testcases/*; do \
		echo "Running $$testfile..."; \
		./$(EXEC) -x $$testfile; \
	done

# compare target compares output with trie_ref
grumpy: snow
	@mkdir -p $(OUTPUT_DIR)
	@for testfile in testcases/*; do \
		base_name=$$(basename $$testfile); \
		./$(EXEC) -x $$testfile > $(OUTPUT_DIR)/$$base_name.out; \
		./$(REFERENCE_EXEC) -x $$testfile > $(OUTPUT_DIR)/$$base_name.ref; \
		if diff $(OUTPUT_DIR)/$$base_name.out $(OUTPUT_DIR)/$$base_name.ref > /dev/null; then \
			echo "🌟 PASSED $$testfile"; \
		else \
			echo "🚨 FAILED $$testfile"; \
			echo "Diff:"; \
			diff $(OUTPUT_DIR)/$$base_name.out $(OUTPUT_DIR)/$$base_name.ref; \
		fi; \
	done


# Clean target to remove compiled files DO NOT REMOVE THE SUPPLIED .o FILES
happy:
	rm -f $(EXEC) $(READABLE_OBJ)
