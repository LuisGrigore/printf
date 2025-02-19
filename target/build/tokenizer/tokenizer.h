#ifndef TOKENIZER
#	define TOKENIZER

#include "token_list.h"
#include <stdarg.h>

#ifndef END_ARGS
#	define END_ARGS (void*)0
#endif
#ifndef ESCAPE_CHAR
#	define ESCAPE_CHAR '%'
#endif

t_token_list *tokenize(char *str, va_list args);

#endif

