#include <stdio.h>

int main()
{
    int number[3];
    int ans[10] = {
        0,
    };
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &number[i]);
    }
    long long tmp = number[0] * number[1] * number[2];

    while (tmp > 0)
    {
        int index = tmp % 10;
        tmp /= 10;
        ans[index] += 1;
        /* code */
    }
    for (int i = 0; i <= 9; i++)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}