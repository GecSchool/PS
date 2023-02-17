#include <stdio.h>
#define size 100001
int binary(int lim[size],int target,int right){
    int left = 1;
    while (left<right)
    {
        int mid = (right+left)/2;
        if(lim[mid]>=target){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    return right;
}
int main(){
    int n;
    while (scanf("%d",&n)!=-1)
    {
        int lim[size] = {0, };
        int num;
        int top = 0;
        for(int i=1;i<=n;i++){ 
            scanf("%d",&num);
            if(lim[top]<num){
                lim[++top] = num;
            }
            else{
                int tmp = binary(lim,num,top);
                lim[tmp] = num;
            }
        }
        printf("%d\n",top);
    }
    return 0;
}