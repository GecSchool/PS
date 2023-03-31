#include <stdio.h>

int main(){
    long long sum = 0;
    for(int i = 0;i < 3;i++){
        long long tmp;
        scanf("%lld",&tmp);
        sum += tmp;
    }
    printf("%lld\n",sum);
    return 0;
}