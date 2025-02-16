#include "token_factory.h"
#include "token_representation.h"
#include "token_functs.h"
#include <stdlib.h>

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
	e_token_types type;

	if(!value)
	{
		if(is_print_str(str_representation))
			return (create_token(str_representation, get_funct_from_type(TOKEN_S)));
		return (NULL);
	}
	type = get_type_from_representation(str_representation);
	return (create_token(value, get_funct_from_type(type)));
}