#include <stdio.h>
#define MAX_INDEX 1025
int n, m;
int matrix[MAX_INDEX][MAX_INDEX];
int arr[4]; // x1 , y1 ,x2 ,y2
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int tmp;
            scanf("%d", &tmp);
            matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1] - matrix[i - 1][j - 1] + tmp;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 4; j++)
            scanf("%d", &arr[j]);
        int ans = matrix[arr[2]][arr[3]] - matrix[arr[0] - 1][arr[3]] - matrix[arr[2]][arr[1] - 1] + matrix[arr[0] - 1][arr[1] - 1];
        printf("%d\n", ans);
    }
    return 0;
}