#ifndef TOKEN
#	define TOKEN
#include "../token_util/token_util_functs.h"

typedef enum
{
	TOKEN_C,
	TOKEN_S,
	TOKEN_P,
	TOKEN_D,
	TOKEN_I,
	TOKEN_U,
	TOKEN_X,
	TOKEN_XX,
	TOKEN_PERCENTAGE,
	TOKEN_STR
} e_token_types;

typedef struct t_token
{
	e_token_types token_type;
	char *str_representation;
	void *value;
	void (*funct)(void *in);
	
} t_token;

t_token	*get_tokens();
t_token	get_str_token();
t_token	*create_token(e_token_types type, char *str_representation, void *value, void (*funct)(void *in));
void	destruct_token(t_token *token);

#endif