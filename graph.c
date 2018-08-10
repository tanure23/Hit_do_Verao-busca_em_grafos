#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "list.h"

graph  create_graph(int n_vertices){
	list *adj = malloc(n_vertices*sizeof(list));
	int i;
	graph gr;
	for(i=0; i<n_vertices; i++){
		//creating each vertex's own adjacency list
		adj[i] = create_list();
	}
	gr.n_vertices = n_vertices;
	gr.adj = adj;
	return gr;
}

void add_edge(graph gr, int src, int dest){
	//we add edges both ways since the graph is
	//...undirected
	add_to_list(&(gr.adj[src]), dest);
	add_to_list(&(gr.adj[dest]), src);

}

int dfs(graph gr, int first, int *visited, int *ages){
	static int n_liked = 0;
	visited[first] = 1; //we start by visiting "first"

	if(ages[first] < 35){ //verify it can like the music
		//add one to the number of people who like the music
		n_liked++;
	}

	//below is an important line. If the first one to listen...
	//..to the music doesn't like it, no one else listens to it...
	//... then nobody else can like it
	else return n_liked;

	//now we start visiting it's neighbours...
	//...by visiting each vertex's adjacency list
	node *current = gr.adj[first].head;
	while(current != NULL){
		if(visited[current->id] == 0 && (ages[current->id] < 35)){
			dfs(gr, current->id, visited, ages);
		}
		current = current->next;
	}
	return n_liked;
}

void free_graph(graph gr, int n_vertices){
	int i;
	for(i=0; i<n_vertices; i++){
		//free every vertex's adjacency list
		free_list(&(gr.adj[i]));
	}
	//free remaining array
	free(gr.adj);
}