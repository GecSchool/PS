#include <stdio.h>
int selfnum(void);
int main(void)
{
        selfnum();
        return 0;
}

int selfnum(){
        int su[10000];
        int jun,baek,sib,il;
        for (int i=0;i<=9999;i++){
                su[i]=i+1;
        }
        for(int i=1,n;n=i,i<=10000;i++){
                jun=n/1000;
                baek=(n-jun*1000)/100;
                sib=(n-jun*1000-baek*100)/10;
                il=n%10;
                if(i<10){
                        n=n*2;
        }
                else if(i<100){
                        n=n+sib+il;
        }
                else if(i<1000){
                        n=n+baek+sib+il;
        }
                else if(i<10000){
                        n=n+jun+baek+sib+il;
        }
                if(n<=10000)
                        su[n-1]=0;
        }
        for (int i=0;i<=9999;i++){
                if(su[i]==0)
                        ;
                else
                        printf("%d\n",su[i]);}
}