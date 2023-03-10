#include <stdio.h>
#include <string.h>
int main(void){
    int n;
    char word[51]={0};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",word);
        int s=strlen(word);
        if(word[0]==')'||word[s]=='('){
            printf("NO\n");
            continue;
        }
        int a=0;
        int q=0;
        for(int j=0;j<s;j++){
            if(word[j]=='(') a++;
            else a--;
            if(a<0){
                printf("NO\n");
                q=1;
                break;
            }
        }
        if(a==0) printf("YES\n");
        else if(q!=1) printf("NO\n");
    }
    return 0;
}