#include <stdio.h>
int main(void){
    int n;
    scanf("%d",&n);
    int x,y,dif;
    for(int i=0;i<n;i++){
        scanf("%d%d",&x,&y);
        dif=y-x;
        long long len=1;
        while(1){
            long long gec=(len+1)/2;
            if(len%2==1){
                if(dif>=gec*gec-gec+1&&dif<=gec*gec){
                    printf("%lld\n",len);
                    break;
                }
            }
            else{
                if(dif>=gec*gec+1&&dif<=gec*gec+gec){
                    printf("%lld\n",len);
                    break;
                }
            }
            len++;
        }
    }
    return 0;
}