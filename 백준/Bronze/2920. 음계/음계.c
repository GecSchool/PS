#include <stdio.h>
int main(void){
    int num[8];
    int re_num[8];
    int test[8];
    for(int i=0;i<8;i++){
        num[i]=i+1;
        re_num[i]=8-i;
    }
    for(int i=0;i<8;i++){
        scanf("%d",&test[i]);
    }
    for(int i=0;i<8;i++){
        if(num[i]!=test[i]){
            break;
        }
        if(i==7){
            printf("ascending\n");
            return 0;
        }
    }
    for(int i=0;i<8;i++){
        if(re_num[i]!=test[i]){
            break;
        }
        if(i==7){
            printf("descending\n");
            return 0;
        }
    }
    printf("mixed\n");
    return 0;
}