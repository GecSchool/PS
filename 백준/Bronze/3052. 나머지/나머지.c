#include <stdio.h>
int main(void)
{
        int input,kk=0,h;
        int gec[10]={0};
        for(int i=0;i<=9;i++){
                scanf("%d",&input);
                gec[i]=input%42;

        }
        for(int i=0;i<=9;i++){
                int h=0;
                for (int j=0;j<i;j++){
                        if(gec[i]==gec[j])
                                h++;
                }
                if(h==0)
                        kk++;
        }


        printf("%d",kk);
        return 0;
}