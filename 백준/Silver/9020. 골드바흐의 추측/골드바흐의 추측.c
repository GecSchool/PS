#include <stdio.h>
int check(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
int main(void){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n;
        int s;
        scanf("%d",&n);
        for(int j=0;j*2+1<=n/2;j++){
            if(check((j==0)?2:2*j+1)){
                if(check(n-(2*((j==0)?1:j)+1))){
                    s=(j==0)?2:2*j+1;
                }
            }
        }
        printf("%d %d\n",s,n-s);
    }
    return 0;
}