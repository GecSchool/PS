#include <stdio.h>
int main(void){
    int n,s;
    scanf("%d",&n);
    if(n==1){
        return 0;
    }
    s=n;
    for(int i=2;i<=s;i++){
        if(n==1){
            return 0;
        }
        while (n%i==0)
        {
            printf("%d\n",i);
            n/=i;
        }
    }
}