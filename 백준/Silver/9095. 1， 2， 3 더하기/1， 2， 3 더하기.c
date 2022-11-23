#include <stdio.h>
int t;
int main()
{
    scanf("%d", &t);
    int dp[12] = {0, 1, 2, 4};
    for (int i = 4; i <= 11; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    for (int i = 0; i < t; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        printf("%d\n", dp[tmp]);
    }
    return 0;
}