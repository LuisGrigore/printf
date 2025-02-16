#include "token_representation.h"
#include "token_functs.h"
#include "token_util_functs.h"

#define TOKEN_NUMBER 9

static const t_str_representation TOKEN_REPRESENTATIONS[TOKEN_NUMBER] = {
	{TOKEN_CHAR, "%c"},
	{TOKEN_STR, "%s"},
	{TOKEN_PTR, "%p"},
	{TOKEN_FLOATING_POINT_DEC, "%d"},
	{TOKEN_INTEGER, "%i"},
	{TOKEN_UNSIGNED_INTEGER, "%u"},
	{TOKEN_LOWCASE_HEX, "%x"},
	{TOKEN_UPCASE_HEX, "%X"},
	{TOKEN_PERCENTAGE, "%%"}
};

static t_token_funct token_functs[TOKEN_NUMBER] = {
	{TOKEN_CHAR, &print_char},
	{TOKEN_STR, &print_str},
	{TOKEN_PTR, &print_ptr},
	{TOKEN_FLOATING_POINT_DEC, &print_dec},
	{TOKEN_INTEGER, &print_int},
	{TOKEN_UNSIGNED_INTEGER, &print_unsigned_int},
	{TOKEN_LOWCASE_HEX, &print_lowcase_hex},
	{TOKEN_UPCASE_HEX, &print_uppercase_hex},
	{TOKEN_PERCENTAGE, &print_percentage},
};