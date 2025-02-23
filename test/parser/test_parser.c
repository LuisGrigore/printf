#include "parser.h"
#include "assertions.h"
#include "token.h"
#include "token_list.h"
#include "token_mapping.h"
#include "token_types.h"

#define BUFF_SIZE 200

void test_parse()
{
	t_token_list *tokens = create_token_list();
	add_token_to_list(tokens,create_token((void *)"aa",get_funct_from_type(TOKEN_STR)));
	int i = 1;
	add_token_to_list(tokens,create_token((void *)&i,get_funct_from_type(TOKEN_INTEGER)));

	char buff[200] = {0};
	start_unit_test();
	capture_output(buff, BUFF_SIZE, stdout, parse(tokens));
	assert_equal_str(buff, "aa1");
}

int main(int argc, char const *argv[])
{
	test_parse();
	return 0;
}
