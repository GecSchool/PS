#include <stdio.h>
#include <stdlib.h>
typedef struct Dot
{
    long long x;
    long long y;
} dot;

long long max(long long a, long long b) { return (a > b) ? a : b; }
long long min(long long a, long long b) { return (a > b) ? b : a; }
int ccw(dot fir, dot sec, dot thr)
{
    long long tmp = (sec.x - fir.x) * (thr.y - fir.y) - (thr.x - fir.x) * (sec.y - fir.y);
    if (tmp)
        tmp /= abs(tmp);
    return tmp;
}
int fun(dot *data)
{
    int result1 = ccw(data[1], data[2], data[3]) * ccw(data[1], data[2], data[4]);
    int result2 = ccw(data[3], data[4], data[1]) * ccw(data[3], data[4], data[2]);

    if (result1 == 0 && result2 == 0)
    {

        if (min(data[1].x, data[2].x) <= max(data[3].x, data[4].x) && min(data[3].x, data[4].x) <= max(data[1].x, data[2].x))
        {
            if (min(data[1].y, data[2].y) <= max(data[3].y, data[4].y) && min(data[3].y, data[4].y) <= max(data[1].y, data[2].y))
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }
    else if (result1 <= 0 && result2 <= 0)
        return 1;
    else
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