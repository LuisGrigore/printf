#include "assertions.h"
#include "tokenizer.h"
#include "token_list.h"
#include <stdarg.h>


void test_tokenizer(int a,...)
{
	int args_arr[] = {10, 20};
    va_list args;
    va_start(args, args_arr);

	t_token_list *tokens = tokenize("HOLA que %d tal %p", args);
	t_token_node *current = *tokens;
	start_unit_test();
	assert_equal_str(current->token->value, "HOLA que ");
}

int main(int argc, char const *argv[])
{
	test_tokenizer(1);
	return 0;
}
