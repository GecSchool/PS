#include <stdio.h>

double fibo(int n)
{
	if (n == 0)
		return 1;
	return n * fibo(n - 1);
}
double combi(int n, int m)
{
	return fibo(n) / (fibo(n - m) * fibo(m));
}
int main(void)
{
	int t, n, m;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d %d", &n, &m);
		printf("%.lf\n", combi(m, n));
	}
	return 0;
}
