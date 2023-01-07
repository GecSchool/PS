#include <stdio.h>
#define size 100001
#define ll long long
void merge(ll data[][2], int p, int q, int r) {
    int i = p, j = q+1, k = p;
    ll tmp[size][2]; 
    while(i<=q && j<=r) {
        if(data[i][0] <= data[j][0]){
            tmp[k][1] = data[i][1];
            tmp[k++][0] = data[i++][0];
        } 
        else {
            tmp[k][1] = data[j][1];   
            tmp[k++][0] = data[j++][0];
        }
    }
    while(i<=q) {
        tmp[k][1] = data[i][1];
        tmp[k++][0] = data[i++][0];
    }
    while(j<=r) {
        tmp[k][1] = data[j][1];
        tmp[k++][0] = data[j++][0];
    }
    for(int a = p; a<=r; a++) {
        data[a][0] = tmp[a][0];
        data[a][1] = tmp[a][1];
    }
    return; 
}
void mergeSort(ll data[][2], int p, int r) {
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
    ll arr[size][2];
    ll totalSum = 0;
    ll targetSum = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%lld%lld",&arr[i][0],&arr[i][1]);
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++) totalSum += arr[i][1];
    for(int i=0;i<n;i++){
        targetSum += arr[i][1];
        if(targetSum>=(totalSum+1)/2){
            printf("%lld\n",arr[i][0]);
            return 0;
        }
    }
}