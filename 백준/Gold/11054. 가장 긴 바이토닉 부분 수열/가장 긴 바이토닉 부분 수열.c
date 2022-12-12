#include <stdio.h>
#define ll long long
ll bigger(ll n, ll m){
    if(n>=m) return n;
    else return m;
}
int arr[1001] = {0, };
ll dp[1001] = {0, };
ll dp_up(int , int);
ll dp_down(int ,int);
int main(void){
    ll n;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    ll dp_sum[1001] = {0};
    for(int i=1;i<=n;i++){
        dp_sum[i] = dp_up(1,i)+dp_down(i,n)-1;
    }
    ll Max = 0;
    for(int i=1;i<=n;i++) Max = bigger(Max,dp_sum[i]);
    printf("%lld\n",Max);
    return 0;
}
ll dp_up(int start,int end){ // to
    for(int i=start;i<=end;i++){
        dp[i] = 1;
    }
    for(int i=start+1;i<=end;i++){
        for(int j=1;j<i;j++){
            if(arr[j]<arr[i]){
                dp[i] = bigger(dp[j] + 1,dp[i]);
            }
        }
    }
    return dp[end];
}
ll dp_down(int Start,int end){ // start -> 최고or저점 end 도착지점 // from
    for(int i=Start;i<=end;i++){
        dp[i] = 1;
    }
    for(int i=end-1;i>=Start;i--){
        for(int j=end;j>i;j--){
            if(arr[j]<arr[i]){
                dp[i] = bigger(dp[j] + 1,dp[i]);
            }
        }
    }
    return dp[Start];
}
