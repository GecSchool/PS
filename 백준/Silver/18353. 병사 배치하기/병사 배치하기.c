#include <stdio.h>
int bigger(int n,int m){
    if(n>m) return n;
    return m;
}
int main(){
    int n;
    scanf("%d",&n);
    int dp[2001] = {0, };
    int arr[2001] = {0, };
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        dp[i] = 1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(arr[i]<arr[j]) dp[i] = bigger(dp[j]+1,dp[i]);
        }
    }
    int max = 0;
    for(int i=1;i<=n;i++) max = bigger(max,dp[i]);
    printf("%d\n",n-max);
    return 0;
}