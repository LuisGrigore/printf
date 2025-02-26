#include "print_functs.h"
#include "assertions.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>
#include <stdint.h>
#include <limits.h>

#define BUFF_SIZE 200

pthread_mutex_t buffer_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t buffer_cond = PTHREAD_COND_INITIALIZER;
int buffer_ready = 0;

// Función para capturar la salida de una función y su valor de retorno de forma segura
void capture_output_safe(char *buffer, size_t size, FILE *output, int *retval, int (*func)(void *), void *arg) {
    pthread_mutex_lock(&buffer_mutex);
    capture_output(buffer, size, output, *retval, func(arg));  
    buffer_ready = 1;
    pthread_cond_broadcast(&buffer_cond);
    pthread_mutex_unlock(&buffer_mutex);
}

// Esperar hasta que el buffer esté listo
void wait_for_buffer_ready() {
    pthread_mutex_lock(&buffer_mutex);
    while (!buffer_ready) {
        pthread_cond_wait(&buffer_cond, &buffer_mutex);
    }
    pthread_mutex_unlock(&buffer_mutex);
}

// Función para probar la salida de una función y su valor de retorno
void test_function_output(const char *test_name, int (*func)(void *), void *arg, const char *expected_output, int expected_return) {
    char buffer[BUFF_SIZE] = {0};
    int retval = -1;

    start_unit_test();
    capture_output_safe(buffer, BUFF_SIZE, stdout, &retval, func, arg);
    wait_for_buffer_ready();

    // Comparar salida y número de caracteres devueltos
    assert_equal_str(buffer, expected_output);
    assert_equal_num(retval, expected_return);

    // Mostrar resultados en formato legible
    printf("       Expected Output: \"%s\" | Actual Output: \"%s\"\n", expected_output, buffer);
    printf("       Expected Return: %d | Actual Return: %d\n", expected_return, retval);

    usleep(500000);  // Pausa de 0.5 segundos
}

// Wrappers para adaptar funciones sin cambiar su firma
int wrapper_print_char(void *arg) {
    return print_char((char)(intptr_t)arg);
}

int wrapper_print_str(void *arg) {
    return print_str((char *)arg);
}

int wrapper_print_hex(void *arg) {
    return print_hex((unsigned long)(uintptr_t)arg, "0123456789abcdef");
}

int wrapper_print_nbr(void *arg) {
    return print_nbr((long)(intptr_t)arg);
}

int main() {
    pthread_mutex_init(&buffer_mutex, NULL);

    // Pruebas para print_char
    test_function_output("test_print_char_A", wrapper_print_char, (void *)(intptr_t)'A', "A", 1);
    test_function_output("test_print_char_newline", wrapper_print_char, (void *)(intptr_t)'\n', "\n", 1);

    // Pruebas para print_str
    test_function_output("test_print_str_hello", wrapper_print_str, "hello", "hello", 5);
    test_function_output("test_print_str_empty", wrapper_print_str, "", "", 0);
    test_function_output("test_print_str_null", wrapper_print_str, NULL, "", 0);

    // Pruebas para print_hex
    test_function_output("test_print_hex_0", wrapper_print_hex, (void *)(uintptr_t)0, "0", 1);
    test_function_output("test_print_hex_255", wrapper_print_hex, (void *)(uintptr_t)255, "ff", 2);
    test_function_output("test_print_hex_large", wrapper_print_hex, (void *)(uintptr_t)3735928559UL, "deadbeef", 8);

    // Pruebas para print_nbr
    test_function_output("test_print_nbr_0", wrapper_print_nbr, (void *)(intptr_t)0, "0", 1);
    test_function_output("test_print_nbr_42", wrapper_print_nbr, (void *)(intptr_t)42, "42", 2);
    test_function_output("test_print_nbr_neg42", wrapper_print_nbr, (void *)(intptr_t)-42, "-42", 3);
    test_function_output("test_print_nbr_int_min", wrapper_print_nbr, (void *)(intptr_t)INT_MIN, "-2147483648", 11);
    test_function_output("test_print_nbr_int_max", wrapper_print_nbr, (void *)(intptr_t)INT_MAX, "2147483647", 10);

    pthread_cond_destroy(&buffer_cond);
    pthread_mutex_destroy(&buffer_mutex);

    return 0;
}
