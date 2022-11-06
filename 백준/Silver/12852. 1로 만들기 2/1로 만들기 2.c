#include <stdio.h>
#define MAX_INDEX 1000001
int max(int n, int m)
{
    return n > m ? 1 : 0;
}
int main()
{
    int dp[MAX_INDEX][2] = {
        0,
    }; // number, ex number
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = dp[i - 1][0] + 1;
        dp[i][1] = i - 1;
        if (i % 2 == 0 && max(dp[i][0], dp[i / 2][0] + 1))
        {
            dp[i][0] = dp[i / 2][0] + 1;
            dp[i][1] = i / 2;
        }
        if (i % 3 == 0 && max(dp[i][0], dp[i / 3][0] + 1))
        {
            dp[i][0] = dp[i / 3][0] + 1;
            dp[i][1] = i / 3;
        }
    }
    printf("%d\n", dp[n][0]);
    printf("%d ", n);
    while (dp[n][1])
    {
        printf("%d ", dp[n][1]);
        n = dp[n][1];
    }
    printf("\n");
    return 0;
}