#include <stdio.h>
#define ll long long
int bigger(ll x, ll y)
{
    if (x > y)
        return 0;
    return 1;
}
int main()
{
    ll x, y, b, c, ans = 0;
    scanf("%lld %lld %lld %lld", &x, &y, &b, &c);
    if (bigger(x, y))
    {
        ll tmp;
        tmp = x;
        x = y;
        y = tmp;
    } // x is bigger than y
    if (bigger(c, b * 2))
    {
        ans += c * y;
        x -= y;
        y = 0;
    }
    if (bigger(c, b))
    {
        ans += (x / 2 + y / 2) * c * 2;
        x %= 2;
        y %= 2;
    }
    ans += x * b + y * b;
    printf("%lld\n", ans);
    return 0;
}