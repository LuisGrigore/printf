#include "assertions.h"
#include "string_separator.h"
#include <stdio.h>


void test_separate_str()
{
	char str[25] = "";
	char a[] = "HOLA que ";
	char b[] = "%s";
	char c[] = ", ";
	char d[] = "%%";
	char e[] = "%d";
	char f[] = "aaa.";

	strcat(strcat(strcat(strcat(strcat(strcat(str, a), b), c), d), e), f);

	t_str_list *str_list = separate_str(str);

	start_unit_test();
	assert_not_null(str_list);
	assert_equal_str(str_list->value, a);
	assert_equal_str(str_list->next->value, b);
	assert_equal_str(str_list->next->next->value, c);
	assert_equal_str(str_list->next->next->next->value, d);
	assert_equal_str(str_list->next->next->next->next->value, e);
	assert_equal_str(str_list->next->next->next->next->next->value, f);
}

int main(int argc, char const *argv[])
{
	test_separate_str();
	return 0;
}
