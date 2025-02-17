#include "token_util_functs.h"
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
	//TODO
}
void print_lowcase_hex(void *x)
{
	//TODO
}
void print_uppercase_hex(void *xx)
{
	//TODO
}