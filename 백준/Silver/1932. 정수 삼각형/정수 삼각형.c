#include <stdio.h>
#define MAX_INDEX 500
int n;
int graph[MAX_INDEX][MAX_INDEX];
void DP(int);
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    for (int i = n - 1; i > 0; i--)
    {
        DP(i);
    }
    printf("%d\n", graph[0][0]);
    return 0;
}

void DP(int value)
{
    for (int i = 0; i < value; i++)
        graph[value - 1][i] += (graph[value][i] > graph[value][i + 1]) ? graph[value][i] : graph[value][i + 1];
}