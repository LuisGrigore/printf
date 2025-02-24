#ifndef FORMAT_FUNCT_MAPPING
#	define FORMAT_FUNCT_MAPPING

#include <stdarg.h>

typedef int (*t_funct)(va_list);

typedef struct t_format_funct
{
	char *format;
	t_funct funct;
}t_format_funct;

t_funct get_funct_from_format(const char *format);
t_format_funct *get_format_functs();
#endif