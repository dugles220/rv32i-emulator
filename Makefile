CC = gcc
TARGET = $(notdir $(patsubst %/,%,$(CURDIR)))
FLAGS = -Wall -Wextra -Werror -g -Iinclude
SRC_DIR = src
OBJ_DIR = obj
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) $(FLAGS)
	@echo "Программа скомпилирована в файл $(TARGET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) -c $< -o $@ $(FLAGS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	rm -f $(TARGET)
	@echo Директория очищена от объектных файлов.