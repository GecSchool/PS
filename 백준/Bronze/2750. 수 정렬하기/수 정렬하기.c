#include <stdio.h>
int main(void){
    int n;
    scanf("%d",&n);
    int num[n+1];
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    int tmp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(num[j]>num[j+1]){
                tmp=num[j];
                num[j]=num[j+1];  
                num[j+1]=tmp; 
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d\n",num[i]);
    }
    return 0;
}