#include "token.h"
#include <stdlib.h>

t_token *get_tokens()
{
	static t_token tokens[] = {
		{TOKEN_C,"%c", NULL, &print_char},
		{TOKEN_S,"%s", NULL, &print_str},
		{TOKEN_P,"%p", NULL, &print_ptr},
		{TOKEN_D,"%d", NULL, &print_dec},
		{TOKEN_I,"%i", NULL, &print_int},
		{TOKEN_U,"%u", NULL, &print_unsigned_int},
		{TOKEN_X,"%x", NULL, &print_lowcase_hex},
		{TOKEN_XX,"%X", NULL, &print_uppercase_hex},
		{TOKEN_PERCENTAGE, "%%", NULL, &print_percentage},
		{TOKEN_STR, NULL, NULL, &print_str},
	};
	return tokens;
}

t_token get_str_token()
{
	static t_token token;
	token.funct = &print_str;
	token.str_representation = NULL;
	token.token_type = TOKEN_STR;
	token.value = NULL;
	return token;
}

t_token *create_token(e_token_types type, char *str_representation, void *value, void (*funct)(void *in))
{
	t_token *new_token;

	new_token = malloc(sizeof(t_token));
	if(!new_token)
		return (NULL);
	
	new_token->token_type = type;
	new_token->str_representation = str_representation;
	new_token->value = value;
	new_token->funct = funct;
}

void	destruct_token(t_token *token)
{
	if(!token)
		return ;
	free(token->str_representation);
	free(token->value);
	free(token);
}