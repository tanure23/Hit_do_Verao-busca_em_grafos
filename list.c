#include "graph.h"
#include "list.h"

void add_to_list(list *l, int id){
	//first we allocate another node dinamically
	node *aux = malloc(sizeof(node));
	aux->id = id; //set its id with the one we receive above
	aux->next = NULL;
	if(!is_empty(l)){
		l->tail->next = aux;
		l->tail = aux;
	}
	else{
		//if the list is empty, the newly created node...
		//...is the first one, so we set it properly
		l->head = aux;
		l-> tail = aux;
	}
}

int is_empty(list *l){
	if(l->head == NULL && l->tail==NULL){
		//there is no node yet
		return 1;
	}
	return 0;
}

void print_list(list *l){
	node *current = l->head;
	if(!is_empty(l)){ //if list is empty, we print nothing
		while(current != NULL){
			//traverse list and print each of its nodes
			printf("%d -> ", current->id);
			current = current->next;
		}
		printf("the end\n");
	}
}

list create_list(){
	list l;
	//set NULL below because each list starts empty
	l.head = NULL;
	l.tail = NULL;
	return l;
}


void free_list(list *l){
	node *current = l->head;
	node *temp; //necessary tool to keep control of where we are
	while(current != NULL){
		//this frees each node one by one until list is empty
		temp = current;
		current = current->next;
		free (temp); //free node assigned to temp
	}
	l->head = NULL; //signals an empty list
}