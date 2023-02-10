#include <stdio.h>
int main(){
    int num[50] = {0, };
    int n;
    int a,b;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&num[i]);
    if(n==1){
        printf("A\n");
        return 0;
    }
    if(n==2){
        if(num[0]==num[1]) printf("%d\n",num[0]);
        else printf("A\n");
        return 0;
    }
    int tmp = num[1] - num[0];
    int TMP = num[2] - num[1];
    if(tmp==0) a = 0;
    else a = TMP/tmp; 
    b = num[1] - num[0]*a;
    for(int i=2;i<n;i++){
        if(num[i] != num[i-1] *a +b){
            printf("B\n");
            return 0;
        }
    }
    printf("%d\n",a*num[n-1]+b);
    return 0;

}   
