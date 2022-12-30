#include <stdio.h>
#define size 7368790
int main(){
    int number[size];
    for(int i=2;i<size;i++){
        number[i]=i;
    }
    for(int i=2;i<size;i++){
        if(number[i]==0) continue;
        for(int s=2*i;s<size;s+=i){
            number[s]=0;
        }
    }
    int n;
    scanf("%d",&n);
    int s=0;
    for(int i=2;i<size;i++){
        if(number[i]==0) continue;
        if(++s==n){ 
            printf("%d\n",number[i]);
            return 0;
        }
    }
}