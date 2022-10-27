#include <stdio.h>

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    if(n>m) printf(">\n");
    else if(n<m) printf("<\n");
    else printf("==\n");
    return 0;
}