#include "token_factory.h"
#include <stdlib.h>

static t_token *get_not_plain_str_token(char *str_representation, void *value)
{
	t_token *result;
	int i;

	result = malloc(sizeof(t_token));
	if(!result)
		return (NULL);
	i = 0;
	while(i < sizeof(e_token_types))
	{
		if(ft_strncmp(get_tokens()[i].str_representation, str_representation,2) == 0)
		{
			result->funct = get_tokens()[i].funct;
			result->str_representation = get_tokens()[i].str_representation;
			result->token_type = get_tokens()[i].token_type;
			result->value = value;
			return result;
		}
		i++;
	}
	return (NULL);
}

static t_token *get_plain_str_token(char *str_representation, void *value)
{
	t_token *result;

	result = malloc(sizeof(t_token));
	if(!result)
		return (NULL);
	if(ft_isprint(str_representation))
	{
		result->funct = &print_str;
		result->str_representation = NULL;
		result->token_type = TOKEN_STR;
		result->value = str_representation;
		return result;
	}
	return (NULL);
}

t_token *token_factory(char *str_representation, void *value)
{
	t_token *result;
	
	result = get_not_plain_str_token(str_representation, value);

	if(result)
		return result;
	return (get_plain_str_token(str_representation, value));
}