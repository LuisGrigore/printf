#include "token_util_chars_functs.h"
#include "libft.h"

void print_char(void *c)
{
	if(sizeof(c) == sizeof(char))
	{
		char *c_ptr = (char *) c;
		ft_putchar_fd(*c_ptr,1);
	}
}

void print_str(void *s)
{
	char *s_ptr = (char *) s;
	ft_putstr_fd(s_ptr,1);
}