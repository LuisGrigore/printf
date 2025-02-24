#include "format_funct_mapping.h"
#include "format_factory.h"


int format_factory(char *str, va_list args)
{
	t_funct funct = get_funct_from_format(str);
	if(!funct)
		return(0);
	return (funct(args));
}