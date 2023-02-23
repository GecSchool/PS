#include <stdio.h>
int arr[100001] = {0, };
int bigger(int n,int m){
    if(n>m) return n;
    return m;
}
int binary(int right,int target){
    int left = 1;
    while(left<right){
        int mid = (right+left)/2;
        if(arr[mid]<target){
            left = mid+1;
        }
        else{
            right = mid;
        }
    }
    return right;
}
int main(void){
    int n;
    int top = 0;
    int target;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&target);
        if(arr[top]>=target){
            int tmp = binary(top,target);
            arr[tmp] = target;
        }
        else if(target>arr[top]) arr[++top] = target;
    }
    printf("%d\n",n-top);
    return 0;
}