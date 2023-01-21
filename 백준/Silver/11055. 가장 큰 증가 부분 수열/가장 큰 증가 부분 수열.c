#include <stdio.h>
long long bigger(long long n, long long m){
    if(n>=m) return n;
    else return m;
}
int main(void){
    int n;
    scanf("%d",&n);
    int arr[1001] = {0, };
    long long dp[1001] = {0, };
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        dp[i] = arr[i];
    }
    dp[1] = arr[1];
    long long Max = 0;
    for(int i=2;i<=n;i++){
        for(int j=i-1;j>0;j--){
            if(arr[j]<arr[i]){
                dp[i] = bigger(dp[j] + arr[i],dp[i]);
            }
        }
    }
    for(int i=1;i<=n;i++) if(Max<dp[i]) Max = dp[i];
    printf("%lld\n",Max);
    return 0;
}