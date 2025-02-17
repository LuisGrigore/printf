#include "string_separator.h"
#include "token_mapping.h"
#include "libft.h"
#include <string.h>
#include <stdlib.h>

t_str_list *create_node(char *value) {
    t_str_list *node = (t_str_list *)malloc(sizeof(t_str_list));
    node->value = value;
    node->next = NULL;
    return node;
}

void append_to_list(t_str_list **list, char *value) {
    t_str_list *new_node = create_node(value);
    if (*list == NULL) {
        *list = new_node;
    } else {
        t_str_list *current = *list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

t_str_list *separate_str(char *str) {
    t_str_list *result = NULL;
    char *temp = ft_strdup(str);
    char *token_start = temp;
    int len;
    
    t_str_representation *representations = get_representations();

    while (*token_start != '\0') {
        int found = 0;

        for (int i = 0; i < 9; i++) {
            len = strlen(representations[i].str_representation);
            if (strncmp(token_start, representations[i].str_representation, len) == 0) {
                append_to_list(&result, representations[i].str_representation);
                token_start += len;
                found = 1;
                break;
            }
        }

        if (!found) {
            char *next_token = strchr(token_start, '%');
            if (next_token) {
                len = next_token - token_start;
                char *normal_part = (char *)malloc(len + 1);
                strncpy(normal_part, token_start, len);
                normal_part[len] = '\0';
                append_to_list(&result, normal_part);
                token_start = next_token;
            } else {
                append_to_list(&result, token_start);
                break;
            }
        }
    }

    free(temp);
    return result;
}
void free_list(t_str_list *list) {
    t_str_list *current = list;
    t_str_list *next;
    while (current != NULL) {
        next = current->next;
        free(current->value);
        free(current);
        current = next;
    }
}
