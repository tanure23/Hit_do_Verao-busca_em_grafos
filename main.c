#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "graph.h"
#include "list.h"

//////////////////////////////////////////////////////////////
////////////////// TP0 - Summer's Hit ////////////////////////
//////////////////////////////////////////////////////////////

int main()
{
	int n_people, aux=0;
	int m_relations;
	int *ages;
	int *visited;
	int src, dest; //id_1 is related to id_2
	int first_id; //first one to listen to the song
	int i=0, index=0, tmp=0;
	int n_liked=0;
	graph gr;

	if(!scanf("%d", &n_people)) return -1;
	if(!scanf("%d", &m_relations)) return -1;

	aux = n_people; //for further use (see line 37)

	//setting our graph and two auxiliar arrays...
	//... that store each person's age and who we have visited
	gr = create_graph(n_people);
	ages = (int*)malloc(n_people*sizeof(int)+1);
	//below we use calloc: as nobody has been visited yet...
	//... each position starts as 0
	visited = (int*)calloc(n_people, sizeof(int));

	//////////////////////////////////////////////////////////////////////
	/////////////////////////// Creating Graph ///////////////////////////
	//////////////////////////////////////////////////////////////////////


	while(aux){ //read ages while theres someone to relate them to
		if(!scanf("%d %d", &index, &tmp)) return -1;
		ages[index-1] = tmp;
		aux--;
	}

	for(i=0; i<m_relations; i++){
		//src and dest are int that represent from and to whom an edge
		//is being created, respectively
		if(!scanf("%d %d", &src, &dest)){
			return -1;
		}
		//now we subtract one from each int because of the way our program
		//is indexed
		src--;
		dest--;
		add_edge(gr, src, dest);
	}

	
	//below is a code to print each vertex's adjacency list...
	//...it's commented because our problem does not necessarily...
	//...needs it printed
	
	/*for(i=0; i<n_people; i++){
		printf(CYN "Adj list of %d: " RESET, i);
		print_list(&(gr.adj[i]));
		printf("\n");
	}*/

	//////////////////////////////////////////////////////////////////////
	//////////////////////////// Operations //////////////////////////////
	//////////////////////////////////////////////////////////////////////
	if(!scanf("%d", &first_id)) return -1;
	first_id--; //again, because indexation
	if(ages[first_id] >= 35){
		n_liked = 0; //if the first one doesnt like the song,...	
		//...there is no sharing, thus no one else listens to it
	} 
	else if(is_empty(&(gr.adj[first_id]))){
		n_liked = 1; //theres no one else to share the song to...
		//...since "first"'s adacency list contains no one
	} 
	else{
		//we start searching for those who like the music
		//note that our dfs returns an integer
		n_liked = dfs(gr, first_id, visited, ages);
	}

	//printf(GRN "%d people liked this summer's hit\n" RESET, n_liked);
	printf("%d\n", n_liked);

	//now we deallocate used memory
	free_graph(gr, n_people);
	free(visited);
	free(ages);


	return 0;
}


























