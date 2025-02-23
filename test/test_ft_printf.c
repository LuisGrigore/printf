#include "ft_printf.h"
#include "assertions.h"

#define BUFF_SIZE 200

void test_ft_printf()
{
	int i = 1;
	char ft_printf_buff[BUFF_SIZE] = {0};
	char printf_buff[BUFF_SIZE] = {0};
	char *str = "HOLA %d";

	start_unit_test();
	capture_output(ft_printf_buff, BUFF_SIZE, stdout, ft_printf(str, &i));
	capture_output(printf_buff, BUFF_SIZE, stdout, printf(str, &i));
	assert_equal_str(ft_printf_buff,printf_buff);
}

int main(int argc, char const *argv[])
{
	test_ft_printf();
	return 0;
}
