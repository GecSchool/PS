#include <stdio.h>
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main(void){
    int n;
    scanf("%d",&n);
    int a,b;
    for(int i=0;i<n;i++){
        scanf("%d%d",&a,&b);
        printf("%d\n",a*b/gcd(a,b));
    }
    return 0;
}