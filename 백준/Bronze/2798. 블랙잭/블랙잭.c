#include <stdio.h>
#define size 100
int main()
{
    int n, m;
    int arr[size] = {
        0,
    };
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int dif = 200000000;
    int tmp;
    int ans;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int s = j + 1; s < n; s++)
            {
                tmp = arr[i] + arr[j] + arr[s];
                if (m < tmp)
                    continue;
                if (m - tmp < dif)
                {
                    dif = m - tmp;
                    ans = tmp;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}