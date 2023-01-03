#include <stdio.h>
int main(void){
    int l,a,b,c,d,korean,math;
    scanf("%d %d %d %d %d",&l,&a,&b,&c,&d);
    korean=(a%c==0)?a/c:a/c+1;
    math=(b%d==0)?b/d:b/d+1;
    if(korean>=math);
    else{
        korean=math;
    }
    printf("%d\n",l-korean);
    return 0;
}