#include <stdio.h>
#include <string.h>

char str[5][16];
int strLen[5];

int main()
{
    int maxLen = 0;
    for (int i = 0; i < 5; i++)
    {
        scanf("%s", str[i]);
        int tmp = strlen(str[i]);
        strLen[i] = tmp;
        maxLen = (maxLen > tmp) ? maxLen : tmp;
    }
    int p = 0;
    while (1)
    {
        for (int i = 0; i < 5; i++)
        {
            if (p < strLen[i])
                printf("%c", str[i][p]);
        }
        if (p++ == maxLen)
            return 0;
    }
}