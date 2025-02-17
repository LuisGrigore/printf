#include "token_util_functs.h"
#include "file_desc_config.h"
#include "libft.h"

void print_char(void *c)
{
	if(sizeof(c) == sizeof(char))
	{
		char *c_ptr = (char *) c;
		ft_putchar_fd(*c_ptr,STDOUT_FD);
	}
}

void print_str(void *s)
{
	char *s_ptr = (char *) s;
	ft_putstr_fd(s_ptr,STDOUT_FD);
}