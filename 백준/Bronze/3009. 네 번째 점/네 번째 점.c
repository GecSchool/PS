#include <stdio.h>
void find_odd(int arr[])
{
    if (arr[0] == arr[1])
        printf("%d", arr[2]);
    else if (arr[1] == arr[2])
        printf("%d", arr[0]);
    else if (arr[0] == arr[2])
        printf("%d", arr[1]);
    return;
}
int main()
{
    int x[3];
    int y[3];
    for (int i = 0; i < 3; i++)
    {
        scanf("%d %d", &x[i], &y[i]);
    }
    find_odd(x);
    printf(" ");
    find_odd(y);
    printf("\n");
    return 0;
}