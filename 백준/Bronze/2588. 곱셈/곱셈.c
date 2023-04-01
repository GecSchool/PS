#include <stdio.h>

int main(void)
{
        int gec,gil,b5,b4,b3;
        scanf("%d%d",&gil,&gec);
        b5=gec/100;
        b4=gec/10-b5*10;
        b3=gec-b5*100-b4*10;
        printf("%d\n",b3*gil);
        printf("%d\n",b4*gil);
        printf("%d\n",b5*gil);
        printf("%d",gec*gil);
        return 0;
}