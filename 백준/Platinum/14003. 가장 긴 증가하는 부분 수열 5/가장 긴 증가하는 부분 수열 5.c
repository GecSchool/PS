#include <stdio.h>
#define size 1000001
int number[size] ={0, };
int binary(int,int);
int main(void){
    int n;
    scanf("%d",&n);
    int arr[size]={0, };
    int index[size]={0, }; // arr i번째 숫자는 number에 index
    int lim[size]={0, };
    int top = 0;
    int tmp;  
    for(int i=0;i<=size -1;i++) number[i] = -2000000000; 
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    for(int i=1;i<=n;i++){
        if(number[top]>=arr[i]){
            tmp = binary(top,arr[i]);
            number[tmp] = arr[i];
            index[i] = tmp;
            // 안에 있는거랑 교체
        }
        else if(arr[i]>number[top]){
            number[++top] = arr[i];
            index[i] = top;
        }
    }
    printf("%d\n",top);
    int find_index = top;
    for(int i=n;i>=1;i--){
        if(find_index == index[i]){
            lim[find_index] = arr[i];
            find_index--;
        }
    }
    for(int i=1;i<=top;i++) printf("%d ",lim[i]);
    printf("\n");
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