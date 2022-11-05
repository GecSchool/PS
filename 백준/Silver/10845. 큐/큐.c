#include <stdio.h>
#include <string.h>
int main()
{
    int n, top = 0, bottom = 0;
    int q[10000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char order[100] = {
            0,
        };
        scanf("%s", order);
        if (strcmp(order, "push") == 0)
        {
            scanf("%d", &q[top++]);
        }
        else if (strcmp(order, "pop") == 0)
        {
            if (top == bottom)
                printf("-1\n");
            else
                printf("%d\n", q[bottom++]);
        }
        else if (strcmp(order, "size") == 0)
        {
            printf("%d\n", top - bottom);
        }
        else if (strcmp(order, "empty") == 0)
        {
            if (top - bottom == 0)
                printf("1\n");
            else
                printf("0\n");
        }
        else if (strcmp(order, "front") == 0)
        {
            if (top == bottom)
                printf("-1\n");
            else
                printf("%d\n", q[bottom]);
        }
        else if (strcmp(order, "back") == 0)
        {
            if (top == bottom)
                printf("-1\n");
            else
                printf("%d\n", q[top - 1]);
        }
    }
    return 0;
}