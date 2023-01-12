#include <stdio.h>
#include <stdlib.h>
typedef struct Dot
{
    long long x;
    long long y;
} dot;

int ccw(dot fir, dot sec, dot thr)
{
    long long tmp = (sec.x - fir.x) * (thr.y - fir.y) - (thr.x - fir.x) * (sec.y - fir.y);
    if (tmp)
        tmp /= abs(tmp);
    return tmp;
}
int fun(dot *data)
{
    if (ccw(data[1], data[2], data[3]) * ccw(data[1], data[2], data[4]) < 0 && ccw(data[3], data[4], data[1]) * ccw(data[3], data[4], data[2]) < 0)
        return 1;
    return 0;
}
int main()
{
    dot data[5] = {
        0,
    };
    for (int i = 1; i <= 2; i++)
    {
        scanf("%lld %lld %lld %lld", &data[2 * i - 1].x, &data[2 * i - 1].y, &data[2 * i].x, &data[2 * i].y);
    }
    int ans = fun(data);
    printf("%d\n", ans);
    return 0;
}