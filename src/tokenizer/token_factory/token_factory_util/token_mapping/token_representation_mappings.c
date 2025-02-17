#include "token_mapping.h"
#include <stdlib.h>

static t_str_representation *get_representations()
{
    static t_str_representation token_representations[] = {
        {TOKEN_CHAR, "%c"},
        {TOKEN_STR, "%s"},
        {TOKEN_PTR, "%p"},
        {TOKEN_FLOATING_POINT_DEC, "%d"},
        {TOKEN_INTEGER, "%i"},
        {TOKEN_UNSIGNED_INTEGER, "%u"},
        {TOKEN_LOWCASE_HEX, "%x"},
        {TOKEN_UPCASE_HEX, "%X"},
        {TOKEN_PERCENTAGE, "%%"}
    };
    return token_representations;
}

/*char *get_representation_from_type(e_token_types type)
{
	int i;

	i = 0;
	while (i < sizeof(get_representations()))
	{
		if(type == get_representations()[i].token_type)
			return (get_representations()[i].str_representation);
	}
	return (NULL);
}*/

e_token_types get_type_from_representation(char *representation)
{
	unsigned long i;
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
		return (TOKEN_STR);
	}
	return (PLAIN_TEXT);
}