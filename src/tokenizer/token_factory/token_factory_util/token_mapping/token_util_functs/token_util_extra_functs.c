#include "token_util_functs.h"
#include "puthex_with_charset.h"
#include "libft.h"

void print_percentage(void *percentage)
{
	ft_putchar_fd('%',1);
}

void print_ptr(void *p)
{
	ft_putstr_fd("0x",1);
    puhex_with_charset((unsigned long)p, 1, HEX_LOWCASE_CHARSET);
}