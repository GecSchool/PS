#include <stdio.h>
#define size 500001
#define True 1
int main()
{
    int n, t;
    scanf("%d %d", &n, &t);
    char arr[size] = {
        0,
    };
    char stack[size] = {
        0,
    };
    scanf("%s", arr);
    int top = 0; // stack top
    for (int i = 0; i < n; i++)
    {
        while (t > 0 && top > 0 && stack[top - 1] < arr[i])
        {
            top -= 1;
            t -= 1;
        }
        stack[top++] = arr[i];
    }
    top -= t;
    stack[top] = 0;
    printf("%s\n", stack);
    return 0;
}
