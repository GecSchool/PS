#include <stdio.h>
int main(void){
    int n,m,sum=0,small,s=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i*i<=m;i++){
        if(i*i>=n){ 
            sum+=i*i;
            if(s++==0){
                small=i*i;
            }
        }    
    }
    if(sum==0) printf("-1\n");
    else printf("%d\n%d\n",sum,small);
    return 0;
}