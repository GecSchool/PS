#include <stdio.h>
#define MAX_SIZE 21

char map[MAX_SIZE][MAX_SIZE];
char visited[26];
int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};
int ans;
int n, m;

int max(int x, int y)
{
    return (x > y) ? x : y;
}

void dfs(int y, int x, int tmp)
{
    int alpha = map[y][x] - 'A';
    if (visited[alpha])
    {
        return;
    }
    else
    {
        visited[alpha] = 1;
        ans = max(tmp, ans);
        for (int i = 0; i < 4; i++)
        {
            if (!(y + Y[i] < 0 || y + Y[i] > n - 1 || x + X[i] < 0 || x + X[i] > m - 1))
                dfs(y + Y[i], x + X[i], tmp + 1);
        }
        visited[alpha] = 0;
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", map[i]);
    }
    dfs(0, 0, 1);
    printf("%d\n", ans);
    return 0;
}