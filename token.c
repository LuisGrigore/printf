#include "token.h"
#include <stdlib.h>

t_token *get_tokens()
{
	static t_token tokens[] = {
		{TOKEN_C,"%c", NULL, &print_char},
		{TOKEN_S,"%s", NULL, &print_str},
		{TOKEN_P,"%p", NULL, &print_ptr},
		{TOKEN_D,"%d", NULL, &print_dec},
		{TOKEN_I,"%i", NULL, &print_int},
		{TOKEN_U,"%u", NULL, &print_unsigned_int},
		{TOKEN_X,"%x", NULL, &print_lowcase_hex},
		{TOKEN_XX,"%X", NULL, &print_uppercase_hex},
		{TOKEN_PERCENTAGE, "%%", NULL, &print_percentage},
		{TOKEN_STR, NULL, NULL, &print_str},
	};
	return tokens;
}

static void print_percentage(void *percentage)
{
	ft_putchar_fd('%',1);
}

static void print_char(void *c)
{
	if(sizeof(c) == sizeof(char))
	{
		char *c_ptr = (char *) c;
		ft_putchar_fd(*c_ptr,1);
	}
}

static void print_str(void *s)
{
	char *s_ptr = (char *) s;
	ft_putstr_fd(*s_ptr,1);
}

static void print_ptr(void *p)
{
	//TODO
}

static void print_dec(void *d)
{
	//TODO
}
static void print_int(void *i)
{
	//TODO
}
static void print_unsigned_int(void *i)
{
	//TODO
}
static void print_lowcase_hex(void *x)
{
	//TODO
}
static void print_uppercase_hex(void *xx)
{
	//TODO
}