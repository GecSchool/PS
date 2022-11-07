#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX_INDEX 51
using namespace std;
int t, m, n, k; // m -> columns , n -> rows , k -> 배추 수
int visited[MAX_INDEX][MAX_INDEX];
int graph[MAX_INDEX][MAX_INDEX];
void DFS(int, int);
int main()
{
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        memset(graph, 0, sizeof(graph));
        memset(visited, 0, sizeof(visited));
        scanf("%d %d %d", &m, &n, &k);
        for (int j = 0; j < k; j++)
        {
            int tmpY, tmpX;
            scanf("%d %d", &tmpX, &tmpY);
            graph[tmpY][tmpX] = 1;
        }
        int ans = 0;
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < m; x++)
            {
                if (graph[y][x] && !visited[y][x])
                {
                    ans++;
                    visited[y][x] = 1;
                    DFS(y, x);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void DFS(int y, int x)
{
    for (int i = 0; i < 4; i++)
    {
        int tmpY = y + dy[i];
        int tmpX = x + dx[i];
        if ((0 <= tmpX && 0 <= tmpY && tmpX < m && tmpY < n) && graph[tmpY][tmpX] && !visited[tmpY][tmpX])
        {
            visited[tmpY][tmpX] = 1;
            DFS(tmpY, tmpX);
        }
    }
}