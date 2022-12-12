#include <stdio.h>
int map[12][12] = {
    0,
};
int tmpMap[12][12] = {
    0,
};
void toggle(int i, int j)
{
    tmpMap[i][j] = (tmpMap[i][j]) ? 0 : 1;
}
void turn(int i, int j)
{
    toggle(i, j);
    toggle(i + 1, j);
    toggle(i - 1, j);
    toggle(i, j + 1);
    toggle(i, j - 1);
}
int check()
{
    for (int i = 1; i <= 10; i++)
    {
        if (tmpMap[10][i])
        {
            return 0; 
        }
    }
    return 1;
}
int main()
{
    int ans = 101;
    for (int i = 1; i <= 10; i++)
    {
        char str[11] = {
            0,
        };
        scanf("%s", str);
        for (int j = 1; j <= 10; j++)
        {
            map[i][j] = (str[j - 1] == '#') ? 0 : 1;
        }
    }
    for (int s = 0; s <= 1024; s++)
    {
        int tmp = 0;

        for (int i = 1; i <= 10; i++)
        {
            for (int j = 1; j <= 10; j++)
            {
                tmpMap[i][j] = map[i][j];
            }
        }
        for (int i = 0; i < 10; i++)
        {
            if (s & (1 << i))
            {
                turn(1, i + 1);
                tmp++;
            }
        }
        for (int i = 2; i <= 10; i++)
        {
            for (int j = 1; j <= 10; j++)
            {
                if (tmpMap[i - 1][j])
                {
                    turn(i, j);
                    tmp++;
                }
            }
        }
        if (check())
        {
            ans = (ans > tmp) ? tmp : ans;
        }
    }
    printf("%d\n", (ans == 101) ? -1 : ans);
    return 0;
}