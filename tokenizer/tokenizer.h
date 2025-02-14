#ifndef TOKENIZER
#	define TOKENIZER
#include "../token_factory/token_factory.h"
#include "../token/token.h"
#include "../token_list/token_list.h"
#include "../libc/libft.h"

#include <stdarg.h>

#ifndef END_ARGS
#	define END_ARGS (void*)0
#endif

t_token_list *tokenize(char *str, va_list args);

#endif

