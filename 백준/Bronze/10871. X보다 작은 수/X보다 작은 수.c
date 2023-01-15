#include <stdio.h>

int main(){
    int n,x;
    scanf("%d %d",&n,&x);
    for(int i = 1;i <= n;i++){
        int tmp;
        scanf("%d",&tmp);
        if(tmp < x) printf("%d ",tmp);
    }
    printf("\n");
    return 0;
}