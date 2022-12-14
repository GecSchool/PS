#include <stdio.h>
int smaller(int n, int m)
{
    if (n > m)
        return m;
    return n;
}
int main()
{
    int n, ans = 1000 * 1000 + 1;
    scanf("%d", &n);
    int color[1001][3] = {
        0,
    };
    int dp[1001][3] = {
        0,
    }; // n번째 집 , r0 g1 b2 시작
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &color[i][0], &color[i][1], &color[i][2]);
    }
    for (int i = 0; i < 3; i++)
    { // 0 = red , 1 = green , 2 = blue
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
            {
                dp[1][j] = color[1][j];
            }
            else
            {
                dp[1][j] = 1001;
            }
        }
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
                dp[2][j] = 1001 * 2;
            else
                dp[2][j] = color[1][i] + color[2][j];
        }
        for (int j = 3; j < n; j++)
        {
            dp[j][0] = color[j][0] + smaller(dp[j - 1][1], dp[j - 1][2]);
            dp[j][1] = color[j][1] + smaller(dp[j - 1][0], dp[j - 1][2]);
            dp[j][2] = color[j][2] + smaller(dp[j - 1][0], dp[j - 1][1]);
        }
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
                continue;
            else
            {
                dp[n][j] = color[n][j] + smaller(dp[n - 1][(j + 1) % 3], dp[n - 1][(j + 2) % 3]);
                ans = smaller(dp[n][j], ans);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}