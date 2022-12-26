#include <stdio.h>
void move(int start,int to){
    printf("%d %d\n",start,to);
    return ;
}
void hanoi(int n,int start,int to,int via){
    if(n==1){
        move(start,to);
    }
    else{
        hanoi(n-1,start,via,to);
        move(start,to);
        hanoi(n-1,via,to,start);
    }
    return ;
}
int main(void){
    int n;
    scanf("%d",&n);
    long long s=1;
    for(int i=0;i<n;i++){
        s*=2;
    }
    printf("%lld\n",s-1);
    hanoi(n,1,3,2);
    return 0;
}