#include <stdio.h>
int t(int i)
{
    int ans = 0;
    while ((i % 2) == 0)
    {
        ans += 1;
        i /= 2;
    }
    return ans;
}
int f(int i)
{
    int ans = 0;
    while ((i % 5) == 0)
    {
        ans += 1;
        i /= 5;
    }
    return ans;
}
int main()
{
    int n;
    int five = 0, two = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        if (i % 5 == 0)
            five += f(i);
        if (i % 2 == 0)
            two += t(i);
    }
    printf("%d\n", (five > two) ? two : five);
    return 0;
}