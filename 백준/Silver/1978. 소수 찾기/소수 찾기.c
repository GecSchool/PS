#include <stdio.h>
int check(int);
int main(void){
    int t,n,num=0;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d",&n);
        num+=check(n);
    }
    printf("%d\n",num);
    return 0;
}
int check(int n){
    int ac=0;
    if(n==1){
        return 0;
    }
    for(int i=1;i<n;i++){
        if(n%i==0){
            ac++;
            if(ac==2){
                return 0;
            }
        }
    }
    return 1;
}