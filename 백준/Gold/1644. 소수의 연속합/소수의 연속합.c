#include <stdio.h>
#include <math.h>
#define false 0
#define true 1
#define size 4000001
#define SIZE 283147
int check_prime[size] = {
    0,
};
int main()
{
    int n;
    int top = 1;
    long long sum[SIZE] = {
        0,
    };
    for (int i = 0; i < 4000001; i++)
    {
        check_prime[i] = true;
    }
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        if (check_prime[i])
        {
            sum[top] = sum[top - 1] + i;
            top += 1;
            for (int j = i * 2; j <= n; j += i)
            {
                check_prime[j] = false;
            }
        }
    }
    int front = 1, back = 0;
    int ans = 0;
    while (true)
    {
        int tmp = sum[front] - sum[back];
        if (tmp == n)
        {
            ans += 1;
            front += 1;
            back += 1;
        }
        else if (tmp > n)
        {
            back += 1;
        }
        else
        {
            if (front != (top - 1))
            {
                front += 1;
            }
            else
            {
                break;
            }
        }
        if (back == top - 1)
            break;
    }
    printf("%d\n", ans);
    return 0;
}