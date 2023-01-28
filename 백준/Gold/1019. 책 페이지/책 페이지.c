#include <stdio.h> 
long long number[10]={0,};
void check(long long n) {
	if(n<=0) return ; 
	long long s=1, t, r;
	while(n>0) { 
        t = n / (s * 10); 
		r = n % (s * 10); 
		for(int i = 0; i < 10; i++) number[i] += t*s; 
		for(int i = 1; i <= r / s; i++) number[i] += s; 
		number[(r/s+1)%10] += r % s; 
		n -= 9 * s; 
		s *= 10; 
	} 
	return ; 
	} 
int main(){ 
	long long a; 
	scanf("%lld", &a);
    check(a);
    for(int i=0;i<10;i++) printf("%lld ",number[i]); 
}