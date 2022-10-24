#include <stdio.h>
int main(){
    int n,min = 1000001,max = -1000001;
    scanf("%d",&n);
    for(int i=0;i < n;i++){
        int tmp;
        scanf("%d",&tmp);
        if(tmp > max){
            max = tmp;
        } 
        if(tmp < min){
            min = tmp;
        }
    }
    printf("%d %d\n",min,max);
    return 0;
}