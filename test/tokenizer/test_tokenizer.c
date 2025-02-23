#include "assertions.h"
#include "tokenizer.h"
#include "token_list.h"
#include <stdarg.h>
#include <string.h>

void test_tokenizer(int i, ...)
{
	char str[14] = "";
	char a[] = "HOLA que ";
	char b[] = "%d";
	char c[] = "%p";

	strcat(strcat(strcat(str, a), b), c);

	int args_arr[] = {10, 20};
    va_list args;
    va_start(args, args_arr);

	t_token_list *tokens = tokenize(str, args);
	t_token_node *current = *tokens;
	start_unit_test();
	assert_not_null(tokens);
	assert_equal_str((char *)current->token->value, c);
	assert_equal_str((char *)current->next->token->value, b);
	assert_equal_str((char *)current->next->next->token->value, a);
}

int main(int argc, char const *argv[])
{
	test_tokenizer(1);
	return 0;
}
