#include "ft_printf.h"
#include <stdarg.h>
#include "parser.h"
#include "tokenizer.h"

int ft_printf(char const *str, void *a, ...)
{
	va_list args;
    va_start(args, END_ARGS);
	t_token_list *list = tokenize((char *)str,args);
	parse(list);
	return (1);
}