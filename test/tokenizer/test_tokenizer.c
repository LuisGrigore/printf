#include "assertions.h"
#include "tokenizer.h"
#include "token_list.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

void test_tokenizer(void *i, ...)
{
	//Arrange
	char a[] = "HOLA que ";
	char b[] = "%d";

	char str[14] = "";
	strcat(strcat(str, a), b);

    va_list args;
    va_start(args, i);

	//Act
	t_token_list *tokens = tokenize(str, args);
	t_token_node *current = *tokens;

	//Assert
	start_unit_test();
	assert_not_null(tokens);
	int *val = current->token->value;
	assert_equal_num(*val, 10);
	assert_equal_str((char *)current->next->token->value, a);

	va_end(args);
}

int main(int argc, char const *argv[])
{
	int i = 10;
	int j = 10;

	test_tokenizer(&i,&j);
	return 0;
}
