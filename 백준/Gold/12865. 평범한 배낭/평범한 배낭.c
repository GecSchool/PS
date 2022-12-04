#include <stdio.h>
int dp[101][100001];
int weight[101];
int value[101];
int n, k;
int bigger(int n, int m)
{
    return (n > m) ? n : m;
}
int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &weight[i], &value[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (j >= weight[i])
                dp[i][j] = bigger(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    printf("%d\n", dp[n][k]);
    return 0;
}
