#include "tokenizer.h"
#include <stdio.h>

static char *find_next_not_plain_str_token(char *str)
{
	int i;
	char *current_ptr;
	const char *const_str;

	i = 0;
	const_str = (const char*)str;
	while (i < sizeof(e_token_types))
	{
		current_ptr = ft_strnstr(const_str, get_tokens()[i].str_representation, ft_strlen(const_str));
		if (current_ptr)
			return current_ptr;
		i++;
	}
	return NULL;
}

t_token_list *tokenize(char *str, va_list args)
{
	t_token_list *token_list;
	t_token *new_token;
	char *current_ptr;

	token_list = create_token_list();
	if(!token_list)
		return (NULL);
	
	current_ptr = find_next_not_plain_str_token(str);
	while(current_ptr != NULL)
	{
		current_ptr = find_next_not_plain_str_token(str);
		if (current_ptr != NULL)
		{
			if ((current_ptr - str) != 0)
			{
				new_token = token_factory(ft_substr(str, 0, current_ptr - str),ft_substr(str, 0, current_ptr - str));
				add_token_to_list(token_list, new_token);
			}
			void* arg = va_arg(args, void*);
			if (arg == END_ARGS) {
            	break;
        	}
			new_token = token_factory(ft_substr(str, current_ptr - str, 2), arg);
			add_token_to_list(token_list, new_token);
			str = current_ptr + 2;
		}
	}
	if(*str != '\0')
	{
		new_token = token_factory(ft_substr(str, 0, ft_strlen(str)),ft_substr(str, 0, ft_strlen(str)));
		add_token_to_list(token_list, new_token);
	}
	return token_list;
}

