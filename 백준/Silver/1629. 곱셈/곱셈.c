#include <stdio.h>
long long a, b, c;

long long divideAndConquer(long long value)
{
    if (value == 1)
        return a % c;
    long long tmp = divideAndConquer(value / 2) % c;
    if (value % 2 == 1)
        return tmp * tmp % c * a % c;
    else
        return tmp * tmp % c;
}

int main()
{
    scanf("%lld %lld %lld", &a, &b, &c);
    int ans = divideAndConquer(b);
    printf("%d\n", ans);
    return 0;
}