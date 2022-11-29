#include <stdio.h>
#define ll long long int
#define size 5000
#define true 1
#define false 0
//a,b입력->최대 공약수 찾기&나누기->짝수 2 나누기(큰 수 먼저) 나눌 때 상대방 ㅁ+ㅁ 넣기-> 반복문(if a!=b) 서로 다른 놈 더하기&& 2 나누기(결국 차이가 절반 씩 줄어든다)
// 만들 함수 1. 최대 공약수 찾기
ll gcd(ll,ll);
int main(void){
    ll a,b,c;
    int s=0;
    char alpha[size][2];
    scanf("%lld%lld",&a,&b);
    c=gcd(a,b);
    a/=c,b/=c;// 최대 공약수 나누기
    while (a!=b)//작은거에 큰거 더해주는게 더 좋을듯... 아닌듯
    {
        while(a%2==0){
            a/=2;
            alpha[s][0]='B',alpha[s][1]='B';
            s++;
        }
        while(b%2==0){
            b/=2;
            alpha[s][0]='A',alpha[s][1]='A';
            s++;
        }
        if(a<b){
            b+=a;
            b/=2;
            alpha[s][0]='B';
            alpha[s][1]='A';
            s++;
            alpha[s][0]='A';
            alpha[s][1]='A';
            s++;
        }
        if(b<a){
            a+=b;
            a/=2;
            alpha[s][0]='A';
            alpha[s][1]='B';
            s++;
            alpha[s][0]='B';
            alpha[s][1]='B';
            s++;
        }
    }
    printf("%d\n",s);
    for(int i;i<s;i++){
            printf("%c+=%c\n",alpha[i][0],alpha[i][1]);
    }
    return 0;
}
ll gcd(ll a,ll b){
    ll tmp;
    if(a<b){
        tmp=a;
        a=b;
        b=tmp;
    }
    while (b!=0)
    {
        tmp=a%b;
        a=b;
        b=tmp;
    }
    return a;
}