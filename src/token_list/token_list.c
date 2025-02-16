#include <stdlib.h>
#include "token_list.h"

t_token_list *create_token_list()
{
	t_token_list *new_token_list;
	
	new_token_list = malloc(sizeof(t_token_list));
	if(!new_token_list)
		return (NULL);
	return new_token_list;
}

void add_token_to_list(t_token_list* list, t_token *token) {
    t_token_node* nuevoNodo = (t_token_node*)malloc(sizeof(t_token_node));
    if (nuevoNodo == NULL)
        return ;
    nuevoNodo->token = token;
    nuevoNodo->next = *list;
    *list = nuevoNodo;
}

t_token* consume(t_token_list* list) {
    if (!list || *list == NULL) {
        return NULL;
    }
    
    t_token_node *current = *list;
    t_token_node *prev = NULL;
    
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
        if (prev == NULL) {
        *list = NULL;
    } else {
        prev->next = NULL;
    }
    
    t_token *token = current->token;
    destruct_token_node(current);
    return token;
}

void destruct_token_list(t_token_list* list) {
    t_token_node* current;
    t_token_node* next;
    
	if(!list || *list == NULL)
		return ;
	current = *list;
    while (current != NULL) {
        next = current->next;
		destruct_token_node(current);
        current = next;
    }
    *list = NULL;
}

void destruct_token_node(t_token_node *node)
{
	if(!node)
		return ;
    free(node);
}