#include <stdio.h>
int bigger(int n,int m){
    if(n>m) return n;
    return m;
}
int main(){
    int n;
    int dp[301] = {0, };
    int arr[301] = {0, };
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    dp[1] = arr[1];
    dp[2] = dp[1] + arr[2];
    dp[3] = bigger(arr[2]+arr[3],arr[1]+arr[3]);
    for(int i=4;i<=n;i++){
        dp[i] = bigger(dp[i-3]+arr[i-1]+arr[i],dp[i-2]+arr[i]);
    }
    printf("%d\n",dp[n]);
    return 0;
}