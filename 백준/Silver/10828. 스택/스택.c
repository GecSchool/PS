#include <stdio.h>
#include <string.h>
int stack[10000];
int main(){
    int n;
    int s=0;
    int num;
    char command[10]={0};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",command);
        if(0==strcmp(command,"push")){
            scanf("%d",&num);
            stack[s++]=num;
        }
        else if(0==strcmp(command,"top")){
            if(s==0) printf("-1\n");
            else printf("%d\n",stack[s-1]);
        }
        else if(0==strcmp(command,"size")){
            printf("%d\n",s);
        }
        else if(0==strcmp(command,"pop")){
            if(s==0) printf("-1\n");
            else printf("%d\n",stack[--s]);
        }
        else if(0==strcmp(command,"empty")){
            if(s==0) printf("1\n");
            else printf("0\n");            
        }       
        memset(command,0,sizeof(command));         
    }
    return 0;
}