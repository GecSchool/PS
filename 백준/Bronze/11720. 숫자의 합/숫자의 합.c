#include <stdio.h>

int main(void){
	int n,sum=0;
	char number[100];
	scanf("%d",&n);
	scanf("%s",number);
	for(int i=0;i<n;i++){
		number[i]-='0';
	}
	for(int i=0;i<n;i++){
		sum+=number[i];
	}
	printf("%d\n",sum);
	return 0;
}