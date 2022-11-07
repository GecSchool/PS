#include <stdio.h>
#define size 1000001
int smaller(int n,int m){
    if(n>m) return m;
    return n;
}
int main(void){
    int dp[size] = {0, };
    int n;
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+1;
        if(i%2==0) dp[i] = smaller(dp[i],dp[i/2]+1);
        if(i%3==0) dp[i] = smaller(dp[i],dp[i/3]+1);
    }
    printf("%d\n",dp[n]);
    return 0;
}