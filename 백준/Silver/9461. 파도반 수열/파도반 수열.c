#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    long long num[101]={0 ,1, 1, 1, 2, 2, 3, 4, 5, 7};
    for(int i=10;i<=100;i++){
        num[i] = num[i-1] + num[i-5]; 
    }
    for(int i=0;i<n;i++){
        int s;
        scanf("%d",&s);
        printf("%lld\n",num[s]);
    }
    return 0;
}