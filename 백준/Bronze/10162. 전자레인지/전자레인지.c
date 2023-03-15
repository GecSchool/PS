#include <stdio.h>
int main(void){
    int t,t300,t60,t10;
    scanf("%d",&t);
    if(t%10!=0){
        printf("-1\n");
        return 0;
    }
    t300=t/300;
    t-=t300*300;
    t60=t/60;
    t-=t60*60;
    t10=t/10;
    printf("%d %d %d\n",t300,t60,t10);
    return 0;
}