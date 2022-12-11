#include <stdio.h>
#include <string.h>
#define size 101
int bigger(int n,int m){ // data[i] data[j]
    char num1[size] = {0, }; //nm
    char num2[size] = {0, }; //mn
    char tmp1[size] = {0, };
    char tmp2[size] = {0, };
    sprintf(num1,"%d",n);
    sprintf(num2,"%d",m);
    sprintf(tmp1,"%d",m);
    sprintf(tmp2,"%d",n);
    strcat(num1,tmp1);
    strcat(num2,tmp2);
    for(int i=0;i<strlen(num1);i++){
        if(num1[i]>num2[i]) return 0; // nm -> n big// mn
        else if(num2[i]>num1[i]) return 1;
    }
    return 1;
}
void merge(int data[], int p, int q, int r) {
    int i = p, j = q+1, k = p;
    int tmp[1001]; // 새 배열
    while(i<=q && j<=r) {
        if(bigger(data[i],data[j])) tmp[k++] = data[i++]; // bigger j가 크거나 같을 때 1
        else tmp[k++] = data[j++];
    }
    while(i<=q) tmp[k++] = data[i++];
    while(j<=r) tmp[k++] = data[j++];
    for(int a = p; a<=r; a++) data[a] = tmp[a];
    return;
}
void mergeSort(int data[], int p, int r) { //정렬하고 싶은 배열,시작점,끝점
    int q;
    if(p<r) {
        q = (p+r)/2;
        mergeSort(data, p , q);
        mergeSort(data, q+1, r);
        merge(data, p, q, r);
    }
    return;
}
int check_first(int n){
    while (n>=10)
    {
        n /= 10;
    }
    return n;
}
int main(){
    int arr[10][1000] ={0,};
    int tmp,n,m,max=0;
    int top[10] ={0, };
    int gec;
    for(int i=0;i<=9;i++) top[i] = -1;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&tmp);
        max = (max<=tmp) ? tmp : max;
        int first = check_first(tmp);
        top[first] += 1;
        arr[first][top[first]] = tmp;
    }
    gec = check_first(max);
    for(int i=0;i<m-n;i++){
        top[gec]+=1;
        arr[gec][top[gec]] = max;
    }
    for(int i=1;i<=9;i++){ // 1 ~ 9
        if(top[i]!=(-1)) mergeSort(arr[i],0,top[i]);
    }
    if(top[0]==n-1) printf("0");
    else{
        for(int i=9;i>=0;i--){
            for(int j=top[i];j>=0;j--){
                printf("%d",arr[i][j]);
            }
        }
    }
    printf("\n");
    return 0;
}