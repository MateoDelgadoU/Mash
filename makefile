# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC_DIR = src
OBJ_DIR = build
TARGET = mash

# Encuentra todos los archivos .c en src/
SRCS = $(wildcard $(SRC_DIR)/*.c)
# Define los archivos .o correspondientes en build/
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Regla principal
all: $(TARGET)

# Vinculación del ejecutable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Compilación de objetos individuales
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Crear carpeta build si no existe
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Limpieza
clean:
	rm -rf $(OBJ_DIR) $(TARGET)