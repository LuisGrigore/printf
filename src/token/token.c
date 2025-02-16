#include "token.h"
#include <stdlib.h>


t_token *create_token(void *value, void (*funct)(void *in))
{
	t_token *new_token;

	new_token = malloc(sizeof(t_token));
	if(!new_token)
		return (NULL);
	
	new_token->value = value;
	new_token->funct = funct;
	return new_token;
}

void	destruct_token(t_token *token)
{
	if(!token)
		return ;
	free(token->value);
	free(token);
}