#include <stdio.h>
int binary(int right,int target,int *lim){
    int left = 1;
    while(right>left){
        int mid = (right + left)/2;
        if(lim[mid]>=target){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    return right;
}
int bigger(int n,int m){
    if(n>m) return n;
    return m;
}
int main(){
    int T; //times
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        int n; // days
        int k; // can_buy day
        int top = 0;
        int num;
        int lim[10001] ={0, };
        int index[10001] = {0, };
        scanf("%d%d",&n,&k);
        for(int j=1;j<=n;j++){
            scanf("%d",&num);
            if(lim[top]>=num){
                int tmp = binary(top,num,lim);
                lim[tmp] = num;
                index[j] = tmp;
            }
            else{
                lim[++top] = num;
                index[j] = top;
            }
        }
        int max = 0;
        for(int j=1;j<=n;j++){
            max = bigger(max,index[j]);
        }
        printf("Case #%d\n",i);
        if(max>=k) printf("1\n");
        else printf("0\n");
    }
    return 0;
}