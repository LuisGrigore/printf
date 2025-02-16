#ifndef TOKEN
#	define TOKEN

typedef struct t_token
{
	void *value;
	void (*funct)(void *in);
} t_token;

t_token	*create_token(void *value, void (*funct)(void *in));
void	destruct_token(t_token *token);

#endif