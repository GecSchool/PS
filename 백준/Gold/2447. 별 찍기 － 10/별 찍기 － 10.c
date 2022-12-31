#include <stdio.h>

void fun(int, int, int);
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fun(n, i, j);
        }
        printf("\n");
    }
}

void fun(int n, int i, int j)
{
    if ((i / n) % 3 == 1 && (j / n) % 3 == 1)
    {
        printf(" ");
    }
    else
    {
        if (n / 3 == 0)
        {
            printf("*");
        }
        else
        {
            fun(n / 3, i, j);
        }
    }
}