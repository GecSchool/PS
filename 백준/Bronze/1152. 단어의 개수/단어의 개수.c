#include <stdio.h>
#include <string.h>
#define MAX_SIZE 1000001
int main(){
  int ans = 0;
  char str[MAX_SIZE] = {0,};
  scanf("%[^\n]",str);
  int strLen = strlen(str);
  if(str[0]!=' ') ans++; 
  for(int i = 1;i < strLen;i++){
    if(str[i] != ' '&& str[i-1]==' ') ans++;
  }
  printf("%d\n",ans);
  return 0;
}