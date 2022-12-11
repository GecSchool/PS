#include <stdio.h>
int number[1000001] ={0, };
int binary(int,int);
int main(void){
    int n;
    scanf("%d",&n);
    int num[100001]={0};
    int gec,top = 0;
    int tmp;    
    for(int i=1;i<=n;i++){
        scanf("%d",&gec);
        if(number[top]>=gec){
            tmp = binary(top,gec);
            number[tmp] = gec;
            // 안에 있는거랑 교체
        }
        else if(gec>number[top]){
            number[++top] = gec;
        }
    }
    printf("%d\n",top);
    return 0;
}
int binary(int right,int target){
    int left = 0;
    int mid;
    while(left<right){
        mid = (right + left)/2;
        if(number[mid] >= target){
            right = mid;
        }
        else if(number[mid] < target){
            left = mid +1;
        }
    }
    return right;
}