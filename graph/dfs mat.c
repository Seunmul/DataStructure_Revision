#include "adjacency matrix.h"
#include "../Stack/stack list.h"

#define TRUE 1
#define FALSE 0
#define STACK_SIZE 50

int visited[MAX_VERTICES];
int totalWeight = 0;

void dfs_mat(GraphType *g, int v)
{
    int w;
    visited[v] = TRUE;
    printf("visit %d -> ", v);
    for (w = 0; w < g->vertex_cnt; w++)
    {
        if (g->adj_mat[v][w] && !visited[w])
        {
            printf("%d (%d)\n", w, g->adj_mat[v][w]);
            totalWeight += g->adj_mat[v][w];
            dfs_mat(g, w);
        }
    }
    return;
}

// dfs
void dfs_stack(GraphType *g, int u)
{
    Stack *pStack = CreateStack(STACK_SIZE);
    int count = 0;
    int visited[STACK_SIZE] = {
        FALSE,
    };

    // stack에 처음 vertex 넣기
    Push(pStack, u);

    while (!IsEmptyStack(pStack))
    {
        //당도한 vertex Pop해서 위치에 도달
        u = Pop(pStack);
        //방문하지 않은 vertex라면 코드 진행
        if (visited[u] == FALSE)
        {
            visited[u] = TRUE;
            printf("\n%d -> ", u);
            //그래프의 vertex cnt만큼 도달했다면 반복문 break
            if (++count == g->vertex_cnt)
                break;
            //스택에 넣고 진행.
            for (int v = 0; v < g->vertex_cnt; v++)
            {
                if (!visited[v] && g->adj_mat[u][v] > 0)
                {
                    printf(" %d (%d)", v, g->adj_mat[u][v]);
                    Push(pStack, v);
                }
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
    insert_edge_weights(g, 0, 1, 5);
    insert_edge_weights(g, 0, 2, 3);
    insert_edge_weights(g, 1, 3, 6);
    insert_edge_weights(g, 1, 4, 2);
    insert_edge_weights(g, 2, 5, 4);
    insert_edge_weights(g, 2, 6, 8);
    insert_edge_weights(g, 3, 6, 9);
    insert_edge_weights(g, 4, 6, 3);
    insert_edge_weights(g, 4, 5, 7);

    //그래ㅍ 출력
    print_adj_mat(g);

    printf("\n>> 재귀호출 DFS : \n");
    dfs_mat(g, 0);
    printf("\ntotal weight : %d\n", totalWeight);
    totalWeight = 0;

    // dfs 반복 수행
    for (int temp, i = 0; i < g->vertex_cnt; i++)
    {
        printf("\n>> %d >> Stack DFS : ", i);
        dfs_stack(g, i);
    }

    free(g);

    return 0;
}