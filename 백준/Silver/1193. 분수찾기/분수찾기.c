#include <stdio.h>
int main(void){
	int number;
    int total=1;
    int i=1;
    int s=1;
    scanf("%d",&number);
    for(;number>=i;i+=s,s++){
        total++;
    }
    if(total%2!=0){
        printf("%d/%d\n",total-(i-number),i-number);
        return 0;        
    }
    else{
        printf("%d/%d\n",i-number,total-(i-number));
        return 0;
    }
}