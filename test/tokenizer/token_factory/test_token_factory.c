#include "assertions.h"
#include "token_factory.h"
#include "token.h"
#include "token_mapping.h"

void test_token_factory()
{
	double value = 1.2;
	char str_representation[] = "%d";
	e_token_types token_type = TOKEN_FLOATING_POINT_DEC;
	funct expected_funct;

	int i = 0;
	while(i < sizeof(get_functs()))
	{
		if(get_functs()[i].token_type == token_type)
		{
			expected_funct = get_functs()[i].funct;
			break;
		}
		i++;
	}

	t_token *token = token_factory(str_representation,(void *)&value);

	start_unit_test();
	assert_not_null(token);
	assert_equal(*((double*)token->value), value);
	assert_equal(token->funct, expected_funct);
}

int main(int argc, char const *argv[])
{
	test_token_factory();
	return 0;
}
