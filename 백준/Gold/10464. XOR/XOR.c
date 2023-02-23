#include <stdio.h>
int main(){
    int top = 0,bottom = 0;
    int t,n,m;

    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int answer = 0;
        scanf("%d%d",&n,&m);
        if(m-n==0) {
            printf("%d\n",m);
            continue;
        }
        else if(m-n>4){
            int bnum = 3-(n%4);
            int tnum = m%4;
            int top=0;
            int bottom=0;
            for(int j=0;j<=bnum;j++) bottom ^= (n+j);
            for(int j=0;j<=tnum;j++) top ^= (m-j);
            answer = bottom ^ top;
        }
        else if(m-n<4){
            for(int j = n;j<=m;j++) answer ^= j;
        }
        printf("%d\n",answer);
    }
    return 0;
}