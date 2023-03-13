#include <stdio.h>
#include <string.h>

int main(void){
    char dan[100];
    int dan_len;
    int num[26];
    for(int i=0;i<26;i++){
        num[i]=-1;
    }
    scanf("%s",dan);
    dan_len=strlen(dan);
    for(int i=0;i<dan_len;i++){
        dan[i]-='a';
    }
    for(int i=0;i<dan_len;i++){
        if(num[dan[i]]==-1){
            num[dan[i]]=i;
        }
    }
    for(int i=0;i<26;i++){
        printf("%d ",num[i]);
    }
    printf("\n");
    return 0;
}