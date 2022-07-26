CC := gcc
CFLAGS := -std=gnu99 -lraylib -O2 -g -Iinclude

OUT_DIR := bin

all: clean celda
.PHONY: all

# TODO: maybe generate it as a .C file and link the other files
# in include/ ??
celda: src/celda.c
	mkdir -p $(OUT_DIR)
	$(CC) $^ $(CFLAGS) -o $(OUT_DIR)/legend-of-$@

clean:
	@rm -rf bin