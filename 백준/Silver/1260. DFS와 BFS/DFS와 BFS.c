#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int *visited;
int **graph;
int *queue;
int n, m, v;
void dfs(int);
void bfs(int);
int main()
{
    scanf("%d %d %d", &n, &m, &v); // 정점 개수(배열 개수), 간선 개수(반복문 수), 시작할 정점의 번호 dfs(v),bfs(v)
    visited = malloc(sizeof(int) * (n + 1));
    queue = malloc(sizeof(int) * (n + 1));
    graph = malloc(sizeof(int *) * (n + 1));
    for (int i = 0; i <= n; i++)
    {
        graph[i] = malloc(sizeof(int) * (n + 1));
    }
    for (int i = 0; i < m; i++)
    {
        int tmp1, tmp2;
        scanf("%d %d", &tmp1, &tmp2);
        graph[tmp1][tmp2] = 1;
        graph[tmp2][tmp1] = 1;
    }
    // insert value in graph
    dfs(v);
    for (int i = 0; i <= n; i++)
    {
        visited[i] = 0;
    }
    bfs(v);
    return 0;
}
void dfs(int v)
{

    visited[v] = 1;
    printf("%d ", v);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i] && graph[v][i])
            dfs(i);
    }
    return;
}
void bfs(int v)
{
    int front = 0, rear = 0;
    visited[v] = 1;
    printf("\n%d ", v);
    queue[rear++] = v;
    while (front < rear)
    {
        int tmp = queue[front++];
        for (int i = 0; i <= n; i++)
        {
            if (!visited[i] && graph[tmp][i])
            {
                printf("%d ", i);
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}