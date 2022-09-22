#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
typedef struct GraphType
{
    int vertex_cnt;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

// 그래프 초기화
void init(GraphType *g)
{
    int r, c;
    g->vertex_cnt = 0;
    for (r = 0; r < MAX_VERTICES; r++)
        for (c = 0; c < MAX_VERTICES; c++)
            g->adj_mat[r][c] = 0;
}

//정점 삽입
void insert_vertex(GraphType *g, int v)
{
    if (((g->vertex_cnt) + 1) > MAX_VERTICES)
    {
        fprintf(stderr, "overflow");
        return;
    }
    g->vertex_cnt++;
}

//간선 삽입
void insert_edge(GraphType *g, int start, int end)
{
    if (start >= g->vertex_cnt || end >= g->vertex_cnt)
    {
        fprintf(stderr, "vertex key error");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

// 인접 행렬 출력 함수
void print_adj_mat(GraphType *g)
{
    printf("vertex counts : %2d\n\n", g->vertex_cnt);
    printf("   ");
    for (int i = 0; i < g->vertex_cnt; i++)
    {
        printf("%2d", i);
    }

    printf("\n    ");
    for (int i = 0; i < g->vertex_cnt; i++)
    {
        printf("--");
    }
    printf("\n");
    for (int i = 0; i < g->vertex_cnt; i++)
    {
        printf("%d |", i);
        for (int j = 0; j < g->vertex_cnt; j++)
        {
            printf("%2d", g->adj_mat[i][j]);
        }
        printf("\n");
    }
}