#include "ft_printf.h"
#include "assertions.h"

#define BUFF_SIZE 200


void test_ft_printf_with_dec()
{
	double d = 20.12030;
	char ft_printf_buff[BUFF_SIZE] = {0};
	char printf_buff[BUFF_SIZE] = {0};
	char *str = "HOLA %d";

	start_unit_test();
	capture_output(ft_printf_buff, BUFF_SIZE, stdout, ft_printf(str, d));
	capture_output(printf_buff, BUFF_SIZE, stdout, printf(str, d));
	assert_equal_str(ft_printf_buff,printf_buff);
}

void test_ft_printf_with_int()
{
	int i = 20;
	char ft_printf_buff[BUFF_SIZE] = {0};
	char printf_buff[BUFF_SIZE] = {0};
	char *str = "HOLA %i";

	start_unit_test();
	capture_output(ft_printf_buff, BUFF_SIZE, stdout, ft_printf(str, i));
	capture_output(printf_buff, BUFF_SIZE, stdout, printf(str, i));
	assert_equal_str(ft_printf_buff,printf_buff);
}

void test_ft_printf_with_unsigned_int()
{
	unsigned int ui = 20;
	char ft_printf_buff[BUFF_SIZE] = {0};
	char printf_buff[BUFF_SIZE] = {0};
	char *str = "HOLA %u";

	start_unit_test();
	capture_output(ft_printf_buff, BUFF_SIZE, stdout, ft_printf(str, ui));
	capture_output(printf_buff, BUFF_SIZE, stdout, printf(str, ui));
	assert_equal_str(ft_printf_buff,printf_buff);
}

void test_ft_printf_with_lowcase_hex()
{
	char ft_printf_buff[BUFF_SIZE] = {0};
	char printf_buff[BUFF_SIZE] = {0};
	char *str = "HOLA %x";

	start_unit_test();
	capture_output(ft_printf_buff, BUFF_SIZE, stdout, ft_printf(str, 10));
	capture_output(printf_buff, BUFF_SIZE, stdout, printf(str, 10));
	assert_equal_str(ft_printf_buff,printf_buff);	
}

void test_ft_printf_with_uppcase_hex()
{
	char ft_printf_buff[BUFF_SIZE] = {0};
	char printf_buff[BUFF_SIZE] = {0};
	char *str = "HOLA %X";

	start_unit_test();
	capture_output(ft_printf_buff, BUFF_SIZE, stdout, ft_printf(str, 10));
	capture_output(printf_buff, BUFF_SIZE, stdout, printf(str, 10));
	assert_equal_str(ft_printf_buff,printf_buff);	
}

void test_ft_printf_with_percentage()
{
	char ft_printf_buff[BUFF_SIZE] = {0};
	char printf_buff[BUFF_SIZE] = {0};

	start_unit_test();
	capture_output(ft_printf_buff, BUFF_SIZE, stdout, ft_printf("HOLA %%"));
	capture_output(printf_buff, BUFF_SIZE, stdout, printf("HOLA %%"));
	assert_equal_str(ft_printf_buff,printf_buff);	
}

void test_ft_printf_with_ptr()
{
	char c = 'c';
	void *ptr = &c;
	char ft_printf_buff[BUFF_SIZE] = {0};
	char printf_buff[BUFF_SIZE] = {0};
	char *str = "HOLA %p";

	start_unit_test();
	capture_output(ft_printf_buff, BUFF_SIZE, stdout, ft_printf(str, ptr));
	capture_output(printf_buff, BUFF_SIZE, stdout, printf(str, ptr));
	assert_equal_str(ft_printf_buff,printf_buff);

}

void test_ft_printf_with_char()
{
	char c = 'c';
	char ft_printf_buff[BUFF_SIZE] = {0};
	char printf_buff[BUFF_SIZE] = {0};
	char *str = "HOLA %c";

	start_unit_test();
	capture_output(ft_printf_buff, BUFF_SIZE, stdout, ft_printf(str, c));
	capture_output(printf_buff, BUFF_SIZE, stdout, printf(str, c));
	assert_equal_str(ft_printf_buff,printf_buff);

}

void test_ft_printf_with_string()
{
	char *s = "que tal";
	char ft_printf_buff[BUFF_SIZE] = {0};
	char printf_buff[BUFF_SIZE] = {0};
	char *str = "HOLA %s";

	start_unit_test();
	capture_output(ft_printf_buff, BUFF_SIZE, stdout, ft_printf(str, s));
	capture_output(printf_buff, BUFF_SIZE, stdout, printf(str, s));
	assert_equal_str(ft_printf_buff,printf_buff);
}



int main(int argc, char const *argv[])
{
	test_ft_printf_with_dec();
	test_ft_printf_with_unsigned_int();
	test_ft_printf_with_int();
	test_ft_printf_with_lowcase_hex();
	test_ft_printf_with_uppcase_hex();
	test_ft_printf_with_percentage();
	test_ft_printf_with_ptr();
	test_ft_printf_with_char();
	test_ft_printf_with_string();
	return 0;
}
