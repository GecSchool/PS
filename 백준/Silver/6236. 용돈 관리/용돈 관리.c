#include <stdio.h>
#define ll long long int
#define size 100001
int check(int num[],int,int,ll);//크기,n,m,mid
int main(){
    int n,m;
    scanf("%d",&n);
    int number[size];
    scanf("%d",&m);
    ll sum=0,result=0;
    for(int i=0;i<n;i++){
        scanf("%d",&number[i]);
        sum+=number[i];
    }
    ll right=sum,left=0;
    while (right>=left)
    {
        ll mid=(right+left)/2;
        int gec;
        gec=check(number,n,m,mid);
        if(gec==1){//mid is too big
            right=mid-1;
            result=mid;
        }
        else if(gec==-1){//mid is too small
            left=mid+1;
        }
    }
    printf("%lld\n",result);
}
int check(int number[size],int n,int m,ll mid){
    int disk_size[size];
    int s=0;
    for(int i=0;i<m;i++){
        disk_size[i]=mid;
    }
    for(int i=0;i<n;i++){
        if(mid<number[i]) return -1;
        disk_size[s]-=number[i];
        if(disk_size[s]<0){
            s++;
            if(s>m-1) return -1;
            i--;
        }
    }
    if(s<=m-1) return 1;
}