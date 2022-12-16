#include <stdio.h>
int arr[1001] = {0, };
int bigger(int n,int m){
    if(n>m) return n;
    return m;
}
int main(){
    int n;
    scanf("%d",&n);
    int dp[1001];
    int lim[1001] = {0, };
    int tmp[1001] = {0, };
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        dp[i] = 1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(arr[i]>arr[j]&&dp[j]+1 > dp[i]){
                dp[i] = dp[j] +1;
                tmp[i] = j;
            }
        }
    }
    int max = 0;
    int max_index;
    int index;
    for(int i=1;i<=n;i++){ 
        if(bigger(max,dp[i]) == dp[i]){
            max = dp[i];
            max_index = i;
        }
    }
    printf("%d\n",max);
    index = max_index;
    for(int i=max;i>0;i--){
        lim[i] = arr[index];
        index = tmp[index];

    }
    for(int i=1;i<=max;i++) printf("%d ",lim[i]);
    printf("\n");
    return 0;
}