#include <stdio.h>
#include <string.h>
int main(void){
    char alpha[101]={0};
    int alphas=0;
    scanf("%s",alpha);
    for(int i=0;i<strlen(alpha);i++){
        if(alpha[i]=='c'&&alpha[i+1]=='='){
            alphas++;
            i+=1;
        }
        else if(alpha[i]=='c'&&alpha[i+1]=='-'){
            alphas++;
            i+=1;
        }
        else if(alpha[i]=='d'&&alpha[i+1]=='z'&&alpha[i+2]=='='){
            alphas++;
            i+=2;
        }
        else if(alpha[i]=='d'&&alpha[i+1]=='-'){
            alphas++;
            i+=1;
        }
        else if(alpha[i]=='l'&&alpha[i+1]=='j'){
            alphas++;
            i+=1;
        }
        else if(alpha[i]=='n'&&alpha[i+1]=='j'){
            alphas++;
            i+=1;
        }
        else if(alpha[i]=='s'&&alpha[i+1]=='='){
            alphas++;
            i+=1;
        }
        else if(alpha[i]=='z'&&alpha[i+1]=='='){
            alphas++;
            i+=1;
        }
        else{
            alphas++;
        }
    }
    printf("%d\n",alphas);
    return 0;
}