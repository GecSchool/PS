#include <stdio.h>
char str1[1002], str2[1002];
int dp[1001][1001];
int i;
int j;
int bigger(int n, int m)
{
    return (n > m) ? n : m;
}
int main()
{
    scanf("%s %s", str1 + 1, str2 + 1);
    for (i = 1; str1[i]; i++)
    {
        for (j = 1; str2[j]; j++)
        {
            int tmp = bigger(dp[i][j - 1], dp[i - 1][j]);
            if (str1[i] == str2[j])
                dp[i][j] = bigger(tmp, dp[i - 1][j - 1] + 1);
            else
                dp[i][j] = bigger(tmp, dp[i - 1][j - 1]);
        }
    }
    printf("%d\n", dp[i - 1][j - 1]);
    return 0;
}