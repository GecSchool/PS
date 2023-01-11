#include <stdio.h>
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main(void){
    int a,b;
    scanf("%d%d",&a,&b);
    int tmp = gcd(a,b);
    printf("%d\n%d\n",tmp,a*b/tmp);
    return 0;
}