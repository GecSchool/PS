#include <stdio.h>
int bigger(int n, int m){
    if(n>=m) return n;
    else return m;
}
int main(void){
    int n;
    scanf("%d",&n);
    int yang[10001] = {0, };
    int sum[10001] = {0, };
    for(int i=1;i<=n;i++){
        scanf("%d",&yang[i]);
    }
    sum[1] = yang[1];
    sum[2] = yang[1] + yang[2];
    for(int i=3;i<=n;i++){
        sum[i] = bigger(sum[i-1],bigger(sum[i-2]+yang[i],yang[i-1]+yang[i]+sum[i-3]));
    }
    printf("%d\n",sum[n]);
    return 0;
}