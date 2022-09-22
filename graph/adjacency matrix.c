#include "adjacency matrix.h"

#define MAX_VERTICES 50

void init(GraphType *g);
void insert_vertex(GraphType* g,int v) ;
void insert_edge(GraphType* g,int start,int end);
void print_adj_mat(GraphType* g);

int main(){
    GraphType *g;
    g=(GraphType *)malloc(sizeof(GraphType));
    init(g);
    for (size_t i = 0; i < 4; i++){
        insert_vertex(g,i);
    }
    insert_edge(g,0,1);
    insert_edge_weights(g,0,2,9);
    insert_edge_weights(g,1,2,5);
    insert_edge_weights(g,2,1,3);
    insert_indegree_edge_weights(g,1,2,7);
    print_adj_mat(g);
     
    free(g);
    return 0;
}
