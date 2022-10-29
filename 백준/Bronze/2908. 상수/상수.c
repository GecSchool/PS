#include <stdio.h>
#include <stdlib.h>

int main()
{
    char firNumber[4] = {
        0,
    };
    char secNumber[4] = {
        0,
    };
    scanf("%s %s", firNumber, secNumber);
    char tmp = firNumber[0];
    firNumber[0] = firNumber[2];
    firNumber[2] = tmp;
    tmp = secNumber[0];
    secNumber[0] = secNumber[2];
    secNumber[2] = tmp;
    int fir = atoi(firNumber);
    int sec = atoi(secNumber);
    printf("%d\n", fir < sec ? sec : fir);
    return 0;
}