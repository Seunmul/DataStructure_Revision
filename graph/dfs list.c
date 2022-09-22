#include "adjacency matrix.h"

#define TRUE 1
#define FALSE 0

int visited[MAX_VERTICES];

void dfs_mat(GraphType* g,int v){
    int w;
    visited[v]=TRUE;
    printf("visit %d -> ",v);
    for (w=0;w<g->n;w++)
        if(g->adj_mat[v][w] && !visited[w]){
            printf("%d\n",w);
            dfs_mat(g,w);
        }
}


int main(void){
    GraphType *g;
    g=(GraphType *)malloc(sizeof(GraphType));
    init(g);
    for(int i=0;i<7;i++)
        insert_vertex(g,i); //그래프 정점 생성
    insert_edge(g,0,1);  // 그래프 간선 생성
    insert_edge(g,0,2);
    insert_edge(g,1,3);
    insert_edge(g,1,4);
    insert_edge(g,2,5);
    insert_edge(g,2,6);
    print_adj_mat(g);
    printf("DFS\n");
    dfs_mat(g,0); //함수 수행
    printf("\n");
    free(g);
    return 0;
}