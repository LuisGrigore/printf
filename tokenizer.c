#include "tokenizer.h"
#include "libft.h"





t_token **get_tokens_for_str(t_token *tokens, char *str, va_list args)
{
	t_token **result = malloc(sizeof(e_token_types) + 1);
	if(!result)
		return (NULL);
	result[sizeof(e_token_types)] = NULL;
}

t_token **tokenize(char *str, void *first, ...)
{
	va_list args;
    va_start(args, END_ARGS);



	return get_tokens_for_str(tokens, str, args);
}

