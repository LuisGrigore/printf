#!/bin/bash

# Nombre del ejecutable generado por Makefile
EXECUTABLE="bin/main"
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_MAKE_DIR="./build"

# Función para mostrar ayuda
show_help() {
    echo "Uso: ./lcgg -[COMANDO]"
    echo ""
    echo "Comandos disponibles:"
    echo "  -build        Compila el proyecto usando Makefile"
    echo "  -run          Ejecuta el programa compilado"
    echo "  -test         Ejecuta pruebas definidas en Makefile"
    echo "  -clean        Elimina archivos de compilación"
    echo "  -help         Muestra este mensaje de ayuda"
}

# Verifica si se pasó un argumento
if [ $# -eq 0 ]; then
    echo "Error: No se proporcionó ningún comando. Usa -help para más información."
    exit 1
fi

# Procesa el argumento
case "$1" in
    -build)
        echo "🧪 Ejecutando pruebas..."
		cd $BUILD_MAKE_DIR
        make
		make copy_headers
		make copy_libs
		cd $SCRIPT_DIR
        ;;
    -run)
        echo "🚀 Ejecutando el programa..."
        if [ -f "$EXECUTABLE" ]; then
            "$EXECUTABLE"
        else
            echo "Error: El ejecutable '$EXECUTABLE' no existe. Compila primero con -build."
            exit 1
        fi
        ;;
    -test)
        echo "🧪 Ejecutando pruebas..."
		cd $BUILD_MAKE_DIR
        make
		make copy_headers
		make copy_libs
		cd $SCRIPT_DIR
        ;;
    -clean)
        echo "🧹 Limpiando archivos de compilación..."
		cd $BUILD_MAKE_DIR
        make clean
		cd $SCRIPT_DIR
        ;;
    -help)
        show_help
        ;;
    *)
        echo "Error: Comando no reconocido '$1'. Usa -help para ver los comandos disponibles."
        exit 1
        ;;
esac
