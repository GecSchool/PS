#include <stdio.h>
int lim[200001] = {0, };
int binary(int right,int target){
    int left=1;
    while(left<right){
        int mid = (right+left)/2;
        if(lim[mid]<target){
            left = mid +1;
        }
        else{
            right = mid;
        }
    }
    return right;
}
int main(){
    int n;
    int book;
    int top = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&book);
        if(lim[top]>=book){
            int tmp = binary(top,book);
            lim[tmp] = book;
        }
        else if(lim[top]<book){
            lim[++top] = book;
        }
    }
    printf("%d\n",n-top);
    return 0;
}