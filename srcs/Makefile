# Generic Makefile for compiling sources with cc

# Compiler and flags
CC = cc
CFLAGS = -g3 -Werror -Wextra -Wall -I$(INC_DIR) -DREADLINE

# Directories
SRC_DIRS = parse expand builtins/env utils
OBJ_DIR = ./obj
INC_DIR = ../inc
LIB_DIR = ../libft

# Source files (add your source files here)
SRCS = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))

# Object files (automatically generated from source files)
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRCS)))

# Target binary
TARGET = my_program

LIBS = -lft -lreadline
LIB_DIRS = -L$(LIB_DIR)

# Targets
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB_DIRS) $(LIBS) -o $@

$(OBJ_DIR)/%.o: $(SRCS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(filter %/$*.c,$(SRCS)) -o $@

clean:
	@rm -rf $(OBJ_DIR) $(TARGET)

re:	clean all

lib:
	@$(MAKE) -C $(LIB_DIR)

.PHONY: all clean re lib
