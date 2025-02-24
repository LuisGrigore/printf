#include "assertions.h"
#include "tokenizer.h"
#include "token_list.h"
#include <stdarg.h>
#include <string.h>

void test_tokenizer(int num_args, ...) {
	//Arrange
	char a[] = "HOLA que ";
	char b[] = "%d";
	char c[] = "%s";

	char str[14] = "";
	strcat(strcat(strcat(str, a), b),c);

    va_list args;
    va_start(args, num_args);
    
    void *first_arg = va_arg(args, void *);
    
    int valor = *(int *)first_arg;
    
    printf("El valor del primer argumento es: %d\n", valor);

	//Act
	t_token_list *tokens = tokenize(str, args);
	t_token_node *current = *tokens;
    
   //Assert
	start_unit_test();
	assert_not_null(tokens);
	printf("%s", va_arg(args, char *));
	/*assert_equal_str((char *)current->token->value, c);
	/*assert_equal_num(*((int *)current->next->token->value), 10);
	assert_equal_str((char *)current->next->next->token->value, a);*/

	va_end(args);
}

int main() {
    int valor = 42;
	char *a = " que tal";
    test_tokenizer(2, &valor, a); // Ejemplo de llamada con 3 argumentos
    return 0;
}
