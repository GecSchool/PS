#include <stdio.h>
#define MAX_SIZE 100001

int main()
{
	int n, m;
	scanf("%d %d",&n,&m);
	int sum[MAX_SIZE] = {0,};
	for(int i = 1;i <= n;i++){
	    int tmp;
	    scanf("%d",&tmp);
	    sum[i] = sum[i - 1] + tmp;
	}
	for(int i = 0;i < m;i++){
	    int s,p;
	    scanf("%d %d",&s,&p);
	    printf("%d\n",sum[p]-sum[s - 1]);
	}
	return 0;
}