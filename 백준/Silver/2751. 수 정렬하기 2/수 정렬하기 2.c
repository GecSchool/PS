#include <stdio.h>
#define NUM 1000001
int main(){
    int n,arr[NUM*2]= {0,};
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        int tmp;
        scanf("%d",&tmp);
        arr[tmp+NUM] = 1;
    }
    for(int i = 1;i <= NUM*2 - 1;i++){
        if(arr[i]){
            printf("%d\n",i - NUM);
        }
    }
    return 0;
}