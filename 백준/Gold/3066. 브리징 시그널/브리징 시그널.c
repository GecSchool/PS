#include <stdio.h>
int binary(int right,int target,int *number){
    int left = 1;
    while(right>left){
        int mid = (right+left)/2;
        if(number[mid]>=target){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    return right;
}

int main(){
    int T;// times
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n;
        scanf("%d",&n);
        int lim[40001] ={0, };
        int target;
        int top = 0;
        for(int i=1;i<=n;i++){
            scanf("%d",&target);
            if(target<=lim[top]){
                int tmp = binary(top,target,lim);
                lim[tmp] = target;
            }
            else{
                lim[++top] = target;
            }
        }
        printf("%d\n",top);
    }
    return 0;
}