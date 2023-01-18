#include <stdio.h>
int main()
{
    int a, b, ans = 0;
    scanf("%d %d", &a, &b);
    while (1)
    {
        if (a > b)
        {
            printf("-1\n");
            return 0;
        }
        else if (a == b)
        {
            ans += 1;
            printf("%d\n", ans);
            return 0;
        }
        else if (b % 10 == 1)
        {
            b--;
            b /= 10;
            ans += 1;
        }
        else if (b % 2 == 0)
        {
            b /= 2;
            ans += 1;
        }
        else
        {
            printf("-1\n");
            return 0;
        }
    }
}