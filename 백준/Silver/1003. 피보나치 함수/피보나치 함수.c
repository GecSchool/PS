#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int dp[41][2];
    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = 1;
    for(int i=2;i<=40;i++){
        dp[i][0] = dp[i-1][0] + dp[i-2][0];
        dp[i][1] = dp[i-1][1] + dp[i-2][1];
    }
    for(int i=0;i<n;i++){
        int m;
        scanf("%d",&m);
        printf("%d %d\n",dp[m][0],dp[m][1]);
    }
    return 0;
}