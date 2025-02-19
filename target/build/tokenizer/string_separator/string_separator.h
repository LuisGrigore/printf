#ifndef STRING_SEPARATOR
#	define STRING_SEPARATOR


typedef struct t_str_list {
    char *value;
    struct t_str_list *next;
} t_str_list;

t_str_list *separate_str(char *str);
#endif