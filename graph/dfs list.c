#include "adjacency matrix.h"
#include "../Stack/stack list.h"

#define TRUE 1
#define FALSE 0
#define STACK_SIZE 50

int visited[MAX_VERTICES];

void dfs_mat(GraphType *g, int v)
{
    int w;
    visited[v] = TRUE;
    printf("visit %d -> ", v);
    for (w = 0; w < g->vertex_cnt; w++)
    {
        if (g->adj_mat[v][w] && !visited[w])
        {
            printf("%d\n", w);
            dfs_mat(g, w);
        }
    }
}

void dfs_stack(GraphType *g, int v)
{
    Stack *pStack = CreateStack(STACK_SIZE);
    int temp = 0;
    int visited[STACK_SIZE] = {
        FALSE,
    };

    Push(pStack, v);
    visited[v] = TRUE;
    while (!IsEmptyStack(pStack))
    {
        temp = Pop(pStack);
        printf("\n%d -> ", temp);
        for (int w = g->vertex_cnt - 1; w >= 0; w--)
        {
            if (!visited[w] && g->adj_mat[temp][w] > 0)
            {
                printf("%d ", w);
                Push(pStack, w);
                visited[w] = TRUE;
            }
        }
    }
    DestroyStack(pStack);
    printf("\n");
    return;
}

int main(void)
{
    Stack *pStack = CreateStack(STACK_SIZE);
    GraphType *g;

    //그래프 정점 생성
    g = (GraphType *)malloc(sizeof(GraphType));
    init(g);
    for (int i = 0; i < 7; i++)
        insert_vertex(g, i);

    // 그래프 간선 생성
    insert_edge(g, 0, 1);
    insert_edge(g, 0, 2);
    insert_edge(g, 1, 3);
    insert_edge(g, 1, 4);
    insert_edge(g, 2, 5);
    insert_edge(g, 2, 6);

    //그래ㅍ 출력
    print_adj_mat(g);

    // dfs 수행
    printf("\n>> 재귀호출 DFS\n");
    dfs_mat(g, 1);

    printf("\n\n>> Stack DFS : ");
    dfs_stack(g, 1);

    free(g);

    return 0;
}