#include <stdio.h>
#define ll long long
ll number[1000001] ={0, };
ll binary(ll,ll);
int main(void){
    int n;
    scanf("%d",&n);
    ll num[1000001]={0};
    ll gec,top = 0;
    ll tmp;
    for(int i=0;i<=1000000;i++) number[i] = -2000000000;  
    for(int i=1;i<=n;i++){
        scanf("%lld",&gec);
        if(number[top]>=gec){
            tmp = binary(top,gec);
            number[tmp] = gec;
            // 안에 있는거랑 교체
        }
        else if(gec>number[top]){
            number[++top] = gec;
        }
    }
    printf("%lld\n",top);
    return 0;
}
ll binary(ll right,ll target){
    ll left = 0;
    ll mid;
    while(left<right){
        mid = (right + left)/2;
        if(number[mid] >= target){
            right = mid;
        }
        else if(number[mid] < target){
            left = mid +1;
        }
    }
    return right;
}