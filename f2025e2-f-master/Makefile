# Compiler and flags
CC = gcc
CFLAGS = -Wall
DEBUG_FLAGS = -g -DDEBUG

#dirs
OUTPUT_DIR = outputs
BIN_DIR = bin

WRAP_SYMBOLS = malloc calloc free
WRAP_FLAGS = $(foreach s,$(WRAP_SYMBOLS),-Wl,--wrap=$(s))

# Source and object files
SRC = stringbuilder.c
READABLE_OBJ = $(BIN_DIR)/stringbuilder.o
OBJ = $(BIN_DIR)/main.o $(BIN_DIR)/parser.o $(BIN_DIR)/wrappers.o
EXEC = $(BIN_DIR)/sb
REFERENCE_EXEC = ref_sb

#default target doesnt do anything
.PHONY: schlotzkeys
schlotzkeys:
	echo "oops read the makefile!"

subway: $(BIN_DIR) $(READABLE_OBJ)
	$(CC) $(OBJ) $(READABLE_OBJ) $(WRAP_FLAGS) -o $(EXEC)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_DIR)/%.o: %.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

potbelly: CFLAGS += $(DEBUG_FLAGS)
potbelly: subway

mikes: subway
	@for testfile in testcases/*; do \
		echo "Running $$testfile..."; \
		./$(EXEC) -i $$testfile; \
	done

cheba: subway
	@mkdir -p $(OUTPUT_DIR)
	@for testfile in testcases/*; do \
		base_name=$$(basename $$testfile); \
		./$(EXEC) -i $$testfile > $(OUTPUT_DIR)/$$base_name.out; \
		./$(REFERENCE_EXEC) -i $$testfile > $(OUTPUT_DIR)/$$base_name.ref; \
		out_tmp=$$(mktemp); \
		ref_tmp=$$(mktemp); \
		tr -d '\n' < $(OUTPUT_DIR)/$$base_name.out > $$out_tmp; \
		tr -d '\n' < $(OUTPUT_DIR)/$$base_name.ref > $$ref_tmp; \
		if diff $$out_tmp $$ref_tmp > /dev/null; then \
			echo "✅ PASSED $$testfile"; \
		else \
			echo "❌ FAILED $$testfile"; \
			echo "Diff (ignoring newlines):"; \
			diff $$out_tmp $$ref_tmp; \
		fi; \
		rm -f $$out_tmp $$ref_tmp; \
	done


snarfs:
	rm -f $(EXEC) $(READABLE_OBJ)

.PHONY: sammy
sammy: $(BIN_DIR)
	$(CC) $(CFLAGS) -Wall -Wextra -Wpedantic -Werror -O3 -c main.c -o $(BIN_DIR)/main.o
	$(CC) $(CFLAGS) -Wall -Wextra -Wpedantic -Werror -O3 -c parser.c -o $(BIN_DIR)/parser.o
	$(CC) $(CFLAGS) -Wall -Wextra -Wpedantic -Werror -O3 -c wrappers.c -o $(BIN_DIR)/wrappers.o

