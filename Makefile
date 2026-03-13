CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
LDFLAGS =

TARGET = minushell
SRC_DIR = src
OBJ_DIR = obj

SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/parser.c \
       $(SRC_DIR)/executor.c \
       $(SRC_DIR)/builtin.c

OBJS = $(OBJ_DIR)/main.o \
       $(OBJ_DIR)/parser.o \
       $(OBJ_DIR)/executor.o \
       $(OBJ_DIR)/builtin.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET)
