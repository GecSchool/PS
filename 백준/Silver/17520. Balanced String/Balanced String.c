#include <stdio.h>
int main()
{
    int dp[100001] = {0, 2};
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            // even
            dp[i] = dp[i - 1];
        }
        else
        {
            // odd
            dp[i] = (2 * dp[i - 1]) % 16769023;
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}