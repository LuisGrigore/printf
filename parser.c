#include "parser.h"
#include <stdarg.h>


void parse(t_token **tokens, void *first, ...)
{
    va_list args;
    va_start(args, END_ARGS);

	int i = 0;
	while (tokens[i] != NULL)
	{
		if(tokens[i]->token_type != TOKEN_STR)
		{
			void* arg = va_arg(args, void*);
	        if (arg == END_ARGS) {
	            break;
	        }
			tokens[i]->funct(arg);
		}
	}
}