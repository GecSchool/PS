#include <stdio.h>
int bigger(int n,int m){
    if(n>=m) return n;
    return m;
}
int main(void){
    int n;
    int dp[1001] = {0, };
    scanf("%d",&n);
    int price[1001] = {0, };
    for(int i=1;i<=n;i++){
        scanf("%d",&price[i]);
        dp[i]=price[i];
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            dp[i] = bigger(dp[i] ,dp[i-j] + dp[j]);
        }
    }
    printf("%d\n",dp[n]);
    return 0;
}