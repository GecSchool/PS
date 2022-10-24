#include <stdio.h>
#include <string.h>
int t;
int main(){
    scanf("%d",&t);
    for(int i = 0;i < t;i++){
        int n,strLen;
        char str[100];
        scanf("%d %s",&n,str);
        strLen = strlen(str);
        for(int j = 0;j < strLen;j++){
            for(int s = 0;s < n;s++){
              printf("%c",str[j]);
            }
        }
      printf("\n");
    }
    return 0;
}