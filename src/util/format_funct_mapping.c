#include "format_funct_mapping.h"
#include "token_util_functs.h"
#include "libft.h"

t_format_funct *get_format_functs()
{
    static t_format_funct token_functs[] = {
        {"%c", print_char},
        {"%s", print_str},
        {"%p", print_ptr},
        {"%d", print_dec},
        {"%i", print_int},
        {"%u", print_unsigned_int},
        {"%x", print_lowcase_hex},
        {"%X", print_uppercase_hex},
        {"%%", print_percentage},
        {NULL, NULL} // Cambié el último elemento a NULL
    };
    return token_functs;
}

t_funct get_funct_from_format(const char *format)
{
    int i = 0;
    t_format_funct *functs = get_format_functs();
    
    while (functs[i].format != NULL) {
        if (ft_strncmp(functs[i].format, format, ft_strlen(functs[i].format)) == 0) {
            return functs[i].funct;
        }
        i++;
    }
    return NULL;
}
