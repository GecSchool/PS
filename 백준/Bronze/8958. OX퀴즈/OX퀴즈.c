#include <stdio.h>
#include <string.h>
#define MAX_SIZE 81
int main(){
  int n;
  scanf("%d",&n);
  for(int i = 0;i < n;i++){
    char str[MAX_SIZE] = {0,};
    int dp[MAX_SIZE] = {0,};
    scanf("%s",str);
    int strLen = strlen(str); 
    for(int j = 1;j <= strLen;j++){
      if(str[j - 1] == 'O'){
        dp[j] = dp[j - 1] + 1;
      }
    }
    int ans = 0;
    for(int j = 1;j <= strLen;j++){
      ans += dp[j];
    }
    printf("%d\n",ans);
  }
  return 0;
}