#include <stdio.h>
int bigger(int n,int m){
    if(n>=m) return n;
    else return m;
}
int main(void){
    int number[501] = {0, };
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        number[a] = b;
       
    }
    int dp[501];
    for(int i=1;i<=500;i++) dp[i] = 1;
    for(int i=1;i<=500;i++){
        if(number[i]==0) continue;
        for(int j=1;j<i;j++){
            if(number[j]==0) continue;
            if(number[j]<number[i]) dp[i] = bigger(dp[j]+1,dp[i]); 
        }
    }
    int max = 0;
    for(int i=1;i<=500;i++) max = bigger(max,dp[i]);
    printf("%d\n",n-max);
    return 0;
}