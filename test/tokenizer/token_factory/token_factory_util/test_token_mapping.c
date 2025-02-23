#include "assertions.h"
#include "token_mapping.h"
#include "token_types.h"

void test_get_representations()
{
	t_str_representation *str_rep = get_representations();
	start_unit_test();
	assert_not_null(str_rep);
}

void test_get_type_from_representation()
{
	e_token_types token_type = get_type_from_representation("%d");
	
	start_unit_test();
	assert_not_null(&token_type);
	assert_equal(token_type, TOKEN_FLOATING_POINT_DEC);
}

void test_get_funct_from_type()
{
	e_token_types token_type = TOKEN_FLOATING_POINT_DEC;

	funct actual_funct = get_funct_from_type(token_type);
	funct expected_funct;
	int i = 0;
	while (i < sizeof(get_functs()))
	{
		if(get_functs()[i].token_type == token_type)
		{
			expected_funct = get_functs()[i].funct;
			break;
		}
		i++;
	}
	
	start_unit_test();
	assert_not_null(actual_funct);
	assert_equal(actual_funct, expected_funct);
}

int main(int argc, char const *argv[])
{
	test_get_representations();
	test_get_type_from_representation();
	test_get_funct_from_type();
	return 0;
}
