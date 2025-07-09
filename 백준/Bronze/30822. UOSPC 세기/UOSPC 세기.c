#include <stdio.h>
#include <string.h>

int main() {
  char str[1001] = {0};
  int n;
  scanf("%d", &n);
  scanf("%s", str);
  for (int i = 0; i < n; i++) {
    if (str[i] == 'a') {
      str[i] = 'b';
    }
  }

  int uospc[26] = {0,};

  for (int i = 0; i < n; i++) {
    uospc[str[i] - 'a']++;
  }

  int min = 1001;

  char *uospc_str = "uospc";

  for (int i = 0; i < 5; i++) {
    if (uospc[uospc_str[i] - 'a'] < min) {
      min = uospc[uospc_str[i] - 'a'];
    }
  }

  printf("%d\n", min);
  return 0;
}