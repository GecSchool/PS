#include <stdio.h>
#include <string.h>

#define size 1000001
int main()
{
    char str[size] = {
        0,
    };
    scanf("%s", str);
    int top = 0;
    int s = -1;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] != s)
        {
            top += 1;
            s = str[i];
        }
    }
    printf("%d\n", top / 2);
    return 0;
}