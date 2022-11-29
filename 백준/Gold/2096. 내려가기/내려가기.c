#include <stdio.h>

int max(int n, int m)
{
    return m > n ? m : n;
}
int min(int n, int m)
{
    return m > n ? n : m;
}

int main()
{
    int n;
    int sumTmp[3] = {
        0,
    };
    int sumMax[3] = {
        0,
    };
    int sumMin[3] = {
        0,
    };
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int tmp[3];
        scanf("%d %d %d", &tmp[0], &tmp[1], &tmp[2]);
        // sumMax
        // 0 -> ex 1 , 2 //1 -> ex 0, 1, 2 // 2 -> ex 1 , 2
        sumTmp[0] = tmp[0] + max(sumMax[0], sumMax[1]);
        sumTmp[1] = tmp[1] + max(max(sumMax[0], sumMax[1]), sumMax[2]);
        sumTmp[2] = tmp[2] + max(sumMax[1], sumMax[2]);
        for (int j = 0; j < 3; j++)
            sumMax[j] = sumTmp[j];
        sumTmp[0] = tmp[0] + min(sumMin[0], sumMin[1]);
        sumTmp[1] = tmp[1] + min(min(sumMin[0], sumMin[1]), sumMin[2]);
        sumTmp[2] = tmp[2] + min(sumMin[1], sumMin[2]);
        for (int j = 0; j < 3; j++)
            sumMin[j] = sumTmp[j];
    }
    printf("%d %d", max(max(sumMax[0], sumMax[1]), sumMax[2]), min(min(sumMin[0], sumMin[1]), sumMin[2]));
    return 0;
}