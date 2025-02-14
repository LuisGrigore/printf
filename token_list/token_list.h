#ifndef TOKEN_LIST
#	define TOKEN_LIST
#include "../token/token.h"

typedef struct t_token_node {
    t_token *token;
    struct t_token_node* next;
} t_token_node;

typedef t_token_node* t_token_list;

t_token_list *create_token_list();
void add_token_to_list(t_token_list* list, t_token *token);
t_token* consume(t_token_list* list);
void destruct_token_list(t_token_list* list);
void destruct_token_node(t_token_node *node);
#endif