#include <stdio.h>
#include <string.h>
#define size 1001
void reverse_arr(char arr[size])
{
    char tmp[size] = {
        0,
    };
    int arr_len = strlen(arr);
    for (int i = arr_len - 1; i >= 0; i--)
    {
        tmp[(arr_len - 1) - i] = arr[i];
    }
    strcpy(arr, tmp);
    return;
}
int main()
{
    char s[size] = {
        0,
    };
    char t[size] = {
        0,
    };
    scanf("%s", s);
    scanf("%s", t);
    int s_len = strlen(s);
    int t_len = strlen(t);
    for (int i = t_len - 1; i >= s_len; i--)
    {
        if (t[i] == 'A')
        {
            t[i] = 0;
        }
        else if (t[i] == 'B')
        {
            t[i] = 0;
            reverse_arr(t);
        }
    }
    if (!(strcmp(t, s)))
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }
    return 0;
}