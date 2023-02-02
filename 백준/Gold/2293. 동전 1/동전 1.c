#include <stdio.h>
int main(void){
    int n,k;
    int dp[10001] = {0, };
    int coin[101] = {0, };
    scanf("%d%d",&n,&k);
    dp[0] = 1;
    for(int i=1;i<=n;i++) scanf("%d",&coin[i]);
    for(int i=1;i<=n;i++){
        for(int j=coin[i];j<=k;j++) dp[j] += dp[j-coin[i]];
    }
    printf("%d\n",dp[k]);
    return 0;
}