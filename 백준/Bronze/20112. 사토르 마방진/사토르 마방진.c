#include <stdio.h>

int main() {
  int n;
  char str[101][101] = {{0,},};
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", str[i]);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (str[i][j] != str[j][i]) {
        printf("NO\n");
        return 0;
      }
    }
  }

  printf("YES\n");
  return 0;
}