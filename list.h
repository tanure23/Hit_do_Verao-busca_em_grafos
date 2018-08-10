#ifndef LIST_H
#define LIST_H

#include "graph.h"

typedef struct node{
	int id;
	struct node *next;
} node;

typedef struct list{
	int size;
	node *head;
	node *tail;
} list;


void print_list(list *l);
int is_empty(list *l);
void add_to_list(list *l, int id);
list create_list();
void free_list(list *l);


#endif /*LIST_H*/