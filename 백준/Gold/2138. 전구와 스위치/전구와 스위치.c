#include <stdio.h>
#include <string.h>
#define size 100001
char change(char tmp)
{
    if (tmp == '0')
        return '1';
    else if (tmp == '1')
        return '0';
}
void click(char arr[], int i)
{
    arr[i] = change(arr[i]);
    arr[i - 1] = change(arr[i - 1]);
    arr[i + 1] = change(arr[i + 1]);
    return;
}
int cal_ans(char start_num[], char end_num[], int n)
{
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (start_num[i - 1] != end_num[i - 1])
        {
            ans += 1;
            click(start_num, i);
        }
    }
    start_num[n] = 0;
    if (!(strcmp(start_num, end_num)))
    {
        return ans;
    }
    else
    {
        return -1;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    char start_num[size] = {
        0,
    };
    char end_num[size] = {
        0,
    };
    char tmp[size] = {
        0,
    };
    scanf("%s", start_num);
    scanf("%s", end_num);
    // click first button
    strcpy(tmp, start_num);
    tmp[0] = change(tmp[0]);
    tmp[1] = change(tmp[1]);
    int fir_tmp = cal_ans(tmp, end_num, n);
    if (fir_tmp != -1)
    {
        fir_tmp += 1;
    }
    // noneclick first button
    strcpy(tmp, start_num);
    int sec_tmp = cal_ans(tmp, end_num, n);
    if (sec_tmp == -1)
    {
        if (fir_tmp == -1)
        {
            printf("-1\n");
            return 0;
        }
        else
        {
            printf("%d\n", fir_tmp);
            return 0;
        }
    }
    else
    {
        if (fir_tmp == -1)
        {
            printf("%d\n", sec_tmp);
            return 0;
        }
        else
        {
            printf("%d\n", (fir_tmp > sec_tmp) ? sec_tmp : fir_tmp);
            return 0;
        }
    }
}