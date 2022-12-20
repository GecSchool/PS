#include <stdio.h>
void check(int n){
    if(n==1){
        return ;
    }
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
           return; 
        }
    }
    printf("%d\n",n);
    return ;
}
int main(void){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=n;i<=m;i++){
        check(i);
    }
    return 0;
}


