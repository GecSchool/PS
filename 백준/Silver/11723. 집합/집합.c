#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d", &n);
    int arr[21] = {
        0,
    };
    for (int i = 0; i < n; i++)
    {
        char cmd[10] = {
            0,
        };
        scanf("%s", cmd);
        int tmp;
        if (strcmp(cmd, "add") == 0)
        {
            scanf("%d", &tmp);
            arr[tmp] = 1;
        }
        else if (strcmp(cmd, "remove") == 0)
        {
            scanf("%d", &tmp);
            arr[tmp] = 0;
        }
        else if (strcmp(cmd, "check") == 0)
        {
            scanf("%d", &tmp);
            if (arr[tmp] == 1)
                printf("1\n");
            else
                printf("0\n");
        }
        else if (strcmp(cmd, "toggle") == 0)
        {
            scanf("%d", &tmp);
            arr[tmp] ^= 1;
        }
        else if (strcmp(cmd, "all") == 0)
        {
            for (int i = 1; i <= 20; i++)
            {
                arr[i] = 1;
            }
        }
        else if (strcmp(cmd, "empty") == 0)
        {
            for (int i = 1; i <= 20; i++)
            {
                arr[i] = 0;
            }
        }
    }
    return 0;
}