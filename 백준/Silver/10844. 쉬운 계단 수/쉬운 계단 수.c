#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    long long num[11]={0, }; //0~9 숫자 개수
    long long ex_num[11]={0, };
    long long sum=0; //계단 수 개수
    for(int i=1;i<=9;i++) ex_num[i] = 1; 
    for(int i=1;i<=9;i++) num[i] = 1;
    for(int i=2;i<=n;i++){
        num[0]=ex_num[1];
        for(int j=1;j<10;j++){
            num[j]=(ex_num[j-1]+ex_num[j+1])%1000000000;
        }
        for(int j=0;j<10;j++) ex_num[j] = num[j];
    }
    for(int i=0;i<10;i++) sum += num[i];
    printf("%lld\n",sum%1000000000);
    return 0;
}