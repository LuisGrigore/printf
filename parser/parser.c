#include "parser.h"

void parse(t_token_list *tokens)
{
	t_token *consumed_token;
	t_token_list *to_destroy;

	to_destroy = create_token_list();
	consumed_token = consume(tokens);
	int i = 0;
	while (consumed_token != NULL)
	{
		consumed_token->funct(consumed_token->value);
		add_token_to_list(to_destroy,consumed_token);
		consumed_token = consume(tokens);
	}

	destruct_token_list(to_destroy);
	destruct_token_list(tokens);
}