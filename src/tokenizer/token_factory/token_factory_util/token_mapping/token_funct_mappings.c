#include "token_mapping.h"
#include "token_util_functs.h"
#include <stdlib.h>

static t_token_funct *get_functs()
{
    static t_token_funct token_functs[] = {
		{TOKEN_CHAR, &print_char},
		{TOKEN_STR, &print_str},
		{TOKEN_PTR, &print_ptr},
		{TOKEN_FLOATING_POINT_DEC, &print_dec},
		{TOKEN_INTEGER, &print_int},
		{TOKEN_UNSIGNED_INTEGER, &print_unsigned_int},
		{TOKEN_LOWCASE_HEX, &print_lowcase_hex},
		{TOKEN_UPCASE_HEX, &print_uppercase_hex},
		{TOKEN_PERCENTAGE, &print_percentage},
    };
    return token_functs;
}

funct get_funct(e_token_types type)
{
	unsigned long i;

	i = 0;
	while (i < sizeof(get_functs()))
	{
		if(type == get_functs()[i].token_type)
			return (get_functs()[i].funct);
	}
	return (NULL);
}