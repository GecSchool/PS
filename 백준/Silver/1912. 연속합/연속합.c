#include <stdio.h>
int bigger(int n,int m){
    if(n>m) return n;
    return m;
}
int main(){
    int n;
    scanf("%d",&n);
    int top=0;
    int arr[100001]={0, };
    int num;
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        if(num>0&&arr[top]>0){
            arr[top] += num;
            continue;
        }
        arr[++top] = num;
    }
    int dp[100001] ={-1001, };
    for(int i=1;i<=top;i++) dp[i] = arr[i];
    for(int i=1;i<=top;i++){
        dp[i] = bigger(dp[i-1]+arr[i],arr[i]);
        
    }
    int max=-2000000000;
    for(int i=1;i<=top;i++){
        max = bigger(max,dp[i]);
    }
    printf("%d\n",max);
    return 0;
}