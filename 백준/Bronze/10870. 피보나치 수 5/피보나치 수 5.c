#include <stdio.h>
#define ll long long int
ll fibo(int); 
int main(void){
    ll n;
    scanf("%lld",&n);
    printf("%lld\n",fibo(n));
    return 0;
}
ll fibo(int n){
    if(n==0) return 0;
    if(n==1||n==2){
        return 1;
    }
    return fibo(n-1)+fibo(n-2);
}