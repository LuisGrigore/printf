#include "assertions.h"
#include "functs.h"

void test_print_functions(int i, ...) {
    char output[100];
    int retval;

    // Probar print_char_args
    start_unit_test();
    va_list args1;
    va_start(args1, 1); // Inicia la lista de argumentos (no se puede usar directamente)
    // Asignamos el valor esperado de un char
    int char_arg = 'A'; 
    // Aún no se puede pasar así, se debe manejar con una función que reciba la lista
    capture_output(output, sizeof(output), stdout, retval, (print_char_args(args1)));
    va_end(args1); // Finaliza la lista de argumentos
    assert_equal_num(1, retval);
    assert_equal_str("A", output);

    // Probar print_str_args
    start_unit_test();
    va_list args2;
    va_start(args2, 1);
    char *str_arg = "Hello, world!";
    capture_output(output, sizeof(output), stdout, retval, (print_str_args(args2)));
    va_end(args2);
    assert_equal_num(13, retval);
    assert_equal_str("Hello, world!", output);
}

int main() {
    test_print_functions(1);
    return 0;
}
