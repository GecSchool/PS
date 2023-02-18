#include <stdio.h>
int arr[40001] = {0, };
int binary(int left,int right,int target){
    int mid;
    while(left<right){
        mid = (right + left)/2;
        if(arr[mid]<target){
            left = mid + 1;
        }
        else if(target<=arr[mid]){
            right = mid;
        }
    }
    return right;
}
int main(void){
    int n;
    scanf("%d",&n);
    int top = 0,gec;
    for(int i=1;i<=n;i++){
        scanf("%d",&gec);
        if(arr[top]<gec){
            arr[++top] = gec;
        }
        else if(arr[top]>gec){
            arr[binary(1, top, gec)] = gec;
        }
    }
    printf("%d\n",top);
    return 0;
}