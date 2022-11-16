#include <stdio.h>
#define ll long long
int main(void){
    int n;
    ll dp[1001]={0, 1, 2};
    scanf("%d",&n);
    for(int i=3;i<=n;i++){
        dp[i] = dp[i-1]%10007 + dp[i-2]%10007;
    }
    printf("%lld\n",dp[n]%10007);
    return 0;
}