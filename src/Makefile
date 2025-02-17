# Directorios principales
SRC_DIR := .
EXTERNALS_DIR := ../externals
BUILD_DIR := ../target/build

# Buscar archivos fuente y cabecera dentro de src
SRC_FILES := $(shell find $(SRC_DIR) -type f -name "*.c")
HDR_DIRS  := $(sort $(dir $(shell find $(SRC_DIR) -type f -name "*.h")))

# Buscar archivos de cabecera y bibliotecas en externals
EXT_HDR_DIRS  := $(sort $(dir $(shell find $(EXTERNALS_DIR) -type f -name "*.h")))
EXT_LIB_FILES := $(shell find $(EXTERNALS_DIR) -type f -name "*.a")

# Generar las rutas de destino en `build/`
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))
LIB_FILES := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.a, $(SRC_FILES))

# Lista de directorios a replicar en `build/`
DIRS := $(sort $(dir $(OBJ_FILES)))

# Flags de compilación e inclusión de headers (-I)
INCLUDE_FLAGS := $(addprefix -I, $(HDR_DIRS) $(EXT_HDR_DIRS))

# Flags de enlace con librerías (-L y -l)
LIB_DIRS := $(sort $(dir $(EXT_LIB_FILES)))
LDFLAGS := $(addprefix -L, $(LIB_DIRS)) $(patsubst $(EXTERNALS_DIR)/lib%.a, -l%, $(EXT_LIB_FILES))

# Configuración del compilador
CC := gcc
CFLAGS := -Wall -Wextra -pedantic -std=c11 $(INCLUDE_FLAGS)

.PHONY: all clean copy_headers copy_libs

# Regla principal
all: $(DIRS) $(LIB_FILES)

# Crear la estructura de directorios en `build/`
$(DIRS):
	mkdir -p $@

# Compilar cada archivo .c a un objeto .o y luego a una librería estática .a
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.a: $(BUILD_DIR)/%.o
	ar rcs $@ $<

# Copiar archivos .h a la misma estructura en `build/`
copy_headers:
	@for file in $(shell find $(SRC_DIR) -type f -name "*.h"); do \
		dest_dir=$(BUILD_DIR)/$$(dirname $${file#$(SRC_DIR)/}); \
		mkdir -p $$dest_dir; \
		cp $$file $$dest_dir; \
	done

# Copiar librerías externas .a a build/
copy_libs:
	@for file in $(EXT_LIB_FILES); do \
		dest_dir=$(BUILD_DIR)/$$(dirname $${file#$(EXTERNALS_DIR)/}); \
		mkdir -p $$dest_dir; \
		cp $$file $$dest_dir; \
	done

# Limpiar la carpeta de build
clean:
	rm -rf $(BUILD_DIR)
