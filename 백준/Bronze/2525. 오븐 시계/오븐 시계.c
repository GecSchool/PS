#include <stdio.h>
int main(){
  int n,m;
  scanf("%d %d",&n,&m);
  int total = n*60+m;
  int time;
  scanf("%d",&time);
  total += time;
  printf("%d %d",total/60%24,total%60);
  return 0;
}