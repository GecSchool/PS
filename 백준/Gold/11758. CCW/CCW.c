#include <stdio.h>
#include <stdlib.h>
int dot[3][2] = {
    0,
};
int ccw()
{
    int tmp = (dot[1][0] - dot[0][0]) * (dot[2][1] - dot[0][1]) - (dot[2][0] - dot[0][0]) * (dot[1][1] - dot[0][1]);
    if (tmp)
    {
        tmp /= abs(tmp);
    }
    return tmp;
}
int main()
{
    for (int i = 0; i < 3; i++)
    {
        scanf("%d %d", &dot[i][0], &dot[i][1]);
    }
    printf("%d\n", ccw());
    return 0;
}