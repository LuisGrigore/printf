# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directorio de Unity
UNITY_DIR = ../Unity-master/src
UNITY_SRC = $(UNITY_DIR)/unity.c

# Directorio donde están los archivos fuente
SOURCE_DIR = ./

# Subcarpeta a excluir (opcional, puedes dejarla vacía)
EXCLUDED_SUBDIR = ./src/excluded_folder

# Busca todos los archivos fuente en SOURCE_DIR, excluyendo EXCLUDED_SUBDIR y test_*.c
SRC = $(shell find $(SOURCE_DIR) -type f -name "*.c" ! -path "$(EXCLUDED_SUBDIR)/*" ! -name "test_*.c")
OBJ = $(patsubst %.c, %.o, $(SRC))

# Busca todos los archivos "test_*.c"
TESTS = $(shell find . -type f -name "test_*.c")
EXECUTABLES = $(patsubst %.c, %, $(TESTS))

# Regla principal: compila y ejecuta los tests
all: $(EXECUTABLES) run_tests

# Regla para compilar cada test con Unity y todos los archivos fuente
%: %.c $(OBJ) $(UNITY_SRC)
	$(CC) $(CFLAGS) $< $(OBJ) $(UNITY_SRC) -o $@

# Regla para compilar archivos .c a .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Ejecuta todos los tests
run_tests: $(EXECUTABLES)
	@echo "Running tests..."
	@for test in $(EXECUTABLES); do \
		echo "Executing $$test..."; \
		./$$test || exit 1; \
	done
	@echo "All tests passed!"

# Limpieza
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXECUTABLES)

re: fclean all
