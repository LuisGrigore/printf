#include "token_util_functs.h"
#include "puthex_with_charset.h"
#include "file_desc_config.h"
#include "libft.h"

void print_percentage(void *percentage)
{
	ft_putchar_fd(PPERCENTAGE_SYMBOL, STDOUT_FD);
}

void print_ptr(void *p)
{
	ft_putstr_fd(POINTER_SYMBOL, STDOUT_FD);
    puhex_with_charset((unsigned long)p, STDOUT_FD, HEX_LOWCASE_CHARSET);
}