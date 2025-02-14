#ifndef FT_PRINTF
#	define FT_PRINTF
#include <stdarg.h>
#include "./parser/parser.h"
#include "./tokenizer/tokenizer.h"

#ifndef END_ARGS
#	define END_ARGS (void*)0
#endif

int ft_printf(char const *, ...);
#endif