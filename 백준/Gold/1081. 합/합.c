#include <stdio.h> 
long long sum(long long n) {
	if(n<=0) return 0; 
	long long c[10]={0,}, s=1, sum=0, t, r;
	while(n>0) { 
        t = n / (s * 10); 
		r = n % (s * 10); 
		for(int i = 0; i < 10; i++) c[i] += t*s; 
		for(int i = 1; i <= r / s; i++) c[i] += s; 
		c[(r/s+1)%10] += r % s; 
		n -= 9 * s; 
		s *= 10; 
	} 
	for(int i = 1; i < 10; i++) sum+=i*c[i]; 
	return sum; 
	} 
int main(){ 
	long long a, b; 
	long long result;
	scanf("%lld%lld", &a, &b);
	result=sum(b)-sum(a-1);
	printf("%lld\n",result); 
}
