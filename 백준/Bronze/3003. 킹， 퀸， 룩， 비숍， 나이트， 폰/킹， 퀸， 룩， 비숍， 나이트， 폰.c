#include <stdio.h>
int number[6] = {1, 1, 2, 2, 2, 8};

int main()
{
    int data[6];
    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &data[i]);
    }
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", (number[i] - data[i]));
    }
    return 0;
}