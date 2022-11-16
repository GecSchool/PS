#include <stdio.h>
#define size 1000
#define ll long long
int main()
{
    ll dp[1001] = {
        0,
    };
    int n;
    scanf("%d", &n);
    dp[1] = 1;
    dp[2] = 3;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] % 10007 + (2 * dp[i - 2]) % 10007;
    }
    printf("%lld\n", dp[n]%10007);
    return 0;
}