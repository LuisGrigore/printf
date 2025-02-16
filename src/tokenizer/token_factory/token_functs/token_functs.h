#ifndef TOKEN_FUNCTS
#	define TOKEN_FUNCTS

#include "token_types.h"
#include <stdlib.h>

typedef void (*funct)(void *in);

typedef struct t_token_funct
{
	e_token_types token_type;
	funct funct;
} t_token_funct;

t_token_funct *get_functs();

funct get_funct_from_type(e_token_types type);

#endif