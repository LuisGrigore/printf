#ifndef TOKEN_MAPPING
#	define TOKEN_MAPPING

#include "token_types.h"

typedef struct t_str_representation
{
	e_token_types token_type;
	char *str_representation;
} t_str_representation;

//t_str_representation *get_representations();
//char *get_representation_from_type(e_token_types type);
e_token_types get_type_from_representation(char *representation);


typedef void (*funct)(void *in);

typedef struct t_token_funct
{
	e_token_types token_type;
	funct funct;
} t_token_funct;

/*t_token_funct *get_functs();*/
funct get_funct_from_type(e_token_types type);
#endif