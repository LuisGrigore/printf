#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include "functs.h"
#include <stdarg.h>
#include "print_functs.h"
#include "symbols_config.h"


int main(int argc, char const *argv[])
{
	print_hex(0, HEX_LOWCASE_CHARSET);
	return 0;
}
