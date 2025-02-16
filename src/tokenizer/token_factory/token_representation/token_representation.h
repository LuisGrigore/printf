#ifndef TOKEN_REPRESENTATION
#	define TOKEN_REPRESENTATION

#include "token_types.h"

typedef struct t_str_representation
{
	e_token_types token_type;
	char *str_representation;
} t_str_representation;

t_str_representation *get_representations();
char *get_representation_from_type(e_token_types type);
e_token_types get_type_from_representation(char *representation);
#endif