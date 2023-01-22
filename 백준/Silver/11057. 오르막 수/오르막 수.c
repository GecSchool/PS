#include <stdio.h>
#define MAX_INDEX 1001
int dp[10][MAX_INDEX];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= 9; i++)
    {
        dp[i][1] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int s = j; s <= 9; s++)
            {
                dp[s][i + 1] += dp[j][i];
                dp[s][i + 1] %= 10007;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= 9; i++)
    {
        ans += dp[i][n] % 10007;
    }
    printf("%d", ans % 10007);
    return 0;
}