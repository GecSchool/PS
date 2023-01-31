#include <stdio.h>
#define size 10001
void merge(int data[], int p, int q, int r) {
    int i = p, j = q+1, k = p;
    int tmp[size]; // 새 배열
    while(i<=q && j<=r) {
        if(data[i] <= data[j]) tmp[k++] = data[i++];
        else tmp[k++] = data[j++];
    }
    while(i<=q) tmp[k++] = data[i++];
    while(j<=r) tmp[k++] = data[j++];
    for(int a = p; a<=r; a++) data[a] = tmp[a];
}
void mergeSort(int data[], int p, int r) { //정렬하고 싶은 배열,시작점,끝점
    int q;
    if(p<r) {
        q = (p+r)/2;
        mergeSort(data, p , q);
        mergeSort(data, q+1, r);
        merge(data, p, q, r);
    }
}
int main(){
    int n;
    int minus[size];
    int plus[size];
    int pTop=-1;
    int mTop=-1;
    int tmp;
    int one=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&tmp);
        if(tmp>1) plus[++pTop] = tmp;
        else if(tmp == 1) one+=1;
        else if(tmp<=0) minus[++mTop] = tmp;
    }
    if(pTop!=-1)mergeSort(plus,0,pTop);
    if(mTop!=-1)mergeSort(minus,0,mTop);
    int sum = 0;
    if(pTop!=-1){
        if(pTop%2==1){
            for(int i=pTop;i>=1;i-=2){
                sum += plus[i]*plus[i-1];
            }
        }
        else{
            for(int i=pTop;i>=2;i -= 2){
                sum += plus[i]*plus[i-1];
            }
            sum += plus[0];
        }
    }
    if(mTop!=-1){
        if(mTop%2==1){ // 짝수개
            for(int i=0;i<mTop;i += 2){
                sum += minus[i]*minus[i+1];
            }
        }
        else{  // 홀수개
            for(int i=0;i<mTop-1;i += 2){
                sum += minus[i]*minus[i+1];
            }
            sum += minus[mTop];
        }
    }
    printf("%d\n",sum+one);
    return 0;
} 