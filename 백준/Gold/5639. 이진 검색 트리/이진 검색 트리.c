#include <stdio.h>
int arr[10001];
int Index;
int n, tmp;

void f(int, int);
int main()
{
    while (scanf("%d", &tmp) != EOF)
    {
        arr[n] = tmp;
        n += 1;
    }
    f(0, n);
    return 0;
}

void f(int start, int end)
{
    if (start >= end)
        return;
    Index = start + 1;
    for (; Index < end; Index++)
        if (arr[start] < arr[Index])
            break;
    f(start + 1, Index);
    f(Index, end);
    printf("%d\n", arr[start]);
}