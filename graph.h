#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "list.h"

//below are macros to print colored text in bash
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define RESET "\x1B[0m" 
//////////////////////////////////////////////////

typedef struct graph{
	int n_vertices;
	list *adj;
} graph;


graph create_graph(int n_vertices);

void add_edge(graph gr, int src, int dest);

int dfs(graph gr, int first, int *visited, int *ages);

void free_graph(graph gr, int n_vertices);

#endif /*GRAPH_H*/