#include "ft_printf.h"
#include "assertions.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // Para usleep
#include <sys/wait.h>
#include <stdint.h>

#define BUFF_SIZE 200

pthread_mutex_t buffer_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t buffer_cond = PTHREAD_COND_INITIALIZER;
int buffer_ready = 0;

void capture_output_safe(char *buffer, size_t size, FILE *output, int *retval, int (*func_call)(const char *, ...), const char *format, void *value) {
    pthread_mutex_lock(&buffer_mutex);
    capture_output(buffer, size, output, *retval, func_call(format, value));
    buffer_ready = 1;
    pthread_cond_broadcast(&buffer_cond);
    pthread_mutex_unlock(&buffer_mutex);
}

void wait_for_buffer_ready() {
    pthread_mutex_lock(&buffer_mutex);
    while (!buffer_ready) {
        pthread_cond_wait(&buffer_cond, &buffer_mutex);
    }
    pthread_mutex_unlock(&buffer_mutex);
}

// Función para verificar si las salidas de ft_printf y printf son iguales
void test_ft_printf_output(const char *format, void *value) {
    char ft_printf_buff[BUFF_SIZE] = {0};
    char printf_buff[BUFF_SIZE] = {0};
    int ft_printf_len, printf_len;

    start_unit_test();

    capture_output_safe(ft_printf_buff, BUFF_SIZE, stdout, &ft_printf_len, ft_printf, format, value);
    wait_for_buffer_ready();
    capture_output_safe(printf_buff, BUFF_SIZE, stdout, &printf_len, printf, format, value);
    wait_for_buffer_ready();

    assert_equal_str(ft_printf_buff, printf_buff);
    printf("test_ft_printf_output: OK\n");
    printf("  printf:    \"%s\"\n", printf_buff);
    printf("  ft_printf: \"%s\"\n", ft_printf_buff);

    usleep(500000);  // Pausa de 0.5 segundos
}

// Función para verificar si los valores devueltos por ft_printf y printf son iguales
void test_ft_printf_return(const char *format, void *value) {
    int ft_printf_len, printf_len;
    char ft_printf_buff[BUFF_SIZE] = {0};
    char printf_buff[BUFF_SIZE] = {0};

    start_unit_test();

    capture_output_safe(ft_printf_buff, BUFF_SIZE, stdout, &ft_printf_len, ft_printf, format, value);
    wait_for_buffer_ready();
    capture_output_safe(printf_buff, BUFF_SIZE, stdout, &printf_len, printf, format, value);
    wait_for_buffer_ready();

    assert_equal_num(ft_printf_len, printf_len);
    printf("test_ft_printf_return: OK\n");
    printf("  printf return:    %d\n", printf_len);
    printf("  ft_printf return: %d\n", ft_printf_len);

    usleep(500000);  // Pausa de 0.5 segundos
}

int main(int argc, char const *argv[]) {
    pthread_mutex_init(&buffer_mutex, NULL);

    // Pruebas de salida y retorno con pausa entre cada una
    test_ft_printf_output("HOLA %d\n", (void*)(intptr_t)20);
    test_ft_printf_return("HOLA %d\n", (void*)(intptr_t)20);

    test_ft_printf_output("HOLA %i\n", (void*)(intptr_t)20);
    test_ft_printf_return("HOLA %i\n", (void*)(intptr_t)20);

    test_ft_printf_output("HOLA %u\n", (void*)(uintptr_t)20);
    test_ft_printf_return("HOLA %u\n", (void*)(uintptr_t)20);

    test_ft_printf_output("HOLA %x\n", (void*)(uintptr_t)10);
    test_ft_printf_return("HOLA %x\n", (void*)(uintptr_t)10);

    test_ft_printf_output("HOLA %X\n", (void*)(uintptr_t)10);
    test_ft_printf_return("HOLA %X\n", (void*)(uintptr_t)10);

    test_ft_printf_output("HOLA %%\n", NULL);
    test_ft_printf_return("HOLA %%\n", NULL);

    test_ft_printf_output("HOLA %p\n", (void*)'c');
    test_ft_printf_return("HOLA %p\n", (void*)'c');

    test_ft_printf_output("HOLA %c\n", (void*)'c');
    test_ft_printf_return("HOLA %c\n", (void*)'c');

    test_ft_printf_output("HOLA %s\n", (void *)"que tal");
    test_ft_printf_return("HOLA %s\n", (void *)"que tal");

    pthread_cond_destroy(&buffer_cond);
    pthread_mutex_destroy(&buffer_mutex);

    return 0;
}
