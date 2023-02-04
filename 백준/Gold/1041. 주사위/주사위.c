#include <stdio.h>
int smaller(int n, int m)
{
    if (n > m)
        return m;
    return n;
}
int main()
{
    int a[6];
    long long n;
    scanf("%lld", &n);
    for (int i = 0; i < 6; i++)
        scanf("%d", &a[i]); // A = 0 , B = 1, c = 2, d = 3 , e = 4, f = 5
    int one = 51, two = 101, three = 151;
    for (int i = 0; i < 6; i++)
    {
        one = smaller(one, a[i]);
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (i + j == 5 || i == j)
                continue;
            else
            {
                two = smaller(two, a[i] + a[j]);
            }
        }
    }
    long long result = 0;
    if (n != 1)
    {
        three = smaller(three, a[0] + a[1] + a[2]);
        three = smaller(three, a[0] + a[1] + a[3]);
        three = smaller(three, a[0] + a[2] + a[4]);
        three = smaller(three, a[0] + a[3] + a[4]);
        three = smaller(three, a[5] + a[1] + a[2]);
        three = smaller(three, a[5] + a[1] + a[3]);
        three = smaller(three, a[5] + a[2] + a[4]);
        three = smaller(three, a[5] + a[3] + a[4]);
        result += three * 4;
        result += ((n - 2) * (n - 2) * one) + (4 * (n - 2) * (n - 1) * one);
        result += (4 * (n - 1) * two) + (4 * (n - 2) * two);
        printf("%lld\n", result);
    }
    else
    {
        int sum = 0;
        int max = 0;
        for (int i = 0; i < 6; i++)
        {
            sum += a[i];
            max = (max < a[i]) ? a[i] : max;
        }
        printf("%d", sum - max);
    }
    return 0;
}