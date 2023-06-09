# Variáveis
CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -Iinclude
LDFLAGS := -lsfml-graphics -lsfml-window -lsfml-system

SRC_DIR := src
OBJ_DIR := build
BIN_DIR := bin

# Arquivos fonte (.cpp) em todas as subpastas da pasta src
SRCS := $(shell find $(SRC_DIR) -type f -name '*.cpp')

# Objetos (.o) correspondentes aos arquivos fonte
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Nome do executável
EXECUTABLE := $(BIN_DIR)/touhou

# Regra principal: construir o executável
all: $(EXECUTABLE)

# Regra para construir o executável
$(EXECUTABLE): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Regra para compilar os objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpar arquivos gerados
clean:
	rm -rf $(OBJ_DIR)/* $(EXECUTABLE)

# Criar diretórios necessários
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

# Ignorar regras padrão do makefile para os arquivos .cpp e .hpp
%.cpp:

.PHONY: all clean
