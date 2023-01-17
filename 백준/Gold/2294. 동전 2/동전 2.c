#include <stdio.h>
#include <stdlib.h>

int smaller(int n,int m){
    if(m>n) return n;
    return m;
}
int com(const void *a,const void *b){
    int num1 = *(int *)a;
    int num2 = *(int *)b;
    if (num1 < num2) return -1;     
    if (num1 > num2) return 1;       
    return 0;    
}
int main(){
    int n;
    int total_money;
    scanf("%d",&n);
    scanf("%d",&total_money);
    int dp[10001] = {0, };
    int money[101] = {0, };
    for(int i=1;i<=n;i++) scanf("%d",&money[i]);
    qsort(money,n+1,sizeof(int),com); 
    for(int i=1;i<=total_money;i++) dp[i] = 100000;
    for(int i=1;i<=n;i++){
        for(int j=money[i];j<=total_money;j++){
            dp[j] = smaller(dp[j-money[i]] + 1,dp[j]);
        }
    }
    if(dp[total_money] == 100000) dp[total_money] = -1;
    printf("%d\n",dp[total_money]);
    return 0;
}