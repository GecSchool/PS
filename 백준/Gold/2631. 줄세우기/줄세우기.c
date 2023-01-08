#include <stdio.h>
int bigger(int n,int m){
    if(n>m) return n;
    return m;
}
int main(void){
    int n;
    int chi[201] = {0, };
    int dp[201] = {0, };
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&chi[i]);
        dp[i] = 1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(chi[i]>chi[j]) dp[i] = bigger(dp[i],dp[j]+1);
        }
    }
    int max=0;
    for(int i=1;i<=n;i++) max = bigger(max,dp[i]);
    printf("%d\n",n-max);
    return 0;
}