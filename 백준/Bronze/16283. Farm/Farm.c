#include <stdio.h>
int main()
{
    int a, b, n, w; // a = 양, b = 염소
    int ans = -1;
    int cnt = 0;
    scanf("%d %d %d %d", &a, &b, &n, &w);
    for (int i = 1; i < n; i++)
    { // i = 양
        int tmp = a * i + b * (n - i);
        if (w == tmp)
        {
            ans = i;
            cnt++;
        }
    }
    if (cnt != 1)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d %d\n", ans, n - ans);
    }
    return 0;
}