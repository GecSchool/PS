#include <stdio.h>
#define ll long long
int main(void)
{
    int n;
    ll m;
    ll cut_len = 0;
    scanf("%d", &n);
    scanf("%lld", &m);
    ll tree[n + 1];
    int left = 0, right = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &tree[i]);
        if (right < tree[i])
            right = tree[i];
    }
    while (left <= right)
    {
        ll mid = (left + right) / 2;
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (mid < tree[i])
            {
                sum += tree[i] - mid;
            }
        }
        if (sum >= m)
        {
            if (cut_len < mid)
            {
                cut_len = mid;
            }
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    printf("%lld\n", cut_len);
    return 0;
}
