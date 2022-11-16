#include <iostream>
#include <stdio.h>
#include <queue>
#define MAX_SIZE 1001
using namespace std;
void bfs();
void nextDay(int, int, int, int);
int graph[MAX_SIZE][MAX_SIZE];
int n, m;

struct Index
{
    int y, x;
};
queue<Index> Q;

int main()
{
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int tmp;
            scanf("%d", &tmp);
            graph[i][j] = tmp;
            if (tmp == 1)
                Q.push({i, j});
        }
    }
    bfs();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == 0)
            {
                printf("-1\n");
                return 0;
            }
            else if (ans < graph[i][j])
                ans = graph[i][j];
        }
    }
    printf("%d\n", ans - 1);
    return 0;
}

void bfs()
{
    while (!Q.empty())
    {
        Index tmp = Q.front();
        Q.pop();
        int xIndex = tmp.x;
        int yIndex = tmp.y;
        nextDay(xIndex, yIndex, xIndex + 1, yIndex);
        nextDay(xIndex, yIndex, xIndex - 1, yIndex);
        nextDay(xIndex, yIndex, xIndex, yIndex + 1);
        nextDay(xIndex, yIndex, xIndex, yIndex - 1);
    }
}

void nextDay(int x, int y, int nx, int ny)
{
    if (((0 <= ny) && (0 <= nx) && (nx < m) && (ny < n)) && graph[ny][nx] == 0)
    {
        graph[ny][nx] = graph[y][x] + 1;
        Q.push({ny, nx});
    }
}