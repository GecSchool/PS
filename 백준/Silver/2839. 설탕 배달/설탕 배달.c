#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int i = n/5;i >= 0;i--){
        int tmp = n - 5 * i;
        if(!(tmp%3)){
            printf("%d\n",i + tmp / 3);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
