#Variables Estándar
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

#Directorios
SRC_DIR = src
OBJ_DIR = build
BIN_DIR = .
INCLUDE_DIR = include
DATA_DIR = data

#Nombre del ejecutable
TARGET = SistemaAcademica

#Archivos fuente y de objeto
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

.PHONY: all clean run setup

all: setup $(BIN_DIR)/$(TARGET)

$(BIN_DIR)/$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir $(OBJ_DIR) 2>NUL || ECHO. > NUL
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I$(INCLUDE_DIR)

setup:
	@mkdir $(OBJ_DIR) 2>NUL || ECHO. > NUL
	@mkdir $(DATA_DIR) 2>NUL || ECHO. > NUL

run: $(BIN_DIR)/$(TARGET)
	./$(BIN_DIR)/$(TARGET)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)/$(TARGET) $(DATA_DIR)/*.txt $(DATA_DIR)/*.bin
	@echo "Limpieza completada."