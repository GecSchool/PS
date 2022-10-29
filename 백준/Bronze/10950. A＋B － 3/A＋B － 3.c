#include <stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    for(int i = 0;i < t;i++){
        int firNum, secNum;
        scanf("%d %d",&firNum,&secNum);
        printf("%d\n",firNum + secNum);
    }
    return 0;
}