#include <stdio.h>
#define MAX_INDEX 5
typedef long long ll;
ll n, b, tmp;
ll matrix[MAX_INDEX][MAX_INDEX], ANS[MAX_INDEX][MAX_INDEX];

void squared(ll a[][MAX_INDEX], ll b[][MAX_INDEX]);
void DaC(ll m);
int main()
{
    scanf("%lld %lld", &n, &b);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lld", &tmp);
            matrix[i][j] = tmp % 1000;
            ANS[i][j] = matrix[i][j];
        }
    }
    DaC(b);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%lld ", ANS[i][j]);
        printf("\n");
    }
    return 0;
}

void squared(ll a[][MAX_INDEX], ll b[][MAX_INDEX])
{
    ll tmp[MAX_INDEX][MAX_INDEX] = {
        0,
    };
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int s = 0; s < n; s++)
                tmp[i][j] += a[i][s] * b[s][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int s = 0; s < n; s++)
                ANS[i][j] = tmp[i][j] % 1000;
}
void DaC(ll m)
{
    if (m == 1)
        return;
    if (m % 2 == 1)
    {
        DaC(m / 2);
        squared(ANS, ANS);
        squared(ANS, matrix);
    }
    else
    {
        DaC(m / 2);
        squared(ANS, ANS);
    }
}