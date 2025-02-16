#include "token_functs.h"
#include "token_util_functs.h"

t_token_funct *get_functs()
{
    static t_token_funct token_functs[] = {
		{TOKEN_C, &print_char},
		{TOKEN_S, &print_str},
		{TOKEN_P, &print_ptr},
		{TOKEN_D, &print_dec},
		{TOKEN_I, &print_int},
		{TOKEN_U, &print_unsigned_int},
		{TOKEN_X, &print_lowcase_hex},
		{TOKEN_XX, &print_uppercase_hex},
		{TOKEN_PERCENTAGE, &print_percentage},
    };
    return token_functs;
}

funct get_funct(e_token_types type)
{
	int i;

	i = 0;
	while (i < sizeof(get_functs()))
	{
		if(type == get_functs()[i].token_type)
			return (get_functs()[i].funct);
	}
	return (NULL);
}