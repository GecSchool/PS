#include <stdio.h>
#define ll long long

ll fi(ll n)
{
    ll a = 1, b = 1, c = 2;
    while (1)
    {
        c = a + b;
        a = b;
        b = c;
        if (c > n)
            break;
    }
    if (a == n)
        return n;
    else
        return fi(n - a);
}

int main()
{
    ll n;
    scanf("%lld", &n);
    printf("%lld\n", fi(n));
    return 0;
}