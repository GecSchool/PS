#include <stdio.h>
int smaller(int n,int m){
    if(n>m) return m;
    return n;
}
int main(){
    int n;
    scanf("%d",&n);
    int r[1001] = {0, };
    int g[1001] = {0, };
    int b[1001] = {0, };
    int dp[1001][3]; //n번째 집 , r0 g1 b2 시작
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&r[i],&g[i],&b[i]);
    }
    dp[1][0] = r[1];
    dp[1][1] = g[1];
    dp[1][2] = b[1];
    for(int i=2;i<=n;i++){
        dp[i][0] = r[i] + smaller(dp[i-1][1],dp[i-1][2]);
        dp[i][1] = g[i] + smaller(dp[i-1][0],dp[i-1][2]);
        dp[i][2] = b[i] + smaller(dp[i-1][1],dp[i-1][0]);
    }
    int result = smaller(dp[n][0],smaller(dp[n][1],dp[n][2]));
    printf("%d\n",result);
    return 0;
}