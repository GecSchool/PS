#include <stdio.h>
#define size 100001
int min(int n, int m)
{
    if (n > m)
        return m;
    return n;
}
int main()
{
    int n, m, ans = 100001, tmp;
    int sum[size] = {
        0,
    };
    int arr[size] = {
        0,
    };
    int bottom = 1, top = 1;
    scanf("%d %d", &n, &m);
    scanf("%d", &sum[1]);
    arr[1] = sum[1];
    for (int i = 2; i <= n; i++)
    {
        scanf("%d", &tmp);
        arr[i] = tmp;
        sum[i] = sum[i - 1] + tmp;
    }
    while (n + 1 != top && n + 1 != bottom)
    {
        if (top == n + 1)
        {
            if ((sum[top] - sum[++bottom]) >= m)
                ans = min(top - bottom + 1, ans);
        }
        if (top == bottom)
        {
            if (arr[top] >= m)
            {
                printf("1\n");
                return 0;
            }
            else if (arr[top] < m)
            {
                top++;
            }
        }
        else
        {
            if (sum[top] - sum[bottom - 1] > m)
            {
                ans = min(ans, top - bottom + 1);
                bottom++;
            }
            else if (sum[top] - sum[bottom - 1] < m)
            {
                top++;
            }
            else if (sum[top] - sum[bottom - 1] == m)
            {
                ans = min(ans, top - bottom + 1);
                top++;
            }
        }
    }

    printf("%d\n", (ans != 100001) ? ans : 0);
}