#include <stdio.h>

int num[5];

int main()
{
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &num[i]);
    }
    int ans = 1;
    while (1)
    {
        int numOfDivided = 0;
        for (int i = 0; i < 5; i++)
        {
            if (!(ans % num[i]))
            {
                numOfDivided++;
            }
        }
        if (numOfDivided >= 3)
        {
            printf("%d\n", ans);
            return 0;
        }
        ans++;
    }
}