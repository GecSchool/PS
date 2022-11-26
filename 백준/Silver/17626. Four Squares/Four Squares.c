#include <stdio.h>
#define size 50001
int min(int n, int m)
{
    if (n > m)
        return m;
    return n;
}
int main()
{
    int dp[size] = {
        0,
    };
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        dp[i] = i;
    }
    for (int i = 1; i * i < 50000; i++)
    {
        dp[i * i] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        if (dp[i] == 1)
            continue;
        for (int j = 1; j * j < i; j++)
        {
            if (dp[j * j] == 1)
            {
                dp[i] = min(dp[i - j * j] + 1, dp[i]);
            }
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}
