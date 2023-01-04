#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2, r1, r2, radiusSum;
        double dotDistance;
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        if (r2 > r1)
        {
            int tmp = x1;
            x1 = x2;
            x2 = tmp;
            tmp = y1;
            y1 = y2;
            y2 = tmp;
            tmp = r1;
            r1 = r2;
            r2 = tmp;
        } // firstCircle has big radius
        if (x1 == x2 && y1 == y2 && r1 == r2)
        {
            printf("-1\n");
            continue;
        }
        radiusSum = r1 + r2;
        dotDistance = sqrt((double)((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
        if ((radiusSum == dotDistance) || (r1 == dotDistance + r2))
        {
            printf("1\n");
        }
        else if ((dotDistance > radiusSum) || ((dotDistance < radiusSum) && (r1 > r2 + dotDistance)))
        {
            printf("0\n");
        }
        else
        {
            printf("2\n");
        }
    }
    return 0;
}