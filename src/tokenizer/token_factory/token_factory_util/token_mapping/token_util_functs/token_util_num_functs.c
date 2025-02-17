#include "token_util_functs.h"
#include "puthex_with_charset.h"
#include "precisions_config.h"
#include "file_desc_config.h"
#include <stdio.h>
#include "libft.h"

void print_dec(void *d)
{
	double *num =  (double*) d;

	if (*num < 0) {
        ft_putchar_fd(NEGATIVE_SYMBOL, STDOUT_FD);
        *num = -*num;
    }

    int integer = (int)*num;
    double decimal = *num - integer;

    ft_putnbr_fd(integer, STDOUT_FD);
    ft_putchar_fd(FLOATING_POINT_SYMBOL, STDOUT_FD);

    for (int i = 0; i < DOUBLE_PRECISION; i++) {
        decimal *= 10;
    }

    ft_putnbr_fd((int)(decimal + 0.5),STDOUT_FD);
}
void print_int(void *integer_ptr)
{
	ft_putnbr_fd(*(int *)integer_ptr, STDOUT_FD);
}

void print_unsigned_int(void *unsigned_integer_ptr)
{
	unsigned int unsigned_integer = (unsigned int) unsigned_integer_ptr;
	char	buffer[12];
	int		i;

	i = 11;
	buffer[i] = '\0';
	while (unsigned_integer > 0)
	{
		buffer[--i] = (unsigned_integer % 10) + '0';
		unsigned_integer /= 10;
	}
	write(STDOUT_FD, &buffer[i], 11 - i);
}


void print_lowcase_hex(void *x)
{
	unsigned long *hex = (unsigned long) x;
	puhex_with_charset(*hex, STDOUT_FD, HEX_LOWCASE_CHARSET);
}

void print_uppercase_hex(void *xx)
{
	unsigned long *hex = (unsigned long) xx;
	puhex_with_charset(*hex, STDOUT_FD, HEX_UPPCASE_CHARSET);
}