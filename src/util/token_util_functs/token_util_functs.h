#ifndef TOKEN_UTIL_FUNCTS
#	define  TOKEN_UTIL_FUNCTS
#include <stdarg.h>

//Num Functs
int print_dec(va_list args);
int print_int(va_list args);
int print_unsigned_int(va_list args);
//Extra Functs
int print_lowcase_hex(va_list args);
int print_uppercase_hex(va_list args);
int print_percentage(va_list args);
int print_ptr(va_list args);
//Chars Functs
int print_char(va_list args);
int print_str(va_list args);
#endif