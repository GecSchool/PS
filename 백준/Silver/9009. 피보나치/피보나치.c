#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    for (int j = 0; j < t; j++)
    {
        int arr[45] = {
            0,
        };
        int ans[45] = {
            0,
        };
        int tmp;
        scanf("%d", &tmp);
        arr[0] = 1;
        arr[1] = 1;
        for (int i = 2; arr[i - 1] <= 1000000000; i++)
        {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
        int n = 0;
        int s = 43;
        while (tmp)
        {
            if (arr[s] <= tmp)
            {
                tmp -= arr[s];
                ans[n++] = arr[s];
            }
            s -= 1;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
    return 0;
}