#include "token_representation.h"
#include <stdlib.h>

t_str_representation *get_representations()
{
    static t_str_representation token_representations[] = {
        {TOKEN_C, "%c"},
        {TOKEN_S, "%s"},
        {TOKEN_P, "%p"},
        {TOKEN_D, "%d"},
        {TOKEN_I, "%i"},
        {TOKEN_U, "%u"},
        {TOKEN_X, "%x"},
        {TOKEN_XX, "%X"},
        {TOKEN_PERCENTAGE, "%%"}
    };
    return token_representations;
}

char *get_representation_from_type(e_token_types type)
{
	int i;

	i = 0;
	while (i < sizeof(get_representations()))
	{
		if(type == get_representations()[i].token_type)
			return (get_representations()[i].str_representation);
	}
	return (NULL);
}

e_token_types get_type_from_representation(char *representation)
{
	int i;
	char *current_representation;

	i = 0;
	while (i < sizeof(e_token_types))
	{
		current_representation = get_representations()[i].str_representation;
		if(ft_strncmp(current_representation, representation, ft_strlen(current_representation)) == 0)
			return (get_representations()[i].token_type);
	}
	if(ft_isprint_str(representation))
	{
		return (TOKEN_S);
	}
	return (NULL);
}