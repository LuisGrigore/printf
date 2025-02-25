#include "ft_printf.h"
#include "assertions.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdint.h>

#define BUFF_SIZE 200

pthread_mutex_t buffer_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t buffer_cond = PTHREAD_COND_INITIALIZER;
int buffer_ready = 0; // Indica si el buffer está listo

// Función para capturar la salida de manera segura
void capture_output_safe(char *buffer, size_t size, FILE *output, int *retval, int (*func_call)(void)) {
    pthread_mutex_lock(&buffer_mutex); // Bloquear el mutex
    CAPTURE_OUTPUT(buffer, size, output, *retval, (*func_call)()); // Captura de salida
    buffer_ready = 1; // Indicar que el buffer está listo
    pthread_cond_broadcast(&buffer_cond); // Notificar que el buffer está listo
    pthread_mutex_unlock(&buffer_mutex); // Liberar el mutex
}

// Esperar a que el buffer esté listo
void wait_for_buffer_ready() {
    pthread_mutex_lock(&buffer_mutex);
    while (!buffer_ready) { // Esperar hasta que el buffer esté listo
        pthread_cond_wait(&buffer_cond, &buffer_mutex);
    }
    pthread_mutex_unlock(&buffer_mutex);
}

// Función de prueba para ft_printf con diferentes formatos
void test_ft_printf_with_format(const char *format, void *value) {
    char ft_printf_buff[BUFF_SIZE] = {0};
    char printf_buff[BUFF_SIZE] = {0};
    int ft_printf_len, printf_len;

    start_unit_test();

    // Captura de salida usando punteros a funciones
    capture_output_safe(ft_printf_buff, BUFF_SIZE, stdout, &ft_printf_len, (int (*)(void))ft_printf);
    wait_for_buffer_ready(); // Esperar a que el buffer esté listo
    capture_output_safe(printf_buff, BUFF_SIZE, stdout, &printf_len, (int (*)(void))printf);
    wait_for_buffer_ready(); // Esperar a que el buffer esté listo

    // Comparar las salidas
    assert_equal_str(ft_printf_buff, printf_buff);
    assert_equal_num(ft_printf_len, printf_len);
}

int main(int argc, char const *argv[]) {
    pthread_mutex_init(&buffer_mutex, NULL); // Inicializar el mutex

    // Ejecutar pruebas con diferentes formatos
    test_ft_printf_with_format("HOLA %d", (void*)(intptr_t)20); // Entero decimal
    test_ft_printf_with_format("HOLA %i", (void*)(intptr_t)20); // Entero con %i
    test_ft_printf_with_format("HOLA %u", (void*)(uintptr_t)20); // Entero sin signo
    test_ft_printf_with_format("HOLA %x", (void*)(uintptr_t)10); // Hexadecimal minúscula
    test_ft_printf_with_format("HOLA %X", (void*)(uintptr_t)10); // Hexadecimal mayúscula
    test_ft_printf_with_format("HOLA %%", NULL); // Porcentaje
    test_ft_printf_with_format("HOLA %p", (void*)'c'); // Puntero
    test_ft_printf_with_format("HOLA %c", (void*)'c'); // Carácter
    test_ft_printf_with_format("HOLA %s", (void *)"que tal"); // Cadena

    pthread_cond_destroy(&buffer_cond); // Destruir la condición
    pthread_mutex_destroy(&buffer_mutex); // Destruir el mutex
    return 0;
}
