#include "token_factory.h"
#include <stdlib.h>
#include <stdio.h>

static int is_print_str(char * str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(ft_isprint((int) str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

t_token *token_factory(char *str_representation, void *value)
{
	int i;

	i = 0;
	while(i < sizeof(e_token_types))
	{
		if(ft_strncmp(get_tokens()[i].str_representation, str_representation,2) == 0)
		{
			return (create_token(get_tokens()[i].token_type, get_tokens()[i].str_representation, value, get_tokens()[i].funct));
		}
		i++;

	}
	if(is_print_str(str_representation))
	{
		return (create_token(get_str_token().token_type, get_str_token().str_representation, str_representation, get_str_token().funct));
	}
	return (NULL);
}

