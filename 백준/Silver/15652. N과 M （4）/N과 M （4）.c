#include <stdio.h>
#define MAX_INDEX 9
int arr[MAX_INDEX];
int n, m;
void dfs(int, int);
int main()
{
    scanf("%d %d", &n, &m);
    dfs(0, 1);
    return 0;
}
void dfs(int len, int index)
{
    if (len == m)
    {
        for (int i = 0; i < m; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return;
    }
    for (int i = index; i <= n; i++)
    {
        arr[len] = i;
        dfs(len + 1, i);
    }
}