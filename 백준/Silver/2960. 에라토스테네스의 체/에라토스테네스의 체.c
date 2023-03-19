#include <stdio.h>
int main(void){
    int number[1000];
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=2;i<=n;i++){
        number[i]=i;
    }
    int s=0;
    for(int i=2;i<=n;i++){
        if(number[i]==0) continue;
        for(int j=i;j<=n;j+=i){
            if(number[j]==0) continue;
            s++;
            if(s==k){
                printf("%d\n",number[j]);
                return 0;
            }
            number[j]=0;
        }
    }
}