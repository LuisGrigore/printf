#include "token_mapping.h"
#include <stdlib.h>
#include "libft.h"

/*static*/ t_str_representation *get_representations()
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

static int is_print_str(char *str)
{
	while(*str)
	{
		if(!ft_isprint(*str))
			return(0);
		str++;
	}
	return (1);
}

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
	if(is_print_str(representation))
	{
		return (TOKEN_STR);
	}
	return (PLAIN_TEXT);
}
