#include <iostream>
#include <stdio.h>
#include <queue>
#define MAX_SIZE 101
using namespace std;
void bfs();
void nextDay(int, int, int, int, int, int);
int graph[MAX_SIZE][MAX_SIZE][MAX_SIZE];
int n, m, h;

struct Index
{
    int y, x, z;
};
queue<Index> Q;

int main()
{
    scanf("%d %d %d", &m, &n, &h);
    for (int s = 0; s < h; s++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                int tmp;
                scanf("%d", &tmp);
                graph[i][j][s] = tmp;
                if (tmp == 1)
                    Q.push({i, j, s});
            }
        }
    }
    bfs();
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int s = 0; s < h; s++)
                if (graph[i][j][s] == 0)
                {
                    printf("-1\n");
                    return 0;
                }
                else if (ans < graph[i][j][s])
                    ans = graph[i][j][s];
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
        int zIndex = tmp.z;
        nextDay(xIndex, yIndex, zIndex, xIndex + 1, yIndex, zIndex);
        nextDay(xIndex, yIndex, zIndex, xIndex - 1, yIndex, zIndex);
        nextDay(xIndex, yIndex, zIndex, xIndex, yIndex + 1, zIndex);
        nextDay(xIndex, yIndex, zIndex, xIndex, yIndex - 1, zIndex);
        nextDay(xIndex, yIndex, zIndex, xIndex, yIndex, zIndex + 1);
        nextDay(xIndex, yIndex, zIndex, xIndex, yIndex, zIndex - 1);
    }
}

void nextDay(int x, int y, int z, int nx, int ny, int nz)
{
    if (((0 <= ny) && (0 <= nx) && (0 <= nz) && (nx < m) && (ny < n) && (nz < h)) && graph[ny][nx][nz] == 0)
    {
        graph[ny][nx][nz] = graph[y][x][z] + 1;
        Q.push({ny, nx, nz});
    }
}