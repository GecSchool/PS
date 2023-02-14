#include <stdio.h>
#define ll long long
ll smaller(ll n,ll m){
    if(n>m) return m;
    return n;
}
int main(){
    ll n,k;
    scanf("%lld%lld",&n,&k);
    ll right = n*n;
    ll left = 1;
    ll result;
    ll mid;
    while (right>=left)
    {
        ll sum = 0;
        mid = (right+left)/2;
        for(int i=1;i<=n;i++) sum += smaller(mid/i,n);
        if (sum>=k)
        {
            right = mid - 1;
            result = mid;    
        }
        else
        {
            left = mid + 1;
        }
    }
    printf("%lld\n",result);
}