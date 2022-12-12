#include <stdio.h>
#define size 500001
int number[100001] ={0, };
int binary(int,int);
int main(void){
    int n;
    scanf("%d",&n);
    int arr[size]={0, };
    int revrse_arr[size] ={0, };
    int index[size]={0, }; // arr i번째 숫자는 number에 index
    int lim[100001]={0, };
    int top = 0;
    int tmp;
    int biggest = 0;
    int re_biggest = 0;  
    for(int i=1;i<=n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        arr[a] = b;
        revrse_arr[b] = a;
        if(a>re_biggest) re_biggest = a;
        if(b>biggest) biggest = b;
    }
    for(int i=1;i<=re_biggest;i++){
        if(number[top]>=arr[i]){
            tmp = binary(top,arr[i]);
            number[tmp] = arr[i];
            index[i] = tmp;
        }
        else if(arr[i]>number[top]){
            number[++top] = arr[i];
            index[i] = top;
        }
    }
    printf("%d\n",n-top);
    int find_index = top;
    for(int i=re_biggest;i>=1;i--){
        if(find_index == index[i]){
            lim[find_index] = arr[i]; // lim에는 lim의 값이 담겨저 있다. -> re_arr로 A값 삭제
            find_index--;
        }
    }
    for(int i=top;i>=1;i--){
        arr[revrse_arr[lim[i]]] = 0;
    }
    for(int i=1;i<=re_biggest;i++) {
        if(arr[i]>0) printf("%d\n",i);
    }
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