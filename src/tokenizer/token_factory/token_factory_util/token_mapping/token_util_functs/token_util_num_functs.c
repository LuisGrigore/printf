#include "token_util_functs.h"
#include "puthex_with_charset.h"
#include <stdio.h>
#include "libft.h"

void print_dec(void *d)
{
	double *num =  (double*) d;

	if (*num < 0) {
        escribir_caracter('-');
        *num = -*num;
    }

    int parte_entera = (int)*num;
    double parte_decimal = *num - parte_entera;

    escribir_numero_entero(parte_entera);
    escribir_caracter('.');

    for (int i = 0; i < DOUBLE_PRECISION; i++) {
        parte_decimal *= 10;
    }

    escribir_numero_entero((int)(parte_decimal + 0.5));
}
void print_int(void *i)
{
	ft_putnbr_fd(*(int *)i, 1);
}
void print_unsigned_int(void *i)
{
	unsigned int ui = (unsigned int) i;
	ft_putui_fd(ui,1);
}
static void	ft_putui_fd(unsigned int n, int fd)
{
	char	buffer[12];
	int		i;

	i = 11;
	buffer[i] = '\0';
	while (n > 0)
	{
		buffer[--i] = (n % 10) + '0';
		n /= 10;
	}
	write(fd, &buffer[i], 11 - i);
}

void print_lowcase_hex(void *x)
{
	unsigned long *hex = (unsigned long) x;
	puhex_with_charset(*hex, 1, HEX_LOWCASE_CHARSET);
}
void print_uppercase_hex(void *xx)
{
	unsigned long *hex = (unsigned long) xx;
	puhex_with_charset(*hex, 1, HEX_UPPCASE_CHARSET);
}