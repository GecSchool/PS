#include <stdio.h>
#define ll long long
ll ans = 0;
ll z(int n)
{
    ll tmp = 1;
    for (int i = 0; i < n; i++)
        tmp *= 2;
    return tmp;
}
ll solve(int n, int x, int y)
{ // n, 행, 렬 return ans 값
    ll ans;
    if (n == 1)
    {
        return (x + 2 * y);
    }
    int place;
    ll z_n = z(n);
    if ((z_n - 1) / 2 < x)
    { // (z(n)-1)/2 x/2 y/2
        if ((z_n - 1) / 2 < y)
        {
            place = 3;
        }
        else
        {
            place = 1;
        }
    }
    else
    {
        if ((z_n - 1) / 2 < y)
        {
            place = 2;
        }
        else
        {
            place = 0;
        }
    }
    ans = place * z_n * z_n / 4;
    return ans + solve(n - 1, x - (place % 2) * z(n - 1), y - (place / 2) * z(n - 1));
}
int main()
{
    int n, x, y;
    scanf("%d%d%d", &n, &y, &x);
    ans = solve(n, x, y);
    printf("%lld\n", ans);
    return 0;
}