#include <stdio.h>
#define size 10001
int bigger(int n,int m){
    if(n>m) return n;
    return m;
}
int main(){
    int dp[size]={0, };
    int index[size] ={0, };
    int num1[size] = {0, }; // 순서 입력 숫자
    int num2[size] = {0, }; // 숫자 입력 순서
    int tmp[size] = {0, }; // 
    int arr[size] = {0, };
    int n;
    int num;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&num1[i]);
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        num2[num] = i;
    }
    for(int i=1;i<=n;i++) tmp[i]=num2[num1[i]]; // tmp = 숫자 순서[순서 숫자] // 순서[]
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            if(tmp[j]<tmp[i]){ 
                if(bigger(dp[i],dp[j]+1)==dp[j]+1) index[i] = j;
                dp[i] = bigger(dp[i],dp[j]+1);
            }
        }
    }
    int max=0;
    int max_index;
    for(int i=1;i<=n;i++){
        if(max<dp[i]){
            max = dp[i];
            max_index = i;
        }
    }
    int s = max_index; // index
    int l = max_index;
    for(int i=0;i<max;i++){
        arr[num1[l]] = 1;
        l = index[s];
        s = index[s];
    }
    printf("%d\n",max);
    if(max==1){
        printf("%d\n",1);
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(arr[i]==1) printf("%d ",i);
    }
    printf("\n");
    return 0;
}