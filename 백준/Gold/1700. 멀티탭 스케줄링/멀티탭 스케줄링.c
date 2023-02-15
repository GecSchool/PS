#include <stdio.h>
int check_same(int plug[],int target,int n){
    for(int i=1;i<=n;i++){
        if(plug[i]==target) return 1;
    }
    return 0;
}
int check_drop(int plug[],int arr[],int i,int k,int n){
    int big = 0;
    int index=1;
    int len[101] = {0, };
    for(int j=1;j<=n;j++){
        for(int s=i;s<=k;s++){
            if(plug[j]==arr[s]){
                if (big<(s-i))
                {
                    big = s-i;
                    index = j;
                    break;
                }
                else if(plug[j]==arr[s]){
                    break;
                }
            }
            else if(s==k){
                big = 5000;
                index = j;
            }
        }
    }
    return index;
}
int main(){
    int n,k;
    int answer = 0; // 정답
    int arr[101]={0, }; // 행동 순서
    int plug[101]={0, }; // plug => 들어가 있는 수
    int top = 1;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++) scanf("%d",&arr[i]);
    for(int i=1;i<=k;i++){
        if(check_same(plug,arr[i],n)) continue; // i번째 물건 이미 있을 때
        if(top<=n){ // 초반 차기 전  넣어주기
            plug[top++] = arr[i];
            continue;
        }            
        // 다를 때 뺄거 정하기 플러그에 있는 수중 가장 먼거 빼기
        int tmp = check_drop(plug,arr,i,k,n);
        answer +=1;
        plug[tmp] = arr[i];
    }
    printf("%d\n",answer);
    return 0;
}