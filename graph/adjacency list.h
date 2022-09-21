#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct GraphNode{
    int vertex;
    struct GraphNode* link;
} GraphNode;

typedef struct GraphType{
    int n;
    GraphNode* adj_list[MAX_VERTICES];
} GraphType;

void init(GraphType* g){
    int v;
    g->n=0;
    for(v=0;v<MAX_VERTICES;v++)
        g->adj_list[v]=NULL;
}

void insert_vertex(GraphType* g,int v){
    if(((g->n)+1)>MAX_VERTICES){
        fprintf(stderr,"overflow");
        return;
    }
    g->n++;
}

void insert_edge(GraphType* g,int u,int v){
    GraphNode* node;
    if(u>=g->n||v>=g->n){
        fprintf(stderr,"vertex index error");
        return;
    }
    node= (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex=v;
    node->link=g->adj_list[u];
    g->adj_list[u]=node;
}

void print_adj_list(GraphType* g){
    for(int i=0;i<g->n;i++){
        GraphNode* p=g->adj_list[i];
        printf("정점 %d의 인접 리스트",i);
        while(p!=NULL){
            printf("->%d",p->vertex);
            p=p->link;
        }
        printf("\n");
    }
}