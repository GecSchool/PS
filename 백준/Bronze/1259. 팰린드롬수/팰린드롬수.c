#include <stdio.h>
#include <string.h>
int main()
{
    while (1)
    {
        char number[6] = {
            0,
        };
        scanf("%s", number);
        if (number[0] == '0')
            return 0;
        int strLen = strlen(number);
        if (strLen == 1)
        {
            printf("yes\n");
        }
        for (int i = 0; i < strLen / 2; i++)
        {
            if (number[i] != number[strLen - 1 - i])
            {
                printf("no\n");
                break;
            }
            else if (i == strLen / 2 - 1)
            {
                printf("yes\n");
            }
        }
    }
    return 0;
}