#include <stdio.h>
int min(int n, int m)
{
    if (n > m)
        return m;
    return n;
}
int main()
{
    int D, P, Q; 
    scanf("%d%d%d", &D, &P, &Q);
    int tmp;
    if (P < Q)
    {
        tmp = P;
        P = Q;
        Q = tmp;
    }
    int n, ans;
    n = D / P + 1;
    ans = n * P;
    for (int i = 1; i <= n; i++)
    {
        int M;
        tmp = D - P * (n - i);
        if (tmp % Q != 0)
            M = P * (n - i) + (tmp / Q + 1) * Q;
        else
            M = P * (n - i) + (tmp / Q) * Q;
        if (M == ans)
            break;
        ans = min(M, ans);
    }
    printf("%d\n", ans);
    return 0;
}