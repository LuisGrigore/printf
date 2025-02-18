#include "tokenizer.h"
#include "string_separator.h"
#include "token_mapping.h"
#include "token_factory.h"

t_token_list *tokenize(char *str, va_list args)
{
	void *arg;
    t_token_list *token_list;
	t_str_list *str_list;
    t_token *new_token;

	token_list = create_token_list();
    /*if (!token_list)
        return (NULL);*/
	
	str_list = separate_str(str);
	while(str_list)
	{
		if(get_type_from_representation(str_list->value) == PLAIN_TEXT)
		{
			arg = va_arg(args, void*);
			if (arg == END_ARGS)
				break;
			new_token = token_factory(str_list->value, arg);
		}
		else
			new_token = token_factory(str_list->value, NULL);
		add_token_to_list(token_list,new_token);
		str_list = str_list->next;
	}
    return (token_list);
}