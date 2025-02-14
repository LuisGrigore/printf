#include "ft_printf.h"

int ft_printf(char const *str, ...)
{
	va_list args;
    va_start(args, END_ARGS);
	t_token_list *list = tokenize((char *)str,args);
	parse(list);
}