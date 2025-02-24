#include "format_funct_mapping.h"
#include "assertions.h"
#include "token_util_functs.h"
#include <stdio.h>

void test_get_funct_from_fromat()
{
	double val = 2;
	char *format = "%d";
	t_funct expected = print_dec;


	int i = 0;
    t_format_funct *functs = get_format_functs();
	
	start_unit_test();

    while (functs[i].format != NULL) {
		t_funct actual = get_funct_from_format(format);

		assert_not_null(actual);
		assert_equal(actual, expected);

        i++;
    }
}

int main(int argc, char const *argv[])
{
	test_get_funct_from_fromat();
	return 0;
}
