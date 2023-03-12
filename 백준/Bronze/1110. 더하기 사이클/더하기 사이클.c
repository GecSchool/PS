#include <stdio.h>
int main(void)
{
        int gec,gil;
        scanf("%d",&gec);
        int sib,il,hap,ngec=0,n=0;
        ngec=gec;
        while(1){
                sib=gec/10;
                il=gec%10;
                hap=sib+il;
                gec=il*10+hap%10;
                n+=1;
                if(ngec==gec)
                        break;
        }
        printf("%d",n);
        return 0;
}