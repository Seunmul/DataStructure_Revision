#include "adjacency list.h"
void init(GraphType* g);
void insert_vertex(GraphType* g,int v);
void insert_edge(GraphType* g,int u,int v);
void print_adj_list(GraphType* g);

int main()
{
    GraphType *g;
    g=(GraphType*)malloc(sizeof(GraphType));
    init(g);
    for(int i=0;i<4;i++)
        insert_vertex(g,i);
    // insert_edge(g,0,1);
    // insert_edge(g,1,0);
    // insert_edge(g,0,2);
    // insert_edge(g,2,0);
    // insert_edge(g,0,3);
    // insert_edge(g,3,0);
    // insert_edge(g,1,2);
    // insert_edge(g,2,1);
    // insert_edge(g,2,3);
    // insert_edge(g,3,2);
    print_adj_list(g);

    free(g);

    return 0;


}